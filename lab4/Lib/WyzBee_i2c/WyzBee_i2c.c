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
 *											  I2C Driver Source File
 *
 * File           : WyzBee_i2c.c
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

#include <WyzBee_i2c.h>
/*
 *********************************************************************************************************
 *                                              LOCAL DEFINES
 *********************************************************************************************************
 */
#define I2C_INSTANCE	&MFS7
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
static volatile uint8_t   		I2cStatus   ;
static 			uint8_t* 		GlobalBuf   ;
static 			uint16_t 		GlobalBufLen;
static 			uint16_t 		RxBufIndex  ;
static 			uint16_t 		TxBufIndex  ;

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
static void   WyzBeeI2c_TxIsr           (void);
static void   WyzBeeI2c_RxIsr           (void);
static void   WyzBeeI2c_SatusIsr        (void);
static err_t  WyzBeeI2cWaitTxRxComplete (void);

/*
 *********************************************************************************************************
 *********************************************************************************************************
 *                                             GLOBAL FUNCTIONS
 *********************************************************************************************************
 *********************************************************************************************************
 */

/*
 *********************************************************************************************************
 *                                           WyzBeeI2c_Init()
 *
 * Description : Initializes the WyzBee I2C module
 *
 * Argument(s) : p_config						Pointer to the I2C Configuration structure
 *
 * Return(s)   : ERR_NONE                 		On successful initialization of the I2C module
 *
 *				 ERR_I2C_UNINITIALIZED      	If I2C modules doesn't configured properly
 *
 *				 ERR_INVALID_PARMS   			If passed parameters to the function was incorrect
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */

err_t WyzBeeI2c_Init( WyzBeeI2c_Config_t    *p_config )
{
	volatile uint16_t 	  retval;
	stc_mfs_i2c_config_t  config_internal; 								// internal i2c configuration structure variable


	if(p_config  !=  NULL) 												// check for valid pointer
	{
		memset(&config_internal , 0 , sizeof(stc_mfs_i2c_config_t));

		config_internal.u32DataRate   = p_config->I2cDataRate;
		config_internal.u8I2cMode     = p_config->I2cMode;
		config_internal.u8NoizeFilter = p_config->NoiseFilterConfig;
		config_internal.u8SlvAddr     = p_config->SlaveAddress;
		config_internal.u8FastMode    = 0u;

		FM4_GPIO->ADE_f.AN21          = 0u;   							// Disable the Analog channel (AN21) on P07 port
		FM4_GPIO->ADE_f.AN22          = 0u;   							// Disable the Analog channel (AN22) on P06 port
		FM4_GPIO->PFR0_f.P06          = 1u;   							// P06 as Peripheral Function
		FM4_GPIO->PFR0_f.P07          = 1u;   							// P07 as Peripheral Function
		FM4_GPIO->EPFR08              = FM4_GPIO->EPFR08 | 0x05000000; 	// Set SCK7_0 and SOT7_0 functionality for clock and data respectively

		(void)Mfs_Csio_DeInit(I2C_INSTANCE); 						 	// De-Init the Channel before initializing.
																		/* Configure the I2c with user settings*/
		retval = Mfs_I2c_Init(I2C_INSTANCE, (stc_mfs_i2c_config_t *)&config_internal);

		if(retval == Ok)
		{
			Mfs_SetTxIntCallBack (I2C_INSTANCE , WyzBeeI2c_TxIsr   );	// Register I2c TX ISR
			Mfs_SetRxIntCallBack (I2C_INSTANCE , WyzBeeI2c_RxIsr   );	// Register I2c RX ISR
			Mfs_SetStsIntCallBack(I2C_INSTANCE , WyzBeeI2c_SatusIsr);	// Register I2c Status ISR
			Mfs_InitTxIrq(I2C_INSTANCE);								// Init transmission interrupt
			Mfs_InitRxIrq(I2C_INSTANCE);								// Init reception interrupt
			I2cStatus = I2cStateStandby;								// Initial State
		}
		else
		{
			FM4_GPIO->ADE_f.AN21  = 1u;   								// Enable the Analog channel (AN21) on P07 port
			FM4_GPIO->ADE_f.AN22  = 1u;   								// Enable the Analog channel (AN22) on P06 port
			FM4_GPIO->PFR0_f.P06  = 0u;   								// P06 as Normal GPIO
			FM4_GPIO->PFR0_f.P07  = 0u;									// P07 as Normal GPIO
			FM4_GPIO->EPFR08      = FM4_GPIO->EPFR08 & ~(0x05000000);	// Clear the SCK7_0 and SOT7_0 functionality for clock and data respectively

			(void)Mfs_Csio_DeInit(I2C_INSTANCE); 						// Clear the Channel before initialization.

			return ERR_I2C_UNINITIALIZED; 								// Err I2C not Configured
		}
	}
	else
	{
		return ERR_INVALID_PARMS;  										// Err Invalid parameters
	}

	return ERR_NONE ;													// No error
}

