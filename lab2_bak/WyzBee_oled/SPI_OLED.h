/**
 * @file     SPI_OLED.h
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief 	:This file contains the function prototypes of the OLED SPI functions( Arduino compactible )
 *
 * @section Description :
 *
 *
 * @section Improvements :
 *
 */


/*
 * Includes
 */
#ifndef _SPI_OLED_H_
#define _SPI_OLED_H_

#define SPI_CLOCK_DIV2		2
#define SPI_CLOCK_DIV4		4
#define SPI_CLOCK_DIV8		8
#define SPI_CLOCK_DIV16		16
#define SPI_CLOCK_DIV32		32
#define SPI_CLOCK_DIV64		64
#define SPI_CLOCK_DIV128	128

#define FRQ_80_MHZ		80000000
#define FRQ_40_MHZ		40000000
#define FRQ_20_MHZ		20000000
#define FRQ_10_MHZ		10000000
#define FRQ_5_MHZ		5000000

#define LSBFIRST	0
#define MSBFIRST	1

class SPI_OLEDClass
{
  protected:
  public:
    void begin(void);
    unsigned char transfer(unsigned char);
    void end(void);
    void setBitOrder(unsigned char);
    void setClockDivider(unsigned char);
    void setDataMode(unsigned char );
};

extern SPI_OLEDClass SPI;
#endif

