/**
 * @file     TimerInit.c
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief 	: This file contains Spansion's Dual timer initialization functions and timer dual_timer0_init
 *
 * @section Description :
 *
 * @section Improvements :
 *
 */


/*
 * Includes
 */
#include "TimerInit.h"
#include "IRremoteInt.h"
#include "stdint.h"
#include "dt.h"


/* initializing the timer init structure these parameters were used by the dual timer init function */
static const stc_dt_channel_config_t stcDtChannelConfig_timer = {
  DtPeriodic,         // Periodic mode
  DtPrescalerDiv1,  // Prescaler dividor f/256
  DtCounterSize32     // 32bits counter size
};

/*===================================================*/
/**
 * @fn			void timer_init(void)
 * @brief		this function initializes the dual timer
 * @param[in]	none
 * @param[out]	none
 * @return		none
 * @description This API should contain the code that will initializes the dual timer with the required timer reload value.
 */
void dual_timer0_init(uint32_t  timer_rl_val)
{
  // Initialize dual timer channel 0
  if (Ok != Dt_Init((stc_dt_channel_config_t*)&stcDtChannelConfig_timer, DtChannel0)) // init function for dual timer
  {
    while (1); // init error
  }
  // Write load value for channel 0
  Dt_WriteLoadVal(timer_rl_val, DtChannel0);  //4020----> 50us // timer reload value
  Dt_EnableInt(Dt0Callback, DtChannel0); //  timer interrupt call back registration
  Dt_EnableCount(DtChannel0); // enable timer counter
}


/*===================================================*/
/**
 * @fn			void Dt0Callback(void)
 * @brief		thus is a call back function which is invoked for every timer interrupt typically every 50us
 * @param[in]	none
 * @param[out]	none
 * @return		none
 * @description This API should contain the code / function call which will handle the corresponding timer interrupt.
 */
void Dt0Callback(void)
{
  Dt_ClrIntFlag(DtChannel0);    // Clear Irq
  Ir_Isr_receive();  // IR reciever ISR
}


/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
