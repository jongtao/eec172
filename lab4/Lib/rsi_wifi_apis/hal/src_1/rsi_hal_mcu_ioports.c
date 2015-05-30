/**
 * @file       rsi_hal_mcu_ioports.c
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
 * @brief Functions to control IO pins of the microcontroller
 *  
 * @section Description
 * This file contains API to control different pins of the microcontroller 
 * which interface with the module and other components related to the module. 
 *
 */


/**
 * Includes
 */
#include "rsi_global.h"
#include "rsi_hal.h"
#include "spi.h"


/*===========================================================*/
/**
 * @fn      int16 rsi_module_power_cycle(void)
 * @brief    MODULE POWER ON, Power cycles the module
 * @param[in]  none
 * @param[out]  none
 * @return    errCode
 *        -1 = Error
 *        0  = OK
 * @description This API is used to power cycle the module. 
 * This API is valid only if there is a power gate, external to the module, 
 * which is controlling the power to the module using a GPIO signal of the MCU.
 */
int16 rsi_module_power_cycle(void)
{
	wifi_reset_routine();
   return 0;
}
