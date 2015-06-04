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

#define CHAT_LEN 10
#define MAX_DELAY 20


rsi_scanInfo  				remote_dev[RSI_AP_SCANNED_MAX];
HttpRequest  					http_req;
volatile 	uint8 			fflag = 0;
volatile 	uint32_t 		time = 0;

int8     							scan_dev[11][34];
//int8     							message[50];
//int8     							http_resp[1000];
int8   								*p_ssid_name;
int8								  status, ix, nbr_scan_devs;

err_t 								err;



extern Adafruit_SSD1351 oled = Adafruit_SSD1351(); //@  OLED class variable



WyzBeeSpi_Config_t config_stc = //SPI Specification Initialization Block
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
};



void printString(uint16_t xCoord, uint16_t yCoord, char* myString, int color)
{
	oled.setTextColor(color, BLACK);
	oled.setCursor(xCoord, yCoord);

	char* temp = myString;
	while(*temp != '\0')
		oled.write(*(temp++));
} // printString()



void send(char url[], char buffer[], uint16_t* count, int8 array[],
	uint8_t* cycle_delay)
{
	GpioPut(P43, 0); // LED

	sprintf(url, "http://calbeedemo.appspot.com/greetings?msg=%s", buffer);
	WyzBeeWiFi_HttpGet(url, (HttpRequest*)NULL, array, sizeof(array));

	buffer[0] = 0;
	*count = 0;
	*cycle_delay = MAX_DELAY + 1;
	GpioPut(P43, 1); // LED
} // send()



