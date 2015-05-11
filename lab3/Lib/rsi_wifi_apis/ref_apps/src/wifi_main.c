/**
 * @file     main.c
 * Copyright(C) 2013 Redpine Signals Inc.
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief MAIN: Top level file, execution begins here
 *
 * @section Description
 * This file contains the entry point for the application. It also has the 
 * initialization of parameters of the global structure and the operations to 
 * control & configure the module, like scanning networks, joining to an Access Point etc.
 */  

/**
 * Include files
 */ 
#include "rsi_global.h"
#include "rsi_config.h"
#include "rsi_app_util.h"
#include "rsi_spi_cmd.h"
#include "rsi_app.h"
#if JSON_LOAD
#include "sensor_data.h"
#endif

#if FIPS_MODE_ENABLE
#include "rsi_fips.h"
#endif

/** Global Variables
 */
#ifdef DATA_PACKET_ACK
volatile int ack_flag =0;
#endif

/* Application control block */
#ifndef LINUX_PLATFORM
rsi_app_cb_t            rsi_app_cb;
#else
rsi_app_cb_t            rsi_app_cb = 
{
#if (RSI_POWER_MODE == RSI_POWER_MODE_3)
  .ps_ok_to_send = 1
#endif
};
#endif

#if !RSI_TCP_IP_BYPASS
#if WEB_PAGE_LOAD 
/* Webpage to be loaded */
uint8 index_htm[] = 
#include "sample_webpage.txt"
;
uint8  webpage_load_done  =  0;
#endif
#if JSON_LOAD
uint8  json_load_done     =  0;
/* User Data Structures */
app_data_t sensor_data;
#endif

#if WEBPAGE_BYPASS_SUPPORT
uint8 host_webpage[] = 
#include "host_webpage.txt"
;
#endif
#endif

#if ENTERPRISE_MODE
#include "../../../../../apis/wlan/ref_apps/include/wifiuser.pem"
#include "../../../../../apis/wlan/ref_apps/include/testuser.pac"
#endif
#if (CLIENT_MODE && SSL_SUPPORT)
#include "../../../../../apis/wlan/ref_apps/include/cacert.pem"
#include "../../../../../apis/wlan/ref_apps/include/clientcert.pem"
#include "../../../../../apis/wlan/ref_apps/include/clientkey.pem"
#include "../../../../../apis/wlan/ref_apps/include/servercert.pem"
#include "../../../../../apis/wlan/ref_apps/include/serverkey.pem"
#endif

#if (FW_UPGRADE || RSI_ENABLE_UPGRADATION_FROM_HOST)
#if (RSI_UPGRADE_IMAGE_TYPE == RSI_UPGRADE_WLAN_FW)
uint32 fw_image[] = {
#include "../../../../../apis/wlan/ref_apps/src/wlan_rps_file"
};
#else
uint32 fw_image[] = {
#include "../../../../../apis/wlan/ref_apps/src/bl_rps_file"
};
#endif
#endif


/* function declarations */
int wifi_main(int app_mode);
int16 rsi_wifi_init(void);

rsi_uCmdRsp *rsi_parse_response(uint8 *rsp);
uint8 *rsi_wrapper_to_rsp(uint8 *rsp, uint8 rsp_type);
void  rsi_receive_data_packet(uint8 *payloadPtr, uint16 pkt_lenth);

