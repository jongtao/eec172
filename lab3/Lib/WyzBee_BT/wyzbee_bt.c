#ifdef __cplusplus
extern "C"{
#endif

#include <stdlib.h>
#include <string.h>
#include <wyzbee_bt.h>
#include <rsi_bt_app.h>
#include <spi.h>
#include <rsi_api.h>
#include <base_types.h>

	
	


	
int8       BT_ToChar (uint8      x)
{
    if (x <= 9) {
        return ('0' + x);
    }
    if ((x >= 0x0A) && (x <= 0x0F)) {
        return ('A' + (x - 0x0A));
    }

    return ((int8)-1);    
}

int8       BT_ToHex (uint8      ch)
{
    if ((ch >= '0') && (ch <= '9')) {
        return (ch - '0');
    }
    if ((ch >= 'A') && (ch <= 'F')) {
        return (0x0A + (ch - 'A'));
    }    
    if ((ch >= 'a') && (ch <= 'f')) {
        return (0x0A + (ch - 'a'));
    }

    return ((int8)-1);
}


uint16  BT_StrToBDAddr (uint8  *p_str_addr,
                        uint8  *p_bd_addr)
{
    int8       digit0;
    int8       digit1;
    uint32     str_len;
    uint32     i;


    if (p_str_addr == NULL) {
        return ((uint16)-1);
    }

    str_len = strlen((int8 *)p_str_addr);
    if (str_len != 17) {
        return ((uint16)-1);
    }

    i = 0;
    while (str_len) {
        digit0 = BT_ToHex(p_str_addr[str_len - 1]);         /* Converting Character to Hexadecimal value */
        if (digit0 < 0) {
            return ((uint16)-1);
        }

        digit1 = BT_ToHex(p_str_addr[str_len - 2]);         /* Converting Character to Hexadecimal value */
        if (digit1 < 0) {
            return ((uint16)-1);
        }

        p_bd_addr[i++] = (uint8     )digit0 | (uint8     )((uint8     )digit1 << 4);        
        str_len -= 2;
        if (str_len > 0) {
            str_len--;
					if (p_str_addr[str_len] != ':') {
                return ((uint16)-1);
            }
        }
    }

    return (ERR_NONE);
}

void  BT_BDAddrToStr (uint8   *p_hex_addr,
                      uint8   *p_str_addr)
{
    int8       i;


    for (i = 6; i > 0; i--) {
                                                           /* Converting Hexadecimal to Character value    */
       *p_str_addr = BT_ToChar((p_hex_addr[i - 1] & 0xF0) >> 4);
        p_str_addr++;
       *p_str_addr = BT_ToChar(p_hex_addr[i - 1] & 0x0F);   /* Converting Hexadecimal to Character value    */
        p_str_addr++;
        if (i > 1) {
			  *p_str_addr = ':';
            p_str_addr++;
        }
    }
   *p_str_addr = '\0';                                      /* Allocating NULL pointer at end of the string */
}
 
/*===================================================*/
/**
 * @fn			   :void  RSI_BT_GetRespPayload (RSI_BT_RESPONSE *cmd_resp)
 * @brief		   :Reads the response from the RS9113 module
 * @param 1[in]	:rsi_uCmdRsp *cmd_resp , pointer to the rsi_uCmdRsp structure  fills the response in cmd_resp
 * @param[out]  	:none
 * @return	   	:none
 * @description   :when interrupt comes it reads the packet from the RS9113 module
 */

uint16  RSI_BT_GetRespPayload (RSI_BT_RESPONSE *p_cmd_resp)
{
    uint16  count = 0;
    uint16  status;
   
    rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
    rsi_irq_enable();
   
	while (rsi_bt_AppControlBlock.PacketPending == RSI_FALSE) {
		count++;
      if (count > 0x1000) {
         return ((uint16)-1);
      }
      delay (10);
	}
	status = rsi_frame_read(rsi_bt_AppControlBlock.ReadPacketBuffer); //@  read data from the module
   if (status != 0) {
       return status;
   }
	p_cmd_resp = (RSI_BT_RESPONSE *) rsi_bt_parse_response(rsi_bt_AppControlBlock.ReadPacketBuffer); //@  copy parsed response to cmd_resp.
      
	return  ERR_NONE;
}

/*===================================================*/
/*
 * @fn			  	 :  WyzBee_BT_init()
 * @brief		    : This initializes the BT EDR module.
 * @param 1[in]	 : none
 * @param 2[in]	 : none
 * @param[out]	    : none
 * @return		    : 0- on success , error code - on failure
 * @description    : This initializes the WiFi module by executing commands in a sequence of order.
 *                   This function should call at very first time before using any BT related APIs.
 */

uint16 WyzBee_SelectMode (uint32  mode)
{
    uint16           retval;
	 rsi_uSelectMode  select_mode;
	 const uint8     rsi_frameCmdOperMode1[3] = {0x10,  0x40, 0x10};

	 select_mode.operModeFrameSnd.select_mode            = (uint32)(5 << 16);  //RSI_OPERMODE;
    select_mode.operModeFrameSnd.feature_bit_map        = (uint32)1; //RSI_FEATURE_BIT_MAP;
    select_mode.operModeFrameSnd.tcp_ip_feature_bit_map = (uint32)((1 << 1) | (1 << 2) | (1 << 10)); //RSI_TCP_IP_FEATURE_BIT_MAP;
    select_mode.operModeFrameSnd.custom_feature_bit_map = (uint32)(1 << 13); //RSI_CUSTOM_FEATURE_BIT_MAP;

    retval = rsi_execute_cmd((uint8 *)rsi_frameCmdOperMode1,(uint8 *)&select_mode, sizeof(rsi_uSelectMode));
  
    return retval;
}

/*===================================================*/
/*
 * @fn			  	 :  WyzBee_BT_init()
 * @brief		    : This initializes the BT EDR module.
 * @param 1[in]	 : none
 * @param 2[in]	 : none
 * @param[out]	    : none
 * @return		    : 0- on success , error code - on failure
 * @description    : This initializes the WiFi module by executing commands in a sequence of order.
 *                   This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_BT_init (void)
{
    uint8   module_type;
    int16    RetVal;
    uint16   ResponseType = 0;
    
    
	 WyzBee_spi_init();
	 RetVal = rsi_sys_init();
	
    if(RetVal != 0) {
       return 0;
    }
    rsi_waitfor_boardready();
    rsi_select_option('1');
	
    rsi_bt_AppControlBlock.uBTApiInitParams = (RSI_BT_API *)malloc(sizeof (RSI_BT_API)); 
    memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));

    rsi_irq_start();                                                 /*Enable the Data receive from  (TA)H/W module interrupt */

    while(1) {
        
        if (rsi_bt_AppControlBlock.PacketPending == RSI_TRUE ) {     /* checking the H/W interrupt */
            RetVal = rsi_frame_read(rsi_bt_AppControlBlock.ReadPacketBuffer);
            rsi_bt_AppControlBlock.ResponseFrame = rsi_bt_parse_response(rsi_bt_AppControlBlock.ReadPacketBuffer);
					
			   module_type = (rsi_bt_AppControlBlock.ReadPacketBuffer[1] & 0xF0) >> 4;
            if (RetVal == 0) {                                       /* receive data sucess */

#ifdef RSI_LITTLE_ENDIAN                                             /* Retrieve response code from the received packet */
                ResponseType            = *(uint16 *)(rsi_bt_AppControlBlock.ResponseFrame->ResponseCode);    
                rsi_bt_AppControlBlock.ErrorCode = *(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status;
#else
                ResponseType           = rsi_bytes2R_to_uint16(rsi_bt_AppControlBlock.ResponseFrame->ResponseCode);
                rsi_bt_AppControlBlock.ErrorCode = rsi_bytes2R_to_uint16(&rsi_bt_AppControlBlock.ResponseFrame->Status);
#endif

                switch (ResponseType) {                              /* checking received packet */
                    case RSI_WIFI_RSP_CARD_READY:
                         if (!rsi_bt_AppControlBlock.ErrorCode) {
                             WyzBee_SelectMode ((5 << 16) | 0);      //rsi_oper_mode1(); //for BR/EDR mode
                         } else {
                             return ((uint16)-1);
                         }
                         break;
                         
                    case RSI_RSP_OPERMODE:                           /*If opermode command response */
                         break;

                    case RSI_BT_RSP_CARD_READY:                      /* BT card ready */
                         if (!rsi_bt_AppControlBlock.ErrorCode) {
                             return ERR_NONE;
                             //rsi_bt_init_struct (RSI_BT_RSP_QUERY_LOCAL_NAME);
                         } else {
                             return ((uint16)-1);
                         }
                         //break;
                         
                }   //switch
            } //
            
            rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
				rsi_irq_enable();	
            
        }  //interrupt check
    }   //while
 }

 
/*===================================================*/
/*
 * @fn			  	 : WyzBee_SetLocalName()
 * @brief		    : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]	    : none
 * @return		    : 0- on success , error code - on failure
 * @description    : This initializes the WiFi module by executing commands in a sequence of order.
 *                   This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_SetLocalName (uint8 *p_name)
{
   uint16                      status;
   RSI_BT_CMD_SET_LOCAL_NAME   set_local_name;
   
   if (p_name == NULL) {
       return ((uint16)-1);
   }
   memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
   set_local_name.SetLocalNameFrameSnd.NameLength = MIN (strlen((int8 *)p_name), sizeof (set_local_name.SetLocalNameFrameSnd.Name));
   memcpy (set_local_name.SetLocalNameFrameSnd.Name, p_name, set_local_name.SetLocalNameFrameSnd.NameLength);
   
   //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
	//rsi_irq_enable();
   status = rsi_bt_set_local_name(&set_local_name);
   status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
   if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                         0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_SET_LOCAL_NAME)) {

			 status =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
   }
   
   return status;
}

/*===================================================*/
/*
 * @fn			  	 : WyzBee_GetLocalName()
 * @brief		    : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]	    : none
 * @return		    : 0- on success , error code - on failure
 * @description    : This initializes the WiFi module by executing commands in a sequence of order.
 *                   This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_GetLocalName (uint8 *p_name)
{
   uint16                         status;
   RSI_BT_RESP_QUERY_LOCAL_NAME  *p_local_name;
   
   memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
   //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
	//rsi_irq_enable();
   status = rsi_bt_query_local_name();
   status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
   if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status        ==                           0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_QUERY_LOCAL_NAME)) {
   
			 status =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode);
       p_local_name = &rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryLocalName;
       memcpy (p_name, p_local_name->Name, p_local_name->NameLength);
       p_name[p_local_name->NameLength] = 0;
   }
   
   return status;
}

/*===================================================*/
/*
 * @fn			  	 : uint16 WyzBee_SetLocalCOD (uint32  local_cod)
 * @brief		    : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]	    : none
 * @return		    : 0- on success , error code - on failure
 * @description    : This initializes the WiFi module by executing commands in a sequence of order.
 *                   This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_SetLocalCOD (uint32  local_cod)
{
   uint16                    status;
   RSI_BT_CMD_SET_LOCAL_COD  set_local_cod;
   
   if (local_cod == 0) {
       return ((uint16)-1);
   }
   memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
   set_local_cod.SetLocalCodFrameSnd.LocalCOD = local_cod;
   //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
	//rsi_irq_enable();
   status = rsi_bt_set_local_cod(&set_local_cod);
   status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
   if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                        0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_SET_LOCAL_COD)) {

       status =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
   }
   
   return status;
}


/*===================================================*/
/*
 * @fn			  	 : uint16 WyzBee_GetLocalCOD (uint32  *p_local_cod)
 * @brief		    : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]	    : none
 * @return		    : 0- on success , error code - on failure
 * @description    : This initializes the WiFi module by executing commands in a sequence of order.
 *                   This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_GetLocalCOD (uint32  *p_local_cod)
{
   uint16  status;
      
   if (p_local_cod == 0) {
       return ((uint16)-1);
   }
   memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
   //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
	//rsi_irq_enable();
   status = rsi_bt_query_local_cod();
   status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
   if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                        0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_QUERY_LOCAL_COD)) {

       status      =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
      *p_local_cod = rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryLocalCOD.LocalCOD;
   }
   
   return status;
}

/*===================================================*/
/*
 * @fn			  	 : uint16 WyzBee_GetRSSI (uint8  *p_remote_bdaddr, uint8  *p_rssi)
 * @brief		    : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]	    : none
 * @return		    : 0- on success , error code - on failure
 * @description    : This initializes the WiFi module by executing commands in a sequence of order.
 *                   This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_GetRSSI (uint8  *p_remote_addr, uint8  *p_rssi)
{
   uint16                        status;
   RSI_BT_CMD_QUERY_RSSI         query_rssi;
      
   if ((p_remote_addr == NULL) ||
       (p_rssi        == NULL)) {
          
       return ((uint16)-1);
   }
   memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
   //rsi_ascii_mac_address_to_6bytes (query_rssi.QueryRssiFrameSnd.BDAddress, (int8 *)p_remote_bdaddr);
   BT_StrToBDAddr (p_remote_addr, query_rssi.QueryRssiFrameSnd.BDAddress);
   //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
	//rsi_irq_enable();
   status = rsi_bt_query_rssi(&query_rssi);
   status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
   
	 if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                     0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_QUERY_RSSI)) {
				 
       status      =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
      *p_rssi = rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryRssi.RSSI;
   }
   
   return status;
}

/*===================================================*/
/*
 * @fn			  	 : uint16 WyzBee_GetLinkQuality (uint8  *p_remote_bdaddr, uint8  *p_link_qa)
 * @brief		    : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]	    : none
 * @return		    : 0- on success , error code - on failure
 * @description    : This initializes the WiFi module by executing commands in a sequence of order.
 *                   This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_GetLinkQuality (uint8  *p_remote_bdaddr, uint8  *p_link_qa)
{
   uint16                          status;
   RSI_BT_CMD_QUERY_LINK_QUALITY   query_link_quality;
      
   if ((p_remote_bdaddr == NULL) ||
       (p_link_qa       == NULL)) {
          
       return ((uint16)-1);
   }
   
   memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
   //rsi_ascii_mac_address_to_6bytes (query_link_quality.QueryLinkQualityFrameSnd.BDAddress, (int8 *)p_remote_bdaddr);
   BT_StrToBDAddr (p_remote_bdaddr, query_link_quality.QueryLinkQualityFrameSnd.BDAddress);
   
   //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
	//rsi_irq_enable();
   status = rsi_bt_query_link_quality(&query_link_quality);
   status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
   if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                             0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_QUERY_LINK_QUALITY)) {
				 
       status      =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
      *p_link_qa = rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryLinkQuality.LinkQuality;
   }
   
   return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_GetLocalBDAddress (uint8  *p_remote_bdaddr)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_GetLocalBDAddress (uint8  *p_remote_bdaddr)
{
   uint16                          status;
   
   
   if (p_remote_bdaddr == NULL) {
       return ((uint16)-1);
   }
   
   memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
   //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
	//rsi_irq_enable();
   status = rsi_bt_query_local_bd_address();
   status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
   if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                                 0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_QUERY_LOCAL_BD_ADDRESS)) {
				 
       status      =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
      //rsi_ascii_mac_address_to_6bytes_rev (rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryLocalBDAddr.BDAddress, (int8 *)p_remote_bdaddr);
       BT_BDAddrToStr (rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryLocalBDAddr.BDAddress, p_remote_bdaddr);
   }
   
   return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SppProfileInit (void)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_InitSppProfile (void)
{
    uint16                          status;
    RSI_BT_CMD_SET_PROFILE_MODE     profile_mode;
      
   
    memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
	 profile_mode.SetprofileModeFrameSnd.ProfileMode = RSI_BT_SET_PROFILE_MODE;	
    //rsi_bt_AppControlBlock.PacketPending            = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_set_profile_mode (&profile_mode);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                           0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_SET_PROFILE_MODE)) {
				 
        status      =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SetDiscoverMode (void)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_SetDiscoverMode (uint8 mode, uint32  timeout)
{
    uint16                       status;
    RSI_BT_CMD_SET_DISCV_MODE    set_discover;
      
	
    if (mode > 2) {
        return ((uint16 )-1);
    }
   
    memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
	 set_discover.SetDiscvModeFrameSnd.Mode    = mode;
	 set_discover.SetDiscvModeFrameSnd.Timeout = timeout;
	
    //rsi_bt_AppControlBlock.PacketPending      = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_set_discovery_mode (&set_discover);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                         0) &&
	     (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_SET_DISCV_MODE)) {
				 
       status      =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
     return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_GetDiscoverMode (uint8  *p_mode)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_GetDiscoverMode (uint8  *p_mode)
{
    uint16                       status;
      
	
	  if (p_mode == NULL) {
         return ((uint16 )-1);
     }
     memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API)); 
    //rsi_bt_AppControlBlock.PacketPending      = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_query_discovery_mode ();
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                               0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_QUERY_DISCOVERY_MODE)) {
				 
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
			  *p_mode  =  rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryDiscvMode.DiscoveryMode;
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SetConnMode (uint8 mode)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_SetConnMode (uint8 mode)
{
    uint16                     status;
    RSI_BT_CMD_SET_CONN_MODE   set_conn;
      
	
	  if (mode > 1) {
					
				return ((uint16 )-1);
		}
   
    memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
    set_conn.SetConnModeFrameSnd.ConnMode = mode;
	
    //rsi_bt_AppControlBlock.PacketPending      = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_set_connectability_mode (&set_conn);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                                  0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_SET_CONNECTABILITY_MODE)) {
				 
        status      =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_GetConnMode (uint8  *p_mode)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_GetConnMode (uint8  *p_mode)
{
    uint16  status;
      
	
	  if (p_mode == NULL) {
					
				return ((uint16 )-1);
		}

    //rsi_bt_AppControlBlock.PacketPending      = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_query_connectability_mode ();
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                                    0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_QUERY_CONNECTABILITY_MODE)) {
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
			  *p_mode  =  rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryDiscvMode.DiscoveryMode;
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SetPairMode (uint8 mode)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_SetPairMode (uint8 mode)
{
    uint16                     status;
    RSI_BT_CMD_SET_PAIR_MODE   set_pair;
      
	
	  if (mode > 1) {
					
				return ((uint16 )-1);
		}
   
	  set_pair.SetPairModeFrameSnd.PairMode = mode;
	
    //rsi_bt_AppControlBlock.PacketPending      = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_set_pair_mode (&set_pair);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                        0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_SET_PAIR_MODE)) {
        status      =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_GetPairMode (uint8  *p_mode)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_GetPairMode (uint8  *p_mode)
{
    uint16  status;
      
	
	  if (p_mode == NULL) {
					
				return ((uint16 )-1);
		}

    //rsi_bt_AppControlBlock.PacketPending      = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_query_pair_mode ();
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                          0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_QUERY_PAIR_MODE)) {
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
			  *p_mode  =  rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryPairMode.PairMode;
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_RemoteNameReq (uint8  *p_remote_bd_addr)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_RemoteNameReq (uint8  *p_remote_bd_addr)   //ascii bd address as input
{
    uint16  status;
	  RSI_BT_CMD_REMOTE_NAME_REQUEST   remote_name_req;
      
	
	  if (p_remote_bd_addr == NULL) {
					
				return ((uint16 )-1);
		}
      memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
		//rsi_ascii_mac_address_to_6bytes (remote_name_req.RemNameReqFrameSnd.BDAddress, (int8 *)p_remote_bd_addr);
      BT_StrToBDAddr (p_remote_bd_addr, remote_name_req.RemNameReqFrameSnd.BDAddress);
    //rsi_bt_AppControlBlock.PacketPending      = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_remote_name_request(&remote_name_req);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                          0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_REMOTE_NAME_REQUEST)) {
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_RemoteNameReqCancel (uint8  *p_remote_bd_addr)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_RemoteNameReqCancel (uint8  *p_remote_bd_addr)   //ascii bd address as input
{
    uint16  status;
	  RSI_BT_CMD_REMOTE_NAME_REQUEST_CANCEL   remote_name_req_cancel;
      
	
	  if (p_remote_bd_addr == NULL) {
					
				return ((uint16 )-1);
		}
      
      memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
		BT_StrToBDAddr (p_remote_bd_addr, remote_name_req_cancel.RemNameReqCancelFrameSnd.BDAddress);
		//rsi_ascii_mac_address_to_6bytes (remote_name_req_cancel.RemNameReqCancelFrameSnd.BDAddress, (int8 *)p_remote_bd_addr);
    //rsi_bt_AppControlBlock.PacketPending      = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_remote_name_request_cancel(&remote_name_req_cancel);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                                     0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_REMOTE_NAME_REQUEST_CANCEL)) {
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_Inquiry (uint8  inquiry_type, uint32  time_out)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_Inquiry (uint8  inquiry_type, uint32  time_out)
{
    uint16  status;
    RSI_BT_CMD_INQUIRY   start_inquiry;
      
	
    if (inquiry_type > 2) {
					
			return ((uint16 )-1);
	 }

    memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
    start_inquiry.InqFrameSnd.InquiryType          = inquiry_type;
		start_inquiry.InqFrameSnd.Duration             = time_out;
		start_inquiry.InqFrameSnd.MaximumDevicesToFind = 5;
		
    //rsi_bt_AppControlBlock.PacketPending           = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_inquiry(&start_inquiry);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status        ==                  0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_INQUIRY)) {
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }

   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_InquiryCancel (void)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_InquiryCancel (void)
{
    uint16  status;

    memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
	 //rsi_bt_AppControlBlock.PacketPending           = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_inquiry_cancel();
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                         0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_INQUIRY_CANCEL)) {
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_Bond (uint8  *p_remote_addr)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_Bond (uint8  *p_remote_addr)  //ascii BD Address 
{
    uint16            status;
	  RSI_BT_CMD_BOND   bond_req;

	
     memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
     BT_StrToBDAddr (p_remote_addr, (uint8 *)bond_req.BondFrameSnd.BDAddress);
	  //rsi_ascii_mac_address_to_6bytes ((uint8 *)bond_req.BondFrameSnd.BDAddress, (int8 *)p_remote_addr);

	  //rsi_bt_AppControlBlock.PacketPending           = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_bond(&bond_req);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==               0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_BOND)) {
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_BondCancel (uint8  *p_remote_addr)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_BondCancel (uint8  *p_remote_addr)  //ascii BD Address 
{
    uint16                   status;
	  RSI_BT_CMD_BOND_CANCEL   bond_req_cancel;

	
     memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
     BT_StrToBDAddr (p_remote_addr, bond_req_cancel.BondCancelFrameSnd.BDAddress);
	  //rsi_ascii_mac_address_to_6bytes ((uint8 *)bond_req_cancel.BondCancelFrameSnd.BDAddress, (int8 *)p_remote_addr);

	  //rsi_bt_AppControlBlock.PacketPending           = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_bond_cancel(&bond_req_cancel);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                      0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_BOND_CANCEL)) {
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_UnBond (uint8  *p_remote_addr)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_UnBond (uint8  *p_remote_addr)  //ascii BD Address 
{
    uint16              status;
	  RSI_BT_CMD_UNBOND   unbond;

	
     
	  //rsi_ascii_mac_address_to_6bytes ((uint8 *)unbond.UnbondFrameSnd.BDAddress, (int8 *)p_remote_addr);
     memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
     BT_StrToBDAddr (p_remote_addr, (uint8 *)unbond.UnbondFrameSnd.BDAddress);

	 //rsi_bt_AppControlBlock.PacketPending           = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_unbond(&unbond);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                 0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_UNBOND)) {
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SetPinType (uint8  pin_type)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_SetPinType (uint8  pin_type)
{
    uint16                    status;
	 RSI_BT_CMD_SET_PIN_TYPE   set_pin_type;

	
	 if (pin_type > 1) {
	     return  ((uint16 )-1);
	 }
	
    memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
    
	 set_pin_type.SetPinTypeFrameSnd.PINType = pin_type;

	 //rsi_bt_AppControlBlock.PacketPending           = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_set_pin_type(&set_pin_type);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                       0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_SET_PIN_TYPE)) {
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_GetPinType (uint8  *p_pin_type)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_GetPinType (uint8  *p_pin_type)
{
    uint16                    status;;
	 
	
	  if (p_pin_type == NULL) {
		   return  ((uint16 )-1);
	  }
     memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
	
	 //rsi_bt_AppControlBlock.PacketPending           = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_query_pin_type();
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                         0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_QUERY_PIN_TYPE)) {
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
				*p_pin_type = rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryPinType.PinType;
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_PinCodeReply (uint8  *p_remote_bdaddr, uint8  replytype, uint32  pincode)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_PinCodeReply (uint8  *p_remote_bdaddr, uint8  replytype, uint32  pincode)
{
    uint16                    status;
	  RSI_BT_CMD_PINCODE_REPLY  pincode_repply;
	 
	
	  if (p_remote_bdaddr == NULL) {
			  return  ((uint16 )-1);
		}
		memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
		BT_StrToBDAddr (p_remote_bdaddr, pincode_repply.PincodeReplyFrameSnd.BDAddress);
		if (replytype == 0) {
			  pincode_repply.PincodeReplyFrameSnd.ReplyType = 0;
			  pincode_repply.PincodeReplyFrameSnd.Pincode   = 0;
		} else {
			  pincode_repply.PincodeReplyFrameSnd.ReplyType = 1;
			  pincode_repply.PincodeReplyFrameSnd.Pincode   = pincode;
		}
	
	 //rsi_bt_AppControlBlock.PacketPending           = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_pincode_reply(&pincode_repply);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                         0) &&
		   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_PINCODE_REPLY)) {
        status   =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_GetDeviceRole (uint8  *p_remote_addr, uint8  *p_role)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_GetDeviceRole (uint8  *p_remote_addr, uint8  *p_role)
{
    uint16                 status;
    RSI_BT_CMD_QUERY_ROLE  dev_role;
	 
	
	 if (p_remote_addr == NULL) {
		  return  ((uint16 )-1);
	 }
		
    memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
    BT_StrToBDAddr (p_remote_addr, dev_role.QueryRoleFrameSnd.BDAddress);
	 //rsi_ascii_mac_address_to_6bytes (dev_role.QueryRoleFrameSnd.BDAddress, (int8  *)p_remote_addr);
    
	 //rsi_bt_AppControlBlock.PacketPending           = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_query_role(&dev_role);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status      ==                     0) &&
		    (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_QUERY_ROLE)) {
       
				status  =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
		    *p_role = rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryRole.Role;
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SetDeviceRole (uint8  *p_remote_addr, uint8  role)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_SetDeviceRole (uint8  *p_remote_addr, uint8  role)
{
    uint16               status;
	  RSI_BT_CMD_SET_ROLE  set_dev_role;
	 
	
	  if (p_remote_addr == NULL) {
			  return ((uint16 )-1);
	  }
	  memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
     BT_StrToBDAddr (set_dev_role.SetRoleFrameSnd.BDAddress, p_remote_addr);
		//rsi_ascii_mac_address_to_6bytes (set_dev_role.SetRoleFrameSnd.BDAddress, (int8  *)p_remote_addr);
	
	 //rsi_bt_AppControlBlock.PacketPending           = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_set_role(&set_dev_role);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                   0) &&
		    (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_SET_ROLE)) {
       
				status  =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_GetRemoteDeviceServices (uint8  *p_remote_addr, uint8  role)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_GetRemoteDeviceServices (uint8  *p_remote_addr, uint32  *p_services, uint8 nbr_services, uint8  *p_nbr_found_sevices)
{
	  uint8                     ix;
    uint16                     status;
	  RSI_BT_CMD_QUERY_SERVICES  get_serv;
	 
	
	  if ((p_remote_addr       == NULL) ||
			  (p_services          == NULL) ||
		    (p_nbr_found_sevices == NULL)){
					
			  return ((uint16 )-1);
		}
          
      memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
     BT_StrToBDAddr (p_remote_addr, get_serv.QueryServFrameSnd.BDAddress);
		
		//rsi_ascii_mac_address_to_6bytes (get_serv.QueryServFrameSnd.BDAddress, (int8  *)p_remote_addr);
	
	 //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_query_services(&get_serv);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                         0) &&
		    (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_QUERY_SERVICES)) {
       
				status               =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
				*p_nbr_found_sevices = MIN (rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryServ.NbrServices, nbr_services);
				for (ix = 0; ix < *p_nbr_found_sevices; ix++) {
					   p_services[ix] = rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uQryServ.uuid[ix];
				}
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SearchForServicce (uint8  *p_remote_addr, uint32  service_uuid)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_SearchForServicce (uint8  *p_remote_addr, uint32  service_uuid)
{
    uint16                     status;
	 RSI_BT_CMD_SEARCH_SERVICE  search_serv;
	 
	
	 if ((p_remote_addr       == NULL) ||
	     (service_uuid        ==    0)){

        return ((uint16 )-1);
    }
	 memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
    BT_StrToBDAddr (p_remote_addr, search_serv.SearchServFrameSnd.BDAddress);
	 //rsi_ascii_mac_address_to_6bytes (search_serv.SearchServFrameSnd.BDAddress, (int8  *)p_remote_addr);
	
	 //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_search_service(&search_serv);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                         0) &&
		    (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_SEARCH_SERVICE)) {
       
				status =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SPPConnet (uint8  *p_remote_addr)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_SPPConnet (uint8  *p_remote_addr)
{
   uint16                   status;
   RSI_BT_CMD_SPP_CONNECT   spp_conn;
	 
	
   if (p_remote_addr       == NULL){
       return ((uint16 )-1);
   }
		
    //rsi_ascii_mac_address_to_6bytes (spp_conn.SppConnFrameSnd.BDAddress, (int8  *)p_remote_addr);
    memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
    BT_StrToBDAddr (p_remote_addr, spp_conn.SppConnFrameSnd.BDAddress);

    //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_spp_connect(&spp_conn);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                      0) &&
        (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_SPP_CONNECT)) {
           
			status =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SPPDisconnet (uint8  *p_remote_addr)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_SPPDisconnet (uint8  *p_remote_addr)
{
    uint16                      status;
	 RSI_BT_CMD_SPP_DISCONNECT   spp_disconn;
	 
	
	 if (p_remote_addr       == NULL){
		  return ((uint16 )-1);
    }
	 memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
    BT_StrToBDAddr (p_remote_addr, spp_disconn.SppDisconnFrameSnd.BDAddress);
	 //rsi_ascii_mac_address_to_6bytes (spp_disconn.SppDisconnFrameSnd.BDAddress, (int8  *)p_remote_addr);
	
	 //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_spp_disconnect(&spp_disconn);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                         0) &&
		    (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_SPP_DISCONNECT)) {
       
				status =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SPPTransfer (uint8  *p_remote_addr, uint8  *p_data, uint16  data_len)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_SPPTransfer (uint8  *p_remote_addr, uint8  *p_data, uint16  data_len)
{
    uint16                    status;
    RSI_BT_CMD_SPP_TRANSFER   spp_tx;


    if ((p_remote_addr       == NULL) ||
        (p_data              == NULL) ||
        (data_len             >  198)) {

        return ((uint16 )-1);
    }

    memset (rsi_bt_AppControlBlock.uBTApiInitParams, 0, sizeof (RSI_BT_API));
     
    spp_tx.SppTransferFrameSnd.DataLength = data_len;
    memcpy (spp_tx.SppTransferFrameSnd.Data, p_data, data_len);

    //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_spp_app_transfer(&spp_tx);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                       0) &&
        (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_SPP_TRANSFER)) {

        status =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SPPReceive (uint8  *p_data, uint16  data_size)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_SPPReceive (uint8  *p_data, uint16  data_size)
{
   uint16  status;
   uint16  data_len;


   if ((p_data    == NULL) ||
      (data_size ==    0)) {

       return ((uint16 )-1);
	}

   //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
   //rsi_irq_enable();
    
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((status == 0) &&
       (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status == (uint16)0)) {
			
		    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode) == RSI_BT_EVT_SPP_RECEIVE){
       
						status =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
						data_len = MIN (data_size, rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uSppRxPkt.DataLen);
						memcpy (p_data, rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uSppRxPkt.Data, data_len);
						return data_len;
							
				} else if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_EVT_SPP_DISCONNECTED) ||
                   (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode ==    RSI_BT_EVT_UNBOND_STATUS)) {

						 return 0;
				}
    }
   
    return 0;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SPPDisconnet (uint8  *p_remote_addr)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WyzBee_LinkKeyReply (uint8  *p_remote_addr, uint8  enable, uint8  *p_linkkey)
{
     uint16                    status;
	  RSI_BT_CMD_LINKKEY_REPLY  linkkey_reply;
	 
	
	  if ((p_remote_addr       == NULL) ||
		    (enable               >    1)) {
					
			  return ((uint16 )-1);
		}
		
    //rsi_ascii_mac_address_to_6bytes (linkkey_reply.LinkKeyReplyFrameSnd.BDAddress, (int8 *)p_remote_addr);
		BT_StrToBDAddr (p_remote_addr, linkkey_reply.LinkKeyReplyFrameSnd.BDAddress);
		linkkey_reply.LinkKeyReplyFrameSnd.ReplyType = enable;
		if (enable == FALSE) {
			memset (linkkey_reply.LinkKeyReplyFrameSnd.LinkKey, 0, 16);
		} else {
			memcpy (linkkey_reply.LinkKeyReplyFrameSnd.LinkKey, p_linkkey, 16);
		}
		
		//rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
    //rsi_irq_enable();
    status = rsi_bt_linkkey_reply(&linkkey_reply);
    status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
    if ((*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status       ==                        0) &&
		    (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode == RSI_BT_RSP_LINKKEY_REPLY)) {
       
				status =  *((uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status);
    }
   
    return status;
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_BT_AcceptSppConnect (void)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
/*uint16 WyzBee_BT_AcceptSppConnect (void)
{
    uint16                    status;
    uint16                    event_id;
    uint8                    str_remote_addr[18];
	 

    while (1) {
        //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
        //rsi_irq_enable();

        status   = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
        if (status == 0) {
            status   = *(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status;
            event_id = *(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode;

            switch (event_id) {
                case RSI_BT_EVT_USER_LINKKEY_REQUEST:
                     //rsi_ascii_mac_address_to_6bytes_rev (rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uUserLinkKeyReq.BDAddress, str_remote_addr);
                     BT_BDAddrToStr (rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uUserLinkKeyReq.BDAddress, str_remote_addr);
                     WyzBee_LinkKeyReply (str_remote_addr, FALSE, NULL);
                     break;
					
                case RSI_BT_EVT_USER_LINKKEY_SAVE:
                    break;
                  
                case RSI_BT_EVT_USER_PINCODE_REQUEST:
                        //rsi_ascii_mac_address_to_6bytes_rev (rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uUserLinkKeyReq.BDAddress, str_remote_addr);
                        BT_BDAddrToStr (rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uUserLinkKeyReq.BDAddress, str_remote_addr);
                        WyzBee_PinCodeReply (str_remote_addr, TRUE, 1234);
                        break;
					
               case RSI_BT_EVT_AUTH_COMPLETE:
                    break;
					
					case RSI_BT_EVT_SPP_CONNECTED:
						   return status;
						   //break;
					
					case RSI_BT_RSP_UNBOND:
						   return status;
						   //break;
				}
			}			
	  }
   
    //return 0;
}*/

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_SPPDisconnet (uint8  *p_remote_addr)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint8  AddScanresults (RSI_BT_EVENT_INQUIRY_RESPONSE   *p_inq_list, uint8  nbr_inq_res, RSI_BT_EVENT_INQUIRY_RESPONSE   *p_inq_resp)
{
	     uint8  ix;
   
   
   if ((p_inq_resp->BDAddress[0] == 0) &&
       (p_inq_resp->BDAddress[1] == 0) &&
       (p_inq_resp->BDAddress[2] == 0) && 
       (p_inq_resp->BDAddress[3] == 0) &&
       (p_inq_resp->BDAddress[4] == 0) && 
       (p_inq_resp->BDAddress[5] == 0)) {
          
       return ((uint8)-1);
   }
       
   if (!strlen (p_inq_resp->RemoteDeviceName)) {
       return ((uint8)-1);
   }
   
   for (ix = 0; ix < nbr_inq_res; ix++) {
      if (!memcmp (p_inq_list[ix].BDAddress, p_inq_resp->BDAddress, 6)) {
         return ((uint8)-1);
      }
   }
   
    if (nbr_inq_res < RSI_BT_INQ_MAX_DEVICES) {
       memcpy (&p_inq_list[nbr_inq_res], p_inq_resp, sizeof (RSI_BT_EVENT_INQUIRY_RESPONSE));
       return 0;
    }       
   
   return ((uint8)-1);
}

/*===================================================*/
/*
 * @fn           : uint16 WyzBee_GetInquiryResults (RSI_BT_EVENT_INQUIRY_RESPONSE  *p_scan_res, uint8 size)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */

uint16 WyzBee_GetInquiryResults (RSI_BT_EVENT_INQUIRY_RESPONSE  *p_scan_res, uint8 size)
{
    //uint8     ix;
    uint16     status;
    uint8     loop;
    uint8     nbr_devs;
	
	

    loop = 0;
    nbr_devs = 0;
   
//inquiry:
	status = WyzBee_Inquiry (0, 3000);
	while (!status) {
        //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
        //rsi_irq_enable();
        status = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
        if (status == 0) {
            status = *(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status;

            switch (*(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode) {
                case RSI_BT_EVT_INQUIRY_RESPONSE:
					  status = AddScanresults (p_scan_res, nbr_devs, &rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uInqResp);
                      if (status == 0) {
                         nbr_devs++;
                      }
                      break;

                 case RSI_BT_EVT_INQ_COMPLETE:
                      loop++;
//                      if (loop < 2) {
//                          delay (1000);
//                          goto inquiry;
//                      }
                      return nbr_devs;
                      //break;
            }
        } else {
           return nbr_devs;
        }
    }
   
    return nbr_devs;
 }

/*===================================================*/
/*
 * @fn           : uint16 WaitForSPPConnComplete (void)
 * @brief        : This initializes the BT EDR module.
 * @param 1[in]	 : p_name   
 * @param 2[in]	 : none
 * @param[out]   : none
 * @return       : 0- on success , error code - on failure
 * @description  : This initializes the WiFi module by executing commands in a sequence of order.
 *                 This function should call at very first time before using any BT related APIs.
 */
 
uint16 WaitForSPPConnComplete (void)
{
    uint16                    status;
    uint16                    event_id;
    uint8                    str_remote_addr[18];
	 

    while (1) {
        //rsi_bt_AppControlBlock.PacketPending = RSI_FALSE;
        //rsi_irq_enable();
        status   = RSI_BT_GetRespPayload (rsi_bt_AppControlBlock.ResponseFrame);
        if (status == 0) {
            status   = *(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->Status;
            event_id = *(uint16 *)rsi_bt_AppControlBlock.ResponseFrame->ResponseCode;

            switch (event_id) {
                case RSI_BT_EVT_USER_LINKKEY_REQUEST:
                     //rsi_ascii_mac_address_to_6bytes_rev (rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uUserLinkKeyReq.BDAddress, str_remote_addr);
                     BT_BDAddrToStr (rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uUserLinkKeyReq.BDAddress, str_remote_addr);
                     WyzBee_LinkKeyReply (str_remote_addr, FALSE, NULL);
                     break;
					
			    case RSI_BT_EVT_USER_LINKKEY_SAVE:
				     break;
					
			    case RSI_BT_EVT_USER_PINCODE_REQUEST:
                     //rsi_ascii_mac_address_to_6bytes_rev (rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uUserLinkKeyReq.BDAddress, str_remote_addr);
                     BT_BDAddrToStr (rsi_bt_AppControlBlock.ResponseFrame->uCmdRspPayLoad.uUserLinkKeyReq.BDAddress, str_remote_addr);
                     WyzBee_PinCodeReply (str_remote_addr, TRUE, 1234);
                     break;
					
				case RSI_BT_EVT_AUTH_COMPLETE:
				     break;
					
				case RSI_BT_EVT_SPP_CONNECTED:
                     return status;
                     //break;

                case RSI_BT_RSP_UNBOND:
                     return status;
                     //break;
			}
		}
    }
    //return status;
}


#ifdef __cplusplus
}
#endif

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
