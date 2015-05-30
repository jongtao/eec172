/**
 * @file     rsi_cfg_get.c
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
 * @brief CFG GET: Function to retrieve configuration data
 *
 * @section Description
 * This file contains the function which retrieves the stored configuration
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
 * @fn          int16 rsi_cfg_get(void)
 * @brief       Sends the Config Get command to the Wi-Fi module ,gets
 *         the module configuration information
 * @param[in]   none
 * @param[out]  none
 * @return      errCode
 *              -1 = Buffer Full
 *              0  = SUCCESS
 * @section description 
 * This API is used to give the CONFIG GET Request for the module. 
 * @section prerequisite 
 * The rsi_cfg_save should be done sussessfully.
 */
 
 
int16 rsi_cfg_get(void)
{
    int16  retval;

 #ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\r\n\n CFG GET Start");
 #endif
  retval =rsi_execute_cmd((uint8 *)rsi_frameCmdCfgGet,NULL,0);
  return retval;
}