int wifi_main(int app_mode)
{
  /* generic return value and counter*/
  int16       retval = 0;
#if !RSI_TCP_IP_BYPASS
  uint16      response_type = 0;
  uint32      tx_seq_no = 0;
  uint32      big_endian_tx_seq_no;
  uint16      send_descriptor = 0;
  uint8       socket_create = 1;
  uint16      socket_descriptor = 0;
  uint16      size =0;
  rsi_api     *ptrStrApi = &rsi_app_cb.rsi_strApi;
  uint32      bytes_sent = 0;
  uint8       opcode = 2;
#endif
#ifndef UART_INTERFACE 
#ifndef LINUX_PLATFORM 
  retval = rsi_sys_init();
  if(retval != 0)
  {
    return -1;
  }
#endif
#endif
#if HOST_INTERACTION_MODE
#if USB_DUAL_ENUMERATION
  if(app_mode == 1)
  {
#endif
    //! wait for board ready
    rsi_waitfor_boardready();
#if FW_UPGRADE
    rsi_upgrade_fw(RSI_UPGRADE_IMAGE_TYPE, (uint8 *)fw_image, sizeof(fw_image));
    /* Once firmware is upgraded re-initialize module again */
#ifndef LINUX_PLATFORM 
    retval = rsi_sys_init();
    if(retval != 0)
    {
      return -1;
    }
#else
    return 0;
#endif
#endif
    /* Load the firmware */
#if FIPS_MODE_ENABLE
    rsi_select_option(RSI_ENABLE_FIPS_MODE);
#endif
    rsi_select_option(RSI_HOST_BOOTUP_OPTION);
    if(RSI_HOST_BOOTUP_OPTION != RSI_LOAD_IMAGE_TYPE)
    {
#ifndef LINUX_PLATFORM 
      retval = rsi_sys_init();
      if(retval != 0)
      {
        return -1;
      }
#else
      return 0;
#endif
    }
#if USB_DUAL_ENUMERATION
    return 0;
  }
#endif
#endif

  /* To use the rsi_config.h settings */
  rsi_init_struct(&rsi_app_cb.rsi_strApi);

  /*Initialize the wi-fi functionality */
  retval = rsi_wifi_init();
  if(retval)
  {
    return retval;
  }
#if !RSI_TCP_IP_BYPASS
  while (1) 
  {
    /* MCU receives an external interrupt from the module */
    if(rsi_app_cb.pkt_pending == RSI_TRUE)
    {          
      retval = rsi_frame_read(rsi_app_cb.read_packet_buffer);                                                            
      rsi_app_cb.uCmdRspFrame = rsi_parse_response(rsi_app_cb.read_packet_buffer);

      if(retval == 0)
      { 
#ifdef RSI_LITTLE_ENDIAN
        /* Retrieve response code from the received packet */
        response_type           = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);    
        rsi_app_cb.error_code = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
#else
        /* Retrieve response code from the received packet */
        response_type           = rsi_bytes2R_to_uint16(rsi_app_cb.uCmdRspFrame->rspCode);
        rsi_app_cb.error_code = rsi_bytes2R_to_uint16(&rsi_app_cb.uCmdRspFrame->status);
#endif

        /* Switch between type of packet received */
        switch (response_type)
        {                                                        

#if JSON_LOAD
          case RSI_RSP_JSON_UPDATE:
            /* Print the response for now! */

#ifdef RSI_DEBUG_PRINT
            RSI_DPRINT(RSI_PL0,"RSI_RSP_JSON_UPDATE: %s\n", rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.uCmdRspBuf);
#endif
            if (sensor_data_update(&sensor_data, rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.uCmdRspBuf)) {
              json_load_done = 0;
              sensor_data_stringify(rsi_app_cb.json_buffer, &sensor_data);
              retval = rsi_json_create(&(rsi_app_cb.rsi_strApi.json), rsi_app_cb.json_buffer);
            }
            break;

          case RSI_RSP_CREATE_JSON:
            if (!rsi_app_cb.error_code) {

#ifdef RSI_DEBUG_PRINT
              RSI_DPRINT(RSI_PL0, "JSON Chunk Passed!\n");
#endif

              if (!json_load_done) {

#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Sending Next Chunk");
#endif
                retval = rsi_json_create(&(rsi_app_cb.rsi_strApi.json), rsi_app_cb.json_buffer);
              }
            }
            break;
#endif /* JSON_LOAD */
          case RSI_RSP_SOCKET_CREATE:
            {
	      if(!rsi_app_cb.error_code)
	     {
              register_socket_protocol(ptrStrApi);
#if DATA_TRANSFER_TYPE
              if(rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.socketFrameRcv.socketType[0] != RSI_SOCKET_TCP_SERVER)
              {
                rsi_app_cb.glbl_send_data = 1;
              }
#endif	
	     }
	     else
	     {
#ifdef RSI_DEBUG_PRINT

	       RSI_DPRINT(RSI_PL0,"\nRemote PEER socket not open state!!");
#endif
               return -1;
	     }
		
            }
            break;            
          case RSI_RSP_CLOSE:
            {
              unregister_socket_protocol();
              rsi_app_cb.glbl_send_data = 0;
            }
            break;    

          case RSI_RSP_REMOTE_TERMINATE: 
            {
              unregister_socket_protocol();
              rsi_app_cb.glbl_send_data = 0;
            }
            break;

          case RSI_RSP_CONN_ESTABLISH:
            {
#if DATA_TRANSFER_TYPE
              rsi_app_cb.glbl_send_data = 1;
#endif
              socket_descriptor = 0;
              //! socket descriptor
#ifdef RSI_LITTLE_ENDIAN
              socket_descriptor = *(uint16 *)(rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.recvLtcpEst.sock_id);
#else
              socketDescriptor  = rsi_bytes2R_to_uint16(rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.recvLtcpEst.sock_id);
#endif
              //! destination port
              memcpy((uint8 *)rsi_app_cb.socketsStrArray.socketsArray[socket_descriptor].dest_port, (uint8 *)rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.recvLtcpEst.fromPortNum, 2);

              if(*(uint16 *)rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.socketFrameRcv.ip_version == IP_VERSION_4)
              {
                //! detination ipv4 address
                memcpy((uint8 *)rsi_app_cb.socketsStrArray.socketsArray[socket_descriptor].dest_ip.ipv4_address, rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.recvLtcpEst.dst_ip_address.ipv4_address, 4);
                memcpy((uint8 *)ptrStrApi->uSocketFrame.socketFrameSnd.destIpaddr.ipv4_address ,rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.recvLtcpEst.dst_ip_address.ipv4_address, 4);                                            
              }
              else
              {
                //! destination ipv6 address
                memcpy((uint8 *)rsi_app_cb.socketsStrArray.socketsArray[socket_descriptor].dest_ip.ipv6_address, rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.recvLtcpEst.dst_ip_address.ipv6_address, 16);
                memcpy((uint8 *)ptrStrApi->uSocketFrame.socketFrameSnd.destIpaddr.ipv6_address , \
                    (uint8 *)rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.recvLtcpEst.dst_ip_address.ipv6_address, 16);                                            

              }
            }
            break;
#if WFU_UPGRADE
          case RSI_FWUP_REQ:
            if(!rsi_app_cb.error_code )
            {
              retval = rsi_wireless_fwupgrade();
            }
            else
            {
              return -1;
            }
            break;
          case RSI_FWUP_OK:
            if(!rsi_app_cb.error_code )
            {
            }
            else
            {
              return -1;
            }
            break;
#endif
          case RSI_RSP_TCP_CONN_STATUS_QUERY:
            if(!rsi_app_cb.error_code )
            {
              //TODO
            }
            else
            {
              return -1;
            }
            break;
          case RSI_RSP_IPCHANGE_NOTIFY:
            if(!rsi_app_cb.error_code )
            {
              //TODO
            }
            else
            {
              return -1;
            }
            break;
#ifdef DATA_PACKET_ACK
          case RSI_RSP_DATA_PACKET_ACK :
            ack_flag = 0;
#ifdef RSI_DEBUG_PRINT
                        
            RSI_DPRINT(RSI_PL0,"\nDATA PACKET ACKE is received!!\n\n");
#endif  
#endif


          default:                
            break;
        }
      }
      if(rsi_irq_status() == RSI_FALSE)
      {
        rsi_app_cb.pkt_pending = RSI_FALSE;
        rsi_irq_enable();
      }
    }

    if(socket_create)
    {
      socket_create = 0;
      retval = rsi_socket(&rsi_app_cb.rsi_strApi.uSocketFrame);
    }
#if (RSI_POWER_MODE == RSI_POWER_MODE_3)
    if(rsi_app_cb.glbl_send_data && !rsi_app_cb.ps_pkt_pending)
#else 
      if(rsi_app_cb.glbl_send_data)
#endif
#ifdef DATA_PACKET_ACK
      if(!ack_flag)
#endif
      {        
        size = 1400;
        send_descriptor = 1;

        big_endian_tx_seq_no = tx_seq_no;
        rsi_swap_4bytes((uint8 *)&big_endian_tx_seq_no);
        *(uint32 *)rsi_app_cb.send_buffer = big_endian_tx_seq_no;
        tx_seq_no++;
        /* 1 -socket descriptor , sendBuf -data to transmit ,size -size of the data ,1 -protocal(0-for UDP,1-for TCP) */

        if((rsi_app_cb.socketsStrArray.socketsArray[send_descriptor].protocol != RSI_PROTOCOL_UDP_V4) && \
            (rsi_app_cb.socketsStrArray.socketsArray[send_descriptor].protocol != RSI_PROTOCOL_UDP_V6))
        {
          if(SOCKET_FEATURE & RSI_WEBS_SUPPORT)
          {
            retval = rsi_send_websocket_data(send_descriptor,rsi_app_cb.send_buffer, size,rsi_app_cb.socketsStrArray.socketsArray[send_descriptor].protocol, opcode, &bytes_sent);
          }
          else
          {
            retval = rsi_send_data(send_descriptor,rsi_app_cb.send_buffer, size,rsi_app_cb.socketsStrArray.socketsArray[send_descriptor].protocol, &bytes_sent);
          }
        }
        else
        {
          retval = rsi_send_ludp_data(send_descriptor, rsi_app_cb.send_buffer, size , rsi_app_cb.socketsStrArray.socketsArray[send_descriptor].protocol, \
              (uint8 *)&rsi_app_cb.socketsStrArray.socketsArray[send_descriptor].dest_ip, *(uint16 *)rsi_app_cb.socketsStrArray.socketsArray[send_descriptor].dest_port, &bytes_sent);
        }
#ifdef LINUX_PLATFORM
        if(!retval)
        {
          measure_throughput(size, 0);
        }
#endif
#ifdef DATA_PACKET_ACK
       ack_flag = 1;
#endif
      }
  }                

  /**
   * System shutdown
   */
#endif
  return 0;
}


/*FUNCTION*********************************************************************
Function Name  : rsi_wifi_init
Description    : This function is used to Initialize the Wi-Fi
Returned Value : int16, -1 for failure
Parameters     : 
-----------------+-----+-----+-----+------------------------------
Name             | I/P | O/P | I/O | Purpose
-----------------+-----+-----+-----+------------------------------
 type            | X   | retval|   |  Wi-Fi initialization

 *END****************************************************************************/

