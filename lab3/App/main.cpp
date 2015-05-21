/* LAB 3
Jonathan Tao
Trevor Gibson
*/

// WyzBee includes

#include <WyzBee_ext.h>
//#include <WyzBee_timer.h>

#include <Adafruit_GFX.h>
#include "Adafruit_SSD1351.h"
#include <SPI_OLED.h>

#include <WyzBee_spi.h>
#include <WyzBee_kit.h>
//#include <WyzBee.h>
//#include <dt.h>

#include <wyzbee_bt.h>


// std includes
#include <stdio.h>
#include <string.h>

// my includes
#include "infrared.h"
//#include "game.h"


#define MASTER

// Board 047 address: 00:23:A7:80:59:8A
// Board 048 address: 00:23:A7:80:59:C8


uint8 master_addr[32] = "00:23:A7:80:59:8A";
uint8 slave_addr[32] = "00:23:A7:80:59:C8";

/*
uint8 master_addr[32] = "00:23:A7:80:59:C8";
uint8 slave_addr[32] = "00:23:A7:80:59:8A";
*/



extern Adafruit_SSD1351 tft = Adafruit_SSD1351();

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

void printString(uint16_t xCoord, uint16_t yCoord, char* myString)
{
	tft.setCursor(xCoord, yCoord);

	char* temp = myString;
	while(*temp != '\0')
		tft.write(*(temp++));
} // printString()


void my_bt_init(uint8 this_addr[])
{
	if(!strcmp((char*)this_addr,(char*)master_addr))
	{
		printString(0,0,"MASTER\nCONNETING");
		WyzBee_SPPConnet(slave_addr);
		WaitForSPPConnComplete();
		printString(0,0,"MASTER\nCONNETED   ");
	} // if is master
	else // not master
		if(!strcmp((char*)this_addr,(char*)slave_addr)) // is slave
		{
			printString(0,0,"SLAVE\nCONNETING");
			WaitForSPPConnComplete();
			printString(0,0,"SLAVE\nCONNETED   ");
		}
		else
			printString(0,0,"DEVICE\nADDRESS\nNOT\nRECOGNIZED");
} // my_bt_init()



void master_main(void)
{
	// Init Infrared Remote
	infrared_init();

	uint8 buffer[64];
	uint32_t delay;
	uint32_t seed = 0;
	char string[64];
	char character = 'A';
	int count = 0;

/*
	while(!key.pressing) seed++;

	buffer[0]=(seed&0x000000FF);
	buffer[1]=(seed&0x0000FF00)>>8;
	buffer[2]=(seed&0x00FF0000)>>16;
	buffer[3]=(seed&0xFF000000)>>24;
	
	WyzBee_SPPTransfer((uint8*)"00:23:A7:80:59:C8", buffer, 4);
	
	game_init(&tft,&key,seed);
*/
	for(;;)
	{
		/*
		buffer[0] = key.pressing;
		buffer[1] = key.cmd;
		WyzBee_SPPTransfer(slave_addr,buffer,2);
		*/

		
		if(key.pressing)
			GpioPut(P42, 0); // LED
		else
			GpioPut(P42, 1); // LED
		
		if(key.cmd == 0x0C && key.pressing)
			character--;
		else
			if(key.cmd == 0x0D && key.pressing)
				character++;
			
		if(key.cmd == 0x4C && key.pressing)
		{
			buffer[count] = character;
			buffer[count+1] = 0;
			count++;
			WyzBee_SPPTransfer(slave_addr,buffer,64);
		}
		
		sprintf(string,"%c",character);
		printString(0,0,string);
	//	game_update(0,0);
		//game_update();
		for(delay=0;delay<0x3FFFFF;delay++); // delayelay
	} // main loop
} // master_main()


void slave_main(void)
{
	uint8 buffer[64];
	uint32_t delay;
	uint32_t seed = 0;
	Button input;
	char string[64];
/*
	WyzBee_SPPReceive(buffer,4);
	seed = buffer[3];
	seed <<= 8;
	seed |= buffer[2];
	seed <<= 8;
	seed |= buffer[1];
	seed <<= 8;
	seed |= buffer[0];

	game_init(&tft,&input,seed);
*/

	for(;;)
	{/*
		WyzBee_SPPReceive(buffer,2);
		input.pressing = buffer[0];
		input.cmd = buffer[1];

		if(input.pressing)
			GpioPut(P42, 0); // LED
		else
			GpioPut(P42, 1); // LED
*/		
		WyzBee_SPPReceive(buffer,64);

		//game_update(128,0);
		//game_update();
		sprintf(string,"%s",buffer);
		printString(0,0,string);
		for(delay=0;delay<0xFFFF;delay++); // delayelay
	} // main loop
} // slave_main()


int main(void)
{
	sys_ticks_init();

	// Init test LED
	GpioInitOut(P42, 1); // RED LED


	// Initialize Screen
	WyzBeeSpi_Init(&config_stc);
	tft.begin();
	tft.fillScreen(BLACK);
	tft.setTextColor(WHITE, BLACK);
	tft.setTextSize(2);

	// Init Bluetooth
  WyzBee_BT_init();
  WyzBee_SetLocalName((uint8*)"THING");
  WyzBee_SetConnMode(1);
  WyzBee_SetDiscoverMode(1, 5000);
  WyzBee_InitSppProfile();

	uint8 this_addr[32];
	WyzBee_GetLocalBDAddress(this_addr);
	my_bt_init(this_addr);

tft.fillScreen(BLACK);
	if(!strcmp((char*)this_addr,(char*)master_addr))
		master_main();
	else
		if(!strcmp((char*)this_addr,(char*)slave_addr))
			slave_main();

	
	return 0;
} // main()
