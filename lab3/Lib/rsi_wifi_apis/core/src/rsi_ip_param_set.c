/**
 * @file       rsi_ip_param_set.c
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
 * @brief IP PARAMETERS: Function to set Network parameters, IP Address, Port Number.
 *
 * @section Description
 * This file contains the TCPIP function.
 *
 *
 */


/**
 * Includes
 */
#include "rsi_global.h"


/*===============================================*/
/**
 * @fn          int16 rsi_ip_param_set(rsi_uIpparam *uIpparamFrame)
 * @brief       Sends the IPCONFIG (TCP/IP configure)command to the Wi-Fi module
 * @param[in]   rsi_uIpparam *uIpparamFrame, pointer to ip configuration stucture
 * @param[out]  none
 * @return      errCode
 *              -2 = Command execution failed
 *              -1 =  Buffer Full
 *              0  = SUCCESS
 * @section description  
 * This API is used to configure the IP address, Subnet Mask 
 * and Gateway IP address for the module in manual mode or DHCP mode. 
 * The Wi-Fi module should be successfully connected to an Access point 
 * (using the rsi_join API) before calling this API. If DHCP mode is enabled, then 
 * it has to be ensured that a DHCP server is present in the network.
 * 
 * @section prerequisite 
 * rsi_join should be done successfully
 */
int16 rsi_ip_param_set(rsi_uIpparam *uIpparamFrame)
{
  int16            retval;

  //! frame sent to set the IP parameters
#ifdef RSI_DEBUG_PRINT
  RSI_DPRINT(RSI_PL3,"\r\n\n IPconfiguration Start");
#endif

  retval = rsi_execute_cmd((uint8 *)rsi_frameCmdIpparam,(uint8 *)uIpparamFrame,sizeof(rsi_uIpparam));
  return retval;
}



