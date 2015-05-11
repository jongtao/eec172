/**
 * @file       rsi_bt_config_init.c
 * @version    1.0
 * @date       2014-Sep-03
 *
 * Copyright(C) Redpine Signals 2014
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief INIT STRUCT: Initializes the global parameter structure to the values in the #define statements in main.h
 *
 * @section Description
 * This file contains function to initialize the main structure which defines
 * system operation
 *
 *
 */


/**
 * Includes
 */
#include "rsi_bt_global.h"
#include "rsi_bt_generic.h"
#include "rsi_bt_api.h"
#include "rsi_bt_config.h"
#include "rsi_app_util.h"
#include "rsi_lib_util.h"
#include "rsi_bt_app.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * Global Variables
 */

extern RSI_BT_APP_CB rsi_bt_AppControlBlock;

static void rsi_bt_fill_bd_address(UINT08  *BDAddressBuf, UINT08  *UsrInitBDAddress);

/*====================================================*/
/**
 * @fn             int16 rsi_init_struct(rsi_api *ptrStrApi)
 * @brief          Initialize the global parameter structure
 * @param[in]      rsi_api *ptrStrApi, pointer to the global parameter structure
 * @param[out]     none
 * @return         status
 *                 0  = SUCCESS
 * @description	
	* This function is used to initialize the global parameter structure with parameters
 * used to configure the Wi-Fi module.
 * 
 * @prerequisite 
	* rsi_sys_init should be done successfully. 		
 */
