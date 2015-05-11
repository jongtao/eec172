/**
 * @file       rsi_select_antenna.c
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
 * @brief ANTENNA SELECTION: Function to set the ANTENNA 
 *
 * @section Description
 * This file contains the rsi_select_antenna function.
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
 * @fn          int16 rsi_select_antenna(uint8 antenna_val)
 * @brief       Sends the ANTENNA SELECTION command to the Wi-Fi module via SPI
 * @param[in]   uint8 antenna_val to configure ,1 for Internal Antenna , 2 for uFL Antenna.
 * @param[out]  none
 * @return      errCode
 *              -1 = Buffer full
 *              0  = SUCCESS
 * @section description 
 * This API is used to select the Internal Antenna or External Antenna.
 */
int16 rsi_select_antenna(uint8 antenna_val)
{
  int16               retval;
  rsi_uAntenna       uAntSel;

#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\r\n\nAntenna Selection");
#endif
  uAntSel.AntennaSelFrameSnd.AntennaVal = antenna_val;
  retval = rsi_execute_cmd((uint8 *)rsi_frameCmdAntSel,(uint8 *)&uAntSel, sizeof(rsi_uAntenna));
  return retval;
}