/*
 *********************************************************************************************************
 *                                           WyzBeeI2c_DeInit()
 *
 * Description : De-Initializes the WyzBee I2C module
 *
 * Argument(s) : None
 *
 * Return(s)   : ERR_NONE                 		On successful initialization of the I2C module
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */


err_t WyzBeeI2c_DeInit( void )
{
	FM4_GPIO->ADE_f.AN21  =  1u;										// Enable the Analog channel (AN21) on P07 port
	FM4_GPIO->ADE_f.AN22  =  1u;										// Enable the Analog channel (AN21) on P07 port
	FM4_GPIO->PFR0_f.P06  =  0u;										// P06 as GPIO
	FM4_GPIO->PFR0_f.P07  =  0u;										// P06 as GPIO
	FM4_GPIO->EPFR08      = FM4_GPIO->EPFR08 & ~(0x05000000);			// Disable peripheral functionality

	(void)Mfs_Csio_DeInit(I2C_INSTANCE); 								// De-Inits the I2C channel

	return ERR_NONE ;
}

/*
 *********************************************************************************************************
 *                                           WyzBeeI2c_Write()
 *
 * Description : Sends the I2c data To the slave.
 *
 * Argument(s) : slave_addr						Slave Address To which data to be transmitted
 *
 * 				 p_buf							Pointer to the Transmit data buffer
 *
 * 				 buf_len						Date length to be transmitted
 *
 * Return(s)   : ERR_NONE                 		On successful initialization of the I2C module
 *
 *				 ERR_I2C_UNINITIALIZED      	If I2C modules doesn't configured properly
 *
 *				 ERR_INVALID_PARMS   			If passed parameters to the function was incorrect
 *
 *				 ERR_I2C_TIMEOUT				Time out error
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */
err_t  WyzBeeI2c_Write( uint8_t    slave_addr,
						uint8_t   *p_buf,
						uint16_t   buf_len)
{
	volatile uint16_t retval;

	union																/*--------------------SMR Bit fields union for configuring I2C modes--------------------*/
	{																	/*																						*/
		uint8_t                  u8SMR;									/*																						*/
		stc_mfs_smr_field_t      stcSMR;								/*																						*/
	} unSMR;															/*--------------------------------------------------------------------------------------*/

	union																/*--------------------IBCR Bit fields union for configuring I2C modes-------------------*/
	{																	/*																						*/
		uint8_t                  u8IBCR;								/*																						*/
		stc_mfs_i2c_ibcr_field_t stcIBCR;								/*																						*/
	} unIBCR;															/*--------------------------------------------------------------------------------------*/


	if( (p_buf != NULL) && (buf_len != 0u) )  // check for valid parameters
	{
		GlobalBuf     =  p_buf;
		GlobalBufLen  =  buf_len;
		TxBufIndex    =  0;
		I2cStatus     =  I2cStateTransmitting;							//Change I2C state to Transmitting

		Mfs_WriteData(I2C_INSTANCE, (uint16_t)(((uint8_t)slave_addr << 1) | I2cWrite));

		unIBCR.u8IBCR           =  Mfs_GetIBCR(I2C_INSTANCE);			// Get the I2C Bus Control Register for current I2C instance
		unIBCR.stcIBCR.MSS      =  TRUE;								// Set master mode
		unIBCR.stcIBCR.ACKE     =  TRUE;								// Enable ACK
		unIBCR.stcIBCR.INTE     =  TRUE;								// Enable interrupt
		unIBCR.stcIBCR.ACT_SCC  =  FALSE;								// The master mode operation is waited when MSS=1 and ACT_SCC=0.
		unIBCR.stcIBCR.WSEL     =  FALSE;								// wait select

		Mfs_SetIBCR(I2C_INSTANCE, unIBCR.u8IBCR);						// Update the configurations in IBCR register

		unSMR.u8SMR             =  Mfs_GetSMR(I2C_INSTANCE);			// Get the SMR (Serial Mode Register)
		unSMR.stcSMR.TIE        =  TRUE;								// Enables the transmit interrupt.

		Mfs_SetSMR(I2C_INSTANCE, unSMR.u8SMR);							// Update the SMR fields for Current I2C Instance

		retval = WyzBeeI2cWaitTxRxComplete();							// Wait until TX is completed

		if (0 == TxBufIndex)
		{
			return ERR_I2C_TIMEOUT;										// Time Out for Transmission
		}
	}
	else
	{
		return ERR_INVALID_PARMS;
	}

	return ERR_NONE;
}

