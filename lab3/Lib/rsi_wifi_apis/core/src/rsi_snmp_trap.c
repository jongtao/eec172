/**
 * @file       rsi_snmp_trap.c
 * @version    1.0
 * @date       2014-Mar-03
 *
 * Copyright(C) Redpine Signals 2012
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief SNMP TRAP: sends SNMP trap
 *
 * @section Description
 * This file contains the Snmp trap function.
 *
 *
 */


/**
 * Includes
 */
#include "rsi_global.h"


/*==============================================*/
/**
 * @fn          int16 rsi_snmp_trap(rsi_uSnmptrap *uSnmpTrapFrame)
 * @brief       Sends the SNMP trap command to the Wi-Fi module
 * @param[in]   rsi_uSnmptrap *uSnmpTrapFrame
 * @param[out]  none
 * @return      errCode
 *              -1 = Buffer Full
 *              0  = SUCCESS
 * @section description 
 * This API is used for SNMP trap command.
 * This API has to be called only after the rsi_snmp_enable API.
 */

int16 rsi_snmp_trap(rsi_uSnmptrap  *uSnmpTrapFrame)
{
  int16               retval;

#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\r\n\nSNMP trap Start");
#endif
  retval = rsi_execute_cmd((uint8 *)rsi_frameCmdSnmpTrap,(uint8 *)uSnmpTrapFrame, sizeof(rsi_uSnmptrap));
  return retval;
}


