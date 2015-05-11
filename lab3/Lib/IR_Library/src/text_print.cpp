/**
 * @file     text_print.cpp
 * @version  1.0
 * @date     2014-Oct-21
 *
 * Copyright(C) Redpine Signals 2013
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief text_print: Fills the characters to the buffer based on received IR remote HEX codes
 *
 * @section Description :fills the buffer with characters and , updates the buffer length to pointer to a length variable
 *
 *
 * @section Improvements :
 *
 */


/*
 * Includes
 */
#include "text_print.h"
#include "IRremote.h"
//#include <Calbee_kit.h>
#include "IRremoteInt.h"
#include <dt.h>

#define CALBEE_REV_2 0
#define CALBEE_REV_5 1
#include <IRremote.h>

static const stc_dt_channel_config_t stcDtChannelConfig_timer2 = {
	    DtPeriodic,         // Periodic mode
	    DtPrescalerDiv1,  // Prescaler dividor f/1
	    DtCounterSize32     // 32bits counter size
};

          IRrecv           irrecv;
          decode_results   results;
          uint32_t         lastTick = 0;
volatile  uint32_t         time     = 0;
          int8_t           lastChar = '\0';
          uint8_t          nextChar = 1;
          //int32_t          next     = 0;


          int8_t           one[]    = {'1','_','-','&'};
			 int8_t           two[] 	= {'a', 'b', 'c', 'A', 'B', 'C', '2'};
			 int8_t           three[]	= {'d', 'e', 'f', 'D', 'E', 'F', '3'};
			 int8_t           four[] 	= {'g', 'h', 'i', 'G', 'H', 'I', '4'};
			 int8_t           five[]   = {'j', 'k', 'l', 'J', 'K', 'L', '5'};
			 int8_t           six[]    = {'m', 'n', 'o', 'M', 'N', 'O', '6'};
			 int8_t           seven[]  = {'p', 'q', 'r', 's', 'P', 'Q', 'R', 'S', '7'};
			 int8_t           eight[]  = {'t', 'u', 'v', 'T', 'U', 'V', '8'};
			 int8_t           nine[]   = {'w', 'x', 'y', 'z', 'W', 'X', 'Y', 'Z', '9'};
			 int8_t           zero[]   = {' ', '0'};

char decodeInput(char *rev_value, char *next)
{
	       int32_t   retval;
	       int32_t   x;
	static int32_t   position;
	       //int32_t   line_status;
	
	
	retval = irrecv.decode(&results);
	if(retval)
	{
		x=1;
#if CALBEE_REV_2
		FM4_GPIO->PDOR5_f.P50 = 0u;				//@ P52   HIGH
#endif
#if CALBEE_REV_5
		FM4_GPIO->PDOR4_f.P44 = 0u;				//@   HIGH
#endif
		*next = 0;
		//line_status=0;
		if ((time - lastTick) > 800)
		{
			*next = 1;
			//line_status=1;
		}
		switch (results.value){
		//read systick value hurr
		case UP_ARROW:
			//up
			lastTick = time;
			*rev_value= '\a';
			break;
		case DOWN_ARROW:
			//down
			lastTick = time;
			*rev_value= '\b';
			break;
		case LEFT_ARROW:
			//left
			lastTick = time;
			*rev_value= '\t';
			break;
		case RIGHT_ARROW:
			//right
			lastTick = time;
			*rev_value= '\n';
			break;
		case NUM_KEY_1:
			//1
			lastTick = time;
			if (!(*next) && lastChar == '1'){
				position = ++position % 4;
			}
			else{
				*next = 1;
				position = 0;
			}
			lastChar = '1';
			*rev_value= one[position];
			break;
		case NUM_KEY_2:
			//2
			lastTick = time;
			if (!(*next) && lastChar == '2'){
				position = ++position % 7;
			}
			else{
				*next = 1;
				position = 0;
			}
			lastChar = '2';
			*rev_value= two[position];
			break;
		case NUM_KEY_3:
			//3
			lastTick = time;
			if (!(*next) && lastChar == '3'){
				position = ++position % 7;
			}
			else{
				*next = 1;
				position = 0;
			}

			lastChar = '3';
			*rev_value= three[position];
			break;
		case NUM_KEY_4:
			//4
			lastTick = time;
			if (!(*next) && lastChar == '4'){
				position = ++position % 7;
			}
			else{
				*next = 1;
				position = 0;
			}
			lastChar = '4';
			*rev_value= four[position];
			break;
		case NUM_KEY_5:
			//5
			lastTick = time;
			if (!(*next) && lastChar == '5'){
				position = ++position % 7;
			}
			else{
				*next = 1;
				position = 0;
			}

			lastChar = '5';
			*rev_value= five[position];
			break;
		case NUM_KEY_6:
			//6
			lastTick = time;
			if (!(*next) && lastChar == '6'){
				position = ++position % 7;
			}
			else{
				*next = 1;
				position = 0;
			}

			lastChar = '6';
			*rev_value= six[position];
			break;
		case NUM_KEY_7:
			//7
			lastTick = time;
			if (!(*next) && lastChar == '7'){
				position = ++position % 9;
			}
			else{
				*next = 1;
				position = 0;
			}

			lastChar = '7';
			*rev_value= seven[position];
			break;
		case NUM_KEY_8:
			//8
			lastTick = time;
			if (!(*next) && lastChar == '8'){
				position = ++position % 7;
			}
			else{
				*next = 1;
				position = 0;
			}

			lastChar = '8';
			*rev_value= eight[position];
			break;
		case NUM_KEY_9:
			//9
			lastTick = time;
			if (!(*next) && lastChar == '9'){
				position = ++position % 9;
			}
			else{
				*next = 1;
				position = 0;
			}

			lastChar = '9';
			*rev_value= nine[position];
			break;
		case NUM_KEY_0:
			//0
			lastTick = time;
			if (!(*next) && lastChar == '0'){
				position = ++position % 2;
			}
			else{
				*next = 1;
				position = 0;
			}

			lastChar = '0';
			*rev_value= zero[position];
			break;
		case ENTER:
			lastTick = time;
			*rev_value= '\v';
			//ok-enter
			break;
		case DELETE:
			lastTick = time;
			*rev_value= '\f';
			//delete
			break;
		default:

			break;
		}
		
		irrecv.resume(); // Receive the next value
		return x;
	}
	
#if CALBEE_REV_2
	FM4_GPIO->PDOR5_f.P50 = 1u;				//@ P52   HIGH
#endif
	
#if CALBEE_REV_5
	FM4_GPIO->PDOR4_f.P44= 1u;				//@ P52   HIGH.
#endif
	
	x=0;
	return x;
}

void ir_timer_init(void)
{
	if (Ok != Dt_Init((stc_dt_channel_config_t*)&stcDtChannelConfig_timer2, DtChannel1))
	{
		while(1); // init error
	}
	// Write load value for channel 1
	Dt_WriteLoadVal(80400, DtChannel1);  //80400----> 1ms
	Dt_EnableInt(Dt1Callback, DtChannel1);
	Dt_EnableCount(DtChannel1);

}

//static int a;

 void Dt1Callback(void)
{
	//extern int checkMessage;
	//extern int startMessagePolling;
  

    Dt_ClrIntFlag(DtChannel1);    // Clear Irq
    time++;

    /*if (time % 10000 == 0 && startMessagePolling){
    	checkMessage = 1;
    }*/
		
}
