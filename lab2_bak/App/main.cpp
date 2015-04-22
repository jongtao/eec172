/*
 *********************************************************************************************************
 *
 *                        (c) Copyright 2015-2020 RedPine Signals Inc. HYDERABAD, INDIA
 *                                            All rights reserved.
 *
 *               This file is protected by international copyright laws. This file can only be used in
 *               accordance with a license and should not be redistributed in any way without written
 *               permission by Redpine Signals.
 *
 *                                            www.redpinesignals.com
 *
 *********************************************************************************************************
 */
 /*
 *********************************************************************************************************
 *
 *											  main file
 *
 * File           : main.c
 * Version        : V1.00
 * Programmer(s)  :
 * Description    : This example uses Serial Peripheral Interface (SPI) of WyzBee board as master in polling method and OLED screen as slave to print a text message.
 *********************************************************************************************************
 * Note(s)		 :
 *********************************************************************************************************
 */
 
 /*
 * Includes
 */
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1351.h"
#include <SPI_OLED.h>
#include  <WyzBee_spi.h>



extern Adafruit_SSD1351 tft = Adafruit_SSD1351(); //@  OLED class variable
/*===================================================*/
/**
 * @fn			void print_oled(int8 *text, uint16_t color)
 * @brief		this functions is used to print the data on the oled screen
 * @param 1[in]	int8 *text
 * @param 2[in]	uint16_t color , color
 * @param[out]	none
 * @return		none
 * @description This API should contain the code / function call which will prints the data on the OLED screen.
 */

void print_oled(int8 *text, uint16_t color)
{
	uint8_t _len;
	tft.setTextColor(color); //@ sets the cursor position
	for (_len = 0; text[_len] != '\0'; _len++)
	{
		tft.write(text[_len]); //@ sends the byte to the screen
	}
	if (text[_len] == '\n')
	{
		//@ do nothing
	}
	else
	{
		tft.write('\n'); //@ prints the new line
	}
	return ;
}

WyzBeeSpi_Config_t  config_stc={
		4000000,
		SpiMaster,
		SpiSyncWaitZero,
		SpiEightBits,
		SpiMsbBitFirst,
		SpiClockMarkHigh,
		SpiNoUseIntrmode,
		NULL,                                                                
		NULL
};

int main()
{
	WyzBeeSpi_Init(&config_stc);
	tft.begin();
	tft.fillScreen(BLACK); //FILL the pixels black

	tft.fillScreen(BLACK); 					//@ fills the OLED screen by black pixels
	tft.setCursor(0, 0); 					//@ setting  OLED print cursor to  the initial location
	tft.setTextSize(3); 					//@ increases the text size on the OLED screen based on the input parameters

	print_oled((int8 *)"WyzBee", WHITE);
}
/*
 *********************************************************************************************************
 *                                           END
 *********************************************************************************************************
 */