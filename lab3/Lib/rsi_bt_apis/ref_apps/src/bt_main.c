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

#include "rsi_bt_app.h"
#include "rsi_bt_global.h"
#include "rsi_bt_generic.h"
#include "rsi_bt_config.h"
#include "rsi_app_util.h"
#include "rsi_lib_util.h"
#include "rsi_hal.h"
#include "string.h"
#include "stdlib.h"
#include <mb9abxxx.h>
#include <spi.h>
#include <rsi_config.h>




RSI_BT_APP_CB            rsi_bt_AppControlBlock;
RSI_BT_SCANNED_DEVICES   rsi_bt_ScannedDevices[RSI_BT_INQ_MAX_DEVICES];
UINT08                   rsi_bt_ScannedDevsCount;


RSI_BT_RESPONSE *rsi_bt_parse_response(UINT08 *rsp);
#if 0
int16 rsi_oper_mode1()
{
    int16          retval;
	 rsi_uOperMode1  oper_mode;
	 const uint8    rsi_frameCmdOperMode1[3] = {0x10,  0x40, 0x10};

	 oper_mode.operModeFrameSnd.oper_mode              = (UINT32)(5 << 16);  //RSI_OPERMODE;
    oper_mode.operModeFrameSnd.feature_bit_map        = (UINT32)1; //RSI_FEATURE_BIT_MAP;
    oper_mode.operModeFrameSnd.tcp_ip_feature_bit_map = (UINT32)((1 << 1) | (1 << 2) | (1 << 10)); //RSI_TCP_IP_FEATURE_BIT_MAP;
    oper_mode.operModeFrameSnd.custom_feature_bit_map = (UINT32)(1 << 13); //RSI_CUSTOM_FEATURE_BIT_MAP;

    retval = rsi_execute_cmd((uint8 *)rsi_frameCmdOperMode1,(uint8 *)&oper_mode, sizeof(rsi_uOperMode1));
  
    return retval;
}

//UINT16 first_cmd_pkt_rcvd = 0;

UINT08  RSI_Add_RemoteDev (RSI_BT_EVENT_INQUIRY_RESPONSE  *p_inq_resp) 
{
   UINT08  ix;
   
   
   if ((p_inq_resp->BDAddress[0] == 0) &&
       (p_inq_resp->BDAddress[1] == 0) &&
       (p_inq_resp->BDAddress[2] == 0) && 
       (p_inq_resp->BDAddress[3] == 0) &&
       (p_inq_resp->BDAddress[4] == 0) && 
       (p_inq_resp->BDAddress[5] == 0)) {
          
       return 0;
   }
       
   if (!strlen (p_inq_resp->RemoteDeviceName)) {
       return 0;
   }
   
   for (ix = 0; ix < rsi_bt_ScannedDevsCount; ix++) {
      if (!memcmp (rsi_bt_ScannedDevices[ix].BDAddress, p_inq_resp->BDAddress, 6)) {
         return 0;
      }
   }
   
    if (rsi_bt_ScannedDevsCount < RSI_BT_INQ_MAX_DEVICES) {
       memcpy (rsi_bt_ScannedDevices[rsi_bt_ScannedDevsCount].BDAddress, p_inq_resp->BDAddress, 6);
       memcpy (rsi_bt_ScannedDevices[rsi_bt_ScannedDevsCount].DeviceName, p_inq_resp->RemoteDeviceName, p_inq_resp->NameLength);
       rsi_bt_ScannedDevsCount++;
       return RSI_TRUE;
    }       
   
   return RSI_FALSE;
}

