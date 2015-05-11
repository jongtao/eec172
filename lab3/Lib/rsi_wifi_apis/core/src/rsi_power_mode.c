/**
 * @file       rsi_power_mode.c
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
 * @brief POWER MODE: Sets the POWER MODE 
 * This file contains the Power Mode setting function.
 *
 *
 */


/**
 * Includes
 */
#include "rsi_global.h"
#ifdef LINUX_PLATFORM
#include "rsi_nl_app.h"
#include "rsi_wireless_copy.h"
#include <sys/ioctl.h>
#endif


/**
 * Global Variables
 */
volatile rsi_powerstate rsi_pwstate;


/*===========================================================================*/
/**
 * @fn             int16 rsi_power_mode(uint8 powerMode)
 * @brief          Sends the SPI POWER MODE command to the Wi-Fi module
 * @param[in]      uint8 powerMode, power mode value  
 * @param[out]     none
 * @return         errCode
 *                 -2 = Command execution failure
 *                 -1 = Buffer Full
 *                 0  = SUCCESS
 *
 * @section description 
 * This API is used to set different power save modes of the module. Please 
 * refer to the Software Programming Reference Manual for more information on 
 * these modes. This API should be called only after rsi_init API.
 * 
 * @section prerequisite  
 * Init command should be complete before this command.
 */
int16 rsi_power_mode(uint8 powerMode)
{
  int16            retval;
  rsi_uPower      uPowerFrame;
  uPowerFrame.powerFrameSnd.powerVal = powerMode;
#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\r\n\nPower save command");
#endif
#ifdef LINUX_PLATFORM
  rsi_linux_app_cb_t *linux_app_cbPtr = &rsi_linux_app_cb;
  retval = rsi_ioctl_send_req(linux_app_cbPtr->ioctl_sd, 0, 0, OID_WSC_POWER_SAVE_ENABLE);
#else 

#if (RSI_POWER_MODE == RSI_POWER_MODE_2)
  if(powerMode == 0)
  {
    rsi_app_cb.power_save_enable = 0;
  }
  else
  {
    rsi_app_cb.power_save_enable = 1;
  }
#endif
#endif
  retval = rsi_execute_cmd((uint8 *)rsi_frameCmdPower,(uint8 *)&uPowerFrame,sizeof(rsi_uPower));
  return retval;
}

#if 0
/*===========================================================================*/
/**
 * @fn          int16 rsi_pwr_save_continue(void)
 * @brief       To move the module to full power save mode.
 * @param[in]   none
 * @param[out]  none
 * @return      errCode
 *              0  = OK
 * @section Description
 * This API is used to move the module back to full power save mode after the 
 * data/command packets are transmitted by the application.
 *
 * @section prerequisite  
 * should use only for power save mode. 
 */
int16 rsi_pwr_save_continue(void)
{
  uint8 sleep_confirm_array[4]={0};
  uint8 localBuf[4];
  int16 retval;

  sleep_confirm_array[3] = PS_CONFIRM;

    /* wait for ready signal to go low */
  while(SPI_READY_VAL != RSI_FALSE);

  /* Send power save confirm for the host,
   * Ack for sleep msg from module 
   */
  retval = rsi_spi_send(sleep_confirm_array, 4, localBuf);

  if(retval == 0)
  {
    rsi_pwstate.ack_sent = 1;
    rsi_pwstate.sleep_received = 0;
  }

  return retval;
}
#endif