int16 rsi_wifi_init(void)
{
  int16 retval;
  uint16 response_type = 0;
  uint8 wificonf_done = 0, index = 0 , wfd_dev_found = 0;
  rsi_wfdDevInfo   *ptrStrWfdDevInfo;
#if(ENTERPRISE_MODE ||(CLIENT_MODE && SSL_SUPPORT))
uint8 certificate_type = 1;
#endif
#if RSI_ENABLE_UPGRADATION_FROM_HOST
uint32 fw_image_size = sizeof(fw_image);
uint32 rps_offset = 0;
#endif
  /*Enable the wi-fi module interrupt*/
  rsi_irq_start();

  while(1)
  {     

    /* MCU receives an external interrupt from the module */
    if( rsi_app_cb.pkt_pending == RSI_TRUE )
    {
      {
        retval = rsi_frame_read(rsi_app_cb.read_packet_buffer);
        rsi_app_cb.uCmdRspFrame = rsi_parse_response(rsi_app_cb.read_packet_buffer);

        if(retval == 0)
        {
#ifdef RSI_LITTLE_ENDIAN
          /* Retrieve response code from the received packet */ 
          response_type            = *(uint16 *)(rsi_app_cb.uCmdRspFrame->rspCode);    
          rsi_app_cb.error_code = *(uint16 *)rsi_app_cb.uCmdRspFrame->status;
#else
          /* Retrieve response code from the received packet */
          response_type           = rsi_bytes2R_to_uint16(rsi_app_cb.uCmdRspFrame->rspCode);
          rsi_app_cb.error_code = rsi_bytes2R_to_uint16(&rsi_app_cb.uCmdRspFrame->status);
#endif                    

          /* Switch between type of packet received */
          switch (response_type)
          {
            case RSI_RSP_CARD_READY:                                    
              if(!rsi_app_cb.error_code)
              {
#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Card ready passed !\n");
#endif
                retval = rsi_oper_mode(&rsi_app_cb.rsi_strApi.opermode);
              }
              else
              {
                return -1;
              }
              break;
			  
#if ENABLE_USER_STORE_CONFIGURATION
            case RSI_RSP_USER_STORE_CFG:
        	if(!rsi_app_cb.error_code)
            {
#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Opermode Pased!\n");
#endif
#if (WEB_PAGE_LOAD && !RSI_TCP_IP_BYPASS)
#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Sending Clear Files Command\n");
#endif
                retval = rsi_webpage_clear_files(&(rsi_app_cb.rsi_strApi.clear_files));
#else
#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Sending FW Version Query\n");
#endif
                retval = rsi_query_fw_version();
#endif /* WEB_PAGE_LOAD */
           }
        	else
        	{
        		return -1;
        	}
            break;
#endif

#if RSI_DEBUG_PRINTS_ENABLE
            case RSI_RSP_DEBUG_PRINTS:
              if(!rsi_app_cb.error_code)
              {
#if ENTERPRISE_MODE
                if(EAP_CERTIFICATE_TYPE == RSI_EAP_TLS_CERTIFICATE)
                {
                  /* If Enterprise mode , send the Certificate load command */
                  retval = rsi_set_certificate(EAP_CERTIFICATE_TYPE, static_cert,sizeof(static_cert) - 1,&rsi_app_cb.set_chunks);
                }
                else
                {
                  /* If Enterprise mode , send the Certificate load command */
                  retval = rsi_set_certificate(EAP_CERTIFICATE_TYPE, testuser_pac, sizeof(testuser_pac) - 1,&rsi_app_cb.set_chunks);
                }
#else
                retval = rsi_oper_mode(&rsi_app_cb.rsi_strApi.opermode);
#endif
              }
              else
              {
                return -1;
              }
              break;
#endif

            case RSI_RSP_OPERMODE:
              /*If opermode command response is success */
              if(!rsi_app_cb.error_code)    
              {
#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Opermode Pased!\n");
#endif
#if RSI_BTLE_ONLY_MODE
                return 1;
#endif
#if RSI_LOAD_FWUPGRADATION_KEY
                retval = rsi_load_fwupgradation_key((uint8 *)&rsi_app_cb.rsi_strApi.fwupgradation_key);
#endif
#if RSI_DEBUG_PRINTS_ENABLE
                retval = rsi_debug_prints(&rsi_app_cb.rsi_strApi.uDebugFrame);
                break;
#endif
#if ENTERPRISE_MODE
                if(EAP_CERTIFICATE_TYPE == RSI_EAP_TLS_CERTIFICATE)
                {
                  /* If Enterprise mode , send the Certificate load command */
                  retval = rsi_set_certificate(EAP_CERTIFICATE_TYPE, wifiuser, sizeof(wifiuser) - 1,&rsi_app_cb.set_chunks);
                }
                else
                {
                  /* If Enterprise mode , send the Certificate load command */
                  retval = rsi_set_certificate(EAP_CERTIFICATE_TYPE, testuser_pac, sizeof(testuser_pac) - 1,&rsi_app_cb.set_chunks);
                }
#elif(CLIENT_MODE && SSL_SUPPORT)
                retval = rsi_set_certificate(RSI_SSL_CLIENT_CERTIFICATE, clientcert, sizeof(clientcert)-1, &rsi_app_cb.set_chunks);

#else
#if ENABLE_USER_STORE_CONFIGURATION
                retval = rsi_user_store_config(&rsi_app_cb.rsi_strApi.userstorecfg);
                break;
#endif

#if (WEB_PAGE_LOAD && !RSI_TCP_IP_BYPASS)
#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Sending Clear Files Command\n");
#endif
                retval = rsi_webpage_clear_files(&(rsi_app_cb.rsi_strApi.clear_files));
#else
#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Sending FW Version Query\n");
#endif
                retval = rsi_query_fw_version();
#endif /* WEB_PAGE_LOAD */
#endif

              }
              /*If opermode command fails */
              else
              {
#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Failed!");
#endif
                return -1;
              }
              break;
#if RSI_LOAD_FWUPGRADATION_KEY 
            case RSI_RSP_LOAD_FWUPGRADATION_KEY:
              {
                if(!rsi_app_cb.error_code)    
                {
#if RSI_DEBUG_PRINTS_ENABLE
                retval = rsi_debug_prints(&rsi_app_cb.rsi_strApi.uDebugFrame);
                break;
#endif
#if ENTERPRISE_MODE
                if(EAP_CERTIFICATE_TYPE == RSI_EAP_TLS_CERTIFICATE)
                {
                  /* If Enterprise mode , send the Certificate load command */
                  retval = rsi_set_certificate(EAP_CERTIFICATE_TYPE, wifiuser, sizeof(wifiuser) - 1,&rsi_app_cb.set_chunks);
                }
                else
                {
                  /* If Enterprise mode , send the Certificate load command */
                  retval = rsi_set_certificate(EAP_CERTIFICATE_TYPE, testuser_pac, sizeof(testuser_pac) - 1,&rsi_app_cb.set_chunks);
                }
#elif(CLIENT_MODE && SSL_SUPPORT)
                retval = rsi_set_certificate(RSI_SSL_CLIENT_CERTIFICATE, clientcert, sizeof(clientcert)-1, &rsi_app_cb.set_chunks);

#else
#if ENABLE_USER_STORE_CONFIGURATION
                retval = rsi_user_store_config(&rsi_app_cb.rsi_strApi.userstorecfg);
                break;
#endif

#if (WEB_PAGE_LOAD && !RSI_TCP_IP_BYPASS)
#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Sending Clear Files Command\n");
#endif
                retval = rsi_webpage_clear_files(&(rsi_app_cb.rsi_strApi.clear_files));
#else
#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Sending FW Version Query\n");
#endif
                retval = rsi_query_fw_version();
#endif /* WEB_PAGE_LOAD */
#endif


                }
                /*If opermode command fails */
                else
                {
#ifdef RSI_DEBUG_PRINT
                  RSI_DPRINT(RSI_PL0, "Failed!");
#endif
                  return -1;
                }
              }
              break;
#endif
            case RSI_RSP_FWVERSION_QUERY:
              /*If Firmware Version query command is success */
              if(!rsi_app_cb.error_code)
              {
#if (JSON_LOAD && !RSI_TCP_IP_BYPASS)
                /* Check if the webpage has associated JSON data */
                if (rsi_app_cb.rsi_strApi.uWebData.webServFrameSnd.Webpage_info.has_json_data
                    || WEB_PAGE_HAS_JSON) {

                  /* True: JSON needs to be loaded into the firmware! */
                  memset(rsi_app_cb.json_buffer, 0, JSON_BUFFER_SIZE);
                  sensor_data_init(&sensor_data);
                  sensor_data_stringify(rsi_app_cb.json_buffer, &sensor_data);
                  retval = rsi_json_create(&(rsi_app_cb.rsi_strApi.json), rsi_app_cb.json_buffer);
                }
                else 
#endif
                {

                  /* False: Proceed with band */
                  retval = rsi_band(rsi_app_cb.rsi_strApi.band);
                }
              }
              /*If Firmware Version query command if fail*/
              else
              {
                return -1;
              }
              break;    

            case RSI_RSP_BAND:
              /*If Band command response is success */
              if(!rsi_app_cb.error_code)
              {
#if RSI_ENABLE_REJOIN_PARAMS
                /*send the Rejoin Params command*/
                retval = rsi_rejoin_params(&rsi_app_cb.rsi_strApi.rejoin_param);
                break;
#endif
#if RSI_ENABLE_UPGRADATION_FROM_HOST
                retval = rsi_fwup_frm_host(&rsi_app_cb.rsi_strApi.fw_up_params,(uint8 *)fw_image,rps_offset,RSI_RPS_HEADER,FW_UP_REQ);
                rps_offset = RSI_RPS_HEADER;
                fw_image_size -= RSI_RPS_HEADER;
                break;
#endif
                /*send the Init command*/
                retval = rsi_init();                   

              }
              /*If Band command is failed*/
              else
              {
                return -1;
              }
              break;
#if RSI_ENABLE_UPGRADATION_FROM_HOST
            case RSI_RSP_FW_UP_REQ:
              {
                if(rsi_app_cb.error_code == RSI_FW_UP_SUCCESS)
                { 
                    fw_image_size = 0;
                    rps_offset = 0;
#if RSI_ENABLE_REJOIN_PARAMS
                    /*send the Rejoin Params command*/
                    retval = rsi_rejoin_params(&rsi_app_cb.rsi_strApi.rejoin_param);
                    break;
#endif
                    /*send the Init command*/
                    retval = rsi_init();                   
                }
                else if((!rsi_app_cb.error_code))
                {
                  if(fw_image_size < RSI_RPS_PAYLOAD_LEN)
                  {
                    retval = rsi_fwup_frm_host(&rsi_app_cb.rsi_strApi.fw_up_params,(uint8 *)fw_image,rps_offset,fw_image_size,FW_UP_PL);
                    fw_image_size = 0;
                    rps_offset = 0;
                  }
                  else
                  {
                    retval = rsi_fwup_frm_host(&rsi_app_cb.rsi_strApi.fw_up_params,(uint8 *)fw_image,rps_offset,RSI_RPS_PAYLOAD_LEN,FW_UP_PL);
                    fw_image_size -= RSI_RPS_PAYLOAD_LEN;
                  }
                  rps_offset += RSI_RPS_PAYLOAD_LEN;

                }
                else 
                {
                  return -1;
                }
              }
              break;
#endif
            case RSI_RSP_INIT:
              /*If Init command response is success */
              if(!rsi_app_cb.error_code)
              {
                memcpy(rsi_app_cb.mac_addr, rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.initResponse.macAddress, 6);

#if SET_REGION_SUPPORT
                retval = rsi_set_region(&rsi_app_cb.rsi_strApi.SetRegion);
                break;

#elif SET_REGION_AP_SUPPORT
                retval = rsi_set_region_ap(&rsi_app_cb.rsi_strApi.SetRegionAp);
                break;
#endif
#if P2P_MODE
                /*If P2p Mode , send the p2p Configure command*/
                retval = rsi_p2p_config(&rsi_app_cb.rsi_strApi.uconfigP2p);
#elif CLIENT_MODE
#if RSI_PSK_SUPPORT
                retval = rsi_psk(&rsi_app_cb.rsi_strApi.uPskFrame);
#else
                /*If legacy client mode ,send PSK*/
                retval = rsi_scan(&rsi_app_cb.rsi_strApi.uScanFrame);
#endif
#elif ENTERPRISE_MODE  
                /* If Enterprise mode , send the EAP command */
                retval = rsi_set_eap(&rsi_app_cb.rsi_strApi.usetEap);
#else
                /* If AP mode , send the AP Config / IP Config command.
                   We are not giving IPconfig here. So, AP will be created with Default IP
                   of 192.168.100.76 */
                retval = rsi_set_ap_config(&rsi_app_cb.rsi_strApi.apconf_data);
#endif
              }
              /*If Init command is failed*/
              else
              {
                return -1;
              }
              break;

#if SET_REGION_SUPPORT
            case RSI_RSP_SET_REG_CODE:
              {
                if(!rsi_app_cb.error_code)
                {
#if P2P_MODE
                  /*If P2p Mode , send the p2p Configure command*/
                  retval = rsi_p2p_config(&rsi_app_cb.rsi_strApi.uconfigP2p);
#elif CLIENT_MODE
                  /*If legacy client mode ,send the scan command*/
                  retval = rsi_scan(&rsi_app_cb.rsi_strApi.uScanFrame);

#elif ENTERPRISE_MODE
                  /* If Enterprise mode , send the EAP command */
                  retval = rsi_set_eap(&rsi_app_cb.rsi_strApi.usetEap);
#else
#endif
                }
                else
                {
                  return -1;
                }

              }
              break;
#endif

#ifdef SET_REGION_AP_SUPPORT
            case RSI_RSP_SET_REG_AP:
              {
                if(!rsi_app_cb.error_code)
                {
#if P2P_MODE
                  /*If P2p Mode , send the p2p Configure command*/
                  retval = rsi_p2p_config(&rsi_app_cb.rsi_strApi.uconfigP2p);
#else
                  /* If AP mode , send the AP Config / IP Config command.
                     We are not giving IPconfig here. So, AP will be created with Default IP
                     of 192.168.100.76 */
                  retval = rsi_set_ap_config(&rsi_app_cb.rsi_strApi.apconf_data);
#endif
                }
                else
                {
                  return -1;
                }
              }
              break;
#endif

#if (ENTERPRISE_MODE ||(CLIENT_MODE && SSL_SUPPORT))
            case RSI_RSP_SET_CERT:
              /* If Certificate chunk loaded  successfully */    

              if(!rsi_app_cb.error_code)
              {
                if(rsi_app_cb.set_chunks.cert_info.more_chunks ==0) /* if last chunk of certificate loaded successfully */ 
                {
#if (CLIENT_MODE && SSL_SUPPORT)
                	//!The next certificate can be given
                	certificate_type = rsi_app_cb.set_chunks.cert_info.CertType + 1;
#else
                  retval = rsi_band(rsi_app_cb.rsi_strApi.band);
                  break;
#endif
                }
                else
                {
                	certificate_type = rsi_app_cb.set_chunks.cert_info.CertType ;
                }
                 switch(certificate_type)
                  {
#if ENTERPRISE_MODE
                  case RSI_EAP_TLS_CERTIFICATE:
                    {
                      retval = rsi_set_certificate(EAP_CERTIFICATE_TYPE, wifiuser, sizeof(wifiuser)-1,&rsi_app_cb.set_chunks);
                    }
                	  break;
                  case RSI_EAP_FAST_PAC_CERTIFICATE:
                    {
                      retval = rsi_set_certificate(EAP_CERTIFICATE_TYPE, testuser_pac, sizeof(testuser_pac) - 1,&rsi_app_cb.set_chunks);
                    }
                  break;
#endif
#if (CLIENT_MODE && SSL_SUPPORT)
                  case RSI_SSL_CLIENT_CERTIFICATE:
                	   retval = rsi_set_certificate(RSI_SSL_CLIENT_CERTIFICATE,clientcert,sizeof(clientcert)-1, &rsi_app_cb.set_chunks);
                	   break;
                  case RSI_SSL_CLIENT_PRIVATE_KEY:
                	   retval = rsi_set_certificate(RSI_SSL_CLIENT_PRIVATE_KEY,clientkey,sizeof(clientkey)-1, &rsi_app_cb.set_chunks);
                	   break;
                  case RSI_SSL_CA_CERTIFICATE:
                	   retval = rsi_set_certificate(RSI_SSL_CA_CERTIFICATE,cacert,sizeof(cacert)-1,&rsi_app_cb.set_chunks);
                	   break;
                  case RSI_SSL_SERVER_CERTIFICATE:
                	   retval = rsi_set_certificate(RSI_SSL_SERVER_CERTIFICATE,servercert,sizeof(servercert)-1, &rsi_app_cb.set_chunks);
                	   break;
                  case RSI_SSL_SERVER_PRIVATE_KEY:
                	   retval = rsi_set_certificate(RSI_SSL_SERVER_PRIVATE_KEY,serverkey,sizeof(serverkey)-1, &rsi_app_cb.set_chunks);
                	   break;
#endif
                  default:
                  /* send the set band command if all the certificates being loaded*/
                  retval = rsi_band(rsi_app_cb.rsi_strApi.band);
                   break;

                  }

              }
              /* If certificate load command fail */
              else
              {
                return -1;
              }
              break;
#endif
            case RSI_RSP_SET_EAP_CFG:
              /* If Set eap command success */
              if(!rsi_app_cb.error_code)
              {
                retval = rsi_scan(&rsi_app_cb.rsi_strApi.uScanFrame);
              }
              /* If set eap command fail */
              else
              {
                return -1;
              }
              break;

#if RSI_PSK_SUPPORT
            case RSI_RSP_HOST_PSK:
              /* If Set eap command success */
              if(!rsi_app_cb.error_code)
              {
                memcpy(rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.PmkResponse.pmk,&rsi_app_cb.rsi_strApi.uPskFrame.PskFrameSnd.psk_or_pmk[0] , 32);
                retval = rsi_scan(&rsi_app_cb.rsi_strApi.uScanFrame);
              }
              /* If set eap command fail */
              else
              {
                return -1;
              }
              break;
#endif

            case RSI_RSP_SCAN:  
              /*If Scan command is success*/
              if(!rsi_app_cb.error_code)
              {

#if FIPS_MODE_ENABLE
                retval = rsi_query_config_checksum();
#else
#if RSI_WMM_PS_SUPPORT
                /* send wmm ps command */
                retval = rsi_wmm_ps(&rsi_app_cb.rsi_strApi.uWmmPs);
                break;
#endif
                /* send join command */

#if RSI_WPS_SUPPORT
                retval = rsi_wps_method(&rsi_app_cb.rsi_strApi.uWpsMethod);                      
#else
                retval = rsi_join(&rsi_app_cb.rsi_strApi.uJoinFrame);                      
#endif
#endif
              }
              else
              {                    
                return -1;
              }
              break;
#if FIPS_MODE_ENABLE		  
            case RSI_RSP_STORE_CFG_CKHSUM:
              if(!rsi_app_cb.error_code)
              {
			    //! Give next command
              }
              else
              {
                return -1;
              }

              break;
            case RSI_RSP_FIPS_FAILURE:
              {
#ifdef ENABLE_DEBUG_PRINTS
                RSI_DPRINT(RSI_PL0,"FIPS FAILURE STATE\n");
#endif
              }
              break;
#endif
#if RSI_BG_SCAN_ENABLE
            case RSI_RSP_BG_SCAN:  
              /*If BG Scan command is success*/
              if(!rsi_app_cb.error_code)
              {
#if RSI_INSTANT_BG
                retval = rsi_bg_scan(&rsi_app_cb.rsi_strApi.ubgScanFrame);
                break;
#endif

#if RSI_ROAMING_SUPPORT
                retval = rsi_roam_params(&rsi_app_cb.rsi_strApi.uRoamParams);
                break;                        
#endif
#if RSI_TCP_IP_BYPASS
                wificonf_done = 1;
                break;
#endif
              }
              else
              {                    
                return -1;
              }
              break;
#endif

            case RSI_RSP_CFG_P2P:
              /*If Config P2p Command success */
              if(!rsi_app_cb.error_code)
              {
                if(GO_INTENT_VALUE == 16)
                {
                  /* send join command in  AUTO GO and Access point mode */
                  retval = rsi_join(&rsi_app_cb.rsi_strApi.uJoinFrame);
                }    
              }
              /* If config P2p command fail */
              else
              {
                return -1;
              }
              break;

            case RSI_RESP_WFD_DEV:
              /* If RSI module finds any WiFi-Direct Devices */
              if(!rsi_app_cb.error_code)
              {
                ptrStrWfdDevInfo = &rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.wfdDevResponse.strWfdDevInfo[0];

                for(index = 0; index < rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.wfdDevResponse.devCount;  index++,ptrStrWfdDevInfo++)
                {    
                  if(!strcmp((void *)ptrStrWfdDevInfo->devName, RSI_JOIN_SSID))
                  {
                    wfd_dev_found = 1;
                    break;
                  }
                }    
                if(wfd_dev_found)                  
                {
                  /* send the Join command */
                  retval = rsi_join(&rsi_app_cb.rsi_strApi.uJoinFrame);                      
                  wfd_dev_found = 0;
                }
              }
              else
              {
                return -1;
              }

              break;

#if AP_MODE
            case RSI_RSP_APCONFIG:
              {
                if( !rsi_app_cb.error_code) 
                {
                  retval = rsi_join(&rsi_app_cb.rsi_strApi.uJoinFrame);                      

                }
                else
                {
                  return -1;
                }
              }
              break;
#endif

            case RSI_RSP_P2P_CONNREQ:
              if( !rsi_app_cb.error_code) 
              {                      
                /*send the join command*/
                retval = rsi_join(&rsi_app_cb.rsi_strApi.uJoinFrame); 

              }
              /*If  it is failed*/
              else
              {                    
                return -1;
              }
              break;

            case RSI_RSP_JOIN:
              /*If Join command response is success */
              if( !rsi_app_cb.error_code) 
              {                     
#if RSI_MULTICAST_FILTER_ENABLE
                uint8 MAC[6];
                rsi_ascii_mac_address_to_6bytes((uint8 *)MAC, RSI_MULTICAST_MAC_ADDRESS);
                retval = rsi_multicast_mac_filter(RSI_MULTICAST_MAC_SET_ALL, MAC);
                break;
#endif

#if RSI_POWER_MODE
                retval = rsi_power_mode(rsi_app_cb.rsi_strApi.powerMode);
                break;
#endif
#if RSI_BG_SCAN_ENABLE
                retval = rsi_bg_scan(&rsi_app_cb.rsi_strApi.ubgScanFrame);
                break;
#endif 
                if(rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.joinResponse.operState == 'G' )
                {
                  wificonf_done = 1;
                  break;
                }
                else
                {
                  /*send the IP config command*/
#if !RSI_TCP_IP_BYPASS
#if IPV6_SUPPORT
                  retval = rsi_ipv6_param_set(&rsi_app_cb.rsi_strApi.uIpconf6Frame);
#else
                  retval = rsi_ip_param_set(&rsi_app_cb.rsi_strApi.uIpparamFrame);
#endif
#else
                  wificonf_done = 1;

#endif
                }

              }
              /*If Join command is failed*/
              else
              {                    
                return -1;
              }
              break;

#if RSI_MULTICAST_FILTER_ENABLE
            case RSI_RSP_MULTICAST_FILTER:
              if( !rsi_app_cb.error_code) 
              {

#if RSI_BG_SCAN_ENABLE
                retval = rsi_bg_scan(&rsi_app_cb.rsi_strApi.ubgScanFrame);
                break;
#endif 
#if RSI_TCP_IP_BYPASS
                wificonf_done = 1;
                break;
#endif
              }else
              {
                return -1;
              }
              break;
#endif

#if RSI_POWER_MODE
            case RSI_RSP_PWRMODE:
              /*If Power mode command response is success */
              if(!rsi_app_cb.error_code )
              {
                /*send the IP config command*/
#if !RSI_TCP_IP_BYPASS
#if IPV6_SUPPORT
                retval = rsi_ipv6_param_set(&rsi_app_cb.rsi_strApi.uIpconf6Frame);
#else
                retval = rsi_ip_param_set(&rsi_app_cb.rsi_strApi.uIpparamFrame);
#endif
#else
                wificonf_done = 1;
#endif

              }
              /*If Power mode command is failed*/
              else
              {                    
                return -1;
              }
              break;
#endif

#if PER_MODE
            case RSI_RSP_PER_PARAMS:
              if(!rsi_app_cb.error_code )
              {

              }
              else
              {
                return -1;
              }
              break;
#endif

            case RSI_RSP_MAC_QUERY:
              /* If MAC Query Response is success */
              if(!rsi_app_cb.error_code)
              {
                wificonf_done =1;

              }
              /* If MAC Query Response is fail */
              else
              {
                return -1;
              }    
              break;

#if RSI_ROAMING_SUPPORT
            case RSI_RSP_ROAM_PARAMS:
              if(!rsi_app_cb.error_code )
              {
                //TODO
              }
              else
              {
                return -1;
              }    
              break;
#endif

#if AP_MODE
            case RSI_RSP_AP_HT_CAPS:
              if(!rsi_app_cb.error_code )
              {
                retval = rsi_set_ap_config(&rsi_app_cb.rsi_strApi.apconf_data);
              }
              else
              {
                return -1;
              }    
              break;
#endif

#if RSI_WMM_PS_SUPPORT
            case RSI_RSP_WMM_PS:
              if(!rsi_app_cb.error_code )
              {
#if RSI_WPS_SUPPORT
                retval = rsi_wps_method(&rsi_app_cb.rsi_strApi.uWpsMethod);                      
#else
                retval = rsi_join(&rsi_app_cb.rsi_strApi.uJoinFrame);                      
#endif
              }
              else
              {
                return -1;
              }    
              break;
#endif

#if RSI_WPS_SUPPORT
            case RSI_RSP_WPS_METHOD:
              if(!rsi_app_cb.error_code )
              {
                retval = rsi_join(&rsi_app_cb.rsi_strApi.uJoinFrame);                      
              }
              else
              {
                return -1;
              }    
              break;
#endif

            case RSI_RSP_MODULE_STATE:
              {
                /*If async message  is enabled through custom bit feature select. Parse response from here*/
#ifdef ENABLE_DEBUG_PRINTS
                RSI_DPRINT(RSI_PL0,"Module status :");
                RSI_DPRINT(RSI_PL0,"Timestamp-> %d \n",*(uint32*)rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.stateFrameRcv.TimeStamp);
                RSI_DPRINT(RSI_PL0,"stateCode-> %x \n",rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.stateFrameRcv.stateCode);
                RSI_DPRINT(RSI_PL0,"ReasonCode-> %x \n",rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.stateFrameRcv.reason_code);
                RSI_DPRINT(RSI_PL0,"Channel-> %x \n",rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.stateFrameRcv.rsi_channel);
                RSI_DPRINT(RSI_PL0,"RSSI-> %x \n",rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.stateFrameRcv.rsi_rssi);
                RSI_DPRINT(RSI_PL0,"MAC-> %x,",rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.stateFrameRcv.rsi_bssid[0]);
                RSI_DPRINT(RSI_PL0," %x,",rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.stateFrameRcv.rsi_bssid[1]);
                RSI_DPRINT(RSI_PL0," %x,",rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.stateFrameRcv.rsi_bssid[2]);
                RSI_DPRINT(RSI_PL0," %x,",rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.stateFrameRcv.rsi_bssid[3]);
                RSI_DPRINT(RSI_PL0," %x,",rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.stateFrameRcv.rsi_bssid[4]);
                RSI_DPRINT(RSI_PL0," %x,",rsi_app_cb.uCmdRspFrame->uCmdRspPayLoad.stateFrameRcv.rsi_bssid[5]);
                RSI_DPRINT(RSI_PL0," \n");
#endif
              }
              break;

#if RSI_ENABLE_REJOIN_PARAMS
            case RSI_RSP_REJOIN_PARAMS:
              if(!rsi_app_cb.error_code )
              {
                /*send the Init command*/
                retval = rsi_init();        
              }else
              {
                return -1;
              }
              break;
#endif

#if !RSI_TCP_IP_BYPASS
#if WEB_PAGE_LOAD
            case RSI_RSP_CLEAR_FILES:
              /*If clear files is success */
              if(!rsi_app_cb.error_code)  
              {
#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Clear Files Pased!\nSending Webpage command\n");
#endif
                retval = rsi_load_web_page(&(rsi_app_cb.rsi_strApi.uWebData), index_htm);
              }
              /*If opermode command response is fail */
              else
              {
                return -1;
              }
              break;

            case RSI_RSP_GET_WEBPAGE:
              /**/
              if (!rsi_app_cb.error_code) {
                /* Send next command */
                if (webpage_load_done) {
                  /*send the Firmware version command*/
#ifdef RSI_DEBUG_PRINT
                  RSI_DPRINT(RSI_PL0, "Webpage Chunk Passed!\nSending FWVersion");
#endif
                  retval = rsi_query_fw_version();
                } else {
#ifdef RSI_DEBUG_PRINT
                  RSI_DPRINT(RSI_PL0, "Webpage Chunk Passed!\nSending Next Chunk");
#endif
                  retval = rsi_load_web_page(&(rsi_app_cb.rsi_strApi.uWebData), index_htm);
                }
              }
              else {
#ifdef RSI_DEBUG_PRINT
                RSI_DPRINT(RSI_PL0, "Opermode Pased!\nSending Webpage command");
#endif
                return -1;
              }
              break;
#endif

#if JSON_LOAD
            case RSI_RSP_CREATE_JSON:
              if (!rsi_app_cb.error_code) {

                if (json_load_done) {

                  /*send the Band command*/
#ifdef RSI_DEBUG_PRINT
                  RSI_DPRINT(RSI_PL0, "JSON Chunk Passed!\nSending Band");
#endif
                  retval = rsi_band(rsi_app_cb.rsi_strApi.band);
                } else {

#ifdef RSI_DEBUG_PRINT
                  RSI_DPRINT(RSI_PL0, "JSON Chunk Passed!\nSending Next Chunk");
#endif
                  retval = rsi_json_create(&(rsi_app_cb.rsi_strApi.json), rsi_app_cb.json_buffer);
                }

              } else {
                return -1;
              }
              break;
#endif

            case RSI_RSP_IPPARAM_CONFIG:
              /*If IP config command response is success */
              if(!rsi_app_cb.error_code )
              {
#if SNMP_SUPPORT
                retval = rsi_snmp_enable(rsi_app_cb.rsi_strApi.snmp_enable);
                break;
#endif
#if RSI_ROAMING_SUPPORT
                retval = rsi_roam_params(&rsi_app_cb.rsi_strApi.uRoamParams);
                break;                        
#endif
#if RSI_ICMP_FROM_MODULE
                retval = rsi_ping_request(&rsi_app_cb.rsi_strApi.ping);
#endif
#if !WEBPAGE_BYPASS_SUPPORT
                wificonf_done =1;
#endif
              }
              /*If IP config command is failed*/
              else
              {                    
                return -1;
              }
              break;

#if RSI_ICMP_FROM_MODULE
            case RSI_RSP_PING_PACKET:
              if(!rsi_app_cb.error_code )
              {
                wificonf_done =1;
              }
              else
              {                    
                return -1;
              }
              break;
#endif

#if IPV6_SUPPORT
            case RSI_RSP_IPCONF6:
              /*If IPV6 config command response is success */
              if(!rsi_app_cb.error_code )
              {
                wificonf_done =1;
              }
              /*If IPV6 config command is failed*/
              else
              {                    
                return -1;
              }
              break;
#endif

#if WEBPAGE_BYPASS_SUPPORT
            case RSI_REQ_HOST_WEBPAGE:
              {
                retval = rsi_send_url_rsp(&rsi_app_cb.rsi_strApi.UrlRsp, &rsi_app_cb.webpage_morechunks, host_webpage, (sizeof(host_webpage) - 1), 1);
              }
              break;
            case RSI_RSP_HOST_WEBPAGE:
              {
                if(!rsi_app_cb.error_code )
                {
                  if(rsi_app_cb.webpage_morechunks == 0)
                  {
                  }
                  else
                  {
                    retval = rsi_send_url_rsp(&rsi_app_cb.rsi_strApi.UrlRsp, &rsi_app_cb.webpage_morechunks, host_webpage, (sizeof(host_webpage) - 1), 0);
                  }
                }
                else
                {
                  return -1;
                }
              }
              break;
#endif

#ifdef SNMP_SUPPORT

            case RSI_RSP_SNMP_ENABLE:
              if(!rsi_app_cb.error_code )
              {
                //! Nothing to do
                retval = rsi_snmp_trap(&rsi_app_cb.rsi_strApi.uSnmptrap);
              }
              else
              {
                return -1;
              }
              break;

            case RSI_REQ_SNMP_SET:
              if(!rsi_app_cb.error_code )
              {
                //! Nothing to do


              }
              else
              {
                return -1;
              }
              break;

            case  RSI_RSP_SNMP_TRAP:
              if(!rsi_app_cb.error_code)
              {

              }
              else
              {
                return -1;
              }
              break;

            case RSI_REQ_SNMP_GET:
              if(!rsi_app_cb.error_code )
              {
                retval = rsi_snmp_get_rsp(&rsi_app_cb.rsi_strApi.uSnmp);
              }
              else
              {
                return -1;
              }    
              break;

            case RSI_RSP_SNMP_GET_RSP:
              if(!rsi_app_cb.error_code )
              {
                retval = rsi_snmp_get_rsp(&rsi_app_cb.rsi_strApi.uSnmp);
              }
              else
              {
                return -1;
              }    
              break;

            case RSI_REQ_SNMP_GETNEXT:
              if(!rsi_app_cb.error_code )
              {
                retval = rsi_snmp_get_next_rsp(&rsi_app_cb.rsi_strApi.uSnmp);
              }
              else
              {
                return -1;
              }    
              break;

            case RSI_RSP_SNMP_GETNEXT_RSP:
              if(!rsi_app_cb.error_code )
              {
                retval = rsi_snmp_get_rsp(&rsi_app_cb.rsi_strApi.uSnmp);
              }
              else
              {
                return -1;
              }    
              break;
#endif

            case RSI_RSP_IPCHANGE_NOTIFY:
              if(!rsi_app_cb.error_code )
              {
                //TODO
              }
              else
              {
                return -1;
              }
              break;
#endif

            default:
              break;

          }
        }
      }
      if(rsi_irq_status() == RSI_FALSE)
      {
        rsi_app_cb.pkt_pending = RSI_FALSE;
        rsi_irq_enable();
      }
    }     

    if(wificonf_done == 1)
    {
      break;
    }
  }
  return 0;
}
/*=================================================*/
/**
 * @fn          rsi_uCmdRsp *rsi_parse_response(uint8 *rsp)
 * @brief       To parse the resposne received from Kernel
 * @param[in]   uint8 *rsp, response buffer pointer
 * @param[out]  none
 * @return      rsi_uCmdRsp *ptr, response pointer
 * @section description 
 * This API is used to parse the recieved response. This returns the 
 * pointer which points to rsptype, status, response payload in order.
 */
