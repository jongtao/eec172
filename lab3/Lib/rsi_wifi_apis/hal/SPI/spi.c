/**
 * @file     spi.c
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief : this file contains Functions to initialize the MFS channel of WIFI SPI.
 *
 * @section Description
 * This file contains the
 * wifi_cs_enable()
 * wifi_cs_disable()
 * wifi_reset_routine()
 * wifi_module_init()
 * rsi_spi_recv()
 * rsi_spi_send()
 *
 *
 *
 */

/**
 * Includes
 */
#include "spi.h"
#include <mfs.h>
#include "mcu.h"
#include "rsi_global.h"
#include "rsi_app.h"
#include "rsi_api.h"
#include "exint.h"
#include "gpio.h"
//#include <WyzBee_kit.h>

#define WyzBee_REV_5 1
/* configuration structure for Wifi SPI channel  */
static const stc_mfs_csio_config_t stcMfsCsioCfg = {
		16000000,                // Baud rate
		MfsCsioMaster,          // Master mode
		MfsCsioActSpiMode,      // CSIO SPI mode
		MfsSyncWaitZero,        // Non wait time insersion
		MfsEightBits,           // 8 data bits
		TRUE,                  // FALSE - LSB first, TRUE - MSB first
		TRUE                    // SCK Mark level High
};


/*===================================================*/
/**
 * @fn			:wifi_cs_enable(void)
 * @brief		:selects the RS9113 modules chip select line
 * @param 1[in]	:none
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:none
 * @description :this functions selects the RS9113 wifi module's chip select line by making it zero.
 */

static void wifi_cs_enable(void)
{
	// ENABLE CS
		FM4_GPIO->PDOR0_f.P0E = 0u;				// LOW
}


/*===================================================*/
/**
 * @fn			:wifi_cs_disable(void)
 * @brief		:de-selects the RS9113 modules chip select line
 * @param 1[in]	:none
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:none
 * @description :this functions de-selects the RS9113 wifi module's chip select line by making it zero.
 */
static void wifi_cs_disable(void)
{
	// DISABLE CS
		FM4_GPIO->PDOR0_f.P0E = 1u;		 		//  HIGH
	
}


/*===================================================*/
/**
 * @fn			:wifi_reset_routine (void)
 * @brief		:This function will initializes the RESET pin and makes low to high transition pulse with 20ms off time .
 * @param 1[in]	:none
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:none
 * @description :This function will initializes the GPIO pin which acts as a RESET for the RS-9113 module and makes low to high transition pulse with 20ms off time .
 */
void wifi_reset_routine (void)
{
#if WyzBee_REV_1 // P41 RESET AN9

	FM4_GPIO->ADE_f.AN9 = 0;			// TURN OFF ANALOG FUN ON P41
	FM4_GPIO->PFR4_f.P41 = 0u;	// P41 RESET AS GPIO
	FM4_GPIO->DDR4_f.P41 = 1u;	// P41 RESET OUTPUT

	/*		reset power cycle  (calling from module_power_cycle)


	  					    __________________________________________
						   |
	  _____________________|
	  (>=20ms OFF (LOW)time)		(Should be always HIGH  from here )

	 */

	FM4_GPIO->PDOR4_f.P41 = 0u;	// P41 RESET LOW
	delay(20); 									// >30ms delay_spi
	FM4_GPIO->PDOR4_f.P41 = 1u;	// RESET ON
	return;
#endif

#if WyzBee_REV_5 // P26 RESET AN0

		FM4_GPIO->PFR1_f.P1E = 0u;	// P41 RESET AS GPIO
	FM4_GPIO->DDR1_f.P1E = 1u;	// P41 RESET OUTPUT


	/*		reset power cycle  (calling from module_power_cycle)

	  	  					   __________________________________________
	  	  					   |
	  	  _____________________|
	  	  (>=20ms OFF (LOW)time)		(Should be always HIGH  from here )

	 */

	FM4_GPIO->PDOR1_f.P1E = 0u;	// P41 RESET LOW
	delay(100); 									// >30ms delay_spi
	FM4_GPIO->PDOR1_f.P1E = 1u;	// RESET ON
	return;

#endif
}


/*===================================================*/
/**
 * @fn			:wifi_spi_init(void)
 * @brief		:this function initializes the MFS channel which is used for RS9113 module
 * @param 1[in]	:none
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:none
 * @description :This function will initialize MFS1 ports and chip select wichi is used for RS9113 and disables the Analog functionalities on those MFS1_1 ports
 */

