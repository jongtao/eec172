/*
 *********************************************************************************************************
 *
 *                           (c) Copyright 2015-2020 RedPine Signals Inc. Hyderabad, INDIA
 *                                           All rights reserved.
 *
 *               This file is protected by international copyright laws. This file can only be used in
 *               accordance with a license and should not be redistributed in any way without written
 *               permission by Redpine Signals.
 *
 *                                            www.redpinesignals.com
 *
 *********************************************************************************************************
 */

/*
 *********************************************************************************************************
 *
 *											  I2C Driver Header File
 *
 * File           : WyzBee_i2c.h
 * Version        : V1.00
 * Programmer(s)  :
 *********************************************************************************************************
 * Note(s)		 :
 *********************************************************************************************************
 */

#ifndef WyzBee_I2C_H
#define WyzBee_I2C_H
#ifdef __cplusplus
extern "C"{
#endif

/*
 *********************************************************************************************************
 *                                              INCLUDE FILES
 *********************************************************************************************************
 */

#include <WyzBee.h>
#include <mfs.h>


/*
 *********************************************************************************************************
 *                                                 DEFINES
 *********************************************************************************************************
 */

/*
*********************************************************************************************************
*********************************************************************************************************
*                                                Error Codes
*********************************************************************************************************
*********************************************************************************************************
*/

#define ERR_I2C_UNINITIALIZED	   41u		// I2C module not initialized properly
#define ERR_I2C_TIMEOUT			   42u		// I2C operation timeout

/*
 *********************************************************************************************************
 *                                               DATA TYPES
 *********************************************************************************************************
 */

typedef enum WyzBeeI2c_Mode					/*------------------I2C mode configuration----------------------*/
{
	I2cMasterMode  				=  0,       // Use I2C in Master Mode
	I2cSlaveMode   				=  1        // Use I2C in Slave  Mode
} WyzBeeI2c_Mode_t;




typedef enum WyzBeeI2c_FrequencyDivsion		/*------------------I2C Noise Filter configuration--------------*/
{
	I2cNoizeFilterLess40M  		=  0x00,   	//   8 MHz <= APB1 bus clock <  40 MHz
	I2cNoizeFilterLess60M  		=  0x01,   	//  40 MHz <= APB1 bus clock <  60 MHz
	I2cNoizeFilterLess80M  		=  0x02,   	//  60 MHz <= APB1 bus clock <  60 MHz
	I2cNoizeFilterLess100M 		=  0x03,   	//  80 MHz <= APB1 bus clock < 100 MHz
	I2cNoizeFilterLess120M 		=  0x04,   	// 100 MHz <= APB1 bus clock < 120 MHz
	I2cNoizeFilterLess140M 		=  0x05,   	// 120 MHz <= APB1 bus clock < 140 MHz
	I2cNoizeFilterLess160M 		=  0x06,   	// 140 MHz <= APB1 bus clock < 160 MHz
	I2cNoizeFilterLess180M 		=  0x07,   	// 160 MHz <= APB1 bus clock < 180 MHz
	I2cNoizeFilterLess200M 		=  0x08,   	// 180 MHz <= APB1 bus clock < 200 MHz
	I2cNoizeFilterLess220M 		=  0x09,   	// 200 MHz <= APB1 bus clock < 220 MHz
	I2cNoizeFilterLess240M 		=  0x0A,   	// 220 MHz <= APB1 bus clock < 240 MHz
	I2cNoizeFilterLess260M 		=  0x0B,   	// 240 MHz <= APB1 bus clock < 260 MHz
	I2cNoizeFilterLess280M 		=  0x0C,   	// 260 MHz <= APB1 bus clock < 280 MHz
	I2cNoizeFilterLess300M 		=  0x0D,   	// 280 MHz <= APB1 bus clock < 300 MHz
	I2cNoizeFilterLess320M 		=  0x0E,   	// 300 MHz <= APB1 bus clock < 320 MHz
	I2cNoizeFilterLess340M 		=  0x0F,   	// 320 MHz <= APB1 bus clock < 340 MHz
	I2cNoizeFilterLess360M 		=  0x10,   	// 340 MHz <= APB1 bus clock < 360 MHz
	I2cNoizeFilterLess380M 		=  0x11,   	// 360 MHz <= APB1 bus clock < 380 MHz
	I2cNoizeFilterLess400M 		=  0x12    	// 380 MHz <= APB1 bus clock < 400 MHz

} WyzBeeI2c_FrequencyDivsion_t;


typedef struct WyzBeeI2c_Config				/*------------------I2C initialization config structure---------*/
{
	uint32		I2cDataRate;				// I2C Data rate
	uint8		I2cMode;					// I2C Mode : Master / Slave see description of #WyzBeeI2c_Mode_t
	uint8		NoiseFilterConfig;			// Noise filter see description of  #WyzBeeI2c_FrequencyDivsion_t
	uint8       SlaveAddress;				// Slave Address (Note this is effective when using in Slave Mode)

} WyzBeeI2c_Config_t;

typedef enum WyzBeeI2c_States				/*------------------I2C Data sending states---------------------*/
{
	I2cStateStandby         	=  0,       // I2C doesn't active.
	I2cStateReceiving    		=  1,       // I2C is performing reception.
	I2cStateTransmitting 		=  2        // I2C is performing transmission.
} WyzBeeI2c_States_t;


typedef enum WyzBeeI2c_DataDirection		/*------------------I2C Data Direction--------------------------*/
{
	I2cWrite 					=  0x00,    // Write Mode
	I2cRead  					=  0x01     // Read  Mode
} WyzBeeI2c_DataDirection_t ;


/*
 *********************************************************************************************************
 *                                           FUNCTION PROTOTYPES
 *********************************************************************************************************
 */

err_t   WyzBeeI2c_Init	 ( WyzBeeI2c_Config_t   *p_config  );

err_t   WyzBeeI2c_DeInit ( void                            );

err_t   WyzBeeI2c_Write  ( uint8_t               slave_addr,
						   uint8_t              *p_buf,
						   uint16_t              buf_len   );


err_t   WyzBeeI2c_Read   ( uint8_t               slave_addr,
					       uint8_t              *p_buf,
					       uint16_t             *p_buf_len );

/*
 *********************************************************************************************************
 *                                           END
 *********************************************************************************************************
 */
#ifdef __cplusplus
}
#endif
#endif // WyzBee_I2c_H