UINT16  rsi_bt_pkt_receive (void)
{
   UINT08  module_type;
   UINT16  RetVal;
   UINT16  ResponseType;
   
   
   while (rsi_bt_AppControlBlock.PacketPending == RSI_FALSE) {
      delay (10);
   }
    if (rsi_bt_AppControlBlock.PacketPending == RSI_TRUE ) {
        RetVal = rsi_frame_read(rsi_bt_AppControlBlock.ReadPacketBuffer);
        rsi_bt_AppControlBlock.ResponseFrame = rsi_bt_parse_response(rsi_bt_AppControlBlock.ReadPacketBuffer);
					
		  module_type = (rsi_bt_AppControlBlock.ReadPacketBuffer[1] & 0xF0) >> 4;
          
        if (RetVal == 0) {
           /* Retrieve response code from the received packet */ 
           ResponseType                     = *(UINT16 *)(rsi_bt_AppControlBlock.ResponseFrame->ResponseCode);    
           rsi_bt_AppControlBlock.ErrorCode = *(UINT16 *)rsi_bt_AppControlBlock.ResponseFrame->Status;
           
           if (rsi_bt_AppControlBlock.ErrorCode) {
              FM4_GPIO->PDOR4_f.P43 = 0;
           } else {
              FM4_GPIO->PDOR4_f.P43 = 1;
           }
           
            
           switch (ResponseType) {
               case RSI_BT_EVT_SPP_RECEIVE:
                    FM4_GPIO->PDOR4_f.P43 = ~FM4_GPIO->PDOR4_f.P43;
                    rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uSppRxPkt.Data[rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uSppRxPkt.DataLen] = 0;
                    //DisplayRxData ((INT08 *)rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uSppRxPkt.Data);
                    break;
               
               case RSI_BT_RSP_SPP_TRANSFER:
                    FM4_GPIO->PDOR4_f.P42 = ~FM4_GPIO->PDOR4_f.P42;
                    break;
           }
        }
    }
    
    rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
	 rsi_irq_enable();
}