void WyzBee_spi_init(void)
{
#if 1 // WIFI MODULE CS
	FM4_GPIO->ADE= 0;						// TURN OFF ANALOG
	FM4_GPIO->PFR0_f.P0E   = 0u;				// P0E CS AS GPIO
	FM4_GPIO->DDR0_f.P0E   = 1u;				// P0E  OUTPUT
	FM4_GPIO->PDOR0_f.P0E  = 1u;				// P0E DEFAULT HIGH
#endif
#if 1  //wifi uart pins
	FM4_GPIO->PFR3_f.P36   = 0u;				// P36 uart out AS GPIO
	FM4_GPIO->DDR3_f.P36   = 0u;				// P36  ip
	FM4_GPIO->PFR3_f.P37   = 0u;				// P36 uart in AS GPIO
	FM4_GPIO->DDR3_f.P37   = 0u;				// P36  ip
#endif
	FM4_GPIO->PFR0   = FM4_GPIO->PFR0 | 0X3800;					// P0B P0C P0D P0E
	FM4_GPIO->EPFR08 = FM4_GPIO->EPFR08 | 0X002A0000; // MFS CH6
	//FM4_GPIO->EPFR16 = FM4_GPIO->EPFR16 | 0X00000002; // MFS CH6 SCS6_1
	//SPI mode configuration
	// HOST SEL
#if 0
	FM4_GPIO->PFR3_f.P3E = 0u;				//@ P3E   AS GPIO
	FM4_GPIO->DDR3_f.P3E = 1u;				//@ P3E   OUTPUT
	FM4_GPIO->PDOR3_f.P3E = 1u;				//@ P3E  HIGH  host_sel 1 SPI MODE (default)
#endif
	// WiFi Gate
#if 1
	FM4_GPIO->PFR1_f.P11 = 0u;				//@ P11   AS GPIO
	FM4_GPIO->DDR1_f.P11 = 1u;				//@ P11   OUTPUT
	FM4_GPIO->PDOR1_f.P11 = 1u;				//@ P11   power OFF module at first
#endif
	(void)Mfs_Csio_DeInit(&MFS6); 										// At first un-initialize CSIO
	if (Ok != Mfs_Csio_Init(&MFS6, (stc_mfs_csio_config_t *)&stcMfsCsioCfg)) 	// Initialize MFS ch.2 as SPI master
	{
		(void)Mfs_Csio_DeInit(&MFS6);
		FM4_GPIO->PFR0 = FM4_GPIO->PFR0 | 0x3800;					// P0B P0C P0D P0E :
		FM4_GPIO->EPFR08 = FM4_GPIO->EPFR08 | 0X002A0000; // MFS CH6
	}
	Mfs_Csio_SetSckOutEnable(&MFS6, TRUE);	// Enable serial clock output

	Mfs_SetTxEnable(&MFS6, TRUE);	// Enable TX function

	Mfs_SetRxEnable(&MFS6, TRUE);	// Enable RX function


	return;
}


/*===================================================*/
/**
 * @fn			:wifi_module_init (void)
 * @brief		:this function will initializes the MFS 1 channel which is used for RS9113 module
 * @param 1[in]	:none
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:none
 * @description :this function will initializes the MFS 1 channel which is used for RS9113 module
 */
void wifi_module_init (void)
{
	WyzBee_spi_init (); // inits the SPI channel
	return;
}

/*==================================================================*/
/**
 * @fn 		int16 rsi_spi_send(uint8 *ptrBuf,uint16 bufLen,uint8 *valBuf,uint8 mode)
 * @param[in]	uint8 *ptrBuf, pointer to the buffer with the data to be sent/received
 * @param[in]	uint16 bufLen, number of bytes to send
 * @param[in]	uint8 *valBuf, pointer to the buffer where the response is stored
 * @param[in]	uint8 mode, To indicate mode 8 BIT/32 BIT.
 * @param[out]	None
 * @return	0, 0=success
 * @section description
 * This API is used to send data to the Wi-Fi module through the SPI interface.
 */

