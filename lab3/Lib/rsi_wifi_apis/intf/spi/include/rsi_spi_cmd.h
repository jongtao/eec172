/**
 * @file     rsi_spi_cmd.h
 * @version  3.6
 * @date     2013-May-16
 *
 * Copyright(C) Redpine Signals 2013
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief SPI HEADER: SPI specific function declarations
 *
 * @section Description
 * This file contains the function prototypes of the api's defined in spi library. 
 *
 */


#ifndef _SPICMDAPI_H_
#define _SPICMDAPI_H_

/**
 * Include Files
 */
#include "rsi_global.h"

/**
 * Global Defines
 */
// coex support
#define CO_EX
/*=========================================================*/
//!C1 Register Bit Field Defines
#define RSI_C1_INIT_CMD     0x15       
//! sent to spi interface after reset/powerup to init the spi interface

#define RSI_C1_INIT_RESP    0x55       
//! response from spi interface to successful init

#define RSI_C176_INIT       0b00111111            //@ and
#define RSI_C176_RW         0b01000000            //@ or
#define RSI_C15_RD          0b11011111            //@ and
#define RSI_C15_WR          0b00100000            //@ or
#define RSI_C14_SPISLV      0b11101111            //@ and 
#define RSI_C14_AHBBUS      0b00010000            //@ or
#define RSI_C13_AHBMEM      0b11110111            //@ and
#define RSI_C13_AHBFRM      0b00001000            //@ or
#define RSI_C12_02BITXFR    0b11111011            //@ and
#define RSI_C12_16BITXFR    0b00000100            //@ or
#define RSI_C110_4BYTESLEN  0b11111100      
//! and number of C bytes transferred, usually 4
#define RSI_C110_1BYTESLEN  0b00000001      
//! or/~and number of C bytes transferred
#define RSI_C110_2BYTESLEN  0b00000010      
//! or/~and number of C bytes transferred
#define RSI_C110_3BYTESLEN  0b00000011      
//! or number of C bytes transferred

/*=========================================================*/
//! C2 Register Defines
#define RSI_C276_08BIT      0b00111111            //@ and
#define RSI_C276_32BIT      0b01000000            //@ or
#define RSI_C250_SPIADDR    0b00111111            //@ and
#define RSI_C250_DATAPACKET 0b00000010            //@ or
#define RSI_C250_MGMTPACKET 0b00000100            //@ or

//#define RSI_C3_XFERLENLSB  0x00                 //@ set value
//#define RSI_C4_XFERLENMSB  0x00                 //@ set value

/*==========================================================*/
//! C1 Register Defines
//! Internal Read
#define RSI_C1INTREAD2BYTES            0x42    
//! (((((0x00 & C176_INT) & C15_RD) & C14_SPISLV) & C13_AHBMEM) & C12_02BITXFR) | C110_2BYTESLEN // 01000010
#define RSI_C1INTREAD1BYTES            0x41

//! Memory ReadWrite (AHB Master Read/Write, Internal Legacy Name)
//! Memory read/write is normally done using 16-bit transfer length with 4 C bytes transferred
#define RSI_C1MEMWR16BIT1BYTE           0x75      
//! (((0x00 | C176_RW | C15_WR | C14_AHBBUS) & C13_AHBMEM) & C12_16BITXFR) | C110_1BYTESLEN // 01110101
#define RSI_C1MEMRD16BIT1BYTE           0x55      
//! (((0x00 | C176_RW & C15_RD | C14_AHBBUS) & C13_AHBMEM) & C12_16BITXFR) | C110_1BYTESLEN // 01010101

#define RSI_C1MEMWR16BIT4BYTE           0x74      
//! (((0x00 | C176_RW | C15_WR | C14_AHBBUS) & C13_AHBMEM) & C12_16BITXFR) & C110_4BYTESLEN // 01110100
#define RSI_C1MEMRD16BIT4BYTE           0x54      
//! ((((0x00 | C176_RW & C15_RD) | C14_AHBBUS) & C13_AHBMEM) & C12_16BITXFR) & C110_4BYTESLEN // 01010100