INT16 rsi_bt_init (void)
{
	  //UINT16   retval;
    UINT08   module_type;
    UINT08   sel_dev;
    INT16    RetVal;
    UINT16   ResponseType = 0;
    UINT08   inqiry_loop;
	 UINT08   spp_initiated = RSI_FALSE;
    
    rsi_bt_ScannedDevsCount = 0;

	
	WyzBee_spi_init();
	RetVal = rsi_sys_init();
	
	if(RetVal != 0)
	{
		return 0;
	}
   rsi_waitfor_boardready();
	rsi_select_option('1');
	
	rsi_bt_AppControlBlock.uBTApiInitParams = (RSI_BT_API *)malloc(sizeof (RSI_BT_API)); 
  //memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
		
    /*Enable the H/W module interrupt*/
    rsi_irq_start();
   
   inqiry_loop = 0;

    while(1) {
        
       /* MCU receives an external interrupt from the module */
        if(rsi_bt_AppControlBlock.PacketPending == RSI_TRUE ) {
            RetVal = rsi_frame_read(rsi_bt_AppControlBlock.ReadPacketBuffer);
            rsi_bt_AppControlBlock.ResponseFrame = rsi_bt_parse_response(rsi_bt_AppControlBlock.ReadPacketBuffer);
					
			   module_type = (rsi_bt_AppControlBlock.ReadPacketBuffer[1] & 0xF0) >> 4;
          
            if (RetVal == 0) {

#ifdef RSI_LITTLE_ENDIAN
                /* Retrieve response code from the received packet */ 
                ResponseType            = *(UINT16 *)(rsi_bt_AppControlBlock.ResponseFrame->ResponseCode);    
                rsi_bt_AppControlBlock.ErrorCode = *(UINT16 *)rsi_bt_AppControlBlock.ResponseFrame->Status;
#else
                /* Retrieve response code from the received packet */
                ResponseType           = rsi_bytes2R_to_uint16(rsi_bt_AppControlBlock.ResponseFrame->ResponseCode);
                rsi_bt_AppControlBlock.ErrorCode = rsi_bytes2R_to_uint16(&rsi_bt_AppControlBlock.ResponseFrame->Status);
#endif
							
                if (rsi_bt_AppControlBlock.ErrorCode) {
                    FM4_GPIO->PDOR4_f.P42 = 0u;				//@ P42	  LOW
                }

  							//printf("Response Rcvd %02x\n",ResponseType);
                /*if(first_cmd_pkt_rcvd == 1){
                    rsi_bt_decode_rsp(ResponseType, rsi_bt_AppControlBlock.ErrorCode, (void*)&rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad);
                    //printf("\r\nEnter to continue...\n");
                    //getchar();
                    //rsi_bt_app();
                }*/
                /* Switch between type of packet received */

                switch (ResponseType) {
									
                    case RSI_WIFI_RSP_CARD_READY:
                       if (!rsi_bt_AppControlBlock.ErrorCode) {
                                  rsi_oper_mode1();
                            }
                            else
                            {
                               return -1;
                            }
                            break;
                    case RSI_RSP_OPERMODE:
                           /*If opermode command response is success */
                         if (!rsi_bt_AppControlBlock.ErrorCode)
                           {
                                 /* Wifi operation mode response sucess. */
                                 //return 0;
                                 //retval = rsi_query_fw_version();
                            }
                            break;

                    case RSI_BT_RSP_CARD_READY:
                         if (!rsi_bt_AppControlBlock.ErrorCode) {
                             FM4_GPIO->PDOR4_f.P42 = 1u;
                             FM4_GPIO->PDOR4_f.P43 = 1u;
                             FM4_GPIO->PDOR4_f.P44 = 1u;
                           
                             rsi_bt_init_struct (RSI_BT_RSP_QUERY_LOCAL_NAME);
                             //rsi_bt_app();
                         } else {
                             return -1;
                         }
                         break;
												 
                     case RSI_BT_RSP_QUERY_LOCAL_NAME:
                           if (!rsi_bt_AppControlBlock.ErrorCode) {
                                 memcpy (rsi_bt_AppControlBlock.LocalName,
                                        rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryLocalName.Name ,
                                        rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryLocalName.NameLength);
                            }
                           rsi_bt_init_struct (RSI_BT_RSP_QUERY_LOCAL_BD_ADDRESS);
                           break;
                     
                     case RSI_BT_RSP_QUERY_LOCAL_BD_ADDRESS:
                           if (!rsi_bt_AppControlBlock.ErrorCode) {
                                 memcpy (rsi_bt_AppControlBlock.LocalBDAddr,
                                        rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryLocalBDAddr.BDAddress,
                                        6);
                            }
                            rsi_bt_init_struct (RSI_BT_RSP_SET_LOCAL_NAME);
                           break;
                            
                     case RSI_BT_RSP_SET_LOCAL_NAME:
                           rsi_bt_init_struct (RSI_BT_RSP_SET_DISCV_MODE);
                           break;
                     
                     case RSI_BT_RSP_SET_DISCV_MODE:
                           rsi_bt_init_struct (RSI_BT_RSP_SET_CONNECTABILITY_MODE);
                           break;
                     
                     case RSI_BT_RSP_SET_CONNECTABILITY_MODE:
                           rsi_bt_init_struct (RSI_BT_RSP_SET_PROFILE_MODE);
                           break;
                     
                     case RSI_BT_RSP_SET_PROFILE_MODE:
                          rsi_bt_init_struct (RSI_BT_REQ_INQUIRY);
                          rsi_bt_ScannedDevsCount = 0;
                          break;
                     
                     case RSI_BT_RSP_INQUIRY:
                          //rsi_bt_ScannedDevsCount = 0;
                          break;
                     
                     case RSI_BT_EVT_INQUIRY_RESPONSE:
                          {
                             RSI_Add_RemoteDev (&rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uInqResp);                                      
                          }
                          break;
                     
                     case RSI_BT_EVT_INQ_COMPLETE:
                          if ((rsi_bt_ScannedDevsCount > 4) || (inqiry_loop > 1)) {
                             //sel_dev = SelectBtDevice ();
                             memcpy(rsi_bt_AppControlBlock.RemoteBDAddress, (UINT08 *)rsi_bt_ScannedDevices[sel_dev].BDAddress, 6);
                             rsi_bt_init_struct (RSI_BT_REQ_BOND);
                          } else {
                             rsi_bt_init_struct (RSI_BT_REQ_INQUIRY);
                          }
                          inqiry_loop++;
                          break;
                     
                     case RSI_BT_RSP_BOND:
                           break;
                     
                     case RSI_BT_EVT_USER_PINCODE_REQUEST:
                           if (!rsi_bt_AppControlBlock.ErrorCode) {
                                 memcpy (rsi_bt_AppControlBlock.RemoteBDAddress,
                                        rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uUserPincodeReq.BDAddress,
                                        6);
                            }
                            rsi_bt_init_struct (RSI_BT_RSP_PINCODE_REPLY);
                           break;
                            
                     case RSI_BT_EVT_USER_LINKKEY_REQUEST:
                           rsi_bt_init_struct (RSI_BT_RSP_LINKKEY_REPLY);
                           break;
                     
                     case RSI_BT_EVT_USER_LINKKEY_SAVE:
                           if (!rsi_bt_AppControlBlock.ErrorCode) {
                                 memcpy (rsi_bt_AppControlBlock.RemoteLinkKey,
                                        rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uUserLinkKeySave.LinkKey,
                                        6);
                            }
                           break;
                            
                     case RSI_BT_REQ_PINCODE_REPLY:
                           break;
                     
                     case RSI_BT_EVT_AUTH_COMPLETE:
                     case RSI_BT_EVT_BOND_RESPONSE:
                           FM4_GPIO->PDOR4_f.P43 = 1u;
                          FM4_GPIO->PDOR4_f.P44 = 0u;
                          if (spp_initiated == RSI_FALSE) {
                              rsi_bt_init_struct (RSI_BT_REQ_SPP_CONNECT);
                                 spp_initiated = RSI_TRUE;
                            }
                           
                           break;
                     
                     case RSI_BT_REQ_SPP_CONNECT:
                           break;
                     
                     case RSI_BT_EVT_SPP_CONNECTED:
                          FM4_GPIO->PDOR4_f.P43 = 0u;
                          return (rsi_bt_AppControlBlock.ErrorCode);
                     
                          rsi_bt_init_struct (RSI_BT_RSP_SPP_TRANSFER);
                          break;
                     
                     case RSI_BT_EVT_SPP_RECEIVE:
                          FM4_GPIO->PDOR4_f.P43 = ~FM4_GPIO->PDOR4_f.P43;
                          rsi_bt_init_struct (RSI_BT_RSP_SPP_TRANSFER);
                          break;
                     
                     case RSI_BT_RSP_SPP_TRANSFER:											   
                           break;
                     
                     case RSI_BT_EVT_DISCONNECTED:
                     case RSI_BT_EVT_SPP_DISCONNECTED:
                          FM4_GPIO->PDOR4_f.P42 = 1u;
                          FM4_GPIO->PDOR4_f.P43 = 1u;
                          FM4_GPIO->PDOR4_f.P44 = 1u;
                          spp_initiated = RSI_FALSE;
                          break;
										
                    default:
											   ;//FM4_GPIO->PDOR4_f.P42 = 0u;				//@ P42	  LOW
											
                } //switch
            }
            else {
                //printf("Error reading response ....\n");	//if frame read ret_val
            }
						
        }

				rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
				rsi_irq_enable();				
				
#ifdef LINUX_PLATFORM
        rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;  //(rsi_linux_app_cb.rcv_queue.pending_pkt_count > 0);
#endif        
    }   //while

    return 0;
}
#endif