int16 rsi_spi_send(uint8 *ptrBuf, uint16 bufLen, uint8 *valBuf, uint8 mode)
{
	volatile uint8   u8Reg;
	volatile uint16_t   u16Data_tx, u16Data_rx;

	volatile uint16				i, j;
#ifdef RSI_BIT_32_SUPPORT
	uint32 dummy_ret;
#else
	//uint8 dummy_ret;
#endif
	wifi_cs_enable ();
	for (i = 0, j = 0; i < bufLen; j++)
	{
#ifdef RSI_BIT_32_SUPPORT
		if (mode == RSI_MODE_8BIT)
#endif
		{
			u16Data_tx = 0;
			u16Data_rx=0;
				do
			{
				u8Reg = Mfs_GetStatus(&MFS6, MFS_CSIO_SSR_TDRE);
			} while ((u8Reg & MFS_CSIO_SSR_TDRE) != MFS_CSIO_SSR_TDRE);

			u16Data_tx = (uint16)ptrBuf[i];
			Mfs_WriteData(&MFS6, u16Data_tx);
			i += 1;

			do
			{
				u8Reg = Mfs_GetStatus(&MFS6, MFS_CSIO_SSR_RDRF);
			} while ((u8Reg & MFS_CSIO_SSR_RDRF) != MFS_CSIO_SSR_RDRF);

			u16Data_rx = Mfs_ReadData(&MFS6);
		}
#ifdef RSI_BIT_32_SUPPORT
else
{

}
#endif
		if ((j < 2))
		{
#ifdef RSI_BIT_32_SUPPORT
			if (mode == RSI_MODE_8BIT)
#endif
			{
				valBuf[j] = (uint8)u16Data_rx;
			}
#ifdef RSI_BIT_32_SUPPORT
			else
			{

			}
#endif
		}
		else
		{
#ifdef RSI_BIT_32_SUPPORT
			if (mode == RSI_MODE_8BIT)
#endif

#ifdef RSI_BIT_32_SUPPORT
				else
#endif
		}
	}
	wifi_cs_disable();
	return 0;
}


/*==================================================================*/
/**
 * @fn 		int16 rsi_spi_recv(uint8 *ptrBuf,uint16 bufLen,uint8 mode)
 * @param[in]	uint8 *ptrBuf, pointer to the buffer with the data to be sent/received
 * @param[in]	uint16 bufLen, number of bytes to send
 * @param[in]	uint8 mode, To indicate the mode 8 BIT / 32 BIT.
 * @param[out]	None
 * @return	0, 0=success
 * @description	This API is used to receive data from Wi-Fi module through the SPI interface.
 */

int16 rsi_spi_recv(uint8 *ptrBuf, uint16 bufLen, uint8 mode)
{
	volatile int16 i;
	volatile uint16_t    u16Data_dumy = 0, u16Data;

#ifdef RSI_BIT_32_SUPPORT
	uint32              dummy = 0;
#else
	uint8              u8Reg;
#endif

	wifi_cs_enable ();
	for (i = 0; i < bufLen; )
	{
#ifdef RSI_BIT_32_SUPPORT
		if (mode == RSI_MODE_8BIT)
#endif
		{
	do
			{
				u8Reg = Mfs_GetStatus(&MFS6, MFS_CSIO_SSR_TDRE);
			} while ((u8Reg & MFS_CSIO_SSR_TDRE) != MFS_CSIO_SSR_TDRE);

			Mfs_WriteData(&MFS6, u16Data_dumy);
			do
			{
				u8Reg = Mfs_GetStatus(&MFS6, MFS_CSIO_SSR_RDRF);
			} while ((u8Reg & MFS_CSIO_SSR_RDRF) != MFS_CSIO_SSR_RDRF);

			u16Data = Mfs_ReadData(&MFS6);
			ptrBuf[i] = (uint8)u16Data;
			i++;
		}
#ifdef RSI_BIT_32_SUPPORT
else
{

}
#endif

#ifdef RSI_BIT_32_SUPPORT
		if (mode == RSI_MODE_8BIT)
#endif
		{

		}
#ifdef RSI_BIT_32_SUPPORT
		else
		{

		}
#endif
#ifdef RSI_DEBUG_PRINT
		RSI_DPRINT(RSI_PL10, "%02x", (uint16)ptrBuf[i]);
#endif
	}
	wifi_cs_disable();
	return 0;
}


void power_on(void)
{
	FM4_GPIO->ADE= 0;			// TURN OFF ANALOG FUN ON P41
	FM4_GPIO->PFR6_f.P66 = 0u;	// P66 POWER  AS GPIO
	FM4_GPIO->DDR6_f.P66 = 1u;	// P66 POWER OUTPUT

	FM4_GPIO->PDOR6_f.P66 = 1u;	// POWER ON
	delay(2000);
}