rsi_uCmdRsp *rsi_parse_response(uint8 *rsp)
{
  rsi_uCmdRsp             *temp_uCmdRspPtr = NULL;
  uint8                   temp_rspCode;
  uint16                  temp_status;
  uint8                   *descPtr = rsp ;
  uint8                   *payloadPtr = rsp + RSI_FRAME_DESC_LEN;
#ifdef RSI_DEBUG_PRINT
  uint8 i;
#endif

#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL13,"Recieved Packet PRINT3 \n");
#endif
  /* Check whether it is any rxpkt or just a status indication */
#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL13,"Recieved Packet PRINT4 \n");
#endif


  /* In Response received First 24 bytes are header.
   * And then Desc and Payload of the response is present.
   * 2nd byte of the Desc is status and 14th byte of the Desc is RspType.
   */

  /* Retrieve response code from the received packet */
#ifdef RSI_LITTLE_ENDIAN
  temp_status = (*(uint16 *)(descPtr + RSI_STATUS_OFFSET));
  temp_rspCode = *((uint8 *)(descPtr + RSI_RSP_TYPE_OFFSET)); 
#else
  temp_status = (uint8)rsi_bytes2R_to_uint16(descPtr + RSI_STATUS_OFFSET);
  temp_rspCode = rsi_bytes2R_to_uint16(descPtr + RSI_RSP_TYPE_OFFSET);
#endif

#ifdef RSI_DEBUG_PRINT
  for(i=0;i<16;i++)
  {
    RSI_DPRINT(RSI_PL13,"received rspcode: 0x%x \n",descPtr[i]);

  }
#endif    

  if(temp_rspCode)
  {
#ifdef RSI_DEBUG_PRINT
    RSI_DPRINT(RSI_PL13,"received status : 0x%x \n",temp_status);
    RSI_DPRINT(RSI_PL13,"received rspcode: 0x%x \n",temp_rspCode);
#endif    
  }
  else
  {
    /* call data receive function */
    rsi_receive_data_packet(payloadPtr, (*(uint16 *)rsp & 0xfff));

  }
  /* this function does re arrange of the reponse 
     for the responses where the response structures are padded in between */
  if(!temp_status)
  {
    rsp = rsi_wrapper_to_rsp(rsp, temp_rspCode);  
  }

  /* Copy the response type and status to payloadPtr-4, payloadPtr-2
   * locations respectively.
   */
#ifdef RSI_LITTLE_ENDIAN
  *((uint16 *)(payloadPtr - 2)) = temp_status;
  *((uint16 *)(payloadPtr - 4)) = temp_rspCode;
#else
  rsi_uint16_to_2bytes((payloadPtr - 2), temp_status);
  rsi_uint16_to_2bytes((payloadPtr - 4), temp_rspCode);
#endif

  temp_uCmdRspPtr = (rsi_uCmdRsp *)(payloadPtr - 4);

  return temp_uCmdRspPtr;
}