#if 0
/*=================================================*/
/**
 * @fn          rsi_uCmdRsp *rsi_parse_response(UINT08 *rsp)
 * @brief       To parse the resposne received from Kernel
 * @param[in]   UINT08 *rsp, response buffer pointer
 * @param[out]  none
 * @return      rsi_uCmdRsp *ptr, response pointer
 * @section description 
 * This API is used to parse the recieved response. This returns the 
 * pointer which points to rsptype, status, response payload in order.
 */

RSI_BT_RESPONSE *rsi_bt_parse_response(UINT08 *rsp)
{
  RSI_BT_RESPONSE         *temp_uCmdRspPtr = NULL;
  UINT16                  temp_rspCode;
  UINT16                  temp_status;
  //UINT08                  temp_module_type;
  UINT08                   *descPtr = rsp ;
  UINT08                   *payloadPtr = rsp + RSI_BT_FRAME_DESC_LEN;


  /* Retrieve response code from the received packet */
#ifdef RSI_LITTLE_ENDIAN
//temp_module_type = (((*(UINT16 *)(descPtr + RSI_BT_STATUS_OFFSET)) & 0xF000) >> 12);
  temp_status = (*(UINT16 *)(descPtr + RSI_BT_STATUS_OFFSET));
  temp_rspCode = *((UINT16 *)(descPtr + RSI_BT_RSP_TYPE_OFFSET)); 
#else
  temp_status = (UINT08)rsi_bytes2R_to_uint16(descPtr + RSI_BT_STATUS_OFFSET);
  temp_rspCode = rsi_bytes2R_to_uint16(descPtr + RSI_BT_RSP_TYPE_OFFSET);
#endif
  

  /* Copy the response type and status to payloadPtr-4, payloadPtr-2
   * locations respectively.
   */
#ifdef RSI_LITTLE_ENDIAN
  *((UINT16 *)(payloadPtr - 2)) = temp_status;
  *((UINT16 *)(payloadPtr - 4)) = temp_rspCode;
#else
  rsi_uint16_to_2bytes((payloadPtr - 2), temp_status);
  rsi_uint16_to_2bytes((payloadPtr - 4), temp_rspCode);
#endif

  temp_uCmdRspPtr = (RSI_BT_RESPONSE *)(payloadPtr - 4);

  return temp_uCmdRspPtr;
}
#endif
