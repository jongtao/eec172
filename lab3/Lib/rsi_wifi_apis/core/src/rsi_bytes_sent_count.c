/**
 * @file     rsi_bytes_sent_count.c
 * @version  1.0
 * @date     2014-Oct-31
 *
 * Copyright(C) Redpine Signals 2012
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief BYTES SENT COUNT: Function to send bytes sent count on socket
 *
 * @section Description
 * This file contains the socket sent bytes count query function.
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
 * @fn          int16 rsi_bytes_sent_count(uint16 socketDescriptor)
 * @brief       Queries the total bytes sent count with the given socket descriptor
 * @param[in]   uint16 socketDescriptor, socket to query
 * @param[out]  none
 * @return      errCode
 *                 -2 = Command execution failed
 *              -1 = Buffer Full
 *              0  = SUCCESS
 *       
 * @section description  
 * This API is used to query the total bytes sent count with the given descriptor.
 * @section prerequisite 
 * Socket with the given descriptor should already be created.
 */
int16 rsi_bytes_sent_count(uint16 socketDescriptor)

{
  int16                                   retval;
  rsi_uQuerySentBytesCount                uQuerySentBytesCountFrame;
  
#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\nSent bytes query\n");
#endif


#ifdef RSI_LITTLE_ENDIAN  
  *(uint16 *)uQuerySentBytesCountFrame.querySentBytesCountFrameSnd.socketDescriptor = socketDescriptor;
#else
  rsi_uint16To2Bytes((uint8 *)&uQuerySentBytesCountFrame.querySentBytesCountFrameSnd.socketDescriptor, socketDescriptor);
#endif
  retval =rsi_execute_cmd((uint8 *)rsi_frameCmdSentBytesCount,(uint8 *)&uQuerySentBytesCountFrame,sizeof(rsi_uQuerySentBytesCount));
  return retval;

}
