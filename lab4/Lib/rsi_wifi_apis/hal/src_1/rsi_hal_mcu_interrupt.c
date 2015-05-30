/**
 * @file     rsi_hal_mcu_interrupt.c
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
 * @brief HAL INTERRUPT: Functions related to HAL Interrupts
 * 
 * @section Description
 * This file contains the list of functions for configuring the microcontroller interrupts. 
 * Following are list of API's which need to be defined in this file.
 *
 */
#include "UsbDeviceCdcCom.h"

/**
 * Includes
 */

#include "rsi_global.h"
#include <rsi_global.h>
#include <rsi_app.h>
#include "mfs.h"
#include <exint.h>
#include <gpio.h>
#include <rsi_api.h>


#define  RSI_SPI_INTR_NBR     7

/*===================================================*/
/**
 * @fn			void Intr_isr(void)
 * @brief		Starts and enables the SPI interrupt
 * @param[in]	none
 * @param[out]	none
 * @return		none
 * @description This HAL API should contain the code to initialize the register related to interrupts.
 */

uint32_t  irq_count;
extern    rsi_app_cb_t  rsi_app_cb;
void  Intr_isr (void)
{
	Exint_DisableChannel(RSI_SPI_INTR_NBR);
	irq_count++;
	rsi_app_cb.pkt_pending = RSI_TRUE;
//	UsbDeviceCdcCom_SendDec("IN ISR");
	//UsbDeviceCdcCom_SendString("\r\n");

	//TODO:

	return;
}

/*===================================================*/
/**
 * @fn			void rsi_irq_start(void)
 * @brief		Starts and enables the SPI interrupt
 * @param[in]	none
 * @param[out]	none
 * @return		none
 * @description This HAL API should contain the code to initialize the register related to interrupts.
 */
void rsi_irq_start(void)
{
		stc_exint_config_t stcExtIntConfig;

  PDL_ZERO_STRUCT(stcExtIntConfig);

  stcExtIntConfig.abEnable[RSI_SPI_INTR_NBR] = TRUE;   // INT7
  stcExtIntConfig.aenLevel[RSI_SPI_INTR_NBR] = ExIntHighLevel;  //ExIntFallingEdge;
  stcExtIntConfig.apfnExintCallback[RSI_SPI_INTR_NBR] = &Intr_isr;


  // Set pin function before enabling external interrupt channel!
//  SetPinFunc_INT14_1(0u); 	        // Pin Function: INT14_1 // previous interrupt line
  //SetPinFunc_INT07_1(dummy);
	SetPinFunc_MADATA07_0(0u);

  Exint_Init(&stcExtIntConfig);
  Exint_EnableChannel(RSI_SPI_INTR_NBR);

	return;
}


/*===================================================*/
/**
 * @fn			void rsi_irq_disable(void)
 * @brief		Disables the SPI Interrupt
 * @param[in]	none
 * @param[out]	none
 * @return		none
 * @description This HAL API should contain the code to disable interrupts.
 */
void rsi_irq_disable(void)
{
	Exint_DisableChannel(RSI_SPI_INTR_NBR);
}


/*===================================================*/
/**
 * @fn			void rsi_irq_enale(void)
 * n
 * @brief		Enables the SPI interrupt
 * @param[in]   none	
 * @param[out]	none
 * @return		none
 * @description This HAL API should contain the code to enable interrupts.
 */
void rsi_irq_enable(void)
{
	Exint_EnableChannel(RSI_SPI_INTR_NBR);
}



/*===================================================*/
/**
 * @fn			void rsi_irq_clear_pending(void)
 * @brief		Clears the pending SPI interrupt
 * @param[in]	none
 * @param[out]	none
 * @return		none
 * @description This HAL API should contain the code to clear the handled interrupts.
 */
void rsi_irq_clear_pending(void)
{
    FM4_EXTI->EICL &= (0xFFFFFFFFu ^ (1u << RSI_SPI_INTR_NBR));
}


/*===================================================*/
/**
 * @fn			    void rsi_irq_status(void)
 * n
 * @brief		    Checks the SPI interrupt
 * @param[in]   none	
 * @param[out]	uint8, interrupt status
 * @return		  none
 * @description This API is used to check pending interrupts.
 */
uint8 rsi_irq_status(void)
{
	FM4_INTREQ->IRQ018MON_f.EXTINT;
  return 0;
}

