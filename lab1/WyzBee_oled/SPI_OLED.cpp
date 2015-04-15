/**
 * @file     SPI_OLED.cpp
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief  SPI_OLED.cpp : contains oled spi channel initialization functions.
 *
 * @section Description : spi transfer , begin , end , bit order and clock divider functions for oled spi channel were implemented
 *
 *
 * @section Improvements :
 *
 */


/*
 * Includes
 */
#include "SPI_OLED.h"
#include "mfs.h"

/* configuration structure of the OLED MFS channel */
static  stc_mfs_csio_config_t stcMfsCsioCfg_oled = {
		16000000,                	// Baud rate
		MfsCsioMaster,          	// Master mode
		MfsCsioActSpiMode,      	// CSIO SPI mode
		MfsSyncWaitZero,        	// Non wait time insersion
		MfsEightBits,           	// 8 data bits
		TRUE,						// FALSE - LSB first, TRUE - MSB first
		TRUE                    	// SCK Mark level High
};

/*===================================================*/
/**
 * @fn			Oled_Cs_Enable(void)
 * @brief		selects the oled chip selects
 * @param 1[in]	none
 * @param 2[in]	none
 * @param[out]	none
 * @return		none
 * @description This API selects the oled OC pin by making it as low .
 */

void Oled_Cs_Enable(void) // OLED CS Enable function
{
	FM4_GPIO->PDOR5_f.P51 = FALSE; // SELECT THE CHIP CS=0
	return ;
}

/*===================================================*/
/**
 * @fn			Oled_Cs_Disable(void)
 * @brief		selects the oled chip selects
 * @param 1[in]	none
 * @param 2[in]	none
 * @param[out]	none
 * @return		none
 * @description This API selects the oled OC pin by making it as high .
 */

void Oled_Cs_Disable(void)  // OLED CS disable function
{
	FM4_GPIO->PDOR5_f.P51 = TRUE;  // DESELECT THE CHIP CS=1
	return ;
}

/*===================================================*/
/**
 * @fn			transfer(unsigned char  tx_char)
 * @brief		this function sends and receives the data from SPI channel MFS3
 * @param 1[in]	char tx_char ,  holds the data to be sent
 * @param 2[in]	none
 * @param[out]	none
 * @return		returns the data received on MISO line
 * @description This function is implemented with SPI read and write it sends the data over MOSI line and receives from MISO line , returns received byte  .
 */

unsigned char SPI_OLEDClass::transfer(unsigned char  tx_char) // SEND AND RECIVE DATA FROM THE SPI MODULE
{
	volatile uint8_t  u8Reg,retval;
	volatile uint16_t u16Data,u16Data_rx;

	u16Data=0;
	Oled_Cs_Enable(); // enable chip select
	do																		 //  SENDING DATA ON  MOSI
	{
		u8Reg = Mfs_GetStatus(&MFS4, MFS_CSIO_SSR_TDRE);
	} while ((u8Reg & MFS_CSIO_SSR_TDRE)!= MFS_CSIO_SSR_TDRE);
	u16Data =(uint16_t)tx_char;
	Mfs_WriteData(&MFS4, u16Data);

	do																		 // RECIEVING DATA ON MISO
	{
		u8Reg = Mfs_GetStatus(&MFS4, MFS_CSIO_SSR_RDRF);
	} while ((u8Reg & MFS_CSIO_SSR_RDRF)!= MFS_CSIO_SSR_RDRF);
	u16Data_rx = Mfs_ReadData(&MFS4);
	retval=(uint8_t)u16Data_rx;

	Oled_Cs_Disable();			// Disable chip select
	return retval;					// returns the recieved data
}

/*===================================================*/
/**
 * @fn			begin(void))
 * @brief		this functions will initializes MFS channel 3 as a OLED SPI
 * @param 1[in]	none
 * @param 2[in]	none
 * @param[out]	none
 * @return		none
 * @description initializes the spi ports and spi configurations like clock frequency , TX , RX enable  , and OLED related PIN functionalities.
 */

void SPI_OLEDClass::begin(void)
{
	FM4_GPIO->PFR5 =  FM4_GPIO->PFR5 | 0x0000001C;			// P52 P53 P54 SIN4_0 SOT4_0 SCK4_0
	FM4_GPIO->EPFR08= FM4_GPIO->EPFR08 | 0x00000150; 		// SELECTEC MFS4 CHANNEL.
	(void)Mfs_Csio_DeInit(&MFS4);
	if (Ok != Mfs_Csio_Init(&MFS4, (stc_mfs_csio_config_t *)&stcMfsCsioCfg_oled))  // INIT THE MFS4 SPI CHANNEL
	{
		(void)Mfs_Csio_DeInit(&MFS4);
		FM4_GPIO->PFR5 =  FM4_GPIO->PFR5 | 0x0000001C;			// P52 P53 P54 SIN4_0 SOT4_0 SCK4_0
		FM4_GPIO->EPFR08= FM4_GPIO->EPFR08 | 0x00000150; 		// SELECTEC MFS4 CHANNEL.
	}
	Mfs_Csio_SetSckOutEnable(&MFS4, TRUE); 				// Enable serial clock output
	Mfs_ErrorClear(&MFS4); 						// Clear possible reception errors
	Mfs_SetTxEnable(&MFS4, TRUE); 			// Enable TX function
	Mfs_SetRxEnable(&MFS4, TRUE); 			// Enable RX function

	// CS CONFIG
	FM4_GPIO->PFR5_f.P51 = 0u;				// CS as GPIO
	FM4_GPIO->DDR5_f.P51  = TRUE;			// CS as OUTPUT
	FM4_GPIO->PDOR5_f.P51 = TRUE;			// DEFAULT HIGH DESELT THE CHIP

	// DC
	FM4_GPIO->PFR4_f.P40 = 0u; 				// P40  DC AS GPIO
	FM4_GPIO->DDR4_f.P40  = TRUE;  			// P40 	DC OUTPUT
	return;
}

