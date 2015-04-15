/* Lab 2
Jonathan Tao
Trevor Gibson
*/

/* Notes
IR Sensor: P10, INT02_1
AKAI 1043
NEC Protocol
*/
 
 /*
 * Includes
 */
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1351.h"
#include <SPI_OLED.h>
#include  <WyzBee_spi.h>
#include <WyzBee_gpio.h>

#include "pdl.h"
#include "mfs.h"

#define PIN_IR P10
#define PIN_BLINKY P12



extern Adafruit_SSD1351 tft = Adafruit_SSD1351(); //@  OLED class variable

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
	
	//WyzBeeGpio_Init(PIN_IR, GPIO_INPUT, 0); // Init IR Sensor
	//WyzBeeGpio_Init(PIN_BLINKY, GPIO_OUTPUT, 1); // Init Output test
	GpioInitIn(PIN_IR, 0);
	GpioInitOut(PIN_BLINKY, 1);

	
	for(;;)
		//WyzBeeGpio_Put(PIN_BLINKY, WyzBeeGpio_Get(PIN_IR)); // Set Blinky to be same as IR
	GpioPut(PIN_BLINKY, GpioGet(PIN_IR));

}
/*
 *********************************************************************************************************
 *                                           END
 *********************************************************************************************************
 */