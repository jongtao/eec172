/**
 * @file     text_print.h
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
 * @brief text_print: this file contains defines of the Samsung remote HEX codes, and function prototypes of text_print.cpp
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
#ifndef __TEXT_PRINT_H__
#define __TEXT_PRINT_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>



void     caps            (void);
void     small           (uint8_t *buf , uint16_t *k);
uint8_t  num             (void);
char     decodeInput     (char *rev_value, char *pos);
void     ir_timer_init   (void);
void     Dt1Callback     (void);
char     IR_in           (void);

//extern int32_t line_status;
//extern int8_t  lastChar;
//extern int32_t next;
//#define SAMSUNG_REMOTE
#define AT_T_REMOTE


#ifdef  AT_T_REMOTE
/* navigational keys*/
#define 	UP_ARROW 		0x02BDC837   //45991991	// UP 		ARROW KEY
#define 	RIGHT_ARROW		0x02BD6897   //45967511	// RIGHT 	ARROW KEY
#define 	DOWN_ARROW		0x02BD28D7   //45951191	// DOWN 	ARROW KEY
#define 	LEFT_ARROW		0x02BDA857   //45983831	// LEFT 	ARROW

/* special keys */
#define 	OK				   0x02BDE817   //46000151 	// OK 	KEY
#define 	INFO			   0xE0E0F807	 //INFO KEY

/* level control keys*/
#define VOL_P 			   0xE0E0E01F	// VOLUME 	UP 		KEY +
#define VOL_M 			   0xE0E0D02F	// VOLUME 	DOWN 	KEY -
#define CH_P 			   0xE0E048B7	// CHANNEL 	UP 		KEY +
#define CH_M 			   0xE0E008F7	// CHANNEL 	DOWN 	KEY -

/* channel specific keys */
#define MUTE		      0xE0E0F00F // MUTE
#define LAST			   0xE0E0C837 // LAST

/* numerical keys */
#define NUM_KEY_1				0x02BD807F    //45973631
#define NUM_KEY_2				0x02BD40BF    //45957311 // A B C
#define NUM_KEY_3				0x02BDC03F    //45989951 // D E F
#define NUM_KEY_4 			0x02BD20DF    //45949151 // G H I
#define NUM_KEY_5  			0x02BDA05F    //45981791 // J K L
#define NUM_KEY_6  			0x02BD609F    //45965471 // M N O
#define NUM_KEY_7 			0x02BDE01F	  //45998111 // P Q R S
#define NUM_KEY_8 			0x02BD10EF	 //	45945071 // T U V
#define NUM_KEY_9 			0x02BD906F	 //	45977711 // W X Y Z
#define NUM_KEY_0 			0x02BD00FF	 //	45940991 // SPACE

/* special keys */
#define DELETE			0x02BD58A7   //45963431 // DELETE
#define ENTER 			0x02BDE817   //46000151 // ENTER
#define MENU			0xE0E058A7 // MENU

#endif

#ifdef SAMSUNG_REMOTE

/* navigational keys*/
#define 	UP_ARROW 		0xE0E006F9	// UP 		ARROW KEY
#define 	RIGHT_ARROW		0xE0E046B9	// RIGHT 	ARROW KEY
#define 	DOWN_ARROW		0xE0E08679	// DOWN 	ARROW KEY
#define 	LEFT_ARROW		0xE0E0A659	// LEFT 	ARROW

/* special keys */
#define 	OK				0xE0E016E9 	// OK 	KEY
#define 	INFO			0xE0E0F807	// INFO KEY

/* level control keys*/
#define VOL_P 			0xE0E0E01F	// VOLUME 	UP 		KEY +
#define VOL_M 			0xE0E0D02F	// VOLUME 	DOWN 	KEY -
#define CH_P 			0xE0E048B7	// CHANNEL 	UP 		KEY +
#define CH_M 			0xE0E008F7	// CHANNEL 	DOWN 	KEY -

/* channel specific keys */
#define MUTE			0xE0E0F00F // MUTE
#define LAST			0xE0E0C837 // LAST

/* numerical keys */
#define NUM_KEY_1				0xE0E020DF
#define NUM_KEY_2				0xE0E0A05F // A B C
#define NUM_KEY_3				0xE0E0609F // D E F
#define NUM_KEY_4 				0xE0E010EF // G H I
#define NUM_KEY_5  				0xE0E0906F // J K L
#define NUM_KEY_6  				0xE0E050AF // M N O
#define NUM_KEY_7 				0xE0E030CF // P Q R S
#define NUM_KEY_8 				0xE0E0B04F // T U V
#define NUM_KEY_9 				0xE0E0708F // W X Y Z
#define NUM_KEY_0 				0xE0E08877 // SPACE

/* special keys */
#define DELETE			0xE0E0926D // DELETE
#define ENTER 			0xE0E016E9 // ENTER
#define MENU			0xE0E058A7 // MENU

#endif


#ifdef __cplusplus
}
#endif
   
#endif // __TEXT_PRINT__



/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