//! Normally, 2-bit transfer length is not used for memory read/write
#define RSI_C1MEMWR02BIT1BYTE           0x71      
//! (((0x00 | C176_RW | C15_WR | C14_AHBBUS) & C13_AHBMEM) & C12_02BITXFR) | C110_1BYTESLEN // 01110001
#define RSI_C1MEMRD02BIT1BYTE           0x51      
//! (((0x00 | C176_RW & C15_RD | C14_AHBBUS) & C13_AHBMEM) & C12_02BITXFR) | C110_1BYTESLEN // 01010001
#define RSI_C1MEMWR02BIT4BYTE           0x70      
//! (((0x00 | C176_RW | C15_WR | C14_AHBBUS) & C13_AHBMEM) & C12_02BITXFR) & C110_4BYTESLEN // 01110000
#define RSI_C1MEMRD02BIT4BYTE           0x50    
//! ((((0x00 | C176_RW & C15_RD) | C14_AHBBUS) & C13_AHBMEM) & C12_02BITXFR) & C110_4BYTESLEN // 01010000


//! Frame ReadWrite
//! Frame read/writes normally  use 16-bit transfer length
#define RSI_C1FRMWR16BIT1BYTE           0x7d      
//! ((C176_RW | C15_WR | C14_AHBBUS | C13_AHBFRM) & C12_16BITXFR) | C110_1BYTESLEN // 01111101
#define RSI_C1FRMRD16BIT1BYTE           0x5d      
//! ((C176_RW & C15_RD | C14_AHBBUS | C13_AHBFRM) & C12_16BITXFR) | C110_1BYTESLEN // 01011101

#define RSI_C1FRMWR16BIT4BYTE           0x7c      
//! ((C176_RW | C15_WR | C14_AHBBUS | C13_AHBFRM) & C12_16BITXFR) | C110_4BYTESLEN // 01111100
#define RSI_C1FRMRD16BIT4BYTE           0x5c      
//! ((C176_RW & C15_RD | C14_AHBBUS | C13_AHBFRM) & C12_16BITXFR) | C110_4BYTESLEN // 01011100

//! Frame read/writes normally do not use 2-bit transfer length
#define RSI_C1FRMWR02BIT1BYTE           0x79      
//! ((C176_RW | C15_WR | C14_AHBBUS | C13_AHBFRM) & C12_02BITXFR) | C110_1BYTESLEN // 01111001
#define RSI_C1FRMRD02BIT1BYTE           0x59      
//! ((C176_RW & C15_RD | C14_AHBBUS | C13_AHBFRM) & C12_02BITXFR) | C110_1BYTESLEN // 01011001

#define RSI_C1FRMWR02BIT4BYTE           0x78      
//! ((C176_RW | C15_WR | C14_AHBBUS | C13_AHBFRM) & C12_02BITXFR) | C110_4BYTESLEN // 01111000
#define RSI_C1FRMRD02BIT4BYTE           0x58      
//! ((C176_RW & C15_RD | C14_AHBBUS | C13_AHBFRM) & C12_02BITXFR) | C110_4BYTESLEN // 01011000

//! SPI Register ReadWrite
#define RSI_C1SPIREGWR16BIT4BYTE        0x64      
//! ((((C176_RW | C15_WR) & C14_SPISLV) & C13_AHBMEM) & C12_16BITXFR) | C110_4BYTESLEN // 01100100
#define RSI_C1SPIREGRD16BIT4BYTE        0x44      
//! ((((C176_RW & C15_RD) & C14_SPISLV) & C13_AHBMEM) & C12_16BITXFR) | C110_4BYTESLEN // 01000100

#define RSI_C1SPIREGWR02BIT4BYTE        0x60    
//! ((((C176_RW | C15_WR) & C14_SPISLV) & C13_AHBMEM) & C12_02BITXFR) | C110_4BYTESLEN // 01100000
#define RSI_C1SPIREGRD02BIT4BYTE        0x40    
//! ((((C176_RW & C15_RD) & C14_SPISLV) & C13_AHBMEM) & C12_02BITXFR) | C110_4BYTESLEN // 01000000

#define RSI_C1SPIREGWR02BIT1BYTE        0x61      
//! ((((C176_RW | C15_WR) & C14_SPISLV) & C13_AHBMEM) & C12_02BITXFR) | C110_1BYTESLEN // 01100001
#define RSI_C1SPIREGRD02BIT1BYTE        0x41      
//! ((((C176_RW & C15_RD) & C14_SPISLV) & C13_AHBMEM) & C12_02BITXFR) | C110_1BYTESLEN // 01000001



//!C2 Register Defines 
#define RSI_C2RDWR4BYTE           0x40            //@ 0x00 | C276_32BIT | C250_DATAPACKET   // 01000010
#define RSI_C2RDWR4BYTE           0x40            //@ 0x00 | C276_32BIT | C250_MGMTPACKET   // 01000100

