/*
 *********************************************************************************************************
 *
 *                        (c) Copyright 2015-2020 RedPine Signals Inc. HYDERABAD, INDIA
 *                                            All rights reserved.
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
 *											  SPI Driver Source File
 *
 * File           : WyzBee_spi.c
 * Version        : V1.00
 * Programmer(s)  :
 *********************************************************************************************************
 * Note(s)		 :
 *********************************************************************************************************
 */


/*
 *********************************************************************************************************
 *                                              INCLUDE FILES
 *********************************************************************************************************
 */

#include  <WyzBee_spi.h>
//#include <WyzBee_gpio.h>
/*
 *********************************************************************************************************
 *                                              LOCAL DEFINES
 *********************************************************************************************************
 */
#define SPI_INSTANCE    &MFS4
/*
 *********************************************************************************************************
 *                                             LOCAL CONSTANTS
 *********************************************************************************************************
 */

/*
 *********************************************************************************************************
 *                                            LOCAL DATA TYPES
 *********************************************************************************************************
 */

/*
 *********************************************************************************************************
 *                                          LOCAL GLOBAL VARIABLES
 *********************************************************************************************************
 */

/*
 *********************************************************************************************************
 *                                             GLOBAL VARIABLES
 *********************************************************************************************************
 */

/*
 *********************************************************************************************************
 *                                         LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************
 */



/*
 *********************************************************************************************************
 *********************************************************************************************************
 *                                             GLOBAL FUNCTION
 *********************************************************************************************************
 *********************************************************************************************************
 */

/*
 *********************************************************************************************************
 *                                           WyzBeeSPI_Init()
 *
 * Description : Initializes the SPI module with used passed configuration parameters
 *
 * Argument(s) : WyzBeeSpi_Config_t    			pointer to the configuration WyzBee SPI configuration structure
 *
 * Return(s)   : ERR_NONE                 		On successful initialization of the SPI module
 *
 *				 ERR_SPI_UNINITIALIZED      	If SPI modules doesn't configured properly
 *
 *				 ERR_INVALID_PARMS   			If passed parameters to the function was incorrect
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */

