/**
 * @file       rsi_gpio_config.c
 * @version    3.6
 * @date       2013-May-15
 *
 * Copyright(C) Redpine Signals 2013
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief GPIO Config: Function to configure GPIOs
 *
 * @section Description
 * This file contains the API for configuring GPIOs. This can be used to configure
 * the particular GPIOs only.
 *
 */




/**
 * Includes
 */
#include "rsi_global.h"

/**
 * Global Variables
 */
/*====================================================*/
/**
 * @fn        void rsi_req_wakeup(void)
 * @brief     set wakeup gpio high. 
 * @param[in] none
 * @return    none
 * @section description
 * This HAL API is used to set wakeup gpio high and waits for wakeup confirmation pin to get set.
 */
void rsi_req_wakeup(void)
{
  config_gpio_output(1);
  config_gpio_input();
  while(1){
#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"Checking for value\r\n");
#endif
    if(get_gpio_value())
    {
#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"Module Awake\r\n");
#endif
      break;
    }
  }
  return;
  
}
/*====================================================*/
/**
 * @fn         void rsi_wait4wakeup(void)
 * @brief      wait to get wakeup status to get set by module. 
 * @param[in]  none
 * @return     none
 * @description 
 * This HAL API is used to set wakeup gpio high and waits for wakeup confirmation pin to get set.
 */
void rsi_wait4wakeup(void)
{
  config_gpio_input();
  while(1){
#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"Checking for value\r\n");
#endif
    if(get_gpio_value())
    {
#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"Module Awake\r\n");
#endif
      break;
    }
  }
  config_gpio_output(1);
  return;
}

/*====================================================*/
/**
 * @fn        void rsi_allow_sleep(void)
 * @brief     set wakeup gpio low. 
 * @param[in] none
 * @return    none
 * @description 
 * This HAL API is used to set wakeup gpio low .
 */
void rsi_allow_sleep(void)
{
  config_gpio_output(0);
}