#define RSI_C2RDWR1BYTE           0x00            //@ (0x00 & C276_08BIT) | C250_DATAPACKET // 00000010
#define RSI_C2RDWR1BYTE           0x00            //@ (0x00 & C276_08BIT) | C250_MGMTPACKET
                                                  //@ 00000100
#define RSI_C2MGMT                0x04
#define RSI_C2DATA                0x02
#define RSI_C2WPS                 0x08

#define RSI_C2SPIADDR1BYTE        0x00            //@(0x00 & C276_08BIT) | C250_SPIADDR   // 00xxxxxx
#define RSI_C2MEMRDWRNOCARE       0x00            //@0x00 or ANYTHING                     // 00000000
#define RSI_C2SPIADDR4BYTE        0x40            //@(0x00 | C276_32BIT) | C250_SPIADDR   // 01xxxxxx

#define RSI_C1INTWRITE1BYTES      0x61
#define RSI_C1INTWRITE2BYTES      0x62

/*====================================================*/
//! Constant Defines
//! Sizes

//! SPI Status
#define RSI_SPI_SUCCESS           0x58
#define RSI_SPI_BUSY              0x54
#define RSI_SPI_FAIL              0x52

#define RSI_SUCCESS               0
#define RSI_BUSY                  -1
#define RSI_FAIL                  -2
#define RSI_BUFFER_FULL           -3
#define RSI_IN_SLEEP              -4
//! SPI Constants
#define RSI_SPI_START_TOKEN       0x55           //@ SPI Start Token


//!SPI Internal Register Offset
#define RSI_SPI_INT_REG_ADDR       0x00           //@ register access method
#define RSI_SPI_MODE_REG_ADDR      0x08           //@ register access method
//#define RSI_SPI_INT_REG_ADDR      0x08000000    //@ memory access method
//#define RSI_SPI_MODE_REG_ADDR     0x08000008    //@ memory access method


//!SPI Mode Register
#define RSI_SPI_MODE_LOW           0x00
#define RSI_SPI_MODE_HIGH          0x01

#ifndef RSI_HWTIMER 
/*@ approximate ticks for timeout implementation */
#define RSI_INC_TIMER_2        rsi_spiTimer2++
#define RSI_INC_TIMER_1        rsi_spiTimer1++
#define RSI_INC_TIMER_3        rsi_spiTimer3++
#define RSI_INC_TIMER_4        rsi_spiTimer4++
#define RSI_RESET_TIMER1       rsi_spiTimer1=0
#define RSI_RESET_TIMER2       rsi_spiTimer2=0
#define RSI_RESET_TIMER3       rsi_spiTimer3=0
#define RSI_RESET_TIMER4       rsi_spiTimer4=0
#else
#define RSI_TICKS_PER_SECOND   10
#define RSI_INC_TIMER_3        rsi_spiTimer3
#define RSI_INC_TIMER_2        rsi_spiTimer2
#define RSI_INC_TIMER_1        rsi_spiTimer1
#define RSI_INC_TIMER_4        rsi_spiTimer4
#define RSI_RESET_TIMER1       rsi_spiTimer1=0
#define RSI_RESET_TIMER2       rsi_spiTimer2=0
#define RSI_RESET_TIMER3       rsi_spiTimer3=0
#define RSI_RESET_TIMER4       rsi_spiTimer4=0
#endif


int16 rsi_send_c1c2(uint8 c1, uint8 c2);
int16 rsi_send_c3c4(uint8 c3, uint8 c4);
int16 rsi_spi_wait_start_token(uint32 timeout,uint8 mode);
int16 rsi_clear_interrupt(uint8 interruptClear);
int16 rsi_mem_wr(uint32 addr, uint16 len, uint8 *dBuf);
int16 rsi_mem_rd(uint32 addr, uint16 len, uint8 *dBuf);
int16 rsi_reg_rd(uint8 regAddr, uint8 *dBuf);
int16 rsi_reg_wr(uint8 regAddr, uint8 *dBuf);
int16 rsi_pre_dsc_rd(uint8 *dbuf);
int16 rsi_pkt_rd(uint8 *pkt, uint16 dummy_len, uint16 total_len);
int16 rsi_set_intr_mask(uint8 interruptMask);
int16 rsi_spi_iface_init(void);
int16 rsi_device_interrupt_status(uint8 *int_status);

#endif
