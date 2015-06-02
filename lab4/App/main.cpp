// Includes
#include <WyzBee_gpio.h>
#include <WyzBee_ext.h>
#include <WyzBee_timer.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1351.h"
#include <SPI_OLED.h>
#include <WyzBee_spi.h>
#include <stdio.h>

#include <WyzBee.h>
#include <math.h>

#include <string.h>
#include <rsi_global.h>
#include <rsi_api.h>
#include <WyzBeeWiFi.h>
#include <variant.h>
#include <delay.h>
#include <WyzBee_i2c.h>

#include <infrared.h>

#define CHAT_LEN 16


rsi_scanInfo  				remote_dev[RSI_AP_SCANNED_MAX];
HttpRequest  					http_req;
volatile 	uint8 			fflag = 0;
volatile 	uint32_t 		time = 0;

int8     							scan_dev[11][34];
int8     							message[50];
//int8     							http_resp[1000];
int8   								*p_ssid_name;
int8								  status, ix, nbr_scan_devs;

err_t 								err;


//Function Prototypes
int printToOLED(char* stringToPrint, int color, int cursorX, int cursorY);

extern Adafruit_SSD1351 oled = Adafruit_SSD1351(); //@  OLED class variable

//SPI Specification Initialization Block
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

//Insert function to print to OLED display (Lab1).
int printToOLED(char* stringToPrint, int color, int cursorX, int cursorY){
//#define	BLACK           0x0000
//#define	BLUE            0x001F
//#define	RED             0xF800
//#define	GREEN           0x07E0
//#define CYAN            0x07FF
//#define MAGENTA         0xF81F
//#define YELLOW          0xFFE0
//#define WHITE           0xFFFF
	
	//set color of text
	oled.setTextColor(color, BLACK);
	
	//get string lendth
	int stringLength = strlen(stringToPrint);
	//set the print cursor to the inital location
	oled.setCursor(cursorX,cursorY);
	//print the string to the screen moving the cursor each time
	for(int i=0; i < stringLength; i++){
			oled.setCursor(10*i+cursorX,cursorY); //set the print cursor to the inital location
			oled.write(stringToPrint[i]); //write a char to screen
	}
	
	return 0;
}

//static variables


void printString(uint16_t xCoord, uint16_t yCoord, char* myString, int color)
{
	oled.setTextColor(color, BLACK);
	oled.setCursor(xCoord, yCoord);

	char* temp = myString;
	while(*temp != '\0')
		oled.write(*(temp++));
} // printString()


enum States
{
	TO,
	SUBJECT,
	MESSAGE
};



