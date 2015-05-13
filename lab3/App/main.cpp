/* File: main.cpp
 *
 *
 * EEC 172 Spring 2015
 *
 * Trevor Gibson
 * Jonathan Tao
 */


#include <Adafruit_GFX.h>
#include "Adafruit_SSD1351.h"
#include <SPI_OLED.h>
#include  <WyzBee_spi.h>
#include <wyzbee_bt.h>
#include <pdl.h>
#include <delay.h>
#include "infrared.h"
#include "game.h"

#define MASTER

// Board 047 address: 00:23:A7:80:59:8A
// Board 048 address: 00:23:A7:80:59:C8

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

rsi_bt_event_inquiry_response rsi[4];
//RSI_BT_RESPONSE response;

// Prints string starting at (xCoord, yCoord)
void printString(uint16_t xCoord, uint16_t yCoord, char* myString)
{
	tft.setCursor(xCoord, yCoord);

	char* temp = myString;
	while(*temp != '\0')
		tft.write(*(temp++));
} // printString()

void init_master(void)
{
	/*  TESTING TO GET ADDRESSES
	uint8 addr[32];
	WyzBee_GetLocalBDAddress(addr);
	*/
	
	WyzBee_SetLocalName((uint8*)"Thing 1");  // Name the MASTER device

	uint16 result;
	result = WyzBee_SPPConnet((uint8*)"00:23:A7:80:59:C8");  // Send connect command to slave
	result = WaitForSPPConnComplete();
	/*
	if (!result) GpioPut(P43, 0);  // If successful, turn on green LED
	else GpioPut(P42, 0);  				 // Otherwise, turn on red LED
	result = WyzBee_SPPTransfer((uint8*)"00:23:A7:80:59:C8", // Send some data
	                            (uint8*)"HELLO WORLD",
	                            (uint16)11);
	*/
}

void init_slave(void)
{
	/*  TESTING TO GET ADDRESSES
	uint8 addr[32];
	WyzBee_GetLocalBDAddress(addr);
	*/
	
	WyzBee_SetLocalName((uint8*)"Thing 2");  // Name the SLAVE device
	
	uint16 result;
	uint8 data[128];
	//result = WyzBee_SPPConnet((uint8*)"00:23:A7:80:59:8A");  // Send connect command to  master
	result = WaitForSPPConnComplete();
	/*
	if (!result) GpioPut(P43, 0);  // If successful, turn on green LED
	else GpioPut(P42, 0);  				 // Otherwise, turn on red LED
	WyzBee_SPPReceive(data, (uint16)12);
	printString(0, 0, (char*)data);
	*/
}




int main(void)
{
	uint16 result;
	char string[32];
	
	sys_ticks_init();
	
	// Set initial BT conditions
	result = WyzBee_BT_init();
	WyzBee_SetDiscoverMode(1, 5000);
	WyzBee_SetConnMode(1);
	WyzBee_InitSppProfile();
	
	// Enable LEDs
	GpioInitOut(P42, 1); // LED
	GpioInitOut(P43, 1); // LED
	
	// Initialize Screen
	WyzBeeSpi_Init(&config_stc);
	tft.begin();
	tft.fillScreen(BLACK);
	tft.setTextColor(WHITE, BLACK);
	tft.setTextSize(2);
	
#ifdef MASTER
	printString(0, 0, (char*)"LAB3 Thing 1");
	init_master();
	
	unsigned seed = 0;
	uint32_t d;
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
	} // main loop
	
	
	
#else // NOT MASTER
	printString(0, 0, (char*)"LAB3 Thing 2");
	init_slave();
	
	unsigned seed = 0;
	uint32_t d;
	button input;
	game_init(&tft,&key,seed);

	for(;;)
	{
		if(button.pressing)
			GpioPut(P42, 0); // LED
		else
			GpioPut(P42, 1); // LED

		game_update();

		for(d=0;d<0xFFFF;d++); // delay
	} // main loop
#endif // MASTER





	/*
	WyzBee_Inquiry(0, 3000);
	RSI_BT_GetRespPayload(&response);
	AddScanresults(&rsi, 1, &(response.uCmdRspPayLoad.uInqResp));
	
	do
	{
		result = WyzBee_GetInquiryResults(rsi, 4);
	} while(!result);
	
	printString(0, 0, (char*)(rsi[0].RemoteDeviceName));
	GpioPut(P43, 0);
	
	delay(2000);
	GpioPut(P43, 1);
	*/
	return 0;
}