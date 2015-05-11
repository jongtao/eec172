/**
 * @file     rsi_http_get.c
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
 * @brief HTTP GET: Function which implements HTTP GET command
 *
 * @section Description
 * This file contains the Join function.
 *
 *
 */

/**
 * Includes
 */
#include "rsi_global.h"

/**
 * Global Variables
 */

/*=================================================*/
/**
 * @fn          int16 rsi_http_get(rsi_uHttpReq *uHttpGetReqFrame)
 * @brief       Sends the Http Get command to the Wi-Fi module via SPI
 * @param[in]   rsi_uHttpReq *uHttpGetReqFrame, Pointer to Http Get structure
 * @param[out]  none
 * @return      errCode
 *              -2 = Command execution failed
 *              -1 = Buffer Full
 *              0  = SUCCESS
 * @section description 
 * This API is used to give the HTTP GET Request for HTTP server. 
 * @section prerequisite 
 * The rsi_ipparam_set  should be done sussessfully.
 */
 
int16 rsi_http_get(rsi_uHttpReq *uHttpGetReqFrame)
{
  int16  retval;
  uint16 buf_len;

  /*Http GET Request Frame */
  uint8   rsi_frameCmdHttpGetReq[RSI_BYTES_3] = {0x00, 0x40, 0x51};

  buf_len = sizeof(rsi_uHttpReq) - HTTP_BUFFER_LEN;

  buf_len += strlen((char *)uHttpGetReqFrame->HttpReqFrameSnd.buffer);

  *(uint16 *)&rsi_frameCmdHttpGetReq[0] = (buf_len & 0xFFF);

  rsi_frameCmdHttpGetReq[1] |= 0x40;


#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\r\n\n HTTP GET Start");
#endif
  retval = rsi_execute_cmd((uint8 *)rsi_frameCmdHttpGetReq,(uint8 *)uHttpGetReqFrame, buf_len);
  return retval;
}
