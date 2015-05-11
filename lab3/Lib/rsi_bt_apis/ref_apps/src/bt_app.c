
#include "rsi_bt_generic.h"
//#include "rsi_bt_app.h"
#include "rsi_bt_api.h"
//#include "rsi_bt_config.h"
#include "rsi_app_util.h"
#include "rsi_lib_util.h"
#include "rsi_hal.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

//#pragma pack(1)
#include "rsi_bt_global.h"
char *bt_commands_str[] =
{
  "SET_LOCAL_NAME",
  "GET_LOCAL_NAME",
  "SET_LOCAL_COD",
  "GET_LOCAL_COD",
  "GET_RSSI",     
  "GET_LINK_QUALITY",                         
  "GET_LOCAL_BDADDR",

  "SET_PROFILE_MODE",

  "SET_DISCOVERY_MODE",
  "GET_DISCOVERY_MODE",      
  "SET_CONN_MODE",          
  "GET_CONN_MODE",
  "SET_PAIR_MODE",          
  "GET_PAIR_MODE",
  "REMOTE_NAME_REQ",
  "REMOTE_NAME_REQ_CANCEL",
  "INQUIRY",
  "INQUIRY_CANCEL",
  "BOND",
  "BOND_CANCEL",
  "UNBOND",
  "SET_PIN_TYPE",
  "GET_PIN_TYPE",
  "USER_CONFIRMATION",
  "PASSKEY_REPLY",
  "USER_PINCODE",
  "GET_DEV_ROLE",
  "SET_DEV_ROLE",

  "GET_SERVICES",
  "SEARCH_SERVICES",

  "SPP_CONNECT",
  "SPP_DISCONNECT",
  "SPP_TX",

  "INIT",
  "DEINIT",
  "LINKKEY_REPLY"

};

char *bt_events_str[] = 
{
  "ROLE_CHANGE_STATUS",
  "RSI_BT_EVT_UNBOND_STATUS",
  "RSI_BT_EVT_BOND_RESPONSE",
  "RSI_BT_EVT_INQUIRY_RESPONSE",
  "RSI_BT_EVT_REMOTE_DEVICE_NAME",
  "RSI_BT_EVT_REMOTE_NAME_REQUEST_CANCEL",
  "RSI_BT_EVT_DISCONNECTED",
  "RSI_BT_EVT_USER_CONFIRMATION_REQUEST",
  "RSI_BT_EVT_USER_PASKEY_DISPLAY",
  "RSI_BT_EVT_USER_PINCODE_REQUEST",
  "RSI_BT_EVT_USER_PASSKEY_REQUEST",
  "RSI_BT_EVT_INQUIRY_COMPLETE",
  "RSI_BT_EVT_AUTH_COMPLETE",
  "RSI_BT_EVT_USER_LINKKEY_REQUEST",
  "RSI_BT_EVT_USER_LINKKEY_SAVE",


  "RSI_BT_EVT_SPP_RECEIVE ",
  "RSI_BT_EVT_SPP_CONNECTED",
  "RSI_BT_EVT_SPP_DISCONNECTED"
};

UINT08  rsi_bt_TransferBuffer[RSI_BT_MAX_PAYLOAD_SIZE];


INT16 bt_print_options(void)
{
    UINT16 ii = 0;
    UINT16 max_cmds = RSI_BT_RSP_SPP_TRANSFER  - RSI_BT_RSP_SET_LOCAL_NAME + 4;
    int in_cmd;

    for  (ii = 0; ii < max_cmds; ii++)
    {
        if((strcmp (bt_commands_str[ii], "GET_LINK_QUALITY")) && \
            (strcmp (bt_commands_str[ii], "SET_PAIR_MODE")) && \
            (strcmp (bt_commands_str[ii], "GET_PAIR_MODE")) && \
            (strcmp (bt_commands_str[ii], "USER_CONFIRMATION")) && \
            (strcmp (bt_commands_str[ii], "PASSKEY_REPLY")) && \
            (strcmp (bt_commands_str[ii], "SET_DEV_ROLE")) )

        printf(" %d. %s\n",ii+1, bt_commands_str[ii]);
    }
    printf("\n");
    printf("Read the packet from recv queue... \n=========================\n");
    printf(" %d. READ RESPONSE....\n", (ii+1));
    printf("Enter your choice:\n");
    scanf("%d",&in_cmd);
    if (in_cmd > max_cmds)
    {
        in_cmd = -1;
    }

    return (INT16)in_cmd;
}

