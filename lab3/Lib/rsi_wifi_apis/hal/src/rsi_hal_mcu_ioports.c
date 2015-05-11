/**
 * @file     rsi_hal_mcu_ioports.c
 * @version		2.7
 * @date 		  2012-Sep-26
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

#if (defined(LINUX) | defined(LINUX_PLATFORM))
#include <linux/gpio.h>
#endif


/**
 * Global Variales
 */



/*====================================================*/
/**
 * @fn		void rsi_module_reset(uint8 tf)
 * @brief	Sets or clears the reset pin on the wifi module
 * @param[in]	uint8 tf, true or false, true sets reset, false clears reset
 * @param[out]	none
 * @return	none
 * @description This HAL API is used to set or clear the active-low reset pin of the Wi-Fi module.
 */
void rsi_module_reset(uint8 tf)
{	
  if (tf == RSI_TRUE) {
  }
  else {
  }


}

/*====================================================*/
/**
 * @fn		void rsi_module_power(uint8 tf)
 * @brief	Turns on or off the power to the wifi module
 * @param[in]	uint8 tf, true or false, true turns on power, false turns off power
 * @param[out]	none
 * @return	none
 * @description This HAL API is used to turn on or off the power to the Wi-Fi module.
 */
void rsi_module_power(uint8 tf)
{	
  if (tf == RSI_TRUE) {
  }
  else {
  }

 }

/*===========================================================*/
/**
 * @fn			int16 rsi_module_power_cycle(void)
 * @brief		MODULE POWER ON, Power cycles the module
 * @param[in]	none
 * @param[out]	none
 * @return		errCode
 *				-1 = Error
 *				0  = OK
 * @description This API is used to power cycle the module. 
 * This API is valid only if there is a power gate, external to the module, 
 * which is controlling the power to the module using a GPIO signal of the MCU.
 */
int16 rsi_module_power_cycle(void)
{
		FM4_GPIO->PDOR1_f.P11 = 0u;				//@ P11   power ON module before issuing reset
	delay(20); 
  wifi_reset_routine(); // spi.c 
   return 0;
}

/*===========================================================*/
/**
 * @fn			void config_gpio_output(uint8 value)
 * @brief		Configures gpio pin in output mode,with a value
 * @param[in]	uint8 value, value to be configures
 * @param[out]	none
 * @return		errCode
 *				-1 = Error
 *				0  = OK
 * @description This API is used to configure host gpio pin in output mode.
 */
void config_gpio_output(uint8 value)
{
  /* Sets gpio pin in output mode */
}

/*===========================================================*/
/**
 * @fn			void config_gpio_input(void)
 * @brief		Configures gpio pin in input mode
 * @param[in]	none
 * @param[out]	none
 * @return		errCode
 *				-1 = Error
 *				0  = OK
 * @description This API is used to configure host gpio pin in input mode.
 */
void config_gpio_input(void)
{
  /* Sets gpio pin in input mode */
}

/*===========================================================*/
/**
 * @fn			uint8 get_gpio_value()
 * @brief		Gets the gpio value
 * @param[in]	 none
 * @param[out] none
 * @return		errCode
 *				-1 = Error
 *				0  = OK
 * @description This API is used to gets the host gpio value.
 */
uint8 get_gpio_value()
{
  /* return gpio value*/
  return 0;
}
