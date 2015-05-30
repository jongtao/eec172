/**
 * @file       rsi_hal_mcu_spi.c
 * @version    2.3.0.0
 * @date       2011-May-30
 *
 * Copyright(C) Redpine Signals 2011
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief HAL SPI API
 *
 * @Description:
 * This file Contains all the API's related to HAL 
 *
 */


/**
 * Includes
 */
#include "rsi_global.h"

/**
 * Global Variables
 */

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
#if 0
int16 rsi_spi_send(uint8 *ptrBuf, uint16 bufLen,uint8 *valBuf,uint8 mode)
{
	uint8  ch,response,u8Reg;
	uint16_t    u16Data,u16Data_tx,u16Data_rx;

	uint16				i,j;
#ifdef RSI_BIT_32_SUPPORT
	uint32 dummy_ret;
#else
	uint8 dummy_ret;
#endif
	SampleMfsSpiEnableCs ();
	for (i=0,j=0; i < bufLen; j++)
	{
		#ifdef RSI_BIT_32_SUPPORT
		if(mode == RSI_MODE_8BIT)
		#endif
		{
			u16Data=0;
			do
			{
				u8Reg = Mfs_GetStatus(&MFS1, MFS_CSIO_SSR_TDRE);
			} while (0 == u8Reg);

			u16Data_tx =(uint16)ptrBuf[i];
			Mfs_WriteData(&MFS1, u16Data_tx);
			i+=1;

			do
			{
				u8Reg = Mfs_GetStatus(&MFS1, 0xFF);
			} while (0 == (u8Reg & MFS_CSIO_SSR_RDRF));

			 u16Data_rx = Mfs_ReadData(&MFS1);
		}
		#ifdef RSI_BIT_32_SUPPORT
		else
		{

		}
		#endif
		if((j<2))
		{
			#ifdef RSI_BIT_32_SUPPORT
			if(mode == RSI_MODE_8BIT)
			#endif
			{
				valBuf[j]=(uint8)u16Data_rx;
			}
			#ifdef RSI_BIT_32_SUPPORT
			else
			{
					Serial.println("TX in 32 bit");
			}
			#endif
		}
		else
		{
			#ifdef RSI_BIT_32_SUPPORT
			if(mode == RSI_MODE_8BIT)
			#endif

			#ifdef RSI_BIT_32_SUPPORT
			else
			#endif
		}
	}
	SampleMfsSpiDisableCs();
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
	int16				i;
	uint16_t    u16Data_dumy=0,u16Data;

#ifdef RSI_BIT_32_SUPPORT
	uint32              dummy=0;
#else
	uint8              dummy=0,u8Reg;
#endif

	SampleMfsSpiEnableCs ();
	for (i=0; i < bufLen; )
	 {
		#ifdef RSI_BIT_32_SUPPORT
		if(mode == RSI_MODE_8BIT)
		#endif
		{
			do
			{
				u8Reg = Mfs_GetStatus(&MFS1, MFS_CSIO_SSR_TDRE);
			} while (0 == u8Reg);

			Mfs_WriteData(&MFS1, u16Data_dumy);
			//i+=1;
			do
			{
				u8Reg = Mfs_GetStatus(&MFS1, 0xFF);
			} while (0 == (u8Reg & MFS_CSIO_SSR_RDRF));

			u16Data = Mfs_ReadData(&MFS1);
			ptrBuf[i]=(uint8)u16Data;
			i++;
		}
		#ifdef RSI_BIT_32_SUPPORT
		else
		{

		}
		#endif

		#ifdef RSI_BIT_32_SUPPORT
		if(mode == RSI_MODE_8BIT)
		#endif
		{

		}
		#ifdef RSI_BIT_32_SUPPORT
		else
		{

		}
		#endif
		#ifdef RSI_DEBUG_PRINT
		RSI_DPRINT(RSI_PL10,"%02x", (uint16)ptrBuf[i]);
		#endif
	}
	SampleMfsSpiDisableCs();
	return 0;
}
#endif


