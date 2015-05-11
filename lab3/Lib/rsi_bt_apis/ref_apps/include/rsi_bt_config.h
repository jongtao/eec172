/**
 * @file           rsi_bt_config.h
 * @version        1.0
 * @date           2014-Aug-23
 *
 * Copyright(C) Redpine Signals 2014
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief BT CONFIG INIT Contains the default configurations used in the BT API's.
 *
 * @section Description
 * USER is supposed to configure the module/API's  by using the following defines.
 *
 *
 */


#ifndef _INITSTRUCT_H_
#define _INITSTRUCT_H_


#include "rsi_bt_api.h"

/*==============================================*/
/**
 * Global Defines
 */
 #define RSI_BT_REMOTE_BD_ADDRESS             0  //"00:23:A7:4C:24:77" //0 //"11:22:33:44:55:66"

#define RSI_BT_SET_LOCAL_NAME                "BT_WYZBEE_MASTER"
#define RSI_BT_SET_LOCAL_COD                 1000 
#define RSI_BT_QUERY_RSSI_ADDR               RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_QUERY_LINK_QUALITY_ADDR       RSI_BT_REMOTE_BD_ADDRESS 
#define RSI_BT_SET_DISC_MODE                 1 
#define RSI_BT_SET_DISC_MODE_TIMEOUT         1000 
#define RSI_BT_SET_CONN_MODE                 1
#define RSI_BT_SET_PAIR_MODE                 1
#define RSI_BT_REM_NAME_REQ_ADDR             RSI_BT_REMOTE_BD_ADDRESS   
#define RSI_BT_REM_NAME_REQ_CANCEL_ADDR      RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_INQ_TYPE                      1
#define RSI_BT_INQ_DURATION                  5000       
#define RSI_BT_INQ_MAX_DEVICES               5
#define RSI_BT_BOND_ADDR                     RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_BOND_CANCEL_ADDR              RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_UNBOND_ADDR                   RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_SET_PIN_TYPE                  1
#define RSI_BT_USER_CONF_ADDR                RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_USER_CONF                     1
#define RSI_BT_PASSKEY_ADDR                  RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_PASSKEY_REPLY_TYPE            1
#define RSI_BT_PASSKEY                       1234
#define RSI_BT_PINCODE_REPLY_ADDR            RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_PINCODE_REPLY_TYPE            1
#define RSI_BT_LINKKEY_REPLY_ADDR            RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_LINKKEY_REPLY_TYPE            0
#define RSI_BT_PINCODE                       1234
#define RSI_BT_QUERY_ROLE_ADDR               RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_SET_ROLE_ADDR                 RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_SET_ROLE                      1

#define RSI_BT_SPP_CONN_ADDR                 RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_SPP_DISCONN_ADDR              RSI_BT_REMOTE_BD_ADDRESS


#define RSI_BT_QUERY_SERV_ADDR               RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_SEARCH_SERV_ADDR              RSI_BT_REMOTE_BD_ADDRESS
#define RSI_BT_SEARCH_SERV_SIZE              2
#define RSI_BT_SEARCH_SERV_UUID              0x1101


extern  UINT08  rsi_bt_TransferBuffer[RSI_BT_MAX_PAYLOAD_SIZE];
#define RSI_BT_SPP_TX_LEN                    (UINT16)(sizeof(rsi_bt_TransferBuffer) - 1)
#define RSI_BT_SPP_TX_DATA                   rsi_bt_TransferBuffer 






#define RSI_BT_DEVICE_IS_MASTER                 1
#define RSI_BT_DEVICE_IS_SLAVE                  (~RSI_BT_DEVICE_IS_MASTER)

#define RSI_BT_CHECK_REMOTE_SERVICES            0
#define RSI_BT_SEARCH_FOR_SERVICE               0

#define RSI_BT_DEV_IS_SCAN_ENABLE               0


/*! Serial Port Profile (SPP) */
#define RSI_BT_DEVICE_SPP_IS_ENABLE             1

#if RSI_BT_DEVICE_SPP_IS_ENABLE
#define RSI_BT_DEVICE_SPP_PROFILE_NUMBER        1    
#else
#define RSI_BT_DEVICE_SPP_PROFILE_NUMBER        0
#endif

#define RSI_BT_DEVICE_SPP_DATA_TRANSFER         (1 && RSI_BT_DEVICE_SPP_IS_ENABLE)
#define RSI_BT_DEVICE_SPP_DATA_RECEIVE          (1 && RSI_BT_DEVICE_SPP_IS_ENABLE)
#define RSI_BT_DEVICE_SPP_UUID        



#define RSI_BT_SET_PROFILE_MODE                 RSI_BT_DEVICE_SPP_PROFILE_NUMBER



INT16 rsi_bt_init_struct(UINT16  CommandType);

#endif
