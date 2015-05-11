/**
 * @file     rsi_buildHttpExtendedHeader.c
 * @version  2.7
 * @date     2012-Sep-12
 *
 * Copyright(C) Redpine Signals 2012
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief rsi_buildHttpExtendedHeader : Function to builds the user http header for http post and get.
 *
 * @section Description
 * This file contains the Store Configuration Enable/Disable function.
 *
 *
 */

/**
 * Includes
 */
#include "rsi_global.h"
#include <string.h>

/*==============================================*/
/**
 * @fn          void rsi_buildHttpExtendedHeader(uint8 *http_header)
 * @brief       User configurable Extended http header 
 * @param[in]   uint8 uint8 *http_header
 * @param[out]  none
  *
 * @section description
  * To build the user configurable http header.user can add http header fields.
 */

void rsi_buildHttpExtendedHeader(uint8 *http_header)
{

  strcat((char *)http_header ,"User-Agent: curl/7.30.0\r\n");
  strcat((char *)http_header ,"Accept: */*\r\n");
  strcat((char *)http_header ,"Content-Type: application/x-www-form-urlencoded\r\n");

}