INT16 rsi_bt_app(void)
{
				INT16 cmd;
				INT16 RetVal = 0;

				cmd = bt_print_options();

				if ((cmd > 0) && (cmd < 34))
				{
								printf("Executing the command %s\n",bt_commands_str[cmd -1]);
								RetVal = rsi_bt_init_struct(cmd);
				}
				else if (cmd == 34)
				{
								printf("Executing the command %s\n",bt_commands_str[33]);
								RetVal = rsi_bt_init_struct(RSI_BT_REQ_INIT);
				}
				else if (cmd == 35)
				{
								printf("Executing the command %s\n",bt_commands_str[34]);
								RetVal = rsi_bt_init_struct(RSI_BT_REQ_DEINIT);
				}
				else if (cmd == 36)
				{
								printf("Executing the command %s\n",bt_commands_str[35]);
								RetVal = rsi_bt_init_struct(RSI_BT_REQ_LINKEKY_REPLY);
				}
				else
								printf("Waiting for events ...\n");
 
        return RetVal;
}


#if 0
void rsi_bt_decode_rsp(UINT16 rsp_type, UINT16 status, void *rsp)
{

  printf("Received response type: 0x%04X, status:%02x\n", rsp_type, status);
  /*if ( (rsp_type >= RSI_BT_RSP_SET_LOCAL_NAME) && (rsp_type <= RSI_BT_RSP_SPP_TRANSFER))
  {
    printf("Received response type: %s, status:%02x\n", bt_commands_str[rsp_type - 1], status);
  }
  else if ( (rsp_type >= RSI_BT_EVT_ROLE_CHANGE_STATUS) && (rsp_type <= RSI_BT_EVT_SPP_DISCONNECTED) )
  {
    printf("Received event type: %s, status:%02x\n", bt_events_str[rsp_type - RSI_BT_EVT_ROLE_CHANGE_STATUS], status);
  }*/

  switch (rsp_type)
  {
    case RSI_BT_RSP_CARD_READY:
      printf("RSI_BT_RSP_CARD_READY");
      break;

    case RSI_BT_RSP_SET_LOCAL_NAME:
      printf("RSI_BT_RSP_SET_LOCAL_NAME");
      break;

    case RSI_BT_RSP_QUERY_LOCAL_NAME:
      printf("RSI_BT_RSP_QUERY_LOCAL_NAME: %s", ((UINT08 *)rsp + 1));

      break;

    case RSI_BT_RSP_SET_LOCAL_COD:
      printf("RSI_BT_RSP_SET_LOCAL_COD:");
      break;

    case RSI_BT_RSP_QUERY_LOCAL_COD:
      printf("RSI_BT_RSP_SET_LOCAL_COD: 0x%x", *((UINT32 *) rsp));
      break;

    case RSI_BT_RSP_QUERY_RSSI:
      printf("RSI_BT_RSP_QUERY_RSSI: 0x%02x", *((UINT08 *) rsp));
      break;

    case RSI_BT_RSP_QUERY_LINK_QUALITY:
      printf("RSI_BT_RSP_QUERY_LINK_QUALITY: %d", *((UINT08 *) rsp));
      break;

    case RSI_BT_RSP_QUERY_LOCAL_BD_ADDRESS:
      printf("RSI_BT_RSP_QUERY_LOCAL_BD_ADDRESS: ");
      {  
        INT08  ix;

        for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)rsp)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n");
      }
      break;

    case RSI_BT_RSP_SET_PROFILE_MODE:
      printf("RSI_BT_RSP_SET_PROFILE_MODE: ");
      break;

    case RSI_BT_RSP_SET_DISCV_MODE:
      printf("RSI_BT_RSP_SET_DISCV_MODE: ");
      break;

    case RSI_BT_RSP_QUERY_DISCOVERY_MODE:
      printf("RSI_BT_RSP_QUERY_DISCOVERY_MODE: %d\r\n", ((UINT08 *)rsp)[0]);
      break;

    case RSI_BT_RSP_SET_CONNECTABILITY_MODE:
      printf("RSI_BT_RSP_SET_CONNECTABILITY_MODE: ");
      break;

    case RSI_BT_RSP_QUERY_CONNECTABILITY_MODE:
      printf("RSI_BT_RSP_QUERY_CONNECTABILITY_MODE: %d\r\n", ((UINT08 *)rsp)[0]);
      break;

    case RSI_BT_RSP_SET_PAIR_MODE:
      printf("RSI_BT_RSP_QUERY_CONNECTABILITY_MODE: ");
      break;

    case RSI_BT_RSP_QUERY_PAIR_MODE:
      printf("RSI_BT_RSP_QUERY_PAIR_MODE: %d\r\n", ((UINT08 *)rsp)[0]);
      break;

    case RSI_BT_RSP_REMOTE_NAME_REQUEST:
      printf("RSI_BT_RSP_REMOTE_NAME_REQUEST:\r\n");
      break;

    case RSI_BT_RSP_REMOTE_NAME_REQUEST_CANCEL:
      printf("RSI_BT_RSP_REMOTE_NAME_REQUEST_CANCEL: \r\n");
      break;

    case RSI_BT_RSP_INQUIRY:
      printf("RSI_BT_RSP_INQUIRY: \r\n");
      break;

    case RSI_BT_RSP_INQUIRY_CANCEL:
      printf("RSI_BT_RSP_INQUIRY_CANCEL: \r\n");
      break;

    case RSI_BT_RSP_BOND:
      printf("RSI_BT_RSP_BOND: \r\n");
      break;

    case RSI_BT_RSP_BOND_CANCEL:
      printf("RSI_BT_RSP_BOND_CANCEL: \r\n");
      break;

    case RSI_BT_RSP_UNBOND:
      printf("RSI_BT_RSP_UNBOND: \r\n");
      {
        INT08  ix;

        for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)rsp)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n");
      }
      break;

    case RSI_BT_RSP_SET_PIN_TYPE:
      printf("RSI_BT_RSP_SET_PIN_TYPE: \r\n");
      break;

    case RSI_BT_RSP_QUERY_PIN_TYPE:
      printf("RSI_BT_RSP_QUERY_PIN_TYPE: %d\r\n", ((UINT08 *)rsp)[0]);
      break;

    case RSI_BT_RSP_USER_CONFIRMATION:
      printf("RSI_BT_RSP_USER_CONFIRMATION: \r\n");
      break;

    case RSI_BT_RSP_PASSKEY_REPLY:
      printf("RSI_BT_RSP_PASSKEY_REPLY: \r\n");
      break;

    case RSI_BT_RSP_PINCODE_REPLY:
      printf("RSI_BT_RSP_PINCODE_REPLY: \r\n");
      break;

    case RSI_BT_RSP_QUERY_ROLE:
      printf("RSI_BT_RSP_QUERY_ROLE:%d \r\n",((UINT08 *)rsp)[0]);
      break;

    case RSI_BT_RSP_SET_ROLE:
      printf("RSI_BT_RSP_SET_ROLE: \r\n");
      break;

    case RSI_BT_RSP_QUERY_SERVICES:
      printf("RSI_BT_RSP_QUERY_SERVICES: \r\n");
      {
        UINT08                       ix;
        RSI_BT_RESP_QUERY_SERVICES  *p_ser;

        p_ser = (RSI_BT_RESP_QUERY_SERVICES *)rsp;
        printf ("NbrServices: %d, uuids: ",p_ser->NbrServices);
        for (ix = 0; ix < p_ser->NbrServices; ix++) {
          printf ("0x%04x, ", p_ser->uuid[ix]);
        }
      }
      break;

    case RSI_BT_RSP_SEARCH_SERVICE:
      printf("RSI_BT_RSP_SEARCH_SERVICE: \r\n");
      break;

    case RSI_BT_RSP_SPP_CONNECT:
      printf("RSI_BT_RSP_SPP_CONNECT: \r\n");
      {
        INT08  ix;

       for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)rsp)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n");
      }
      break;

    case RSI_BT_RSP_SPP_DISCONNECT:
      printf("RSI_BT_RSP_SPP_DISCONNECT: \r\n");
      {
        INT08  ix;
        for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)rsp)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n");
      }
      break;

    case RSI_BT_RSP_SPP_TRANSFER:
      printf("RSI_BT_RSP_SPP_TRANSFER \r\n");
      break;

      /* events list */
    case RSI_BT_EVT_ROLE_CHANGE_STATUS:
      printf("RSI_BT_EVT_ROLE_CHANGE_STATUS: \r\n");
      {
        INT08  ix;
        for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)rsp)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n");   
      }
      break;

    case RSI_BT_EVT_UNBOND_STATUS:
      printf("RSI_BT_EVT_UNBOND_STATUS: \r\n");
      {
        INT08  ix;
        for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)rsp)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n");
      }
      break;

    case RSI_BT_EVT_BOND_RESPONSE:
      printf("RSI_BT_EVT_BOND_RESPONSE: \r\n");
      {
        INT08  ix;
        for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)rsp)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n");
      }
      break;

    case RSI_BT_EVT_INQUIRY_RESPONSE:
      printf("RSI_BT_EVT_INQUIRY_RESPONSE: \r\n");
      {
        RSI_BT_EVENT_INQUIRY_RESPONSE *p_inq_resp;
        INT08  ix;

        p_inq_resp = (RSI_BT_EVENT_INQUIRY_RESPONSE *)rsp;
       
       for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)p_inq_resp->BDAddress)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n"); 
        printf ("\r\nName: %s", p_inq_resp->RemoteDeviceName);
      }
      break;