/*===================================================*/
/**
 * @fn			end(void))
 * @brief		this functions will de-inits the SPI MFS3 channel
 * @param 1[in]	none
 * @param 2[in]	none
 * @param[out]	none
 * @return		none
 * @description this API de selects the all the spi configurations and makes as default GPIO pins.
 */

void SPI_OLEDClass::end(void)
{
	//  DE-INIT THE MODULE
	(void)Mfs_Csio_DeInit(&MFS4);
	FM4_GPIO->PFR5 =  FM4_GPIO->PFR5 & ~(0x0000001C); 		// P33,P34,P35 :: P33-SIN4_1,P34-SOT4_1,P35-SCK4_1
	FM4_GPIO->EPFR08= FM4_GPIO->EPFR08 & ~(0x00000150); 	// SELECTEC MFS4 CHANNEL.
	FM4_GPIO->DDR5_f.P53  = FALSE; // CS AS IN
	FM4_GPIO->PDOR5_f.P53 = FALSE; // CS =0
	return ;
}


/*===================================================*/
/**
 * @fn			setBitOrder(unsigned char bit_order)
 * @brief		Sets the SPI bit Order
 * @param 1[in]	bit_order ,  bit order parameter
 * @param 2[in]	none
 * @param[out]	none
 * @return		none
 * @description this function selects the SPI channel BIT order MSB/LSB first
 */

void SPI_OLEDClass::setBitOrder(unsigned char bit_order) // SET DAATA ORDER OF THE SPI CHANNEL
{

	if(LSBFIRST==bit_order)
	{
		stcMfsCsioCfg_oled.bBitDirection=LSBFIRST;  // 1= MSB FIRST,0=LSB FIRST
	}
	else
	{
		stcMfsCsioCfg_oled.bBitDirection=MSBFIRST;  // 1= MSB FIRST,0=LSB FIRST
	}
	(void)Mfs_Csio_DeInit(&MFS4);
	if (Ok != Mfs_Csio_Init(&MFS4, (stc_mfs_csio_config_t *)&stcMfsCsioCfg_oled))  // INIT THE MFS4 SPI CHANNEL
	{
		(void)Mfs_Csio_DeInit(&MFS4);
		FM4_GPIO->PFR5 =  FM4_GPIO->PFR5 & ~(0x0000001C); 		// P33,P34,P35 :: P33-SIN4_1,P34-SOT4_1,P35-SCK4_1
		FM4_GPIO->EPFR08= FM4_GPIO->EPFR08 & ~(0x00000150); 	// SELECTEC MFS4 CHANNEL.
	}
	return ;
}

/*===================================================*/
/**
 * @fn			setClockDivider(unsigned char div_num)
 * @brief		sets the SPI clock frequency
 * @param 1[in]	div_num , clock divider number
 * @param 2[in]	none
 * @param[out]	none
 * @return		none
 * @description This function divides the systems clock frequency and sets the appropriate SPI clock , based on division number passed to it .
 */

void SPI_OLEDClass::setClockDivider(unsigned char div_num) // SET CLOCK FREQUENCY OF THE SPI CHANNEL
{
	switch(div_num)
	{
	case SPI_CLOCK_DIV2:
		stcMfsCsioCfg_oled.u32DataRate=FRQ_80_MHZ;  // 80MHZ-SPI CLOCK
		break;
	case SPI_CLOCK_DIV4:
		stcMfsCsioCfg_oled.u32DataRate=FRQ_40_MHZ;	// 40MHZ-SPI CLOCK
		break;
	case SPI_CLOCK_DIV8:
		stcMfsCsioCfg_oled.u32DataRate=FRQ_20_MHZ;	// 20MHZ-SPI CLOCK
		break;
	case SPI_CLOCK_DIV16:
		stcMfsCsioCfg_oled.u32DataRate=FRQ_10_MHZ;	// 10MHZ-SPI CLOCK
		break;
	case SPI_CLOCK_DIV32:
		stcMfsCsioCfg_oled.u32DataRate=FRQ_5_MHZ;		// 5MHZ-SPI CLOCK
		break;
	default:
		break;
	}
	(void)Mfs_Csio_DeInit(&MFS4);
	if (Ok != Mfs_Csio_Init(&MFS4, (stc_mfs_csio_config_t *)&stcMfsCsioCfg_oled))  // INIT THE MFS4 SPI CHANNEL
	{
		(void)Mfs_Csio_DeInit(&MFS4);
		FM4_GPIO->PFR5 =  FM4_GPIO->PFR5 & ~(0x0000001C); 		// P33,P34,P35 :: P33-SIN4_1,P34-SOT4_1,P35-SCK4_1
		FM4_GPIO->EPFR08= FM4_GPIO->EPFR08 & ~(0x00000150); 	// SELECTEC MFS4 CHANNEL.
	}

	return ;
}

/*===================================================*/
/**
 * @fn			setDataMode(unsigned char data_mode)
 * @brief		sets the SPI data mode
 * @param 1[in]	data_mode
 * @param 2[in]	none
 * @param[out]	none
 * @return		none
 * @description this functions sets the SPI standard modes like MODE 0 ,MODE 1 ,MODE 2 ,MODE 3  */

void SPI_OLEDClass::setDataMode(unsigned char data_mode) // SET DATA MODE OF THE SPI CHANNEL
{
	return ;
}

SPI_OLEDClass SPI;
