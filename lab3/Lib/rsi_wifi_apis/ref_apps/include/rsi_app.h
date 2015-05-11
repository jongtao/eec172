/**
 * @file     rsi_app.h
 * @version      1.0
 * @date         2014-Jan-31
 *
 * Copyright(C) Redpine Signals 2012
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief HEADER, APP, APPLICATION Header file which contains application specific structures 
 *
 * @section Description
 * This file contains the Application related information.
 *
 *
 */
#include "rsi_config.h"
#ifndef _RSI_APP_CB_H
#define _RSI_APP_CB_H
/* Application control block */
typedef struct 
{
   /* For Certificate */
   struct        SET_CHUNK_S set_chunks;
   /* For Webpage write */
   uint8         webpage_morechunks;
   /* received paket count */
   uint32        rcvd_data_pkt_count;
   /* flag to enable send data*/
   uint8         glbl_send_data;
   /* Error code */
   uint16        error_code;
   /* Mac address */
   uint8         mac_addr[6];
   /* Buffer to receive to response from Wi-Fi module */
   rsi_uCmdRsp   *uCmdRspFrame;
   /* Buffer to store Wi-Fi and network Initialization parameters */
   rsi_api       rsi_strApi;
   /*structure to store socket information */
   volatile      rsi_sockets   socketsStrArray;  
   /* packet pending flag */
   volatile      uint32 pkt_pending;
   /* Send buffer data */
   uint8         send_buffer[RSI_MAX_PAYLOAD_SIZE+100];
   /* Json buffer */
 #if JSON_LOAD
   uint8 json_buffer[JSON_BUFFER_SIZE];
#endif
   /* Buffer to hold the received packet */
   uint8 read_packet_buffer[1600];
  //! frame sent for the send command,  includes data
  rsi_uSend        uSendFrame;   
#if (RSI_POWER_MODE == RSI_POWER_MODE_3)
  //! backup of frame type 
  uint8          ps_descparam[16];   
  //! Paket pending for power save
  void *          ps_pkt_pending;   
  //! size of currently held packet
  uint16        ps_size_param;
  //! devide sleep indication
  uint16        ps_ok_to_send;
#endif
#if (RSI_POWER_MODE == RSI_POWER_MODE_2)
  uint16        power_save_enable;
#endif
}rsi_app_cb_t;

extern rsi_app_cb_t rsi_app_cb;

#endif
