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
*                                        Timer Driver Source File
*
* File           : WyzBee_timer.c
* Version        : V1.00
* Programmer(s)  :
*********************************************************************************************************
* Note(s)        :
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/

#ifdef __cplusplus
extern "C"{
#endif
#include  <WyzBee_timer.h>




/*
*********************************************************************************************************
*                                              LOCAL DEFINES
*********************************************************************************************************
*/




/*
*********************************************************************************************************
*                                             LOCAL CONSTANTS
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                            LOCAL DATA TYPES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                         LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/





/*
*********************************************************************************************************
*                                         GLOBAL VARIABLES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                        LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                             GLOBAL FUNCTIONS
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           WyzBeeDualTimer_Init
*
* Description :Initializes the Dual timer with the reload value
*
* Argument(s) :dual_timer dual timer configuration structure
*             :ch_num  channel number of dual timer
*
* Return(s)   :error value
*
* Caller(s)   :
*
* Note(s)     :
*********************************************************************************************************
*/


err_t WyzBeeDualTimer_Init(WyzBee_DualTimer_config_t dual_timer, uint8_t ch_num)
{

		 stc_dt_channel_config_t  dt_Internal;
		 err_t err;

	     dt_Internal.u8Mode = 				dual_timer.u8Mode;
	     dt_Internal.u8PrescalerDiv = 		dual_timer.u8PrescalerDiv;
	     dt_Internal.u8CounterSize = 		dual_timer.u8CounterSize;

	     err = Dt_Init(&dt_Internal,ch_num);
	     if(err == Ok) return ERR_NONE;
	     else return ERR_INVALID_PARMS;


}




/*
*********************************************************************************************************
*                                          WyzBeeDualTimer_LoadTime()
*
* Description :loads the time value for the dual timer
*
* Argument(s) :time value in micro seconds to be loaded
* 			  :ch_num channel number of dual timer
*
* Return(s)   :error value
*
* Caller(s)   :
*
* Note(s)     :Master clock HCLK = 160 MHz, PCLK  =  80 MHz,
*             :Timer Clock is initialized to 5 MHz
*             :time value in microseconds, For Prescaler Division 16, clock duration is 0.2us.
*             ;For 1us duration count of 5 to be loaded.
*             ;time value of 1us to more than 1 sec can be loaded.
*********************************************************************************************************
*/

err_t WyzBeeDualTimer_LoadTime(uint32_t time, uint8_t ch_num)
{

	     err_t err;
	     float32_t count_Internal,t1,t2;

   	 	 count_Internal = time;
   	 											//														    /*  Write load value for given channel	*/
	     err = Dt_WriteLoadVal(time, ch_num);
	     if(err == Ok) return ERR_NONE;
	     else return ERR_INVALID_PARMS;
}






/*
*********************************************************************************************************
*                                          WyzBeeDualTimer_Atach_Callback()
*
* Description :Initializes callback function for the dual timer
*
* Argument(s) :cb_fn  callback function to be attached to the dual timer
* 			  :ch_num channel number of dual timer
*
* Return(s)   :error value
*
* Caller(s)   :
*
* Note(s)     :
*********************************************************************************************************
*/

err_t WyzBeeDualTimer_Attach_Callback(timer_callback cb_Fn, uint8_t ch_num)
{

	     err_t err;

	     err = Dt_EnableInt(cb_Fn, ch_num); 							//  timer interrupt call back registration

	     if(err == Ok)
	     {

	     }
	     else return ERR_INVALID_PARMS;

	     err = Dt_EnableCount(ch_num); 									// enable timer counter
	     if(err == Ok) return ERR_NONE;
	     else return ERR_INVALID_PARMS;
}

#ifdef __cplusplus
}
#endif
