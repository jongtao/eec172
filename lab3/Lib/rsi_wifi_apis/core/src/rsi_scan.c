/**
 * @file      rsi_scan.c
 * @version   2.7
 * @date      2012-Sep-26
 *
 * Copyright(C) Redpine Signals 2012
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief SCAN: Function which scans for available access points
 *
 * @section Description
 * This file contains the Scan function.
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


/*===========================================================================
 *
 * @fn          int16 rsi_scan(rsi_uScan *uScanFrame)
 * @brief       Sends the Scan command to the Wi-Fi module
 * @param[in]   rsi_uScan *uScanFrame,Pointer to scan structure
 * @param[out]  none
 * @return      errCode
 *              -2 = Command execution failure
 *              -1 = Buffer Full
 *              0  = SUCCESS
 * @section description 
 * This API is used to scan for Access Points. This API should be called only 
 * after the rsi_init API.
 *
 * @section prerequisite 
 * rsi_init should be done successfully  
 */

int16 rsi_scan(rsi_uScan *uScanFrame)
{
  int16          retval;

#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\r\n\nScan Start ");
#endif

  retval = rsi_execute_cmd((uint8 *)rsi_frameCmdScan, (uint8 *)uScanFrame, sizeof(rsi_uScan));
  return retval;
}
