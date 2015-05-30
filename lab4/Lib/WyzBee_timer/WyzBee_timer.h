/*
*********************************************************************************************************
*
*                (c) Copyright 2015 Redpine Signals
*                                           All rights reserved.
*
*               This file is protected by international copyright laws. This file can only be used in
*               accordance with a license and should not be redistributed in any way without written
*               permission by Redpine Signals.
*
*                                            www.redpinesignals.com
*
**************************************************************************************************************
*/


/*
*********************************************************************************************************
*
*                                        Timer Driver Header File
*
* File           : WyzBee_timer.h
* Version        : V1.00
* Programmer(s)  :
*********************************************************************************************************
* Note(s)        :
*********************************************************************************************************
*/


#ifndef  WyzBee_TIMER_H
#define  WyzBee_TIMER_H


/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/

#include   <WyzBee.h>
#include   <dt.h>



/*
*********************************************************************************************************
*                                                 DEFINES
*********************************************************************************************************
*/

typedef       en_result_t             Error_Value;
typedef       dt_cb_func_ptr_t        timer_callback;



/*
*********************************************************************************************************
*                                               DATA TYPES
*********************************************************************************************************
*/

typedef enum en_WyzBee_dt_mode             	/*-------------DUAL TIMER MODE----*/
{
    Dt_FreeRun      = 0,  						// Free-running mode
    Dt_Periodic     = 1,  						// Periodic mode
    Dt_OneShot      = 2   						// One-shot mode
} en_WyzBee_dt_mode_t;


typedef enum en_WyzBee_dt_prescaler        	/*-------------DUAL TIMER PRESCALER----*/
{
    Dt_PrescalerDiv1     = 0,  					// Prescaler divisor 1
    Dt_PrescalerDiv16    = 1,  					// Prescaler divisor 16
    Dt_PrescalerDiv256   = 2   					// Prescaler divisor 256
} en_WyzBee_dt_prescaler_t;

typedef enum en_WyzBee_dt_countersize           /*-------------DUAL TIMER COUNTER SIZE----*/
{
    Dt_CounterSize16     = 0,  					// 16 Bit counter size
    Dt_CounterSize32     = 1   					// 32 Bit counter size
} en_WyzBee_dt_countersize_t;


typedef enum en_WyzBee_dt_channel            /*-------------DUAL TIMER CHANNEL----*/
{
    Dt_Channel0     = 0,  						// channel 0
    Dt_Channel1     = 1,  						// channel 1
    Dt_MaxChannels  = 2   						// Number of channels
} en_WyzBee_dt_channel_t;


typedef struct WyzBee_DualTimer_config          /*-------------DUAL TIMER STRUCTURE CONFIG----*/
{
  uint8_t u8Mode;           					// Mode, see description of #en_dt_mode_t
  uint8_t u8PrescalerDiv;   					// Prescaler, see description of #en_dt_prescaler_t
  uint8_t u8CounterSize;    					// Counter size, see description of #en_dt_countersize_t
} WyzBee_DualTimer_config_t;








/*
*********************************************************************************************************
*                                         LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/

static  WyzBee_DualTimer_config_t Dual_Timer;


/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/



err_t WyzBeeDualTimer_Init(WyzBee_DualTimer_config_t dual_timer, uint8_t ch_num);

err_t WyzBeeDualTimer_LoadTime(uint32_t count, uint8_t ch_num);

err_t WyzBeeDualTimer_Attach_Callback(timer_callback cb_Fn, uint8_t ch_num);







/*
*********************************************************************************************************
*                                           END
*********************************************************************************************************
*/


#endif // WyzBee_TIMER__H