int main(void)
{
	err_t err;
	sys_ticks_init();																				/*Initialize Systick timer*/
	GpioInitOut(P42, 1); // RED LED
	GpioInitOut(P43, 1); // ? LED

	// Initialize the OLED display according to Lab1
	err_t SPIErr = WyzBeeSpi_Init(&config_stc); //initialize spi
	
	status = WyzBeeWiFi_Init(); // Wifi
	memset(scan_dev,'\0',sizeof(scan_dev));
  int8 array[64];
	
	//OLED
	oled.begin(); //OLED screen Initialization
	oled.fillScreen(BLACK); //@fills the OLED screen with black pixels
	oled.setTextSize(1); //OLED set text size
	printToOLED("It's alive", RED, 0,0);

	//char URL[128] = "http://calbeedemo.appspot.com/greetings?msg=HELLO_2";
	
	//uint8_t state = 0;
	int cycle_delay = 0;

	// Chat
	char chat_log[CHAT_LEN][64];
	int chat_head, chat_tail;
	chat_head = chat_tail = 0;
	char chat_buffer[512];
	

	if(status == 0) 
	{
		oled.fillScreen(BLACK);
		printToOLED("initted", RED, 0,0);

		nbr_scan_devs = WyzBeeWiFi_ScanNetworks(remote_dev);
		for (ix = 0; ix < nbr_scan_devs; ix++)
			memcpy(scan_dev[ix], remote_dev[ix].ssid,
				strlen ((const int8 *)remote_dev[ix].ssid));

		status = WyzBeeWiFi_ConnectAccessPoint((int8 *)"Bacon", "nahtanojoat"); //join with access point
		//status = WyzBeeWiFi_ConnectAccessPoint((int8 *)"EEC172", 0); //join with access point

		if (status == 0)
		{
			printToOLED("conneted", RED, 0,0);
			infrared_init();
			printToOLED("IR initted", RED, 0,0);
			//status = WyzBeeWiFi_HttpGet(URL, (HttpRequest*)NULL, array, sizeof(array));

			//printToOLED("posted", RED, 0,0);

			char buffer[1024];
			buffer[0] = 0;

			uint32 delay;
			int8 array[1024];

			char string[64];
			char character = 'A';
			int count = 0;

			//char URL[128] = "http://calbeedemo.appspot.com/greetings?msg=TESTING...";
			char url[128];
			char to_str[64];
			char subject_str[64];

/*
			//HttpRequest http_req;
			uint8  p_username[64] = "jgtao";
			uint8  p_password[64] = "embeddedsystem";
			uint8  p_headers[1024] =
				"Accept: application/json\r\n"
				"Content-Type: application/json\r\n"
				"X-Postmark-Server-Token: 8e7246db-7f94-41e0-98bd-c95f09ce4643\r\n\r\n";
			uint8  p_data[1024] = "\0";

			http_req.p_username = NULL;//p_username;
			http_req.p_password = NULL;//p_password;
			http_req.p_headers = p_headers;
			http_req.p_data = p_data;
*/
			int16 ret;
			oled.fillScreen(BLACK);

			printString(0,119,">A", BLUE);

			for(;;)
			{
				if(key.pressing)
				{
					switch(key.cmd)
					{
						case 0x0C: character--; break; // up
						case 0x0D: character++; break; // down
						case 0x02: // right
							buffer[count] = character;
							count++;
						 	buffer[count] = 0;
						 	break;
						case 0x03: // left
							if(count == 0) break;
							buffer[count-1] = 0;
							count--;
							break;
						case 0x15: // 5 (space)
							buffer[count] = '%';
							count++;
							buffer[count] = '2';
							count++;
							buffer[count] = '0';
							count++;
							buffer[count] = 0;
							break;
						case 0x04C:
							GpioPut(P43, 0); // LED
							buffer[count] = character;
							buffer[count+1] = 0;
							count++;
							sprintf(url,"http://calbeedemo.appspot.com/greetings?msg=%s", buffer);
							WyzBeeWiFi_HttpGet(url, (HttpRequest*)NULL, array, sizeof(array));

							printString(0,119,"                             ", BLUE);
							cycle_delay = 21;

							buffer[0] = 0;
							count = 0;
							GpioPut(P43, 1); // LED
							break;
					}; // swith key.cmd

					sprintf(string,">%s%c  ", buffer, character);
					printString(0,119,string, BLUE);
				} // if pressing


				// Print chat
				if(cycle_delay > 20 || key.cmd == 0x10 && key.pressing)
				{
					GpioPut(P42, 0); // LED
					strcpy(url, "http://calbeedemo.appspot.com/status");
					//sprintf(url,"http://calbeedemo.appspot.com/greetings?msg=%s", "HERLLOWORDL");
					memset(array, 0, sizeof (array));
					status = WyzBeeWiFi_HttpGet(url, (HttpRequest*)NULL, array, sizeof(array));

					strcpy(chat_log[chat_tail], array);
					chat_tail = (chat_tail++) % CHAT_LEN;
					if(chat_tail == chat_head) chat_head = (chat_head++) % CHAT_LEN;
					
					int chat_index;
					int buffer_index = 0;
					int str_num;
					memset(chat_buffer, 0, sizeof(chat_buffer));

					for(chat_index = chat_head; chat_index != chat_tail;
						chat_index= (chat_index++) % CHAT_LEN)
					{
						strcpy(chat_buffer+buffer_index, chat_log[chat_index]);
						buffer_index += strlen(chat_log[chat_index]) + 1; // add 1 for \n
						chat_buffer[buffer_index] = '\n';
					} // for every message
					//chat_buffer[buffer_index] = 0; // end buffer
					//printString(0,0,array, RED);
					printString(0,0,chat_buffer, RED);

					cycle_delay = 0;
					GpioPut(P42, 1); // LED
				}
				else
				{
					cycle_delay++;
					for(delay=0;delay<0x3FFFFF;delay++); // delayelay
				}

			} // main loop

		} // if connected
		printToOLED("connet failed", RED, 0,0);
	} // if status
	return 0;
} // main()
	
/*
 *********************************************************************************************************
 *                                           END
 *********************************************************************************************************
 */
