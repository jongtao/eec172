/* Lab 2
	 Jonathan Tao
	 Trevor Gibson
 */

/* Notes
	 IR Sensor: P10, INT02_1
	 AKAI 1043
	 NEC Protocol
 */

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

// My Includes
#include "infrared.h"
#include "string.h"
#include "game.h"

// GPIO Constants
#define PIN_BLINKY P12



extern Adafruit_SSD1351 tft = Adafruit_SSD1351(); //@  OLED class variable

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
	// string
	char string[64];
	uint32_t d;
	uint32_t seed = 0;

	// Config GPIO
	GpioInitOut(PIN_BLINKY, 0);
	GpioInitOut(P42, 1); // LED

	// Screen init
	WyzBeeSpi_Init(&config_stc);

	tft.begin();
	tft.fillScreen(BLACK);
	tft.setTextColor(WHITE, BLACK);
	tft.setTextSize(2);

	sprintf(string, "MINCERAFT\n\nPress OK\nto start");
	printString(0, 0, string);

	// IR init
	infrared_init();
	while(!key.pressing) seed++; // get seed based on user's input

	game_init(&tft,&key,seed);

	for(;;)
	{
		if(key.pressing)
			GpioPut(P42, 0); // LED
		else
			GpioPut(P42, 1); // LED

		game_update();

		for(d=0;d<0xFFFF;d++); // delay

		//sprintf(string, "Addr:%02X\nCmd:%02X", key.addr, key.cmd);
		//printString(0, 0, string);
	} // main loop

	return 0;
} // main()
