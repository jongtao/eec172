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
*											  SPI Driver Header File
*
* File           : WyzBee_spi.h
* Version        : V1.00
* Programmer(s)  :
*********************************************************************************************************
* Note(s)		 :
*********************************************************************************************************
*/

#ifndef  WyzBee_SPI_H
#define  WyzBee_SPI_H

#ifdef __cplusplus
extern "C"{
#endif


/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/

#include <mfs.h>
#include <WyzBee.h>



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
#define ERR_SPI_UNINITIALIZED	10u

/*
*********************************************************************************************************
*                                               DATA TYPES
*********************************************************************************************************
*/

typedef void (* WyzBeeSpi_TxIsrCallBack_t)(void);	// SPI TX ISR call back
typedef void (* WyzBeeSpi_RxIsrCallBack_t)(void);	// SPI RX ISR call back

typedef enum WyzBeeSpi_BitLength							/*-------------SPI TRANSFER BIT LENGTHS----*/
{
    SpiFiveBits        	= 0u,      					//  5 Bit character length
    SpiSixBits         	= 1u,      					//  6 Bit character length
    SpiSevenBits       	= 2u,    					//  7 Bit character length
    SpiEightBits       	= 3u,      					//  8 Bit character length
    SpiNineBits        	= 4u,      					//  9 Bit character length
    SpiTenBits         	= 5u,     					// 10 Bit character length
    SpiElevenBits      	= 6u,     					// 11 Bit character length
    SpiTwelveBits      	= 7u,      					// 12 Bit character length
    SpiThirteenBits    	= 8u,      					// 13 Bit character length
    SpiFourteenBits    	= 9u,      					// 14 Bit character length
    SpiFifteenBits     	= 10u,     					// 15 Bit character length
    SpiSixteenBits     	= 11u,     					// 16 Bit character length
} WyzBeeSpi_BitLength_t;

typedef enum WyzBeeSpi_WaitTimes							/*-------------SPI TRANSFER BIT LENGTHS----*/
{
	SpiSyncWaitZero    	= 0u,           			// 0 wait time insertion
	SpiSyncWaitOne     	= 1u,           			// 1 wait time insertion
	SpiSyncWaitTwo     	= 2u,           			// 2 wait time insertion
	SpiSyncWaitThree   	= 3u            			// 3 wait time insertion
} WyzBeeSpi_WaitTimes_t;

typedef enum WyzBeeSpi_Mode									/*-------------SPI MODES-------------------*/
{
   SpiMaster        	= 0u,          				// Master mode (generating serial clock)
   SpiSlave         	= 1u           				// Slave mode  (external serial clock)
} WyzBeeSpi_Mode_t;

typedef enum WyzBeeSpi_IntrConfig							/*-------------SPI INTR MODE---------------*/
{
	SpiUseIntrMode   	= 1u,          				// Enable  SPI interrupts
	SpiNoUseIntrmode 	= 0u          				// Disable SPI interrupts
} WyzBeeSpi_IntrConfig_t;

typedef enum WyzBeeSpi_BitOrde								/*-------------SPI BIT ORDER---------------*/
{
	SpiMsbBitFirst	    = 1u,          				// MSB bit First
	SpiLsbBitFirst 	    = 0u          				// LSB bit First
} WyzBeeSpi_BitOrde_t;

typedef enum WyzBeeSpi_Clock								/*-------------SPI CLOK MODE---------------*/
{
	SpiClockMarkHigh    = 1u,          				// HIGH to LOW clock
	SpiClockMarkLow 	= 0u          				// LOW to HIGH clock
} WyzBeeSpi_Clock_t;


typedef struct WyzBeeSpi_Config								/*-------------SPI CONFIG STRUCTURE--------*/
{
	uint32_t         			BaudRate;     		// Baud rate (bps)
	uint8_t          			Mode;         		// See description of #WyzBeeSpi_Mode_t
	uint8_t          			WaitTime;       	// See description of  #WyzBeeSpi_WaitTimes_t
	uint8_t          			DateLen;        	// 5..16 Bit Character Length, see description of #WyzBeeSpi_BitLength_t
	bool_t        				BitDirection;   	// MSB first or MSB first see description of #WyzBeeSpi_BitOrde_t
	bool_t        				ClockLvl;       	// Clock Level (LOW/HIGH)
	bool_t       		 	 	UseInterrupts;  	// Enable Disable Interrupts
	WyzBeeSpi_TxIsrCallBack_t  	TxIsr;				// Tx Isr Callback
	WyzBeeSpi_RxIsrCallBack_t  	RxIsr;				// Rx Isr CallBack

} WyzBeeSpi_Config_t;

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
err_t   WyzBeeSpi_Init		 	( WyzBeeSpi_Config_t      *p_config );

err_t   WyzBeeSpi_SyncSend     	( uint8_t 				  *p_buf,
							      uint16_t 	 			   buf_len  );

err_t   WyzBeeSpi_SyncSendRecv 	( uint8_t 				  *p_tx_buf,
							      uint16_t   			       tx_len,
							      uint8_t 				  *p_rx_buf,
							      uint16_t   			   rx_len  	);

err_t   WyzBeeSpi_SyncRecv	 	( uint8_t 				  *buf,
							      uint16_t    			   buf_len   );

err_t   WyzBeeSpi_Write		 	( uint8_t 				   tx_char   );

err_t   WyzBeeSpi_DeInit		( void                            	);

void    WyzBeeSpi_CsEnable	 	( void                            	);

void    WyzBeeSpi_CsDisable    	( void                            	);

err_t   WyzBeeSpi_TxIntrEnable	( void                            	);

err_t   WyzBeeSpi_TxIntrDisable	( void                            	);

err_t   WyzBeeSpi_RxIntrEnable 	( void                            	);

err_t   WyzBeeSpi_RxIntrDisable ( void                            	);

uint8_t WyzBeeSpi_Read		 	( void                            	);

err_t   WyzBeeSpi_RxEnable	 	( void                            	);

err_t   WyzBeeSpi_TxEnable	 	( void                            	);

err_t   WyzBeeSpi_RxDisable	 	( void                            	);

err_t   WyzBeeSpi_TxDisable	 	( void                            	);

/*
*********************************************************************************************************
*                                           END
*********************************************************************************************************
*/

#ifdef __cplusplus
}
#endif

#endif // WyzBee_SPI_H
