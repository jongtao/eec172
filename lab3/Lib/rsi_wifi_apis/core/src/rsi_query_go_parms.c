/**
 * @file       rsi_query_go_parms.c
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
 * @brief QUERY GO PARAMETERS: Function to get the status of an existing connection
 *
 * @section Description
 * This file contains the QUERY GO PARAMETERS function.
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


/*===========================================================================*/
/**
 * @fn          int16 rsi_query_go_parms(void)
 * @brief       SPI, QUERY GO PARAMETERS Command
 * @param[in]   none
 * @param[out]  none
 * @return      errCode
 *              -2 = Command execution failure
 *              -1 = Buffer Full
 *              0  = SUCCESS
 *      
 * @section description 
 * This API is used to query the GO parameters of the Wi-Fi module.
 */
int16 rsi_query_go_parms(void)
{
  int16            retval;

#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\r\n\nQuery GO Parms Start");
#endif

  retval = rsi_execute_cmd((uint8 *)rsi_frameCmdQryGoParms,NULL,0);

  return retval;
}
