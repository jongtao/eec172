/* Lab 1
EEC 172
Jonathan Tao
Trevor Gibson
*/

// WyzBee Includes
#include <WyzBee.h>

#include <WyzBee_spi.h>

#include <Adafruit_GFX.h>
#include "Adafruit_SSD1351.h"
#include <SPI_OLED.h>

#include <WyzBee_gpio.h>

#include <pdl_user.h>
#include <WyzBee_i2c.h>

// std includes
#include <stdio.h>
#include <stdint.h>




// WyzBee instantiations
extern Adafruit_SSD1351 tft = Adafruit_SSD1351();

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



WyzBeeI2c_Config_t config ={
		100000,
		I2cMasterMode,
		I2cNoizeFilterLess100M,
		0x00
};


// I2C values
#define ADDR_HUM_TEMP 0x40
#define CMD_HUM		0xE5
#define CMD_TEM   0xE3

#define ADDR_ACCEL 0x68
#define REG_ACCEL 0x3B


// Constant
#define GRAV (9.8)



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
	// Screen init
	WyzBeeSpi_Init(&config_stc);
	char string[128] =
	" Trevor\n"
	"    &\n"
	" Jonathan\n\n"
	" PRESENTS:\n  LAB 1";

	// config screen
	tft.begin();
	tft.fillScreen(BLACK);
	tft.setTextColor(WHITE, BLACK);
	tft.setTextSize(2);


	// Print Names
	printString(0, 0, string);
	uint32_t count;
	for(count=0; count<0xFFFFFF; count++); // delay
	
	// Button init
	uint8_t prev, color;
	prev = color = 0;
	
	// I2C variables
	uint8 command[1], i2cBuffer[6];
	uint16_t bufLen;
	WyzBeeI2c_Init((WyzBeeI2c_Config_t*)&config);

	// temp/humidity init
	uint32_t raw_humidity, raw_temperature;
	float humidity, temperature;
	unsigned hum_whole, hum_frac;
	unsigned temp_whole, temp_frac;

	// Accelerometer init
	uint16_t raw_accel_x, raw_accel_y, raw_accel_z;
	float accel_x, accel_y, accel_z;
	unsigned ax_whole, ax_frac;
	unsigned ay_whole, ay_frac;
	unsigned az_whole, az_frac;
	WyzBeeGpio_Init(3A, GPIO_OUTPUT, 0); // AD0 = 0

	humidity = temperature = accel_x = accel_y = accel_z = 0;
	
	for(;;)
	{
		// Button
		if(WyzBeeGpio_Get(4E) && prev == 0) // triggers on rising edge of button
		{
			prev = 1; // last button state to 1 to identify edge direction

			switch(color) // Change LED color to the color of the state
			{
				case 0:
					WyzBeeGpio_Init(GPIO_LED2, GPIO_OUTPUT, 0);
					WyzBeeGpio_Init(GPIO_LED4, GPIO_OUTPUT, 1);
					color = 1;
						tft.fillScreen(BLACK);
					break;
				case 1:
					WyzBeeGpio_Init(GPIO_LED3, GPIO_OUTPUT, 0);
					WyzBeeGpio_Init(GPIO_LED2, GPIO_OUTPUT, 1);
					color = 2;
					tft.fillScreen(BLACK);
					break;
				case 2:
					WyzBeeGpio_Init(GPIO_LED4, GPIO_OUTPUT, 0);
					WyzBeeGpio_Init(GPIO_LED3, GPIO_OUTPUT, 1);
					color = 0;
					tft.fillScreen(BLACK);
					break;
				default:
					color = 0;
			} // switch(color)
		} // if button is rising edge

		if(!WyzBeeGpio_Get(4E))
			prev = 0;


		// Print to Screen
		switch(color)
		{
			case 0: // Humidity Sensor
				// get sensor data
				bufLen = 2;
				command[0] = CMD_HUM;

				WyzBeeI2c_Write(ADDR_HUM_TEMP, command, 1);
				WyzBeeI2c_Read(ADDR_HUM_TEMP, i2cBuffer, &bufLen); // read hum

				// concatenate bytes
				raw_humidity = i2cBuffer[0];
				raw_humidity <<= 8;
				raw_humidity |= i2cBuffer[1];

				// calculate relative humidity
				humidity = ((125.0 * (float)raw_humidity) / 65536.0) - 6.0;
				if(humidity < 0)
					humidity = 0;

				// convert to decimal and print
				hum_whole = (unsigned)humidity;
				hum_frac = (unsigned) ((humidity - hum_whole)*10);
				sprintf(string, "Humi:\n%u.%u%%     ", hum_whole, hum_frac);
				printString(0, 0, string);
				break;

			case 1: // Temperature Sensor
				// get sensor data
				bufLen = 2;
				command[0] = CMD_TEM;
				WyzBeeI2c_Write(ADDR_HUM_TEMP, command, 1);
				WyzBeeI2c_Read(ADDR_HUM_TEMP, i2cBuffer, &bufLen); // read temp

				// concatenate bytes
				raw_temperature = i2cBuffer[0];
				raw_temperature <<= 8;
				raw_temperature |= i2cBuffer[1];

				// calculate temperature
				temperature = (175.72 * (float)raw_temperature) / 65536.0 - 46.85;
				if(temperature < 0)
					temperature = 0;

				// convert to decimal and print
				temp_whole = (unsigned)temperature;
				temp_frac = (unsigned) ((temperature- temp_whole)*10);
				sprintf(string, "Temp(C):\n%u.%u     ", temp_whole, temp_frac);
				printString(0, 0, string);
				break;

			case 2: // Accelerometer Sensor
				// get sensor data
				bufLen = 6;
				command[0] = REG_ACCEL;
				WyzBeeI2c_Write(ADDR_ACCEL, command, 1);
				WyzBeeI2c_Read(ADDR_ACCEL, i2cBuffer, &bufLen);

				// concatenate to bytes
				raw_accel_x = i2cBuffer[0];
				raw_accel_x <<= 8;
				raw_accel_x |= i2cBuffer[1];

				raw_accel_y = i2cBuffer[2];
				raw_accel_y <<= 8;
				raw_accel_y |= i2cBuffer[3];

				raw_accel_z = i2cBuffer[4];
				raw_accel_z <<= 8;
				raw_accel_z |= i2cBuffer[5];


				// Normalize to earth gravitational acceleration
				accel_x = GRAV * ((int16_t)raw_accel_x) / (float)(1<<14);
				accel_y = GRAV * ((int16_t)raw_accel_y) / (float)(1<<14);
				accel_z = GRAV * ((int16_t)raw_accel_z) / (float)(1<<14);

				// Print results: converts to decimal and handles negative numbers
				sprintf(string, "a (m/ss):\n");
				printString(0, 0, string);
				
				if(accel_x >= 0.0)
				{
					ax_whole = (float)accel_x;
					ax_frac = (unsigned) ((accel_x - ax_whole)*10);
					sprintf(string, "x: %u.%u     ", ax_whole, ax_frac);
					printString(0, 16, string);
				} // if positive
				else // negative
					if(accel_x < 0.0)
					{
						accel_x *= -1;
						ax_whole = (float)accel_x;
						ax_frac = (unsigned) ((accel_x - ax_whole)*10);
						sprintf(string, "x: -%u.%u\n", ax_whole, ax_frac);
						printString(0, 16, string);
					} // if negative



				if(accel_y >= 0.0)
				{
					ay_whole = (float)accel_y;
					ay_frac = (unsigned) ((accel_y - ay_whole)*10);
					sprintf(string, "y: %u.%u     ", ay_whole, ay_frac);
					printString(0, 32, string);
				} // if positive
				else // negative
					if(accel_y < 0.0)
					{
						accel_y *= -1;
						ay_whole = (float)accel_y;
						ay_frac = (unsigned) ((accel_y - ay_whole)*10);
						sprintf(string, "y: -%u.%u     ", ay_whole, ay_frac);
						printString(0, 32, string);
					} // if negative



				if(accel_z >= 0.0)
				{
					az_whole = (float)accel_z;
					az_frac = (unsigned) ((accel_z - az_whole)*10);
					sprintf(string, "z: %u.%u     ", az_whole, az_frac);
					printString(0, 48, string);
				} // if positive
				else // negative
					if(accel_z < 0.0)
					{
						accel_z *= -1;
						az_whole = (float)accel_z;
						az_frac = (unsigned) ((accel_z - az_whole)*10);
						sprintf(string, "z: -%u.%u     ", az_whole, az_frac);
						printString(0, 48, string);
					} // if negative
		} // switch color for screen
	} // main loop

	return 0;
} // main()