/*=================================================*/
/**
 * @fn          uint8 *rsi_wrapper_to_rsp(uint8 *rsp, uint8 rsp_type)
 * @brief       To rearrange the response in response structure
 * @param[in]   uint8 *rsp, response buffer pointer
 * @param[in]   uint8 rsp_type, response type
 * @param[out]  none
 * @return      uint8 *ptr, response pointer
 * @section description 
 * This API is used to rearrange the response in the response structures when 
 * response bytes are shifted because of padding bytes added between the members
 * of the response structure.
 */
uint8 *rsi_wrapper_to_rsp(uint8 *rsp, uint8 rsp_type)
{
  uint8 *descPtr, *payloadPtr, *temp_payloadPtr;
  uint8 ii, scanInfo_size;
  rsi_wfdDevResponse wfdDevResp;
  rsi_scanResponse scanRsp;
#if (RSI_POWER_MODE == RSI_POWER_MODE_3)
  int16 retval = 0;
#endif

#if RSI_POWER_MODE
#ifdef RSI_DEBUG_PRINT
  static uint8 sleep_count = 0;
#endif
#endif
  descPtr = rsp;

  switch(rsp_type)
  {

#if (RSI_POWER_MODE == RSI_POWER_MODE_3)
    case RSI_RSP_SLP:
#ifdef RSI_DEBUG_PRINT
      RSI_DPRINT(RSI_PL13,"SLP%d\n",sleep_count++);
#endif
      do
      {
        retval = rsi_execute_cmd((uint8 *)rsi_sleepack,0,0);
      }while(retval == BUFFER_FULL_FAILURE);
      rsi_app_cb.ps_ok_to_send = 0;
      break;

    case RSI_RSP_WKP:
      rsi_app_cb.ps_ok_to_send = 1;
#ifdef RSI_DEBUG_PRINT
      RSI_DPRINT(RSI_PL13,"WKP\n");
#endif
      if (rsi_app_cb.ps_pkt_pending){
        do
        {
          retval = rsi_execute_cmd(rsi_app_cb.ps_descparam, 
              rsi_app_cb.ps_pkt_pending, rsi_app_cb.ps_size_param);
        }while(retval == BUFFER_FULL_FAILURE);
        rsi_app_cb.ps_pkt_pending = 0;
      }
      break;
#endif

    case RSI_RESP_WFD_DEV:
      memset(&wfdDevResp,0,sizeof(rsi_wfdDevResponse));
      descPtr = rsp ;
      temp_payloadPtr = payloadPtr = descPtr + RSI_FRAME_DESC_LEN;
      wfdDevResp.devCount = (descPtr[0] | ((descPtr[1] & 0x0f) << 8))/41;
      /* 1 byte(devState) + 32 byte(devName) + 6 byte(macAddress) + 2 byte (devtype)*/

      for(ii=0; ii< wfdDevResp.devCount; ii++)
      {
        wfdDevResp.strWfdDevInfo[ii].devState = *(payloadPtr);
        payloadPtr += 1;
        memcpy(wfdDevResp.strWfdDevInfo[ii].devName, payloadPtr, 32);
        payloadPtr += 32;
        memcpy(wfdDevResp.strWfdDevInfo[ii].macAddress, payloadPtr, 6);
        payloadPtr += 6;
        memcpy(wfdDevResp.strWfdDevInfo[ii].devtype, payloadPtr, 2);
        payloadPtr += 2;
      }

      memcpy(temp_payloadPtr, (uint8 *)&wfdDevResp, sizeof(rsi_wfdDevResponse));
      break;

#if RSI_INSTANT_BG
    case RSI_RSP_BG_SCAN:
#endif
    case RSI_RSP_SCAN:
      scanInfo_size = 46;
      /* 1 + 1 + 1 + 1 + 34 + 6 + 1 + 1 = 46 (sizeof scaninfo structure without padding bytes */
      memset(&scanRsp,0,sizeof(rsi_scanResponse));
      descPtr = rsp;
      temp_payloadPtr = payloadPtr = descPtr + RSI_FRAME_DESC_LEN;
      scanRsp.scanCount[0] = *(payloadPtr);
      if(scanRsp.scanCount[0] != 0)
      {
        payloadPtr += 8; /* move to  (scan count + reserved bytes) */

        for(ii=0; ii< scanRsp.scanCount[0]; ii++)
        {
          memcpy(&scanRsp.strScanInfo[ii], payloadPtr, scanInfo_size);
          payloadPtr += scanInfo_size;
        }
        memcpy(temp_payloadPtr, (uint8 *)&scanRsp, sizeof(rsi_scanResponse));
      }
      break;
    default:
      break;
  }

  return rsp;
}

/*=================================================*/
/**
 * @fn          void rsi_receive_data_packet(uint8 *rx_pkt_payload, uint16 pkt_length)
 * @brief       To receive data packet
 * @param[in]   uint8 *rx_pkt_payload, received packet payload
 * @param[in]   uint16 pkt_length,length of the received packet
 * @param[out]  none
 * @return      none
 * @section description 
 * This API is used to receive data packet from WIFI module
 */
void rsi_receive_data_packet(uint8 *rx_pkt_payload, uint16 pkt_length)
{
  rsi_app_cb.rcvd_data_pkt_count++;
#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL13,"pkt %d received \n",rsi_app_cb.rcvd_data_pkt_count);
#endif    
#ifdef LINUX_PLATFORM
  measure_throughput(pkt_length, 1);
#endif

}
