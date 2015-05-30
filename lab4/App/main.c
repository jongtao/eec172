/**
 * @file     main.c
 * @version  1.0
 * @date     2014-Oct-21
 *
 * Copyright(C) Redpine Signals 2013
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief main: Beginning of the code
 *
 * @section Description : main function invokes the  system initialization and carries out the application.
 *
 *
 * @section Improvements :
 *
 */
/*
 * Includes
 */

#include <rsi_global.h>
#include <string.h>
#include <rsi_api.h>
#include <WyzBeeWiFi.h>
#include <variant.h>
#include <delay.h>
#include <WyzBee_i2c.h>
#include <WyzBee_gpio.h>
#include <WyzBee_timer.h>



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
		
/*I2C Configuration (data rate, Mode, Noise Filter, slave address)*/

WyzBeeI2c_Config_t config ={
		100000,
		I2cMasterMode,
		I2cNoizeFilterLess100M,
		0x00,
};



/*******************************************************************************************************************
 * @fn			:main(void)
 * @brief		:
 * @param 1[in]	:none
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:int 0
 * @description :main function invokes the  system initialization and USB CDC initialization along with it calls the setup and loop functions
 *******************************************************************************************************************/

int main(void)
{
		sys_ticks_init();									//@ systick init
		memset(scan_dev,'\0',sizeof(scan_dev));

		status = WyzBeeWiFi_Init();  					                 //@ initializes the RS9113 wifi module
	  if(status == 0) 
		{

					//WyzBeeGpio_Init(GPIO_LED2,GPIO_OUTPUT,GPIO_LOW);				//Glows Red LED
					nbr_scan_devs = WyzBeeWiFi_ScanNetworks(remote_dev); //@ this functions scans the AP's in vicinity and returns the number of networks scanned.
					for (ix = 0; ix < nbr_scan_devs; ix++)
					{							                       //@ returns pointer to a string of each SSID scanned in the network.
						memcpy (scan_dev[ix], remote_dev[ix].ssid, strlen ((const int8 *)remote_dev[ix].ssid)); 	   //@ copying the all SSIDs into a local buffer
					}
					
					status = WyzBeeWiFi_ConnectAccessPoint((int8 *)"ucd-guest", NULL); //join with access point
				
					if (status == 0)
					{
						//WyzBeeGpio_Init(GPIO_LED2,GPIO_OUTPUT,GPIO_HIGH);			//Red LED off
						
						
										//WyzBeeWiFi_HttpPost ("http://calbeedemo.appspot.com/greetings?msg=testit",(HttpRequest *)NULL);					//@HTTP POST
										WyzBeeWiFi_HttpGet  ("http://calbeedemo.appspot.com/status", (HttpRequest *)NULL, http_resp, sizeof (http_resp)); //@HTTP GET
								
					}
				}
		return 0;
}

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

