/**
 * @file     spi.h
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief : this file contains the function prototypes of Wifi SPI channel
 *
 * @section Description :
 *
 *
 * @section Improvements :
 *
 */


/*
 * Includes
 */
#ifndef _SPI_H_
#define _SPI_H_



#include "stdio.h"
#include "stdint.h"
#include "rsi_global.h"
#include "rsi_app.h"
#include "exint.h"
#include "gpio.h"
#include "rsi_api.h"



#ifdef __cplusplus
extern "C" {
#endif


static void wifi_cs_enable(void);

static void wifi_cs_disable(void);

void wifi_reset_routine (void);

void WyzBee_spi_init(void);

void wifi_module_init (void);

void power_on(void);


#ifdef __cplusplus
}
#endif
#endif