/*
 *********************************************************************************************************
 *                                           WyzBeeI2c_Read()
 *
 * Description : Receives the I2c data From slave.
 *
 * Argument(s) : slave_addr						Slave Address From which data to be Received
 *
 * 				 p_buf							Pointer to the receive data buffer
 *
 * 				 p_buf_len						Data length to be received
 *
 *
 * Return(s)   : ERR_NONE                 		On successful initialization of the I2C module
 *
 *				 ERR_I2C_UNINITIALIZED      	If I2C modules doesn't configured properly
 *
 *				 ERR_INVALID_PARMS   			If passed parameters to the function was incorrect
 *
 *				 ERR_I2C_TIMEOUT				Time out error
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */

err_t WyzBeeI2c_Read(uint8_t    slave_addr,
					 uint8_t   *p_buf,
					 uint16_t  *p_buf_len)
{
	uint16_t retval;

	union																/*--------------------SMR Bit fields union for configuring I2C modes--------------------*/
	{																	/*																						*/
		uint8_t                  u8SMR;									/*																						*/
		stc_mfs_smr_field_t      stcSMR;								/*																						*/
	} unSMR;															/*--------------------------------------------------------------------------------------*/

	union																/*--------------------IBCR Bit fields union for configuring I2C modes-------------------*/
	{																	/*																						*/
		uint8_t                  u8IBCR;								/*																						*/
		stc_mfs_i2c_ibcr_field_t stcIBCR;								/*																						*/
	} unIBCR;															/*--------------------------------------------------------------------------------------*/

	if ( (NULL == p_buf) ||  (NULL == p_buf_len) )						// Check for valid pointers
	{
		return ERR_INVALID_PARMS ;
	}

	GlobalBuf       =  p_buf;
	GlobalBufLen    = *p_buf_len;
	RxBufIndex      =  0;
	I2cStatus       =  I2cStateReceiving;								// Change I2C state to Receiving

	Mfs_WriteData(I2C_INSTANCE, (uint16_t)(((uint8_t)slave_addr << 1) | I2cRead));

	unIBCR.u8IBCR          =  Mfs_GetIBCR(I2C_INSTANCE);				// Get the Serial Control Register for current I2C instance
	unIBCR.stcIBCR.ACKE    =  TRUE;										// Enable ACK
	unIBCR.stcIBCR.WSEL    =  TRUE;										// wait select
	unIBCR.stcIBCR.INTE    =  TRUE;										// interrupt enable
	unIBCR.stcIBCR.ACT_SCC =  FALSE;									
	unIBCR.stcIBCR.INT     =  FALSE;									//Clear interrupt
	unIBCR.stcIBCR.MSS     =  TRUE;  									// Set master mode
	Mfs_SetIBCR(I2C_INSTANCE, unIBCR.u8IBCR);

	retval = WyzBeeI2cWaitTxRxComplete();								// Wait until TX is completed

	if ((Ok != retval) ||  (0 == RxBufIndex))
	{
		*p_buf_len = 0;

		return ERR_I2C_TIMEOUT ;
	}
	*p_buf_len = RxBufIndex; 											// Set received bytes

	return ERR_NONE;
}