//    case RSI_BT_EVT_INQUIRY_COMPLETE:
//      printf("RSI_BT_EVT_INQUIRY_COMPLETE: \r\n");
//      break;

    case RSI_BT_EVT_REMOTE_DEVICE_NAME:
      printf("RSI_BT_EVT_REMOTE_DEVICE_NAME: \r\n");
      {
        RSI_BT_EVENT_REMOTE_DEVICE_NAME *p_rmt_name;
        INT08  ix;

        p_rmt_name = (RSI_BT_EVENT_REMOTE_DEVICE_NAME *)rsp;
        
        for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)p_rmt_name->BDAddress)[ix]);
          if(ix > 0)
            printf("-");
        }
        
        printf ("\n");

        printf ("\r\nlen: %d, Name: %s", p_rmt_name->NameLength, p_rmt_name->RemoteDeviceName);
      }
      break;

    case RSI_BT_EVT_REMOTE_NAME_REQUEST_CANCEL:
      printf("RSI_BT_EVT_REMOTE_NAME_REQUEST_CANCEL: \r\n");
      break;

    case RSI_BT_EVT_DISCONNECTED:
      printf("RSI_BT_EVT_DISCONNECTED: \r\n");
      break;

    case RSI_BT_EVT_USER_CONFIRMATION_REQUEST:
      printf("RSI_BT_EVT_USER_CONFIRMATION_REQUEST: \r\n");
      break;

    case RSI_BT_EVT_USER_PASKEY_DISPLAY:
      printf("RSI_BT_EVT_USER_PASKEY_DISPLAY: \r\n");
      break;

    case RSI_BT_EVT_USER_PINCODE_REQUEST:
      printf("RSI_BT_EVT_USER_PINCODE_REQUEST: \r\n");
      {
        RSI_BT_EVENT_USER_PINCODE_REQUEST *p_pincode;
        INT08  ix;

        p_pincode = (RSI_BT_EVENT_USER_PINCODE_REQUEST *)rsp;
       
        for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)p_pincode->BDAddress)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n");
        
        memcpy(rsi_bt_AppControlBlock.RemoteBDAddress, p_pincode->BDAddress, RSI_BT_BD_ADDR_LEN);
      }
      break;

    case RSI_BT_EVT_USER_LINKKEY_REQUEST:
      printf("RSI_BT_EVT_USER_LINKKEY_REQUEST: \r\n");
      {
        RSI_BT_EVENT_USER_LINKKEY_REQUEST *p_linkkey;
        INT08  ix;

        p_linkkey = (RSI_BT_EVENT_USER_LINKKEY_REQUEST *)rsp;

        for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)p_linkkey->BDAddress)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n");

        memcpy(rsi_bt_AppControlBlock.RemoteBDAddress, p_linkkey->BDAddress, RSI_BT_BD_ADDR_LEN);
      }
      break;

    case RSI_BT_EVT_USER_LINKKEY_SAVE:
      printf("RSI_BT_EVT_USER_LINKKEY_SAVE: \r\n");
      {
        RSI_BT_EVENT_USER_LINKKEY_SAVE *p_linkkey_save;
        INT08  ix;

        p_linkkey_save = (RSI_BT_EVENT_USER_LINKKEY_SAVE *)rsp;

        for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)p_linkkey_save->BDAddress)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n");

        for (ix = 0; ix < 16; ix++) {
          printf ("%02x", ((UINT08 *)p_linkkey_save->LinkKey)[ix]);
          if(ix > 0)
            printf(" ");
        }
        printf ("\n");
        /* Only one entry is saved here, to let the user understand the usage. 
		 * User can write his own algorithm to save as many entries as per his requirement. 
		 */
        memcpy(rsi_bt_AppControlBlock.RemoteBDAddress, p_linkkey_save->BDAddress, RSI_BT_BD_ADDR_LEN);
        memcpy(rsi_bt_AppControlBlock.RemoteLinkKey, p_linkkey_save->LinkKey, RSI_BT_LINK_KEY_LEN);
      }
      break;

    case RSI_BT_EVT_USER_PASSKEY_REQUEST:
      printf("RSI_BT_EVT_USER_PASSKEY_REQUEST: \r\n");
      break;

    case RSI_BT_EVT_INQ_COMPLETE:
      printf("RSI_BT_EVT_USER_INQ_COMPLETE: \r\n");
      break;

    case RSI_BT_EVT_AUTH_COMPLETE:
      printf("RSI_BT_EVT_USER_AUTH_COMPLETE: \r\n");
      break;

    case RSI_BT_EVT_SPP_RECEIVE:
      printf("RSI_BT_EVT_SPP_RECEIVE: \r\n");
      {
        UINT16  len;

        len = *((UINT16 *)rsp);
        printf ("len: %d, data: %s", len, &((UINT08 *)rsp)[2]);
      }
      break;

    case RSI_BT_EVT_SPP_CONNECTED:
      printf("RSI_BT_EVT_SPP_CONNECTED: \r\n");
      {
        RSI_BT_EVENT_SPP_CONNECTED *p_conn;
        INT08  ix;

        p_conn = (RSI_BT_EVENT_SPP_CONNECTED *)rsp;
        for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)p_conn->BDAddress)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n");
      }
      break;

    case RSI_BT_EVT_SPP_DISCONNECTED:
      printf("RSI_BT_EVT_SPP_DISCONNECTED: \r\n");
      {
        RSI_BT_EVENT_SPP_DISCONNECTED *p_disconn;
        INT08  ix;

        p_disconn = (RSI_BT_EVENT_SPP_DISCONNECTED *)rsp;
        for (ix = 5; ix >= 0; ix--) {
          printf ("%02x", ((UINT08 *)p_disconn->BDAddress)[ix]);
          if(ix > 0)
            printf("-");
        }
        printf ("\n");      }
      break;

    case RSI_BT_RSP_INIT:
      printf("RSI_BT_RSP_INIT: \r\n");
      break;
     
    case RSI_BT_RSP_DEINIT:
      printf("RSI_BT_RSP_DEINIT: \r\n");
      break;

    default:
      printf ("undefined event\r\n");
  }
}
#endif

