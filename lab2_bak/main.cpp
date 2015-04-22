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
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1351.h"
#include <SPI_OLED.h>
#include  <WyzBee_spi.h>
#include <WyzBee_gpio.h>

// PDL
#include "pdl.h"

// Constants
#define PIN_IR P10
#define PIN_BLINKY P12
//#define IR_INT_CHAN 2
#define IR_INT_CHAN 11



// Adafruit datastructures
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



#ifdef TEST_IR
// IR Testing example: Sets P12 to the value on P10 (sensor)
int main(void)
{
	GpioInitIn(PIN_IR, 0);
	GpioInitOut(PIN_BLINKY, 1);

	for(;;)
		GpioPut(PIN_BLINKY, GpioGet(PIN_IR)); // Set Blinky to be same as IR
		
	return 0;
} // main
#endif // TEST_IR



#ifndef TEST_IR

void Main_ExtIntCallback1(void)
{
	GpioPut(P42, 0);
} // IR_ISR()



int main(void)
{
	WyzBeeSpi_Init(&config_stc);

	// Config GPIO
	GpioInitIn(PIN_IR, 0);
	//GpioInitOut(PIN_BLINKY, 1);
	GpioInitOut(PIN_BLINKY, 0);

	GpioInitOut(P42, 1);



/*
	// Config Interrupt
	stc_exint_config_t int_config;

	int_config.abEnable[IR_INT_CHAN] = TRUE;
	int_config.aenLevel[IR_INT_CHAN] = ExIntRisingEdge;
	int_config.apfnExintCallback[IR_INT_CHAN] = &IR_ISR;

	//SetPinFunc_INT02_1();
	SetPinFunc_INT11_1(0u);
	
	Exint_Init(&int_config);
	Exint_EnableChannel(IR_INT_CHAN);

*/
/*
  stc_exint_config_t stcExtIntConfig;

  PDL_ZERO_STRUCT(stcExtIntConfig);
  
  stcExtIntConfig.abEnable[11] = TRUE;   // INT00
  stcExtIntConfig.aenLevel[11] = ExIntFallingEdge;
  stcExtIntConfig.apfnExintCallback[11] = &Main_ExtIntCallback1;
    
  // Set pin function before enabling external interrupt channel!
  SetPinFunc_INT11_1(0u); 	        // Pin Function: INT02_1
  
  Exint_Init(&stcExtIntConfig);
  Exint_EnableChannel(11);
*/
	WyzBee_exint_config_t WyzBeeExtIntConfig;

	WyzBee_PDL_ZERO(WyzBeeExtIntConfig);

	WyzBeeExtIntConfig.abEnable[11] = TRUE;   // INT11
	WyzBeeExtIntConfig.aenLevel[11] = (en_exint_level_t)CalExIntRisingEdge;
	WyzBeeExtIntConfig.apfnExintCallback[11] = &Main_ExtIntCallback1;

	WyzBee_Exint_Init(&WyzBeeExtIntConfig);
	WyzBee_Exint_EnableChannel(11);


	for(;;)
	{
		//GpioPut(PIN_BLINKY, GpioGet(PIN_IR)); // Set Blinky to be same as IR
	} // main loop

	return 0;
} // main

#endif // not TEST_IR