/*
 *********************************************************************************************************
 *                                           WyzBeeI2cWaitTxRxComplete()
 *
 * Description : Waits until TX and TX completion
 *
 * Argument(s) : None
 *
 * Return(s)   : ERR_NONE                 	On successful initialization of the I2C module
 *
 * 				 ERR_I2C_TIMEOUT			Time out error
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */

static err_t WyzBeeI2cWaitTxRxComplete(void)
{
	volatile uint32_t    cnt;
	         uint32_t    max_cnt;
	         uint16_t    retval;


	max_cnt   =  Mfs_GetBusClock() / 10;
	cnt       =  0;
	retval    =  ERR_I2C_TIMEOUT;

	while (cnt < max_cnt)
	{
		if (I2cStateStandby == I2cStatus) 								// Wait until TX or RX is completed or error occur
		{
			retval = ERR_NONE;
			break;
		}
		cnt++;
	}

	I2cStatus = I2cStateStandby;

	return (retval);
}

/*
 *********************************************************************************************************
 *********************************************************************************************************
 *                                             LOCAL FUNCTIONS
 *********************************************************************************************************
 *********************************************************************************************************
 */

/*
 *********************************************************************************************************
 *                                           WyzBeeI2c_TxIsr()
 *
 * Description : I2C TX interrupt service routine , sets the I2C transmitting conditions and sends the data
 *
 * Argument(s) : None
 *
 * Return(s)   : None
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */

static void WyzBeeI2c_TxIsr(void)
{
	union																/*--------------------SMR Bit fields union for configuring I2C modes--------------------*/
	{																	/*																						*/
		uint8_t                  u8SMR;									/*																						*/
		stc_mfs_smr_field_t      stcSMR;								/*																						*/
	} unSMR;															/*--------------------------------------------------------------------------------------*/

	union																/*--------------------SSR Bit fields union for configuring I2C modes--------------------*/
	{																	/*																						*/
		uint8_t                  u8SSR;									/*																						*/
		stc_mfs_ssr_field_t      stcSSR;								/*																						*/
	} unSSR;															/*--------------------------------------------------------------------------------------*/

	union																/*--------------------IBSR Bit fields union for configuring I2C modes-------------------*/
	{																	/*																						*/
		uint8_t                  u8IBSR;								/*																						*/
		stc_mfs_i2c_ibsr_field_t stcIBSR;								/*																						*/
	} unIBSR;															/*--------------------------------------------------------------------------------------*/

	union																/*--------------------IBCR Bit fields union for configuring I2C modes-------------------*/
	{																	/*																						*/
		uint8_t                  u8IBCR;								/*																						*/
		stc_mfs_i2c_ibcr_field_t stcIBCR;								/*																						*/
	} unIBCR;															/*--------------------------------------------------------------------------------------*/

	union																/*--------------------IMSK Bit fields union for configuring I2C modes-------------------*/
	{																	/*																						*/
		uint8_t                  u8ISMK;								/*																						*/
		stc_mfs_i2c_ismk_field_t stcISMK;								/*																						*/
	} unISMK;															/*--------------------------------------------------------------------------------------*/

	memset(&unSSR, 0, sizeof(unSSR));
	memset(&unIBSR, 0, sizeof(unIBSR));
	memset(&unIBCR, 0, sizeof(unIBCR));
	memset(&unISMK, 0, sizeof(unISMK));

	unIBSR.u8IBSR = Mfs_GetIBSR(I2C_INSTANCE);
	unIBCR.u8IBCR = Mfs_GetIBCR(I2C_INSTANCE);

	if (TRUE == unIBSR.stcIBSR.SPC) 									// stop condition
	{
		unIBSR.stcIBSR.SPC     = FALSE; 								// Clear stop condition interrupt
		Mfs_SetIBSR(I2C_INSTANCE , unIBSR.u8IBSR);

		unIBCR.stcIBCR.CNDE    = FALSE; 								// stop condition interrupt disable
		unIBCR.stcIBCR.ACT_SCC = FALSE;
		Mfs_SetIBCR(I2C_INSTANCE, unIBCR.u8IBCR);


		unISMK.u8ISMK          = Mfs_GetISMK(I2C_INSTANCE); 			// Clear IBSR:RACK
		unISMK.stcISMK.EN      = FALSE;
		Mfs_SetISMK(I2C_INSTANCE ,unISMK.u8ISMK);

		unISMK.stcISMK.EN      = TRUE; 									// Restart
		Mfs_SetISMK(I2C_INSTANCE , unISMK.u8ISMK);

		I2cStatus = I2cStateStandby; 									// stop condition
	}
	else if (((GlobalBufLen == TxBufIndex)
			&&        (TRUE == unIBCR.stcIBCR.INT))
			||        (TRUE == unIBSR.stcIBSR.RACK))
	{

		unIBCR.stcIBCR.MSS     = FALSE; 								// Disable master mode
		unIBCR.stcIBCR.ACT_SCC = FALSE;
		unIBCR.stcIBCR.INTE    = FALSE; 								// Disable interrupt
		unIBCR.stcIBCR.INT     = FALSE;   								// Clear interrupt
		unIBCR.stcIBCR.CNDE    = TRUE; 									// Enable stop condition interrupt
		Mfs_SetIBCR(I2C_INSTANCE , unIBCR.u8IBCR);
	}
	else
	{
		unSSR.u8SSR            = Mfs_GetSSR(I2C_INSTANCE);
		if (TRUE == unSSR.stcSSR.TDRE)
		{																// TX data to register
			Mfs_WriteData(I2C_INSTANCE, (uint16_t)GlobalBuf[TxBufIndex]);
			TxBufIndex++;
			if (GlobalBufLen == TxBufIndex) 							// Complete to transmit
			{
				unSMR.u8SMR      = Mfs_GetSMR(I2C_INSTANCE); 			// TX interrupt disable
				unSMR.stcSMR.TIE = FALSE;
				Mfs_SetSMR(I2C_INSTANCE , unSMR.u8SMR);
			}
		}

		unIBCR.stcIBCR.ACT_SCC    = FALSE; 								// clear interrupt
		unIBCR.stcIBCR.INT        = FALSE;
		Mfs_SetIBCR(I2C_INSTANCE , unIBCR.u8IBCR);
	}
	return ;
}

/*
 *********************************************************************************************************
 *                                           WyzBeeI2c_RxIsr()
 *
 * Description : I2C RX interrupt service routine , sets the I2C Receiving conditions and Receives the data
 *
 * Argument(s) : None
 *
 * Return(s)   : None
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */

static void WyzBeeI2c_RxIsr(void)
{

	union																/*--------------------SSR Bit fields union for configuring I2C modes--------------------*/
	{																	/*																						*/
		uint8_t                  u8SSR;									/*																						*/
		stc_mfs_ssr_field_t      stcSSR;								/*																						*/
	} unSSR;															/*--------------------------------------------------------------------------------------*/

	union																/*--------------------IBSR Bit fields union for configuring I2C modes-------------------*/
	{																	/*																						*/
		uint8_t                  u8IBSR;								/*																						*/
		stc_mfs_i2c_ibsr_field_t stcIBSR;								/*																						*/
	} unIBSR;															/*--------------------------------------------------------------------------------------*/

	union																/*--------------------IBCR Bit fields union for configuring I2C modes-------------------*/
	{																	/*																						*/
		uint8_t                  u8IBCR;								/*																						*/
		stc_mfs_i2c_ibcr_field_t stcIBCR;								/*																						*/
	} unIBCR;															/*--------------------------------------------------------------------------------------*/

	union																/*--------------------IMSK Bit fields union for configuring I2C modes-------------------*/
	{																	/*																						*/
		uint8_t                  u8ISMK;								/*																						*/
		stc_mfs_i2c_ismk_field_t stcISMK;								/*																						*/
	} unISMK;															/*--------------------------------------------------------------------------------------*/

	memset(&unSSR, 0, sizeof(unSSR));
	memset(&unIBSR, 0, sizeof(unIBSR));
	memset(&unIBCR, 0, sizeof(unIBCR));
	memset(&unISMK, 0, sizeof(unISMK));

	unIBSR.u8IBSR              = Mfs_GetIBSR(I2C_INSTANCE);
	unIBCR.u8IBCR              = Mfs_GetIBCR(I2C_INSTANCE);
	unSSR.u8SSR                = Mfs_GetSSR (I2C_INSTANCE);

	if (TRUE == unIBSR.stcIBSR.SPC) 									// stop condition
	{
		unIBSR.stcIBSR.SPC     = FALSE; 								// Clear stop condition interrupt
		Mfs_SetIBSR(I2C_INSTANCE , unIBSR.u8IBSR);

		unIBCR.stcIBCR.CNDE    = FALSE; 								// Disable stop condition interrupt
		unIBCR.stcIBCR.INTE    = FALSE; 								// Disable interrupt
		unISMK.u8ISMK          = Mfs_GetISMK(I2C_INSTANCE);  			// Clear IBSR:RACK
		unISMK.stcISMK.EN      = FALSE;

		Mfs_SetISMK(I2C_INSTANCE , unISMK.u8ISMK);

		unISMK.stcISMK.EN      = TRUE;  								// Restart
		Mfs_SetISMK(I2C_INSTANCE , unISMK.u8ISMK);


		I2cStatus = I2cStateStandby; 									// stop condition
	}
																		// Received data after second byte
	else if ((TRUE == unSSR.stcSSR.RDRF) && (FALSE == unIBSR.stcIBSR.FBT))
	{
		while (RxBufIndex < GlobalBufLen) 								// Continue until specified data length is received
		{
			unSSR.u8SSR = Mfs_GetSSR(I2C_INSTANCE);
			if (TRUE == unSSR.stcSSR.RDRF)
			{
				GlobalBuf[RxBufIndex] = (uint8_t)Mfs_ReadData(I2C_INSTANCE);
				RxBufIndex++;
			}
			else
			{
				break; /* No data */
			}
		}
		if (RxBufIndex == GlobalBufLen) 								// Complete to receive
		{
			unIBCR.stcIBCR.MSS  = FALSE; 								// Stop condition
			unIBCR.stcIBCR.ACKE = FALSE; 								// NACK
			unIBCR.stcIBCR.CNDE = TRUE; 								// stop condition interrupt enable
			unIBSR.u8IBSR = Mfs_GetIBSR(I2C_INSTANCE);
			if (TRUE == unIBSR.stcIBSR.RSC) 							// If restart condition was detected
			{
				unIBSR.stcIBSR.RSC = FALSE; 							// Clear restart condition
				Mfs_SetIBSR(I2C_INSTANCE, unIBSR.u8IBSR);
			}
		}
	}
	if (TRUE == unSSR.stcSSR.ORE) 										// Overrun error
	{
		Mfs_ErrorClear(I2C_INSTANCE); 									// Clear RX error
	}
	unIBCR.stcIBCR.ACT_SCC = FALSE; 									// Clear interrupt
	unIBCR.stcIBCR.INT = FALSE;
	Mfs_SetIBCR(I2C_INSTANCE, unIBCR.u8IBCR);

	return;
}

/*
 *********************************************************************************************************
 *                                           WyzBeeI2c_SatusIsr()
 *
 * Description : I2C status interrupt service routine
 *
 * Argument(s) : None
 *
 * Return(s)   : None
 *
 * Caller(s)   :
 *
 * Note(s)     :
 *********************************************************************************************************
 */

static void WyzBeeI2c_SatusIsr(void)
{
	if (I2cStateTransmitting == I2cStatus) 								// Transmitting
	{
		WyzBeeI2c_TxIsr();
	}
	else 																// Receiving
	{
		WyzBeeI2c_RxIsr();
	}
	return ;
}

/*
 *********************************************************************************************************
 *                                           END
 *********************************************************************************************************
 */
