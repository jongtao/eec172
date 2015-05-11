/**
 * @file     rsi_socket_close.c
 * @version  2.7
 * @date     2012-Sep-26
 *
 * Copyright(C) Redpine Signals 2012
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief SOCKET CLOSE: Function which closes an open socket
 *
 * @section Description
 * This file contains the SOCKET CLOSE function.
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


/**===========================================================================
 * @fn          int16 rsi_socket_close(uint16 socketDescriptor, uint16 port_number)
 * @brief       Closes an open socket
 * @param[in]   uint16 socketDescriptor, socket to close
 * @param[in]   uint16 port_number, to close all LTCP connection with provided port number
 * @param[out]  none
 * @return      errCode
 *              -2 = Command execution failure
 *              -1 = Buffer Full
 *              0  = SUCCESS
 *       
 * @section description  
 * This API is used to close an already open socket.
 * @section prerequisite 
 * Socket with the given descriptor should already been created
 */
int16 rsi_socket_close(uint16 socketDescriptor, uint16 port_number)
{
  int16                                   retval;
  rsi_uSocketClose                        uSocketCloseFrame;
#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\nSocket Close Start\n");
#endif

#ifdef RSI_LITTLE_ENDIAN  
  *(uint16 *)uSocketCloseFrame.socketCloseFrameSnd.socketDescriptor = socketDescriptor;
  *(uint16 *)uSocketCloseFrame.socketCloseFrameSnd.port_number = port_number;
#else
  rsi_uint16_to_2bytes((uint8 *)&uSocketCloseFrame.socketCloseFrameSnd.socketDescriptor, socketDescriptor);
  rsi_uint16_to_2bytes((uint8 *)&uSocketCloseFrame.socketCloseFrameSnd.port_number, port_number);
#endif
  retval = rsi_execute_cmd((uint8 *)rsi_frameCmdSocketClose,(uint8 *)&uSocketCloseFrame,sizeof(rsi_uSocketClose));
  return retval;
}
