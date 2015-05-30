/**
 * @file       rsi_init.c
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
 * @brief INIT: Function which initiaizes the modules baseband and RF components
 *
 * @section Description
 * This file contains the function to initialize module baseband and RF components
 * This command must be preceeded by the BAND command
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

/*==============================================*/
/**
 * @fn             int16 rsi_init(void)
 * @brief          Initializes the baseband and RF components
 * @param[in]      none
 * @param[out]     none
 * @return         errCode
 *                 -2 = Command execution failed
 *                 -1 = Buffer Full
 *                 0  = SUCCESS
 * @section description   
 * This API initializes the Wi-Fi module's Baseband and RF components. 
 * It has to be called only after the rsi_bootloader and rsi_band APIs.
 */
int16 rsi_init(void)
{
  int16            retval;

#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\r\n\nINIT Start");
#endif
  retval = rsi_execute_cmd((uint8 *)rsi_frameCmdInit,NULL, 0);
  return retval;
}
