/**
 * @file     rsi_ltcp_conn_status.c
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
 * @brief CTCP: Function to close an open socket
 *
 * @section Description
 * This file contains the LTCP connection status query function.
 *
 *
 */


/**
 * Includes
 */
#include "rsi_global.h"


/**
 * Global defines
 */



/**===========================================================================
 * @fn          int16 rsi_ltcp_conn_status(uint16 socketDescriptor)
 * @brief       Queries the status of the LTCP socket with socket descriptor
 * @param[in]   uint16 socketDescriptor, socket to query
 * @param[out]  none
 * @return      errCode
 *              -2 = Command execution failed
 *              -1 = Buffer Full
 *              0  = SUCCESS
 *       
 * @section description  
 * This API is used to query the connection status of listening TCP socket.
 * @section prerequisite 
 * Socket with the given descriptor should already be created.
 */
int16 rsi_ltcp_conn_status(uint16 socketDescriptor)
{
  int16                                   retval;
  rsi_uQueryLtcpConnStatus                     uQueryLtcpConnStatusFrame;
#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\nLTCP Conn Status Start\n");
#endif

#ifdef RSI_LITTLE_ENDIAN  
  *(uint16 *)uQueryLtcpConnStatusFrame.queryLtcpConnStatusFrameSnd.socketDescriptor = socketDescriptor;
#else
  rsi_uint16To2Bytes((uint8 *)&uQueryLtcpConnStatusFrame.queryLtcpConnStatusFrameSnd.socketDescriptor, socketDescriptor);
#endif
  retval =rsi_execute_cmd((uint8 *)rsi_frameCmdLtcpConnStatus,(uint8 *)&uQueryLtcpConnStatusFrame,sizeof(rsi_uQueryLtcpConnStatus));
  return retval;
}
