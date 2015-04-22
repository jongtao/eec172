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
*                                         GPIO Driver Header File
*
* File           : WyzBee_gpio.h
* Version        : V1.00
* Programmer(s)  :
*********************************************************************************************************
* Note(s)        :
*********************************************************************************************************
*/


#ifndef  WyzBee_GPIO_H
#define  WyzBee_GPIO_H


/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/


#include <gpio.h>


/*
*********************************************************************************************************
*                                                 DEFINES
*********************************************************************************************************
*/


											/*  GPIO INTERFACE GPIO, PORT NUMBERS AND CORRESPONDING HEADER PINS  ON WyzBee REVISION 4 BOARD  */




											            /*	TRI LED INTERFACE     */
#define       GPIO_LED2 		  42 					//PORT  P42
#define       GPIO_LED3 		  43 					//PORT  P43
#define       GPIO_LED4 		  44 					//PORT  P44

											            /*  GPIO  INTERFACE       */
#define       GPIO_2 			  12 					//PORT  P12  J2-11
#define       GPIO_1 			  13 				    //PORT  P13  J3-7


											            /*	I2C  INTERFACE        */
#define       GPIO_I2CSDA 	      06	 				//PORT  P06  J2-13
#define       GPIO_I2CSCL 	      07	 				//PORT  P07  J2-12

											            /*  UART  INTERFACE       */
#define       GPIO_UART2IN 	31	 				        //PORT  P31  J3-5
#define       GPIO_UART2OUT 	  32	 				//PORT  P32  J3-4

											            /*  PWM  INTERFACE        */
#define       GPIO_PWM2 	      40	 				//PORT  P40  J3-13
#define       GPIO_PWM1 	      41	 				//PORT  P41  J3-12

											            /*  SPI  INTERFACE        */
#define       GPIO_SPI2CS         51	 				//PORT  P51  J3-11
#define       GPIO_SPI2CLK        52	 				//PORT  P52  J3-10
#define       GPIO_SPI2MOSI       53	 				//PORT  P53  J3-8
#define       GPIO_SPI2MISO       54	 				//PORT  P54  J3-9

											            /*   ADC  INTERFACE       */
#define       GPIO_ADC1           19	 				//PORT  P19  J3-6


														/*   DEFINES FOR GPIO PIN DIRECTION  */
#define       GPIO_OUTPUT         1u
#define       GPIO_INPUT          0u

										    			/*   DEFINES FOR GPIO DATA           */
#define       GPIO_HIGH           1u
#define       GPIO_LOW    	      0u


														/*  WyzBee GPIO MACROS DEFINITIONS    */






#define       WyzBeeGpio_Get(port)               GPIO_EVALUATOR(GPIO1PIN_P, port, _GET)
#define       WyzBeeGpio_Put(port, value)        GPIO_EVALUATOR(GPIO1PIN_P, port, _PUT( value ))
#define       WyzBeeGpio_InitOut(port, pullup)   GPIO_EVALUATOR2(Gpio1pin_InitOut, GPIO1PIN_P, port, Gpio1pin_InitVal( pullup ))
#define       WyzBeeGpio_InitIn(port, value)     GPIO_EVALUATOR2(Gpio1pin_InitIn,  GPIO1PIN_P, port, Gpio1pin_InitPullup( value ))

#define       WyzBeeGpio_Init(port,dir,value)   {if(dir){GPIO_EVALUATOR2(Gpio1pin_InitOut, GPIO1PIN_P, port, Gpio1pin_InitVal( value ));} \
                                                      else GPIO_EVALUATOR2(Gpio1pin_InitIn,  GPIO1PIN_P, port, Gpio1pin_InitPullup( value ));}




/*
*********************************************************************************************************
*                                               DATA TYPES
*********************************************************************************************************
*/





/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/





/*
*********************************************************************************************************
*                                           END
*********************************************************************************************************
*/


#endif // WyzBee_GPIO__H
