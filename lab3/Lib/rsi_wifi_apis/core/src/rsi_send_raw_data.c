/**
 * @file       rsi_send_raw_data.c
 * @version    2.7
 * @date       2012-Sep-26
 *
 * Copyright(C) Redpine Signals 2012
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief SEND RAW DATA: Function to send raw data.
 *
 * @section Description
 * This file contains the SEND Raw data function.
 *
 *
 */


/**
 * Includes
 */
#include "rsi_global.h"


/*
 * Global Variables 
 */


/*=============================================================*/
/**
 * @fn          int16 rsi_send_raw_data(uint8 *payload, uint32 payloadLen,uint32 *bytes_sent)
 * @brief       SEND Packet command
 * @param[in]   uint8 *payload, pointer to the data to payload buffer
 * @param[in]   uint32 payloadLen, length of the payload
 * @param[out]  uint32 bytes_sent, number of bytes sent
 * @return      errCode
 *              -1 = Buffer Full
 *               0 = Success
 *
 * @section description 
 * This API used to send raw data over Wi-Fi module. This API is used to send data 
 * packets in TCP/IP bypass mode.If this API return error code like -1, 
 * Application need to retry this function until successfully send the packet 
 * over WiFi module.
 */

int16 rsi_send_raw_data(uint8 *payload, uint32 payloadLen,uint32 *bytes_sent)
{
  int16         retval = 0;
  rsi_uFrameDsc uFrameDscFrame;
  //!payload length sent in each packet
  uint32        send_payload_len;
  //!payload offset
  uint32        payload_offset = 0;
  //! build the SEND frame descriptor
  rsi_build_frame_descriptor(&uFrameDscFrame,(uint8 *) rsi_frameCmdSend);
  while(payloadLen)
  {
    if(payloadLen >= 1500)
    {
      send_payload_len = 1500;
    }
    else
    {
      send_payload_len = payloadLen;
    }
#ifdef RSI_LITTLE_ENDIAN
    //! set the frame length LSB
      uFrameDscFrame.frameDscDataSnd.dataFrmLenAndQueue[0] = (uint8)(send_payload_len & 0x00ff);
      //! set the frame length MSB
      uFrameDscFrame.frameDscDataSnd.dataFrmLenAndQueue[1] = (uint8)(((send_payload_len >> 8) & 0x000f)| 0x50);
#else 
    //! set the frame length LSB
    uFrameDscFrame.frameDscDataSnd.dataFrmLenAndQueue[0] = (uint8)(send_payload_len & 0x00ff);
    //! set the frame length MSB
    uFrameDscFrame.frameDscDataSnd.dataFrmLenAndQueue[1] = (uint8)(((send_payload_len >> 8) & 0x000f) | 0x50);
#endif
#ifndef UART_INTERFACE
    //! Write out the command frame descriptor
    retval = rsi_spi_frame_dsc_wr(&uFrameDscFrame);

    //! Write the Raw Data to send
    retval = rsi_spi_frame_data_wr(send_payload_len,(uint8 *)(payload + payload_offset),0,NULL);
	
#endif
    if (retval != 0x00) 
    {
#ifdef RSI_DEBUG_PRINT
      RSI_DPRINT(RSI_PL4,"SndFrmDescErr=%02x", (uint16)retval);  
#endif
      return retval;
    }

    payloadLen     -= send_payload_len;
    payload_offset += send_payload_len;
    *bytes_sent    += send_payload_len;
  }
  return retval;
}