int main(void)
{
	sys_ticks_init();

	GpioInitOut(P42, 1); // RED LED
	GpioInitOut(P43, 1); // GREEN LED

	WyzBeeSpi_Init(&config_stc); //initialize spi for oled
	
	//OLED
	oled.begin(); //OLED screen Initialization
	oled.fillScreen(BLACK); //@fills the OLED screen with black pixels
	oled.setTextSize(1); //OLED set text size


	// Chat
	char chat_log[CHAT_LEN][64];
	int chat_head, chat_tail, prev_tail;
	chat_head = chat_tail = 0;
	prev_tail = -1;
	char chat_buffer[512];
	int not_same; 
	int chat_index;
	int buffer_index = 0;

	// User interface
	uint32_t delay;
	uint8_t cycle_delay = MAX_DELAY + 1;
	char buffer[1024];
	buffer[0] = 0;
	char string[64];
	uint16_t count = 0;
	char character = 'A';

	// Web and internet
	int8 array[3000];
	char url[256];

	
	memset(scan_dev,0,sizeof(scan_dev));
	status = WyzBeeWiFi_Init(); // Wifi

	if(status == 0) // if wifi init success
	{
		oled.fillScreen(BLACK);
		printString(0,0, "Conneting...", RED);

		nbr_scan_devs = WyzBeeWiFi_ScanNetworks(remote_dev);
		for(ix=0; ix<nbr_scan_devs; ix++)
			memcpy(scan_dev[ix], remote_dev[ix].ssid,
				strlen((const int8 *)remote_dev[ix].ssid));

 		//join with access point
		//status = WyzBeeWiFi_ConnectAccessPoint((int8 *)"Bacon", "nahtanojoat");
		status = WyzBeeWiFi_ConnectAccessPoint((int8 *)"EEC172", 0);

		
		
int number_nl;
char tmp_number[64];
		
		if (status == 0) // if connected to WiFi
		{
			printString(0,0, "Conneted", RED);
			infrared_init();

			oled.fillScreen(BLACK);
			printString(0,119,">A", BLUE);

			for(;;)
			{
				if(key.pressing)
				{
					switch(key.cmd)
					{
						case 0x0C: // up
							if(character == 34) character = 126;
							else character--;
							break;
						case 0x0D: // down
							if(character == 126) character = 33;
							else character++;
							break;
						case 0x02: // right
							buffer[count++] = character;
						 	buffer[count] = 0;
						 	break;
						case 0x03: // left
							if(count == 0) break;
							else buffer[--count] = 0;
							break;
						case 0x10: // 0 (space)
							buffer[count++] = '%';
							buffer[count++] = '2';
							buffer[count++] = '0';
							buffer[count] = 0;
							break;
						case 0x4C: // OK
							buffer[count++] = character;
							buffer[count] = 0;
							send(url, buffer, &count, array, &cycle_delay);
							break;
						case 0x11: //1
							strcpy(buffer, "Yes.");
							send(url, buffer, &count, array, &cycle_delay);
							break;
						case 0x12: // 2
							strcpy(buffer, "No.");
							send(url, buffer, &count, array, &cycle_delay);
							break;
						case 0x13: // 3
							strcpy(buffer, ":)");
							send(url, buffer, &count, array, &cycle_delay);
							break;
						case 0x14: // 4
							strcpy(buffer, ":(");
							send(url, buffer, &count, array, &cycle_delay);
							break;
						case 0x15: // 5
							strcpy(buffer, "Hello");
							send(url, buffer, &count, array, &cycle_delay);
							break;
						case 0x16: // 6
							//strcpy(url, "http://api.openweathermap.org/data/2.5/weather?zip=95616,us");
							strcpy(tmp_number,chat_log[prev_tail]);
							number_nl = strlen(chat_log[prev_tail]) - 1;
							tmp_number[number_nl] = 0;
							sprintf(url, "http://numbersapi.com/%s", tmp_number);
							memset(array, 0, sizeof (array));
							status = WyzBeeWiFi_HttpGet(url, (HttpRequest*)NULL, array,
								sizeof(array));
							printString(0,60,array, GREEN); for(delay=0;delay<0xFFFFFFF;delay++); // delayelay
						
							strcpy(buffer, "I'm%20reading%20about%20numbers!");
							send(url, buffer, &count, array, &cycle_delay);
							break;
						case 0x17: // 6
							strcpy(buffer,"How%20is%20the%20weather?");
							send(url, buffer, &count, array, &cycle_delay);
							break;
						case 0x18: // 7
							strcpy(buffer,"Sent%20from%20an%20Embedded%20System");
							send(url, buffer, &count, array, &cycle_delay);
							break;
						case 0x19: // 8
							strcpy(buffer,"ALL%20YOUR%20BASE%20ARE%20BELONG%20TO%20US");
							send(url, buffer, &count, array, &cycle_delay);
							break;
							
					}; // swith key.cmd

					sprintf(string,">%s%c                           ", buffer, character);
					printString(0,119,string, BLUE);

					//sprintf(string, "k:%x", key.cmd); printString(0,100,string, GREEN);
				} // if pressing


				// Print chat after period or GUIDE key is pressed
				if(cycle_delay > MAX_DELAY || (key.cmd == 0x25 && key.pressing))
				{
					GpioPut(P42, 0); // LED
					strcpy(url, "http://calbeedemo.appspot.com/status");
					memset(array, 0, sizeof (array));
					status = WyzBeeWiFi_HttpGet(url, (HttpRequest*)NULL, array,
						sizeof(array));
					strcpy(array,&array[12]);

					if(prev_tail != -1)
						not_same = strcmp(array,chat_log[prev_tail]);
					else
						not_same = 1;

					if(not_same)
					{
						strcpy(chat_log[chat_tail], array);
						chat_tail = (chat_tail+1) % CHAT_LEN;
						prev_tail = (prev_tail+1) % CHAT_LEN;
						if(chat_tail == chat_head) chat_head = (chat_head+1) % CHAT_LEN;
						
						buffer_index = 0;
						memset(chat_buffer, 0, sizeof(chat_buffer));

						for(chat_index = chat_head; chat_index != chat_tail;
							chat_index= (chat_index+1) % CHAT_LEN)
						{
							strcpy(chat_buffer+buffer_index, chat_log[chat_index]);
							buffer_index += strlen(chat_log[chat_index]);
							// string already ends a newline followed by a null termination
						}
						oled.fillRect(0, 0, 192, 118, BLACK); // background
						printString(0,0,chat_buffer, WHITE);
					} // if new message

					cycle_delay = 0;
					GpioPut(P42, 1); // LED
				} // get message
				else
				{
					cycle_delay++;
					for(delay=0;delay<0x7FF000;delay++); // delayelay
				} // don't get message
			} // main loop
		} // if connected
		printString(0,0, "Connet Failed", RED);
	} // if status
	return 0;
} // main()