err_t WyzBeeSpi_Init(WyzBeeSpi_Config_t   *p_config)
{
	volatile uint16_t res;
	stc_mfs_csio_config_t config_internal;							// Internal SPI configuration structure


	if(p_config!=NULL)												// Check for valid pointers
	{
		memset(&config_internal,0,sizeof(stc_mfs_csio_config_t));	// Clear the local structure variable
		/*--------------Fill user configurations in internal structure-------------*/
		config_internal.bBitDirection	= p_config->BitDirection;
		config_internal.u32DataRate	    = p_config->BaudRate;
		config_internal.bSignalSystem	= p_config->ClockLvl;
		config_internal.u8CharLength	= p_config->DateLen;
		config_internal.u8SyncWaitTime	= p_config->WaitTime;
		config_internal.u8CsioMode		= p_config->Mode;
		config_internal.u8CsioActMode	= MfsCsioActSpiMode;
	}
	else
	{
		return ERR_INVALID_PARMS;									// Return error (invalid parameters)
	}
	FM4_GPIO->PFR5 =  FM4_GPIO->PFR5   | 0x0000001C;				// Set SPI ports as Peripheral I/O ports
	FM4_GPIO->EPFR08= FM4_GPIO->EPFR08 | 0x00000150;				// set MISO , MOSI , CLK functionalities

	(void)Mfs_Csio_DeInit(SPI_INSTANCE);							// De-Init SPI before initializing the module
	/*--------------Initialize the SPI module with user configurations---------*/
	res=Mfs_Csio_Init(SPI_INSTANCE, (stc_mfs_csio_config_t *)&config_internal);
	if(Ok != res)													// Check for Initialization success
	{
		/*--------------If init fails clear the port settings and return ----------*/
		(void)Mfs_Csio_DeInit(SPI_INSTANCE);
		FM4_GPIO->PFR5 =  FM4_GPIO->PFR5   & ~(0x0000001C);			// Clear SPI ports as Peripheral I/O ports
		FM4_GPIO->EPFR08= FM4_GPIO->EPFR08 & ~(0x00000150);			// Clear MISO , MOSI , CLK functionalities
		return ERR_SPI_UNINITIALIZED;								// return error
	}

	Mfs_Csio_SetSckOutEnable(SPI_INSTANCE, TRUE);					// Enable SPI clock
	Mfs_ErrorClear(SPI_INSTANCE);									// Clear Possible errors
	WyzBeeSpi_TxEnable();											// Enable TX (MOSI)
	WyzBeeSpi_RxEnable();											// Enable RX (MISO)

	if(p_config->UseInterrupts==SpiUseIntrMode)						// Check for interrupt mode
	{
		Mfs_SetTxIntCallBack(SPI_INSTANCE, p_config->TxIsr);		// Register the TX call back
		Mfs_SetRxIntCallBack(SPI_INSTANCE, p_config->RxIsr);		// Register the RX call back

		Mfs_InitTxIrq(SPI_INSTANCE);								// init TX IRQ
		Mfs_InitRxIrq(SPI_INSTANCE);								// init RX IRQ
	}
	/*--------------Configure the chip select pin expansion header CS pin------*/
	FM4_GPIO->PFR5_f.P51  = 0u;										// CS pin as GPIO
	FM4_GPIO->DDR5_f.P51  = TRUE;									// CS pin Output
	FM4_GPIO->PDOR5_f.P51 = TRUE;									// CS pin High (Disable by default)

//	WyzBeeGpio_Init(GPIO_SPI2CS,GPIO_OUTPUT,GPIO_HIGH);

	return ERR_NONE;
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_SyncSend()
 *
 * Description : Sends the data on SPI MOSI line
 *
 * Argument(s) : p_buf							pointer to the transmit buffer indicates data to be sent
 *
 *				 buf_len     					Buffer length indicates no.of bytes to be transmitted
 *
 * Return(s)   : ERR_INVALID_PARMS   			If passed parameters to the function was incorrect
 *
 *				 ERR_NONE                		On success
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t WyzBeeSpi_SyncSend(uint8_t *p_buf , uint16_t buf_len)
{

	volatile uint8_t    tx_status;
	volatile uint16_t   send_char;
	volatile uint16_t   Indx;


	if((p_buf!=NULL) && (buf_len!=0))								// check for valid parameters
	{
		send_char=0;
		Indx=0;

		WyzBeeSpi_CsEnable();										// Enable SPI chip select

		while(buf_len!=0)
		{
			do
			{														// Check for Transmission ready
				tx_status = Mfs_GetStatus(SPI_INSTANCE, MFS_CSIO_SSR_TDRE);
			} while ((tx_status & MFS_CSIO_SSR_TDRE)!= MFS_CSIO_SSR_TDRE);

			//send_char =(uint16_t)p_buf[Indx++];
			WyzBeeSpi_Write(p_buf[Indx++]);								// Send SPI data
			buf_len--;
		}

		WyzBeeSpi_CsDisable();										// Disable Chip select
	}
	else
	{
		return ERR_INVALID_PARMS;
	}
	return ERR_NONE;
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_SyncSendRecv()
 *
 * Description : sends and receives the data on SPI
 *
 * Argument(s) : p_tx_buf						pointer to the transmit buffer indicates data to be sent
 *
 *				 p_rx_buf						pointer to the receive buffer, where receive data to be stored.
 *
 *				 tx_len							Transmit data length
 *
 *				 rx_len							Receive data length
 *
 * Return(s)   : ERR_INVALID_PARMS   			If passed parameters to the function was incorrect
 *
 *				 ERR_NONE                 		On success
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t WyzBeeSpi_SyncSendRecv(uint8_t *p_tx_buf , uint16_t tx_len , uint8_t *p_rx_buf , uint16_t rx_len)
{
	volatile uint8_t   rx_status;
	volatile uint8_t   tx_status;
	volatile uint16_t  tx_char,rx_char;
	volatile uint16_t  tx_buf_indx;
	volatile uint16_t  rx_buf_indx;
	uint16_t  MaxTxRxCnt;


	tx_buf_indx=0;
	rx_buf_indx=0;
	// Check for valid pointers and data lengths
	if((p_tx_buf!=NULL) && (p_rx_buf !=NULL) && (tx_len!=0) && (rx_len!=0))
	{
		tx_char=0;
		WyzBeeSpi_CsEnable();										// Enable SPI chip select
		MaxTxRxCnt=MAX(tx_len,rx_len);

		while(MaxTxRxCnt!=0)
		{
			do
			{														// Check for transmission ready
				tx_status = Mfs_GetStatus(SPI_INSTANCE, MFS_CSIO_SSR_TDRE);
			} while ((tx_status & MFS_CSIO_SSR_TDRE)!= MFS_CSIO_SSR_TDRE);

			if(tx_buf_indx <= tx_len)
			{
				//tx_char =(uint16_t)p_tx_buf[tx_buf_indx++];
				WyzBeeSpi_Write(p_tx_buf[tx_buf_indx++]);							// Send SPI data
			}
			else
			{
				tx_buf_indx=0;
				WyzBeeSpi_Write(0xFF);								// dummy data send for reading
			}
			if(rx_buf_indx <= rx_len)
			{
				do
				{													// check for reception ready
					rx_status = Mfs_GetStatus(SPI_INSTANCE, MFS_CSIO_SSR_RDRF);
				} while ((rx_status & MFS_CSIO_SSR_RDRF)!= MFS_CSIO_SSR_RDRF);

				rx_char = WyzBeeSpi_Read();							// Read SPI data
				p_rx_buf[rx_buf_indx++]=(uint8_t)rx_char;
			}
			MaxTxRxCnt--;
		}
		WyzBeeSpi_CsDisable();										// Disable Chip select
	}
	else
	{
		return ERR_INVALID_PARMS;
	}

	return ERR_NONE;
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_SyncRecv()
 *
 * Description : Receives the data from SPI
 *
 * Argument(s) : buf							pointer to the buffer where receive data is stored.
 *
 *				 buf_len						buffer length , no.of bytes to be read.
 *
 * Return(s)   : ERR_INVALID_PARMS   			If passed parameters to the function was incorrect
 *
 *				 ERR_NONE                 		On success
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t  WyzBeeSpi_SyncRecv(uint8_t *buf , uint16_t buf_len)
{

	volatile uint8_t   rx_status;
	volatile uint8_t   tx_status;
	volatile uint16_t  tx_char,rx_char;
	volatile uint16_t  rx_buf_indx;


	tx_char=0x00;
	rx_buf_indx=0;

	if((buf!=NULL) && (buf_len!=0))									// Check for valid pointers
	{
		WyzBeeSpi_CsEnable();										// Enable SPI chip select line
		while(buf_len!=0)
		{
			do
			{														// Check for transmission ready
				tx_status = Mfs_GetStatus(SPI_INSTANCE, MFS_CSIO_SSR_TDRE);
			} while ((tx_status & MFS_CSIO_SSR_TDRE)!= MFS_CSIO_SSR_TDRE);

			WyzBeeSpi_Write(tx_char);  								// Write SPI data

			do
			{														// Check for reception ready
				rx_status = Mfs_GetStatus(SPI_INSTANCE, MFS_CSIO_SSR_RDRF);
			} while ((rx_status & MFS_CSIO_SSR_RDRF)!= MFS_CSIO_SSR_RDRF);

			rx_char = WyzBeeSpi_Read();								// read SPI data

			buf[rx_buf_indx++]=(uint8_t)rx_char;
			buf_len--;
		}
		WyzBeeSpi_CsDisable();										// Disable Chip select
	}
	else
	{
		return ERR_INVALID_PARMS;
	}
	return ERR_NONE;
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_DeInit()
 *
 * Description : De-Initializes the SPI
 *
 * Argument(s) : none
 *
 * Return(s)   : ERR_NONE						On success
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t WyzBeeSpi_DeInit(void)
{
	(void)Mfs_Csio_DeInit(SPI_INSTANCE);							// DeInit the SPI configurations

	FM4_GPIO->PFR5 =  FM4_GPIO->PFR5 & ~(0x0000001C);				// Clear SPI ports as Peripheral I/O ports
	FM4_GPIO->EPFR08= FM4_GPIO->EPFR08 & ~(0x00000150);				// Clear MISO , MOSI , CLK functionalities
	FM4_GPIO->DDR5_f.P53  = FALSE;									// CS as input

	return ERR_NONE;
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_CsEnable()
 *
 * Description : Selects the SPI slave chip
 *
 * Argument(s) : none
 *
 * Return(s)   : none
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
void WyzBeeSpi_CsEnable(void)
{
	FM4_GPIO->PDOR5_f.P51 = FALSE;									// CS = 0 , Enable chip select

	return ;
}


/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_CsDisable()
 *
 * Description : De-Selects the SPI slave chip
 *
 * Argument(s) : none
 *
 * Return(s)   : none
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
void WyzBeeSpi_CsDisable(void)
{
	FM4_GPIO->PDOR5_f.P51 = TRUE;									// CS = 1 , Disable chip select

	return ;
}


/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_TxIntrEnable()
 *
 * Description : Enables the SPI Transmit interrupt
 *
 * Argument(s) : none
 *
 * Return(s)   : ERR_UNKNOWN 					If any error occurs
 *
 *				 ERR_NONE						On success
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t WyzBeeSpi_TxIntrEnable(void)
{
	volatile uint16_t res;


	res = Mfs_SetTxIntEnable(SPI_INSTANCE, TRUE);					// Enable SPI TX Interrupt
	if(res==Ok)
	{
		return ERR_NONE;
	}
	else
	{
		return ERR_UNKNOWN;
	}
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_TxIntrDisable()
 *
 * Description : Disables the SPI Transmit interrupt
 *
 * Argument(s) : none
 *
 * Return(s)   : ERR_UNKNOWN 				If any error occurs
 *
 *				 ERR_NONE					On success
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t WyzBeeSpi_TxIntrDisable(void)
{
	volatile uint16_t res;


	res = Mfs_SetTxIntEnable(SPI_INSTANCE, FALSE);					// Disables the SPI TX interrupt
	if(res == Ok)
	{
		return ERR_NONE;
	}
	else
	{
		return ERR_UNKNOWN;
	}
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_RxIntrEnable()
 *
 * Description : Enables the SPI Receive interrupt
 *
 * Argument(s) : none
 *
 * Return(s)   : ERR_UNKNOWN 				If any error occurs
 *
 *				 ERR_NONE					On success
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t WyzBeeSpi_RxIntrEnable(void)
{
	volatile uint16_t res;


	res = Mfs_SetRxIntEnable(SPI_INSTANCE, TRUE);					// Enable SPI RX interrupt
	if(res == Ok)
	{
		return ERR_NONE;
	}
	else
	{
		return ERR_UNKNOWN;
	}
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_RxIntrDisable()
 *
 * Description : Disables the SPI Receive interrupt
 *
 * Argument(s) : none
 *
 * Return(s)   : ERR_UNKNOWN 				If any error occurs
 *
 *				 ERR_NONE					On success
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t WyzBeeSpi_RxIntrDisable(void)
{
	volatile uint16_t res;


	res = Mfs_SetRxIntEnable(SPI_INSTANCE, FALSE);					// Disable SPI RX interrupt
	if(res == Ok)
	{
		return ERR_NONE;
	}
	else
	{
		return ERR_UNKNOWN;
	}
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_Write()
 *
 * Description : Writes the single character on SPI
 *
 * Argument(s) : tx_char   data to be sent on SPI
 *
 * Return(s)   : ERR_UNKNOWN 				If any error occurs
 *
 *				 ERR_NONE					On success
 * Caller(s)   :
 *
 * Note(s)     : Typically used in SPI TX ISR routine for writing data
 *********************************************************************************************************
 */
err_t WyzBeeSpi_Write(uint8_t tx_char)
{
	volatile uint16_t   res ;
	volatile uint16_t   send_char;

	send_char = (uint16_t )  tx_char;
	res = Mfs_WriteData(SPI_INSTANCE, send_char);						// Write SPI data
	if(res == Ok)
	{
		return ERR_NONE;
	}
	else
	{
		return ERR_UNKNOWN;
	}
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_Read()
 *
 * Description : Reads the single character on SPI
 *
 * Argument(s) : none
 *
 * Return(s)   : rx_char  					received data on SPI
 *
 * Caller(s)   :
 *
 * Note(s)     : Typically used in SPI RX ISR routine for Reading data
 *********************************************************************************************************
 */
uint8_t WyzBeeSpi_Read(void)
{
	volatile uint16_t rx_char;


	rx_char = Mfs_ReadData(SPI_INSTANCE);							// Read SPI data
	return (uint8_t) rx_char;
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_RxEnable()
 *
 * Description : Enables the Receiver module on SPI
 *
 * Argument(s) : none
 *
 * Return(s)   : ERR_UNKNOWN 				If any error occurs
 *
 *				 ERR_NONE					On success
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t WyzBeeSpi_RxEnable(void)
{
	volatile uint16_t res;


	res = Mfs_SetRxEnable(SPI_INSTANCE, TRUE);						// Enable RX channel
	if(res == Ok)
	{
		return ERR_NONE;
	}
	else
	{
		return ERR_UNKNOWN;
	}
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_TxEnable()
 *
 * Description : Enables the Transmitter on SPI
 *
 * Argument(s) :
 *
 * Return(s)   : ERR_UNKNOWN 				If any error occurs
 *
 *				 ERR_NONE					On success
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t WyzBeeSpi_TxEnable(void)
{
	volatile uint16_t res;


	res = Mfs_SetTxEnable(SPI_INSTANCE, TRUE);						// Enable TX channel
	if(res == Ok)
	{
		return ERR_NONE;
	}
	else
	{
		return ERR_UNKNOWN;
	}
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_RxDisable()
 *
 * Description : Disables the Receiver module on SPI
 *
 * Argument(s) : none
 *
 * Return(s)   : ERR_UNKNOWN 				If any error occurs
 *
 *				 ERR_NONE					On success
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t WyzBeeSpi_RxDisable(void)
{
	volatile uint16_t res;


	res = Mfs_SetRxEnable(SPI_INSTANCE, FALSE);						// Disable RX channel
	if(res == Ok)
	{
		return ERR_NONE;
	}
	else
	{
		return ERR_UNKNOWN;
	}
}

/*
 *********************************************************************************************************
 *                                           WyzBeeSpi_TxDisable()
 *
 * Description : Disables the Transmitter on SPI
 *
 * Argument(s) : none
 *
 * Return(s)   : ERR_UNKNOWN 				If any error occurs
 *
 *				 ERR_NONE					On success
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t WyzBeeSpi_TxDisable(void)
{
	volatile uint16_t res;


	res = Mfs_SetTxEnable(SPI_INSTANCE, FALSE);						// Disable TX channel
	if(res == Ok)

	{
		return ERR_NONE;
	}
	else
	{
		return ERR_UNKNOWN;
	}
}

/*
 *********************************************************************************************************
 *                                           END
 *********************************************************************************************************
 */
