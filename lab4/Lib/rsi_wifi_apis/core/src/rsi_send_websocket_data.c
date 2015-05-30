/**
 * @file       rsi_send_websocket_data.c
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
 * @fn          int16 rsi_send_websocket_data(uint16 socketDescriptor, uint8 *payload, uint32 payloadLen,uint8 protocol, uint32 *total_bytes_sent)
 * @brief       SEND websocket Packet command
 * @param[in]   uint16 socketDescriptor, socket descriptor for the socket to send data to
 * @param[in]   uint8 *payload, pointer to the data to send payload buffer
 * @param[in]   uint32 payloadLen, length of the data to send payload
 * @param[in]   uint8  protocol, TCPV4 or TCPV6
 * @param[out]  uint32 *total_bytes_sent, number of bytes sent succesfuly
 * @return      errCode
 *              -2 = Command execution failure
 *              -1 = Buffer Full
 *              0  = SUCCESS
 *
 * @section description 
 * This API used to send websocket TCP data using an already opened socket. This function 
 * should be called after successfully opening a socket using the rsi_socket API.
 * If this API return error code-1, Application need to retry this function until 
 * successfully send the packet over WiFi module.
 */
#if !RSI_TCP_IP_BYPASS
int16 rsi_send_websocket_data(uint16 socketDescriptor, uint8 *payload, uint32 payloadLen,uint8 protocol, uint8 opcode, uint32 *total_bytes_sent)
{
  int16 retval          = 0;
  uint16 send_length    = 0;
  uint32 payload_offset = 0;
  uint8 websocket_info  = 0;
  uint32 bytes_sent     = 0;

  while(payloadLen)
  {
    websocket_info = opcode;
    if(payloadLen > RSI_TCP_MAX_SEND_SIZE)
    {
      send_length = RSI_TCP_MAX_SEND_SIZE;
    }
    else
    {
      send_length = payloadLen;
      //! Set the fin bit
      websocket_info |= BIT(7);
    }
    socketDescriptor |= (websocket_info << 8);

    //! call actual send API
    retval = rsi_send_data(socketDescriptor, (payload + payload_offset), send_length, (protocol | BIT(7)), &bytes_sent);
    if(retval != 0)
    {
#ifdef RSI_DEBUG_PRINT
      RSI_DPRINT(RSI_PL4,"SendCmd Err=%02x", (uint16)retval);
#endif
      return retval;
    }

    payloadLen           -= bytes_sent;
    *total_bytes_sent    += bytes_sent;
    payload_offset       += bytes_sent;

  }
  return retval;
}
#endif

