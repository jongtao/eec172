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


rsi_scanInfo  				remote_dev[RSI_AP_SCANNED_MAX];
HttpRequest  					http_req;
volatile 	uint8 			fflag = 0;
volatile 	uint32_t 		time = 0;

int8     							scan_dev[11][34];
int8     							message[50];
int8     							http_resp[1000];
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


void printString(uint16_t xCoord, uint16_t yCoord, char* myString)
{
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

	// Initialize the OLED display according to Lab1
	err_t SPIErr = WyzBeeSpi_Init(&config_stc); //initialize spi
	
	status = WyzBeeWiFi_Init(); // Wifi
	
	//OLED
	oled.begin(); //OLED screen Initialization
	oled.fillScreen(BLACK); //@fills the OLED screen with black pixels
	oled.setTextSize(2); //OLED set text size
	printToOLED("It's alive", RED, 0,0);

  int8 array[1024];
	char URL[128] = "http://calbeedemo.appspot.com/greetings?msg=HELLO_2";
	
	uint8_t state = 0;
	
	memset(scan_dev,'\0',sizeof(scan_dev));
	  if(status == 0) 
		{
			oled.fillScreen(BLACK);
			printToOLED("initted", RED, 0,0);
					
					nbr_scan_devs = WyzBeeWiFi_ScanNetworks(remote_dev); //@ this functions scans the AP's in vicinity and returns the number of networks scanned.
					for (ix = 0; ix < nbr_scan_devs; ix++)
					{							                       //@ returns pointer to a string of each SSID scanned in the network.
						memcpy (scan_dev[ix], remote_dev[ix].ssid, strlen ((const int8 *)remote_dev[ix].ssid)); 	   //@ copying the all SSIDs into a local buffer
					}
					
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
						
						char temp_string[1024];
						uint32 delay;
						int8 array[1024];

						char string[64];
						char character = 'A';
						int count = 0;
						
						//char URL[128] = "http://calbeedemo.appspot.com/greetings?msg=TESTING...";
						char url[128];
						char to_str[64];
						char subject_str[64];
						
						HttpRequest packet;
						uint8  p_username[64] = "jgtao";
						uint8  p_password[64] = "embeddedsystem";
						uint8  p_headers[1024] =
							"Accept: application/json\r\n"
							"Content-Type: application/json\r\n"
							"X-Postmark-Server-Token: 8e7246db-7f94-41e0-98bd-c95f09ce4643\r\n\r\n";
						uint8  p_data[1024] = "\0";
						
						packet.p_username = NULL;//p_username;
						packet.p_password = NULL;//p_password;
						packet.p_headers = p_headers;
						packet.p_data = p_data;
						
						int16 ret;
						oled.fillScreen(BLACK);
						
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
										buffer[count+1] = 0;
										count++;
										break;
									case 0x03: // left
										if(count == 0) break;
										buffer[count-1] = 0;
										count--;
										break;
									case 0x15: // 5 (space)
										buffer[count] = '_';
										buffer[count+1] = 0;
										count++;
										break;
									case 0x04C:
										buffer[count] = character;
										buffer[count+1] = 0;
										count++;
									
									
									

										switch(state)
										{
											case TO: strcpy(to_str, buffer); state = SUBJECT; break;
											case SUBJECT: strcpy(subject_str, buffer); state = MESSAGE; break;
											case MESSAGE: // send
												sprintf((char*)p_data,
													"{From: 'jgtao@ucdavis.edu', "
													"To: 'jgtao@ucdavis.edu', "
													"Subject: 'Hello from Postmark', "
													"HtmlBody: '<html><body>%s<br><br><br>Sent from my Embedded System</body></html>'}",
													buffer);
									
											//strcpy(url, "https://api.postmarkapp.com/email");
											strcpy(url, "https://posttestserver.com/post.php");
											//status = WyzBeeWiFi_HttpPost(url, &packet);
												
										//status = WyzBeeWiFi_HttpGet(url, (HttpRequest*)NULL, array, sizeof(array));
										status = WyzBeeWiFi_HttpGet(url, &packet, array, sizeof(array));
											
											state = TO;
										}; // switch state for printing
										oled.fillScreen(BLACK);
										
										buffer[0] = 0;
										count = 0;
										
										
										
										/*
										sprintf(temp_string,"http://calbeedemo.appspot.com/greetings?msg=%s", buffer);
										status = WyzBeeWiFi_HttpGet(temp_string, (HttpRequest*)NULL, array, sizeof(array));
										if (status) printToOLED("failed", RED, 0,20);
										else printToOLED("posted", RED, 0,20);
										*/
								}; // swith key.cmd
							} // if pressing
								
							switch(state)
							{
								case TO: sprintf(string,"To: %s%c  ", buffer, character); break;
								case SUBJECT: sprintf(string,"Subject: %s%c  ", buffer, character); break;
								case MESSAGE: sprintf(string,"Message: %s%c  ", buffer, character); break;
							}; // switch state for printing
							printString(0,0,string);
							
							for(delay=0;delay<0x3FFFFF;delay++); // delayelay
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
