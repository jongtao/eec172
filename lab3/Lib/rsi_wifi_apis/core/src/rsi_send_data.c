/**
 * @file       rsi_send_data.c
 * @version    1.2
 * @date       2013-Feb-16
 *
 * Copyright(C) Redpine Signals 2013
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief SEND: Function to send udp / tcp data to an existing connection
 *
 * @section Description
 * This file contains the SEND function.
 *
 * @Improvements
 *
 */


/**
 * Includes
 */
#include "rsi_global.h"
#include "rsi_app.h"

/*
 * Global Variables 
 */


/*=============================================================*/
/**
 * @fn          int16 rsi_send_data(uint16 socketDescriptor, uint8 *payload, uint32 payloadLen,uint8 protocol)
 * @brief       SEND Packet command
 * @param[in]   uint16 socketDescriptor, socket descriptor for the socket to send data to
 * @param[in]   uint8 *payload, pointer to the data to send payload buffer
 * @param[in]   uint32 payloadLen, length of the data to send payload
 * @param[in]   uint8  protocol, TCP or UDP
 * @param[out]  uint32 bytes_sent, number of bytes sent succesfuly
 * @return      errCode
 *              -2 = Command execution failure
 *              -1 = Buffer Full
 *              0  = SUCCESS
 *
 * @section description
 * This API used to send TCP/UDP data using an already opened socket. This function
 * should be called after successfully opening a socket using the rsi_socket API.
 * If this API return error code-1, Application need to retry this function until
 * successfully send the packet over WiFi module.
 */
#if !RSI_TCP_IP_BYPASS
int16 rsi_send_data(uint16 socketDescriptor, uint8 *payload, uint32 payloadLen,uint8 protocol,uint32 *bytes_sent)
{
  int16   retval = 0;
  uint16  headerLen = 0;
  //!payload length sent in each packet
  uint32  send_payload_len = 0;
  //!payload offset
  uint32  payload_offset = 0;
  //! length of frame without padding bytes
  uint32  frameLen = 0;

  //! length to pad the transfer so it lines up on a 4 byte boundary
  uint8  rsi_local_frameCmdSend[RSI_BYTES_3];

  memcpy(rsi_local_frameCmdSend, rsi_frameCmdSend, RSI_BYTES_3);

#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\nSend Data Start\n");
#endif

#ifdef RSI_LITTLE_ENDIAN
  *(uint16 *)rsi_app_cb.uSendFrame.sendFrameSnd.ip_version = RSI_IP_VERSION;
#else
  rsi_uint16_to_2bytes(rsi_app_cb.uSendFrame.sendFrameSnd.ip_version, RSI_IP_VERSION);
#endif


  if((protocol & 0xF) == RSI_PROTOCOL_TCP_V4)
  {
    headerLen =  RSI_TCP_FRAME_HEADER_LEN;
  }
  else
  {
    headerLen =  RSI_TCP_V6_FRAME_HEADER_LEN;
  }

  if(protocol & BIT(7))
  {
    //! If websocket is enabled
    headerLen += ((payloadLen < 126) ? 6 : 8);
  }

#ifdef RSI_LITTLE_ENDIAN
  memcpy((uint8 *)&rsi_app_cb.uSendFrame.sendFrameSnd.sendDataOffsetSize[0], (uint8 *)&headerLen, 2);
#else
  rsi_uint16_to_2bytes(rsi_app_cb.uSendFrame.sendFrameSnd.sendDataOffsetSize, headerLen);
#endif

#ifdef RSI_LITTLE_ENDIAN
  memcpy(rsi_app_cb.uSendFrame.sendFrameSnd.socketDescriptor, &socketDescriptor, 2);
#else
  rsi_uint16_to_2bytes(rsi_app_cb.uSendFrame.sendFrameSnd.socketDescriptor,socketDescriptor);
#endif

  while(payloadLen)
  {
    if(payloadLen >= RSI_TCP_MAX_SEND_SIZE)
    {
      send_payload_len = RSI_TCP_MAX_SEND_SIZE;
    }
    else
    {
      send_payload_len = payloadLen;
    }
    frameLen = send_payload_len + headerLen;

#ifdef RSI_DEBUG_PRINT
    RSI_DPRINT(RSI_PL3," PayloadLen=%08x", (uint16)send_payload_len);
#endif

#ifdef RSI_LITTLE_ENDIAN
    //!set the length here
      rsi_local_frameCmdSend[0] = (frameLen & 0x00ff);
      rsi_local_frameCmdSend[1] = (((frameLen & 0x0f00) >> 8)|0x50);
#else
    //!set the LSB
    rsi_local_frameCmdSend[0] = (uint8)(frameLen & 0x00ff);
    //!set the MSB
     rsi_local_frameCmdSend[1] = (((frameLen & 0x0f00) >> 8)|0x50);
#endif

#ifdef RSI_LITTLE_ENDIAN
    memcpy((uint8 *)rsi_app_cb.uSendFrame.sendFrameSnd.sendBufLen,&send_payload_len, 2);
#else
    rsi_uint16_to_2bytes(rsi_app_cb.uSendFrame.sendFrameSnd.sendBufLen,send_payload_len);
#endif
    memcpy((uint8 *)&rsi_app_cb.uSendFrame.uSendBuf[headerLen],(uint8 *)(payload + payload_offset), send_payload_len);
    retval = rsi_execute_cmd((uint8 *)rsi_local_frameCmdSend,(uint8 *)&rsi_app_cb.uSendFrame,frameLen);
    if (retval != 0x00)
    {
#ifdef RSI_DEBUG_PRINT
      RSI_DPRINT(RSI_PL4,"SendCmd Err=%02x", (uint16)retval);
#endif
      return retval;
    }
    payloadLen     -= send_payload_len;
    *bytes_sent    += send_payload_len;
    payload_offset += send_payload_len;
  }
  return retval;
}
#endif
