/* Lab 2
	 Jonathan Tao
	 Trevor Gibson
 */

/* Notes
	 IR Sensor: P10, INT02_1
	 AKAI 1043
	 NEC Protocol
 */

// Defines whether or not to enable the IR testing example
//#define TEST_IR


// WyzBee Includes
#include <WyzBee_gpio.h>
#include <WyzBee_ext.h>
#include <WyzBee_timer.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1351.h"
#include <SPI_OLED.h>
#include <WyzBee_spi.h>
#include <stdio.h>
#include <WyzBee_kit.h>
#include <WyzBee.h>

#include "infrared.h"



// GPIO Constants
#define PIN_BLINKY P12


extern Adafruit_SSD1351 tft = Adafruit_SSD1351(); //@  OLED class variable

/*TODO: Insert function to print to OLED display (Lab1).*/


WyzBeeSpi_Config_t  config_stc =
{
	4000000,
	SpiMaster,
	SpiSyncWaitZero,
	SpiEightBits,
	SpiMsbBitFirst,
	SpiClockMarkHigh,
	SpiNoUseIntrmode,
	NULL,                                                                
	NULL
}; // SPI Struct



// Prints string starting at (xCoord, yCoord)
void printString(uint16_t xCoord, uint16_t yCoord, char* myString)
{
	tft.setCursor(xCoord, yCoord);

	char* temp = myString;
	while(*temp != '\0')
		tft.write(*(temp++));
} // printString()



int main(void)
{

	// Config GPIO
	GpioInitOut(PIN_BLINKY, 0);
	GpioInitOut(P42, 1); // LED

	// Screen init
	WyzBeeSpi_Init(&config_stc);

	// config screen
	tft.begin();
	tft.fillScreen(BLACK);
	tft.setTextColor(WHITE, BLACK);
	tft.setTextSize(2);


	infrared_init();

		
	/*TODO: Initialize the OLED display according to Lab1.*/
	
	GpioPut(PIN_BLINKY, 1);
	GpioPut(PIN_BLINKY, 0);
	GpioPut(PIN_BLINKY, 1);
	while(1)
	{
		if((buffer & 0x000F0000) == 0x00010000)
			printString(0, 0, "1");

		if((buffer & 0x000F0000) == 0x00020000)
			printString(0, 0, "2");

		if((buffer & 0x000F0000) == 0x00030000)
			printString(0, 0, "3");

		if((buffer & 0x000F0000) == 0x00040000)
			printString(0, 0, "4");

		if((buffer & 0x000F0000) == 0x00050000)
			printString(0, 0, "5");


		/*
		count = Dt_ReadCurCntVal(0);
		if(Dt_ReadCurCntVal(0) > 0 && Dt_ReadCurCntVal(0) < 100)
			GpioPut(PIN_BLINKY, 0);
			*/
	} // main loop

} // main()