INT16 rsi_bt_init_struct(UINT16  CommandType)
{
  RSI_BT_API *uApiParams;
   
  
  uApiParams = rsi_bt_AppControlBlock.uBTApiInitParams;
  memset(uApiParams, 0, sizeof(RSI_BT_API));

    switch (CommandType) {
        case RSI_BT_REQ_SET_LOCAL_NAME:
             strcpy(uApiParams->uSetLocalName.SetLocalNameFrameSnd.Name, RSI_BT_SET_LOCAL_NAME);
             uApiParams->uSetLocalName.SetLocalNameFrameSnd.NameLength = strlen(RSI_BT_SET_LOCAL_NAME);
             rsi_bt_set_local_name (&uApiParams->uSetLocalName);
             break;
        
        case RSI_BT_REQ_QUERY_LOCAL_NAME:
             rsi_bt_query_local_name();
             break;

        case RSI_BT_REQ_SET_LOCAL_COD:
             uApiParams->uSetLocalCOD.SetLocalCodFrameSnd.LocalCOD = RSI_BT_SET_LOCAL_COD;
             rsi_bt_set_local_cod (&uApiParams->uSetLocalCOD);
             break;

        case RSI_BT_REQ_QUERY_LOCAL_COD:
             rsi_bt_query_local_cod();
             break;
        
        case RSI_BT_REQ_QUERY_RSSI:
             rsi_bt_fill_bd_address(uApiParams->uQryRssi.QueryRssiFrameSnd.BDAddress, (UINT08 *)RSI_BT_QUERY_RSSI_ADDR); 
             rsi_bt_query_rssi(&uApiParams->uQryRssi);
             break;

        case RSI_BT_REQ_QUERY_LINK_QUALITY:
             rsi_bt_fill_bd_address(uApiParams->uQryLinkQuality.QueryLinkQualityFrameSnd.BDAddress, (UINT08 *)RSI_BT_QUERY_LINK_QUALITY_ADDR);
             rsi_bt_query_link_quality (&uApiParams->uQryLinkQuality);
             break;

        case RSI_BT_REQ_QUERY_LOCAL_BD_ADDRESS:
             rsi_bt_query_local_bd_address();
             break;

        case RSI_BT_REQ_SET_PROFILE_MODE:
             uApiParams->uSetProfMode.SetprofileModeFrameSnd.ProfileMode = RSI_BT_SET_PROFILE_MODE;
             rsi_bt_set_profile_mode (&uApiParams->uSetProfMode);
             break;

        case RSI_BT_REQ_SET_DISCV_MODE:
             uApiParams->uSetDiscvMode.SetDiscvModeFrameSnd.Mode    = RSI_BT_SET_DISC_MODE;
             uApiParams->uSetDiscvMode.SetDiscvModeFrameSnd.Timeout = RSI_BT_SET_DISC_MODE_TIMEOUT;
             rsi_bt_set_discovery_mode (&uApiParams->uSetDiscvMode);
             break;

        case RSI_BT_REQ_QUERY_DISCOVERY_MODE:
             rsi_bt_query_discovery_mode ();
             break;

        case RSI_BT_REQ_SET_CONNECTABILITY_MODE:
             uApiParams->uSetConnMode.SetConnModeFrameSnd.ConnMode = RSI_BT_SET_CONN_MODE;
             rsi_bt_set_connectability_mode (&uApiParams->uSetConnMode);
             break;

        case RSI_BT_REQ_QUERY_CONNECTABILITY_MODE:
             rsi_bt_query_connectability_mode ();
             break;

        case RSI_BT_REQ_SET_PAIR_MODE:
             uApiParams->uSetPairMode.SetPairModeFrameSnd.PairMode = RSI_BT_SET_PAIR_MODE;
             rsi_bt_set_pair_mode (&uApiParams->uSetPairMode);
             break;
        
        case RSI_BT_REQ_QUERY_PAIR_MODE:
             rsi_bt_query_pair_mode ();
             break;
        
        case RSI_BT_REQ_REMOTE_NAME_REQUEST:
             rsi_bt_fill_bd_address(uApiParams->uRemNameReq.RemNameReqFrameSnd.BDAddress, (UINT08 *)RSI_BT_REM_NAME_REQ_ADDR);
             rsi_bt_remote_name_request (&uApiParams->uRemNameReq);
             break;

        case RSI_BT_REQ_REMOTE_NAME_REQUEST_CANCEL:
             rsi_bt_fill_bd_address(uApiParams->uRemNameReqCancel.RemNameReqCancelFrameSnd.BDAddress, (UINT08 *)RSI_BT_REM_NAME_REQ_CANCEL_ADDR);
             rsi_bt_remote_name_request_cancel(&uApiParams->uRemNameReqCancel);
             break;

        case RSI_BT_REQ_INQUIRY:
             uApiParams->uInq.InqFrameSnd.InquiryType = RSI_BT_INQ_TYPE;
             uApiParams->uInq.InqFrameSnd.Duration = (UINT32 )RSI_BT_INQ_DURATION;
             uApiParams->uInq.InqFrameSnd.MaximumDevicesToFind = RSI_BT_INQ_MAX_DEVICES;
             rsi_bt_inquiry(&uApiParams->uInq);
             break;

        case RSI_BT_REQ_INQUIRY_CANCEL:
             rsi_bt_inquiry_cancel();
             break;

        case RSI_BT_REQ_BOND:
             if (RSI_BT_BOND_ADDR != NULL) {
                rsi_bt_fill_bd_address(uApiParams->uBond.BondFrameSnd.BDAddress, (UINT08 *)RSI_BT_BOND_ADDR);
             } else {
                rsi_bt_fill_bd_address(uApiParams->uBond.BondFrameSnd.BDAddress, (UINT08 *)rsi_bt_AppControlBlock.RemoteBDAddress);
             }
             rsi_bt_bond (&uApiParams->uBond);
             break;

        case RSI_BT_REQ_BOND_CANCEL:
             rsi_bt_fill_bd_address(uApiParams->uBondCancel.BondCancelFrameSnd.BDAddress, (UINT08 *)RSI_BT_BOND_CANCEL_ADDR);
             rsi_bt_bond_cancel (&uApiParams->uBondCancel);
             break;
        
        case RSI_BT_REQ_UNBOND:
             rsi_bt_fill_bd_address(uApiParams->uUnbond.UnbondFrameSnd.BDAddress, (UINT08 *)RSI_BT_UNBOND_ADDR);
             rsi_bt_unbond(&uApiParams->uUnbond);
             break;

        case RSI_BT_REQ_SET_PIN_TYPE:
             uApiParams->uSetPinType.SetPinTypeFrameSnd.PINType = RSI_BT_SET_PIN_TYPE;
             rsi_bt_set_pin_type (&uApiParams->uSetPinType);
             break;
        
        case RSI_BT_REQ_QUERY_PIN_TYPE:
             rsi_bt_query_pin_type();
             break;
        
        case RSI_BT_REQ_USER_CONFIRMATION:
             rsi_bt_fill_bd_address(uApiParams->uUserConf.UserConfFrameSnd.BDAddress, (UINT08 *)RSI_BT_USER_CONF_ADDR);
             uApiParams->uUserConf.UserConfFrameSnd.Confirmation = RSI_BT_USER_CONF;
             rsi_bt_user_confirmation (&uApiParams->uUserConf);
             break;

        case RSI_BT_REQ_PASSKEY_REPLY:
             rsi_bt_fill_bd_address(uApiParams->uPasskeyReply.PasskeyReplyFrameSnd.BDAddress, (UINT08 *)RSI_BT_PASSKEY_ADDR);
             uApiParams->uPasskeyReply.PasskeyReplyFrameSnd.ReplyType = RSI_BT_PASSKEY_REPLY_TYPE;
             uApiParams->uPasskeyReply.PasskeyReplyFrameSnd.Passkey = (UINT32)RSI_BT_PASSKEY;
             rsi_bt_passkey_request_reply (&uApiParams->uPasskeyReply);
             break;

        case RSI_BT_REQ_PINCODE_REPLY:
             uApiParams->uPincodeReply.PincodeReplyFrameSnd.ReplyType = RSI_BT_PINCODE_REPLY_TYPE;

             if (RSI_BT_PINCODE_REPLY_ADDR != 0) {
                 rsi_ascii_mac_address_to_6bytes_rev(uApiParams->uPincodeReply.PincodeReplyFrameSnd.BDAddress,(UINT08 *) RSI_BT_PINCODE_REPLY_ADDR);   // Convert from BD address string to BD address.
             } else {
                 memcpy (uApiParams->uPincodeReply.PincodeReplyFrameSnd.BDAddress, rsi_bt_AppControlBlock.RemoteBDAddress, RSI_BT_BD_ADDR_LEN);
             }
             uApiParams->uPincodeReply.PincodeReplyFrameSnd.Pincode = (UINT32 )RSI_BT_PINCODE;
             rsi_bt_pincode_reply (&uApiParams->uPincodeReply);
             break;

        case RSI_BT_REQ_LINKEKY_REPLY:
             uApiParams->uLinkKeyReply.LinkKeyReplyFrameSnd.ReplyType = RSI_BT_LINKKEY_REPLY_TYPE;

             if(RSI_BT_LINKKEY_REPLY_ADDR != 0) {
               rsi_ascii_mac_address_to_6bytes_rev(uApiParams->uLinkKeyReply.LinkKeyReplyFrameSnd.BDAddress,(UINT08 *) RSI_BT_LINKKEY_REPLY_ADDR);   // Convert from BD address string to BD address.
             } else {
               memcpy (uApiParams->uLinkKeyReply.LinkKeyReplyFrameSnd.BDAddress, rsi_bt_AppControlBlock.RemoteBDAddress, RSI_BT_BD_ADDR_LEN);
             }
             memcpy (uApiParams->uLinkKeyReply.LinkKeyReplyFrameSnd.LinkKey, rsi_bt_AppControlBlock.RemoteLinkKey, RSI_BT_LINK_KEY_LEN);
             rsi_bt_linkkey_reply (&uApiParams->uLinkKeyReply);
             break;

        case RSI_BT_REQ_QUERY_ROLE:
             rsi_bt_fill_bd_address(uApiParams->uQryRole.QueryRoleFrameSnd.BDAddress,(UINT08 *) RSI_BT_QUERY_ROLE_ADDR);
             rsi_bt_query_role (&uApiParams->uQryRole);
             break;

        case RSI_BT_REQ_SET_ROLE:
             rsi_bt_fill_bd_address(uApiParams->uSetRole.SetRoleFrameSnd.BDAddress, (UINT08 *)RSI_BT_SET_ROLE_ADDR);
             uApiParams->uSetRole.SetRoleFrameSnd.Role = RSI_BT_SET_ROLE;
             rsi_bt_set_role (&uApiParams->uSetRole);
             break;

        case RSI_BT_REQ_QUERY_SERVICES:
             rsi_bt_fill_bd_address(uApiParams->uQryServ.QueryServFrameSnd.BDAddress, (UINT08 *)RSI_BT_QUERY_SERV_ADDR);
             rsi_bt_query_services (&uApiParams->uQryServ);
             break;

        case RSI_BT_REQ_SEARCH_SERVICE:
             rsi_bt_fill_bd_address(uApiParams->uSearchServ.SearchServFrameSnd.BDAddress, (UINT08 *)RSI_BT_SEARCH_SERV_ADDR);
             uApiParams->uSearchServ.SearchServFrameSnd.ServiceUUID.size = RSI_BT_SEARCH_SERV_SIZE;
             uApiParams->uSearchServ.SearchServFrameSnd.ServiceUUID.Val.val16 = (UINT16 )RSI_BT_SEARCH_SERV_UUID;
             rsi_bt_search_service(&uApiParams->uSearchServ);
             break;

				case RSI_BT_REQ_SPP_CONNECT: 
             if (RSI_BT_SPP_CONN_ADDR != 0) {
                 rsi_ascii_mac_address_to_6bytes_rev(uApiParams->uSPPConn.SppConnFrameSnd.BDAddress,(UINT08 *) RSI_BT_SPP_CONN_ADDR);   // Convert from BD address string to BD address.
					   } else {
						     memcpy (uApiParams->uSPPConn.SppConnFrameSnd.BDAddress, rsi_bt_AppControlBlock.RemoteBDAddress, 6);
					   }
					   rsi_bt_spp_connect (&uApiParams->uSPPConn);
					   break;

        case RSI_BT_REQ_SPP_DISCONNECT:
             if (RSI_BT_SPP_DISCONN_ADDR != 0) {
                 rsi_ascii_mac_address_to_6bytes_rev(uApiParams->uSPPDisConn.SppDisconnFrameSnd.BDAddress, (UINT08 *)RSI_BT_SPP_DISCONN_ADDR);   // Convert from BD address string to BD address.
             } else {
								 uApiParams->uSPPDisConn.SppDisconnFrameSnd.BDAddress[0] = rsi_bt_AppControlBlock.RemoteBDAddress[0];
								 uApiParams->uSPPDisConn.SppDisconnFrameSnd.BDAddress[1] = rsi_bt_AppControlBlock.RemoteBDAddress[1];
								 uApiParams->uSPPDisConn.SppDisconnFrameSnd.BDAddress[2] = rsi_bt_AppControlBlock.RemoteBDAddress[2];
								 uApiParams->uSPPDisConn.SppDisconnFrameSnd.BDAddress[3] = rsi_bt_AppControlBlock.RemoteBDAddress[3];
								 uApiParams->uSPPDisConn.SppDisconnFrameSnd.BDAddress[4] = rsi_bt_AppControlBlock.RemoteBDAddress[4];
								 uApiParams->uSPPDisConn.SppDisconnFrameSnd.BDAddress[5] = rsi_bt_AppControlBlock.RemoteBDAddress[5];
									//memcpy (uApiParams->uSPPConn.SppConnFrameSnd.BDAddress, rsi_bt_AppControlBlock.RemoteBDAddress, 6);
             }
             rsi_bt_spp_disconnect (&uApiParams->uSPPDisConn);
             break;

        case RSI_BT_REQ_SPP_TRANSFER:
             {
                 static UINT08 ch = 'A';
				
#if 0
								rsi_uint16_to_2bytes(uApiParams->uSPPTransfer.SppTransferFrameSnd.DataLength, RSI_BT_SPP_TX_LEN);
								memset(uApiParams->uSPPTransfer.SppTransferFrameSnd.Data, 0, RSI_BT_SPP_TX_LEN);
								memset(rsi_bt_TransferBuffer, 0, RSI_BT_SPP_TX_LEN);
								/*for(ii = 0; ii < 100; ii++)
								{
									rsi_bt_TransferBuffer[ii] = ('a'+ii);
								}*/
								memset (rsi_bt_TransferBuffer, ch, sizeof (rsi_bt_TransferBuffer));
								
								memcpy(uApiParams->uSPPTransfer.SppTransferFrameSnd.Data, RSI_BT_SPP_TX_DATA, RSI_BT_SPP_TX_LEN);
								rsi_bt_spp_transfer (&uApiParams->uSPPTransfer);
#else								
								
								uApiParams->uSPPTransfer.SppTransferFrameSnd.DataLength = strlen ("HI_MALLIKARJUNA_") + 3;
								strcpy ((INT08 *)uApiParams->uSPPTransfer.SppTransferFrameSnd.Data, "HI_MALLIKARJUNA_");
								uApiParams->uSPPTransfer.SppTransferFrameSnd.Data[16] = ch;
								uApiParams->uSPPTransfer.SppTransferFrameSnd.Data[17] = '\r';
								uApiParams->uSPPTransfer.SppTransferFrameSnd.Data[18] = '\n';
								
								rsi_bt_spp_app_transfer (&uApiParams->uSPPTransfer);
#endif
                if (ch >= 'Z') {
										ch = 'A';
								} else {
									ch++;
								}
						 }
						 break;
						 
        case RSI_BT_REQ_INIT:
             rsi_bt_device_init();
             break;
				
        case RSI_BT_REQ_DEINIT:
	           rsi_bt_device_deinit();
     				 break;
    }

    return 0;    
}


static void rsi_bt_fill_bd_address(UINT08  *BDAddressBuf, UINT08  *UsrInitBDAddress)
{
  if(RSI_BT_SPP_DISCONN_ADDR != 0) 
  {
    rsi_ascii_mac_address_to_6bytes_rev(BDAddressBuf, UsrInitBDAddress);   // Convert from BD address string to BD address.    
  } 
  else 
  {
    BDAddressBuf[0] = rsi_bt_AppControlBlock.RemoteBDAddress[0];
    BDAddressBuf[1] = rsi_bt_AppControlBlock.RemoteBDAddress[1];
    BDAddressBuf[2] = rsi_bt_AppControlBlock.RemoteBDAddress[2];
    BDAddressBuf[3] = rsi_bt_AppControlBlock.RemoteBDAddress[3];
    BDAddressBuf[4] = rsi_bt_AppControlBlock.RemoteBDAddress[4];
    BDAddressBuf[5] = rsi_bt_AppControlBlock.RemoteBDAddress[5];
  }
}

