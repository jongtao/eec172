/*******************************************************************************
* Copyright (C) 2013 Spansion LLC. All Rights Reserved. 
*
* This software is owned and published by: 
* Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with Spansion 
* components. This software is licensed by Spansion to be adapted only 
* for use in systems utilizing Spansion components. Spansion shall not be 
* responsible for misuse or illegal use of this software for devices not 
* supported herein.  Spansion is providing this software "AS IS" and will 
* not be responsible for issues arising from incorrect user implementation 
* of the software.  
*
* SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS), 
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING, 
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED 
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED 
* WARRANTY OF NONINFRINGEMENT.  
* SPANSION SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, 
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT 
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, 
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR 
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, 
* SAVINGS OR PROFITS, 
* EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED 
* FROM, THE SOFTWARE.  
*
* This software may be replicated in part or whole for the licensed use, 
* with the restriction that this Disclaimer and Copyright notice must be 
* included with each copy of this software, whether used in part or whole, 
* at all times.  
*/
/******************************************************************************/
/** \file gpio_mb9bf56xm.h 
 **
 ** Headerfile for MB9BF56XM GPIO functions, included in gpio1pin.h
 **
 ** History:
 **   - 2013-04-10  1.0  MWi    First version.
 **
 ******************************************************************************/

#ifndef __GPIO_MB9BF56XM_H__
#define __GPIO_MB9BF56XM_H__

#include <stdint.h>

/******************************************************************************
   Note, that X0A/P46, X1A/P47, VREGCTL, and VWAKEUP functionality is done in
   the CLK and RTC modules.
*******************************************************************************/

/******************************************************************************
   GPIO
*******************************************************************************/

/*---- GPIO bit P00 ----*/

#define GPIO1PIN_P00_GET             ( bFM4_GPIO_PDIR0_P00 )

#define GPIO1PIN_P00_PUT(v)          ( bFM4_GPIO_PDOR0_P00=(v) )

#define GPIO1PIN_P00_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P00_INITIN(v) \
                                                        : GPIO1PIN_P00_INITOUT(v) )

#define GPIO1PIN_P00_INITIN(v)       do{ bFM4_GPIO_PCR0_P00=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P00=0u; \
                                         bFM4_GPIO_PFR0_P00=0u; }while(0)

#define GPIO1PIN_P00_INITOUT(v)      do{ bFM4_GPIO_PDOR0_P00=(v).bInitVal; \
                                         bFM4_GPIO_DDR0_P00=1u; \
                                         bFM4_GPIO_PFR0_P00=0u; }while(0)


/*---- GPIO bit NP00 ----*/
#define GPIO1PIN_NP00_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR0_P00)) )

#define GPIO1PIN_NP00_PUT(v)         ( bFM4_GPIO_PDOR0_P00=(uint32_t)(!(v)) )

#define GPIO1PIN_NP00_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP00_INITIN(v) \
                                                        : GPIO1PIN_NP00_INITOUT(v) )

#define GPIO1PIN_NP00_INITIN(v)      do{ bFM4_GPIO_PCR0_P00=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P00=0u; \
                                         bFM4_GPIO_PFR0_P00=0u; }while(0)

#define GPIO1PIN_NP00_INITOUT(v)     do{ bFM4_GPIO_PDOR0_P00=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR0_P00=1u; \
                                         bFM4_GPIO_PFR0_P00=0u; }while(0)


/*---- GPIO bit P01 ----*/

#define GPIO1PIN_P01_GET             ( bFM4_GPIO_PDIR0_P01 )

#define GPIO1PIN_P01_PUT(v)          ( bFM4_GPIO_PDOR0_P01=(v) )

#define GPIO1PIN_P01_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P01_INITIN(v) \
                                                        : GPIO1PIN_P01_INITOUT(v) )

#define GPIO1PIN_P01_INITIN(v)       do{ bFM4_GPIO_PCR0_P01=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P01=0u; \
                                         bFM4_GPIO_PFR0_P01=0u; }while(0)

#define GPIO1PIN_P01_INITOUT(v)      do{ bFM4_GPIO_PDOR0_P01=(v).bInitVal; \
                                         bFM4_GPIO_DDR0_P01=1u; \
                                         bFM4_GPIO_PFR0_P01=0u; }while(0)


/*---- GPIO bit NP01 ----*/
#define GPIO1PIN_NP01_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR0_P01)) )

#define GPIO1PIN_NP01_PUT(v)         ( bFM4_GPIO_PDOR0_P01=(uint32_t)(!(v)) )

#define GPIO1PIN_NP01_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP01_INITIN(v) \
                                                        : GPIO1PIN_NP01_INITOUT(v) )

#define GPIO1PIN_NP01_INITIN(v)      do{ bFM4_GPIO_PCR0_P01=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P01=0u; \
                                         bFM4_GPIO_PFR0_P01=0u; }while(0)

#define GPIO1PIN_NP01_INITOUT(v)     do{ bFM4_GPIO_PDOR0_P01=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR0_P01=1u; \
                                         bFM4_GPIO_PFR0_P01=0u; }while(0)


/*---- GPIO bit P02 ----*/

#define GPIO1PIN_P02_GET             ( bFM4_GPIO_PDIR0_P02 )

#define GPIO1PIN_P02_PUT(v)          ( bFM4_GPIO_PDOR0_P02=(v) )

#define GPIO1PIN_P02_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P02_INITIN(v) \
                                                        : GPIO1PIN_P02_INITOUT(v) )

#define GPIO1PIN_P02_INITIN(v)       do{ bFM4_GPIO_PCR0_P02=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P02=0u; \
                                         bFM4_GPIO_PFR0_P02=0u; }while(0)

#define GPIO1PIN_P02_INITOUT(v)      do{ bFM4_GPIO_PDOR0_P02=(v).bInitVal; \
                                         bFM4_GPIO_DDR0_P02=1u; \
                                         bFM4_GPIO_PFR0_P02=0u; }while(0)


/*---- GPIO bit NP02 ----*/
#define GPIO1PIN_NP02_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR0_P02)) )

#define GPIO1PIN_NP02_PUT(v)         ( bFM4_GPIO_PDOR0_P02=(uint32_t)(!(v)) )

#define GPIO1PIN_NP02_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP02_INITIN(v) \
                                                        : GPIO1PIN_NP02_INITOUT(v) )

#define GPIO1PIN_NP02_INITIN(v)      do{ bFM4_GPIO_PCR0_P02=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P02=0u; \
                                         bFM4_GPIO_PFR0_P02=0u; }while(0)

#define GPIO1PIN_NP02_INITOUT(v)     do{ bFM4_GPIO_PDOR0_P02=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR0_P02=1u; \
                                         bFM4_GPIO_PFR0_P02=0u; }while(0)


/*---- GPIO bit P03 ----*/

#define GPIO1PIN_P03_GET             ( bFM4_GPIO_PDIR0_P03 )

#define GPIO1PIN_P03_PUT(v)          ( bFM4_GPIO_PDOR0_P03=(v) )

#define GPIO1PIN_P03_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P03_INITIN(v) \
                                                        : GPIO1PIN_P03_INITOUT(v) )

#define GPIO1PIN_P03_INITIN(v)       do{ bFM4_GPIO_PCR0_P03=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P03=0u; \
                                         bFM4_GPIO_PFR0_P03=0u; }while(0)

#define GPIO1PIN_P03_INITOUT(v)      do{ bFM4_GPIO_PDOR0_P03=(v).bInitVal; \
                                         bFM4_GPIO_DDR0_P03=1u; \
                                         bFM4_GPIO_PFR0_P03=0u; }while(0)


/*---- GPIO bit NP03 ----*/
#define GPIO1PIN_NP03_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR0_P03)) )

#define GPIO1PIN_NP03_PUT(v)         ( bFM4_GPIO_PDOR0_P03=(uint32_t)(!(v)) )

#define GPIO1PIN_NP03_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP03_INITIN(v) \
                                                        : GPIO1PIN_NP03_INITOUT(v) )

#define GPIO1PIN_NP03_INITIN(v)      do{ bFM4_GPIO_PCR0_P03=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P03=0u; \
                                         bFM4_GPIO_PFR0_P03=0u; }while(0)

#define GPIO1PIN_NP03_INITOUT(v)     do{ bFM4_GPIO_PDOR0_P03=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR0_P03=1u; \
                                         bFM4_GPIO_PFR0_P03=0u; }while(0)


/*---- GPIO bit P04 ----*/

#define GPIO1PIN_P04_GET             ( bFM4_GPIO_PDIR0_P04 )

#define GPIO1PIN_P04_PUT(v)          ( bFM4_GPIO_PDOR0_P04=(v) )

#define GPIO1PIN_P04_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P04_INITIN(v) \
                                                        : GPIO1PIN_P04_INITOUT(v) )

#define GPIO1PIN_P04_INITIN(v)       do{ bFM4_GPIO_PCR0_P04=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P04=0u; \
                                         bFM4_GPIO_PFR0_P04=0u; }while(0)

#define GPIO1PIN_P04_INITOUT(v)      do{ bFM4_GPIO_PDOR0_P04=(v).bInitVal; \
                                         bFM4_GPIO_DDR0_P04=1u; \
                                         bFM4_GPIO_PFR0_P04=0u; }while(0)


/*---- GPIO bit NP04 ----*/
#define GPIO1PIN_NP04_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR0_P04)) )

#define GPIO1PIN_NP04_PUT(v)         ( bFM4_GPIO_PDOR0_P04=(uint32_t)(!(v)) )

#define GPIO1PIN_NP04_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP04_INITIN(v) \
                                                        : GPIO1PIN_NP04_INITOUT(v) )

#define GPIO1PIN_NP04_INITIN(v)      do{ bFM4_GPIO_PCR0_P04=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P04=0u; \
                                         bFM4_GPIO_PFR0_P04=0u; }while(0)

#define GPIO1PIN_NP04_INITOUT(v)     do{ bFM4_GPIO_PDOR0_P04=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR0_P04=1u; \
                                         bFM4_GPIO_PFR0_P04=0u; }while(0)


/*---- GPIO bit P09 ----*/

#define GPIO1PIN_P09_GET             ( bFM4_GPIO_PDIR0_P09 )

#define GPIO1PIN_P09_PUT(v)          ( bFM4_GPIO_PDOR0_P09=(v) )

#define GPIO1PIN_P09_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P09_INITIN(v) \
                                                        : GPIO1PIN_P09_INITOUT(v) )

#define GPIO1PIN_P09_INITIN(v)       do{ bFM4_GPIO_PCR0_P09=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P09=0u; \
                                         bFM4_GPIO_PFR0_P09=0u; \
                                         bFM4_GPIO_ADE_AN19=0u; }while(0)


#define GPIO1PIN_P09_INITOUT(v)      do{ bFM4_GPIO_PDOR0_P09=(v).bInitVal; \
                                         bFM4_GPIO_DDR0_P09=1u; \
                                         bFM4_GPIO_PFR0_P09=0u; \
                                         bFM4_GPIO_ADE_AN19=0u; }while(0)


/*---- GPIO bit NP09 ----*/
#define GPIO1PIN_NP09_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR0_P09)) )

#define GPIO1PIN_NP09_PUT(v)         ( bFM4_GPIO_PDOR0_P09=(uint32_t)(!(v)) )

#define GPIO1PIN_NP09_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP09_INITIN(v) \
                                                        : GPIO1PIN_NP09_INITOUT(v) )

#define GPIO1PIN_NP09_INITIN(v)      do{ bFM4_GPIO_PCR0_P09=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P09=0u; \
                                         bFM4_GPIO_PFR0_P09=0u; \
                                         bFM4_GPIO_ADE_AN19=0u; }while(0)


#define GPIO1PIN_NP09_INITOUT(v)     do{ bFM4_GPIO_PDOR0_P09=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR0_P09=1u; \
                                         bFM4_GPIO_PFR0_P09=0u; \
                                         bFM4_GPIO_ADE_AN19=0u; }while(0)


/*---- GPIO bit P0A ----*/

#define GPIO1PIN_P0A_GET             ( bFM4_GPIO_PDIR0_P0A )

#define GPIO1PIN_P0A_PUT(v)          ( bFM4_GPIO_PDOR0_P0A=(v) )

#define GPIO1PIN_P0A_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P0A_INITIN(v) \
                                                        : GPIO1PIN_P0A_INITOUT(v) )

#define GPIO1PIN_P0A_INITIN(v)       do{ bFM4_GPIO_PCR0_P0A=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P0A=0u; \
                                         bFM4_GPIO_PFR0_P0A=0u; }while(0)

#define GPIO1PIN_P0A_INITOUT(v)      do{ bFM4_GPIO_PDOR0_P0A=(v).bInitVal; \
                                         bFM4_GPIO_DDR0_P0A=1u; \
                                         bFM4_GPIO_PFR0_P0A=0u; }while(0)


/*---- GPIO bit NP0A ----*/
#define GPIO1PIN_NP0A_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR0_P0A)) )

#define GPIO1PIN_NP0A_PUT(v)         ( bFM4_GPIO_PDOR0_P0A=(uint32_t)(!(v)) )

#define GPIO1PIN_NP0A_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP0A_INITIN(v) \
                                                        : GPIO1PIN_NP0A_INITOUT(v) )

#define GPIO1PIN_NP0A_INITIN(v)      do{ bFM4_GPIO_PCR0_P0A=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P0A=0u; \
                                         bFM4_GPIO_PFR0_P0A=0u; }while(0)

#define GPIO1PIN_NP0A_INITOUT(v)     do{ bFM4_GPIO_PDOR0_P0A=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR0_P0A=1u; \
                                         bFM4_GPIO_PFR0_P0A=0u; }while(0)


/*---- GPIO bit P0B ----*/

#define GPIO1PIN_P0B_GET             ( bFM4_GPIO_PDIR0_P0B )

#define GPIO1PIN_P0B_PUT(v)          ( bFM4_GPIO_PDOR0_P0B=(v) )

#define GPIO1PIN_P0B_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P0B_INITIN(v) \
                                                        : GPIO1PIN_P0B_INITOUT(v) )

#define GPIO1PIN_P0B_INITIN(v)       do{ bFM4_GPIO_PCR0_P0B=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P0B=0u; \
                                         bFM4_GPIO_PFR0_P0B=0u; }while(0)

#define GPIO1PIN_P0B_INITOUT(v)      do{ bFM4_GPIO_PDOR0_P0B=(v).bInitVal; \
                                         bFM4_GPIO_DDR0_P0B=1u; \
                                         bFM4_GPIO_PFR0_P0B=0u; }while(0)


/*---- GPIO bit NP0B ----*/
#define GPIO1PIN_NP0B_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR0_P0B)) )

#define GPIO1PIN_NP0B_PUT(v)         ( bFM4_GPIO_PDOR0_P0B=(uint32_t)(!(v)) )

#define GPIO1PIN_NP0B_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP0B_INITIN(v) \
                                                        : GPIO1PIN_NP0B_INITOUT(v) )

#define GPIO1PIN_NP0B_INITIN(v)      do{ bFM4_GPIO_PCR0_P0B=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P0B=0u; \
                                         bFM4_GPIO_PFR0_P0B=0u; }while(0)

#define GPIO1PIN_NP0B_INITOUT(v)     do{ bFM4_GPIO_PDOR0_P0B=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR0_P0B=1u; \
                                         bFM4_GPIO_PFR0_P0B=0u; }while(0)


/*---- GPIO bit P0C ----*/

#define GPIO1PIN_P0C_GET             ( bFM4_GPIO_PDIR0_P0C )

#define GPIO1PIN_P0C_PUT(v)          ( bFM4_GPIO_PDOR0_P0C=(v) )

#define GPIO1PIN_P0C_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P0C_INITIN(v) \
                                                        : GPIO1PIN_P0C_INITOUT(v) )

#define GPIO1PIN_P0C_INITIN(v)       do{ bFM4_GPIO_PCR0_P0C=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P0C=0u; \
                                         bFM4_GPIO_PFR0_P0C=0u; }while(0)

#define GPIO1PIN_P0C_INITOUT(v)      do{ bFM4_GPIO_PDOR0_P0C=(v).bInitVal; \
                                         bFM4_GPIO_DDR0_P0C=1u; \
                                         bFM4_GPIO_PFR0_P0C=0u; }while(0)


/*---- GPIO bit NP0C ----*/
#define GPIO1PIN_NP0C_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR0_P0C)) )

#define GPIO1PIN_NP0C_PUT(v)         ( bFM4_GPIO_PDOR0_P0C=(uint32_t)(!(v)) )

#define GPIO1PIN_NP0C_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP0C_INITIN(v) \
                                                        : GPIO1PIN_NP0C_INITOUT(v) )

#define GPIO1PIN_NP0C_INITIN(v)      do{ bFM4_GPIO_PCR0_P0C=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P0C=0u; \
                                         bFM4_GPIO_PFR0_P0C=0u; }while(0)

#define GPIO1PIN_NP0C_INITOUT(v)     do{ bFM4_GPIO_PDOR0_P0C=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR0_P0C=1u; \
                                         bFM4_GPIO_PFR0_P0C=0u; }while(0)


/*---- GPIO bit P0D ----*/

#define GPIO1PIN_P0D_GET             ( bFM4_GPIO_PDIR0_P0D )

#define GPIO1PIN_P0D_PUT(v)          ( bFM4_GPIO_PDOR0_P0D=(v) )

#define GPIO1PIN_P0D_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P0D_INITIN(v) \
                                                        : GPIO1PIN_P0D_INITOUT(v) )

#define GPIO1PIN_P0D_INITIN(v)       do{ bFM4_GPIO_PCR0_P0D=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P0D=0u; \
                                         bFM4_GPIO_PFR0_P0D=0u; }while(0)

#define GPIO1PIN_P0D_INITOUT(v)      do{ bFM4_GPIO_PDOR0_P0D=(v).bInitVal; \
                                         bFM4_GPIO_DDR0_P0D=1u; \
                                         bFM4_GPIO_PFR0_P0D=0u; }while(0)


/*---- GPIO bit NP0D ----*/
#define GPIO1PIN_NP0D_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR0_P0D)) )

#define GPIO1PIN_NP0D_PUT(v)         ( bFM4_GPIO_PDOR0_P0D=(uint32_t)(!(v)) )

#define GPIO1PIN_NP0D_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP0D_INITIN(v) \
                                                        : GPIO1PIN_NP0D_INITOUT(v) )

#define GPIO1PIN_NP0D_INITIN(v)      do{ bFM4_GPIO_PCR0_P0D=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P0D=0u; \
                                         bFM4_GPIO_PFR0_P0D=0u; }while(0)

#define GPIO1PIN_NP0D_INITOUT(v)     do{ bFM4_GPIO_PDOR0_P0D=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR0_P0D=1u; \
                                         bFM4_GPIO_PFR0_P0D=0u; }while(0)


/*---- GPIO bit P0E ----*/

#define GPIO1PIN_P0E_GET             ( bFM4_GPIO_PDIR0_P0E )

#define GPIO1PIN_P0E_PUT(v)          ( bFM4_GPIO_PDOR0_P0E=(v) )

#define GPIO1PIN_P0E_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P0E_INITIN(v) \
                                                        : GPIO1PIN_P0E_INITOUT(v) )

#define GPIO1PIN_P0E_INITIN(v)       do{ bFM4_GPIO_PCR0_P0E=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P0E=0u; \
                                         bFM4_GPIO_PFR0_P0E=0u; }while(0)

#define GPIO1PIN_P0E_INITOUT(v)      do{ bFM4_GPIO_PDOR0_P0E=(v).bInitVal; \
                                         bFM4_GPIO_DDR0_P0E=1u; \
                                         bFM4_GPIO_PFR0_P0E=0u; }while(0)


/*---- GPIO bit NP0E ----*/
#define GPIO1PIN_NP0E_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR0_P0E)) )

#define GPIO1PIN_NP0E_PUT(v)         ( bFM4_GPIO_PDOR0_P0E=(uint32_t)(!(v)) )

#define GPIO1PIN_NP0E_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP0E_INITIN(v) \
                                                        : GPIO1PIN_NP0E_INITOUT(v) )

#define GPIO1PIN_NP0E_INITIN(v)      do{ bFM4_GPIO_PCR0_P0E=(v).bPullup; \
                                         bFM4_GPIO_DDR0_P0E=0u; \
                                         bFM4_GPIO_PFR0_P0E=0u; }while(0)

#define GPIO1PIN_NP0E_INITOUT(v)     do{ bFM4_GPIO_PDOR0_P0E=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR0_P0E=1u; \
                                         bFM4_GPIO_PFR0_P0E=0u; }while(0)


/*---- GPIO bit P10 ----*/

#define GPIO1PIN_P10_GET             ( bFM4_GPIO_PDIR1_P10 )

#define GPIO1PIN_P10_PUT(v)          ( bFM4_GPIO_PDOR1_P10=(v) )

#define GPIO1PIN_P10_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P10_INITIN(v) \
                                                        : GPIO1PIN_P10_INITOUT(v) )

#define GPIO1PIN_P10_INITIN(v)       do{ bFM4_GPIO_PCR1_P10=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P10=0u; \
                                         bFM4_GPIO_PFR1_P10=0u; \
                                         bFM4_GPIO_ADE_AN00=0u; }while(0)


#define GPIO1PIN_P10_INITOUT(v)      do{ bFM4_GPIO_PDOR1_P10=(v).bInitVal; \
                                         bFM4_GPIO_DDR1_P10=1u; \
                                         bFM4_GPIO_PFR1_P10=0u; \
                                         bFM4_GPIO_ADE_AN00=0u; }while(0)


/*---- GPIO bit NP10 ----*/
#define GPIO1PIN_NP10_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR1_P10)) )

#define GPIO1PIN_NP10_PUT(v)         ( bFM4_GPIO_PDOR1_P10=(uint32_t)(!(v)) )

#define GPIO1PIN_NP10_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP10_INITIN(v) \
                                                        : GPIO1PIN_NP10_INITOUT(v) )

#define GPIO1PIN_NP10_INITIN(v)      do{ bFM4_GPIO_PCR1_P10=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P10=0u; \
                                         bFM4_GPIO_PFR1_P10=0u; \
                                         bFM4_GPIO_ADE_AN00=0u; }while(0)


#define GPIO1PIN_NP10_INITOUT(v)     do{ bFM4_GPIO_PDOR1_P10=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR1_P10=1u; \
                                         bFM4_GPIO_PFR1_P10=0u; \
                                         bFM4_GPIO_ADE_AN00=0u; }while(0)


/*---- GPIO bit P11 ----*/

#define GPIO1PIN_P11_GET             ( bFM4_GPIO_PDIR1_P11 )

#define GPIO1PIN_P11_PUT(v)          ( bFM4_GPIO_PDOR1_P11=(v) )

#define GPIO1PIN_P11_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P11_INITIN(v) \
                                                        : GPIO1PIN_P11_INITOUT(v) )

#define GPIO1PIN_P11_INITIN(v)       do{ bFM4_GPIO_PCR1_P11=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P11=0u; \
                                         bFM4_GPIO_PFR1_P11=0u; \
                                         bFM4_GPIO_ADE_AN01=0u; }while(0)


#define GPIO1PIN_P11_INITOUT(v)      do{ bFM4_GPIO_PDOR1_P11=(v).bInitVal; \
                                         bFM4_GPIO_DDR1_P11=1u; \
                                         bFM4_GPIO_PFR1_P11=0u; \
                                         bFM4_GPIO_ADE_AN01=0u; }while(0)


/*---- GPIO bit NP11 ----*/
#define GPIO1PIN_NP11_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR1_P11)) )

#define GPIO1PIN_NP11_PUT(v)         ( bFM4_GPIO_PDOR1_P11=(uint32_t)(!(v)) )

#define GPIO1PIN_NP11_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP11_INITIN(v) \
                                                        : GPIO1PIN_NP11_INITOUT(v) )

#define GPIO1PIN_NP11_INITIN(v)      do{ bFM4_GPIO_PCR1_P11=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P11=0u; \
                                         bFM4_GPIO_PFR1_P11=0u; \
                                         bFM4_GPIO_ADE_AN01=0u; }while(0)


#define GPIO1PIN_NP11_INITOUT(v)     do{ bFM4_GPIO_PDOR1_P11=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR1_P11=1u; \
                                         bFM4_GPIO_PFR1_P11=0u; \
                                         bFM4_GPIO_ADE_AN01=0u; }while(0)


/*---- GPIO bit P12 ----*/

#define GPIO1PIN_P12_GET             ( bFM4_GPIO_PDIR1_P12 )

#define GPIO1PIN_P12_PUT(v)          ( bFM4_GPIO_PDOR1_P12=(v) )

#define GPIO1PIN_P12_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P12_INITIN(v) \
                                                        : GPIO1PIN_P12_INITOUT(v) )

#define GPIO1PIN_P12_INITIN(v)       do{ bFM4_GPIO_PCR1_P12=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P12=0u; \
                                         bFM4_GPIO_PFR1_P12=0u; \
                                         bFM4_GPIO_ADE_AN02=0u; }while(0)


#define GPIO1PIN_P12_INITOUT(v)      do{ bFM4_GPIO_PDOR1_P12=(v).bInitVal; \
                                         bFM4_GPIO_DDR1_P12=1u; \
                                         bFM4_GPIO_PFR1_P12=0u; \
                                         bFM4_GPIO_ADE_AN02=0u; }while(0)


/*---- GPIO bit NP12 ----*/
#define GPIO1PIN_NP12_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR1_P12)) )

#define GPIO1PIN_NP12_PUT(v)         ( bFM4_GPIO_PDOR1_P12=(uint32_t)(!(v)) )

#define GPIO1PIN_NP12_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP12_INITIN(v) \
                                                        : GPIO1PIN_NP12_INITOUT(v) )

#define GPIO1PIN_NP12_INITIN(v)      do{ bFM4_GPIO_PCR1_P12=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P12=0u; \
                                         bFM4_GPIO_PFR1_P12=0u; \
                                         bFM4_GPIO_ADE_AN02=0u; }while(0)


#define GPIO1PIN_NP12_INITOUT(v)     do{ bFM4_GPIO_PDOR1_P12=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR1_P12=1u; \
                                         bFM4_GPIO_PFR1_P12=0u; \
                                         bFM4_GPIO_ADE_AN02=0u; }while(0)


/*---- GPIO bit P13 ----*/

#define GPIO1PIN_P13_GET             ( bFM4_GPIO_PDIR1_P13 )

#define GPIO1PIN_P13_PUT(v)          ( bFM4_GPIO_PDOR1_P13=(v) )

#define GPIO1PIN_P13_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P13_INITIN(v) \
                                                        : GPIO1PIN_P13_INITOUT(v) )

#define GPIO1PIN_P13_INITIN(v)       do{ bFM4_GPIO_PCR1_P13=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P13=0u; \
                                         bFM4_GPIO_PFR1_P13=0u; \
                                         bFM4_GPIO_ADE_AN03=0u; }while(0)


#define GPIO1PIN_P13_INITOUT(v)      do{ bFM4_GPIO_PDOR1_P13=(v).bInitVal; \
                                         bFM4_GPIO_DDR1_P13=1u; \
                                         bFM4_GPIO_PFR1_P13=0u; \
                                         bFM4_GPIO_ADE_AN03=0u; }while(0)


/*---- GPIO bit NP13 ----*/
#define GPIO1PIN_NP13_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR1_P13)) )

#define GPIO1PIN_NP13_PUT(v)         ( bFM4_GPIO_PDOR1_P13=(uint32_t)(!(v)) )

#define GPIO1PIN_NP13_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP13_INITIN(v) \
                                                        : GPIO1PIN_NP13_INITOUT(v) )

#define GPIO1PIN_NP13_INITIN(v)      do{ bFM4_GPIO_PCR1_P13=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P13=0u; \
                                         bFM4_GPIO_PFR1_P13=0u; \
                                         bFM4_GPIO_ADE_AN03=0u; }while(0)


#define GPIO1PIN_NP13_INITOUT(v)     do{ bFM4_GPIO_PDOR1_P13=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR1_P13=1u; \
                                         bFM4_GPIO_PFR1_P13=0u; \
                                         bFM4_GPIO_ADE_AN03=0u; }while(0)


/*---- GPIO bit P14 ----*/

#define GPIO1PIN_P14_GET             ( bFM4_GPIO_PDIR1_P14 )

#define GPIO1PIN_P14_PUT(v)          ( bFM4_GPIO_PDOR1_P14=(v) )

#define GPIO1PIN_P14_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P14_INITIN(v) \
                                                        : GPIO1PIN_P14_INITOUT(v) )

#define GPIO1PIN_P14_INITIN(v)       do{ bFM4_GPIO_PCR1_P14=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P14=0u; \
                                         bFM4_GPIO_PFR1_P14=0u; \
                                         bFM4_GPIO_ADE_AN04=0u; }while(0)


#define GPIO1PIN_P14_INITOUT(v)      do{ bFM4_GPIO_PDOR1_P14=(v).bInitVal; \
                                         bFM4_GPIO_DDR1_P14=1u; \
                                         bFM4_GPIO_PFR1_P14=0u; \
                                         bFM4_GPIO_ADE_AN04=0u; }while(0)


/*---- GPIO bit NP14 ----*/
#define GPIO1PIN_NP14_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR1_P14)) )

#define GPIO1PIN_NP14_PUT(v)         ( bFM4_GPIO_PDOR1_P14=(uint32_t)(!(v)) )

#define GPIO1PIN_NP14_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP14_INITIN(v) \
                                                        : GPIO1PIN_NP14_INITOUT(v) )

#define GPIO1PIN_NP14_INITIN(v)      do{ bFM4_GPIO_PCR1_P14=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P14=0u; \
                                         bFM4_GPIO_PFR1_P14=0u; \
                                         bFM4_GPIO_ADE_AN04=0u; }while(0)


#define GPIO1PIN_NP14_INITOUT(v)     do{ bFM4_GPIO_PDOR1_P14=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR1_P14=1u; \
                                         bFM4_GPIO_PFR1_P14=0u; \
                                         bFM4_GPIO_ADE_AN04=0u; }while(0)


/*---- GPIO bit P15 ----*/

#define GPIO1PIN_P15_GET             ( bFM4_GPIO_PDIR1_P15 )

#define GPIO1PIN_P15_PUT(v)          ( bFM4_GPIO_PDOR1_P15=(v) )

#define GPIO1PIN_P15_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P15_INITIN(v) \
                                                        : GPIO1PIN_P15_INITOUT(v) )

#define GPIO1PIN_P15_INITIN(v)       do{ bFM4_GPIO_PCR1_P15=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P15=0u; \
                                         bFM4_GPIO_PFR1_P15=0u; \
                                         bFM4_GPIO_ADE_AN05=0u; }while(0)


#define GPIO1PIN_P15_INITOUT(v)      do{ bFM4_GPIO_PDOR1_P15=(v).bInitVal; \
                                         bFM4_GPIO_DDR1_P15=1u; \
                                         bFM4_GPIO_PFR1_P15=0u; \
                                         bFM4_GPIO_ADE_AN05=0u; }while(0)


/*---- GPIO bit NP15 ----*/
#define GPIO1PIN_NP15_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR1_P15)) )

#define GPIO1PIN_NP15_PUT(v)         ( bFM4_GPIO_PDOR1_P15=(uint32_t)(!(v)) )

#define GPIO1PIN_NP15_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP15_INITIN(v) \
                                                        : GPIO1PIN_NP15_INITOUT(v) )

#define GPIO1PIN_NP15_INITIN(v)      do{ bFM4_GPIO_PCR1_P15=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P15=0u; \
                                         bFM4_GPIO_PFR1_P15=0u; \
                                         bFM4_GPIO_ADE_AN05=0u; }while(0)


#define GPIO1PIN_NP15_INITOUT(v)     do{ bFM4_GPIO_PDOR1_P15=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR1_P15=1u; \
                                         bFM4_GPIO_PFR1_P15=0u; \
                                         bFM4_GPIO_ADE_AN05=0u; }while(0)


/*---- GPIO bit P16 ----*/

#define GPIO1PIN_P16_GET             ( bFM4_GPIO_PDIR1_P16 )

#define GPIO1PIN_P16_PUT(v)          ( bFM4_GPIO_PDOR1_P16=(v) )

#define GPIO1PIN_P16_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P16_INITIN(v) \
                                                        : GPIO1PIN_P16_INITOUT(v) )

#define GPIO1PIN_P16_INITIN(v)       do{ bFM4_GPIO_PCR1_P16=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P16=0u; \
                                         bFM4_GPIO_PFR1_P16=0u; \
                                         bFM4_GPIO_ADE_AN06=0u; }while(0)


#define GPIO1PIN_P16_INITOUT(v)      do{ bFM4_GPIO_PDOR1_P16=(v).bInitVal; \
                                         bFM4_GPIO_DDR1_P16=1u; \
                                         bFM4_GPIO_PFR1_P16=0u; \
                                         bFM4_GPIO_ADE_AN06=0u; }while(0)


/*---- GPIO bit NP16 ----*/
#define GPIO1PIN_NP16_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR1_P16)) )

#define GPIO1PIN_NP16_PUT(v)         ( bFM4_GPIO_PDOR1_P16=(uint32_t)(!(v)) )

#define GPIO1PIN_NP16_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP16_INITIN(v) \
                                                        : GPIO1PIN_NP16_INITOUT(v) )

#define GPIO1PIN_NP16_INITIN(v)      do{ bFM4_GPIO_PCR1_P16=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P16=0u; \
                                         bFM4_GPIO_PFR1_P16=0u; \
                                         bFM4_GPIO_ADE_AN06=0u; }while(0)


#define GPIO1PIN_NP16_INITOUT(v)     do{ bFM4_GPIO_PDOR1_P16=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR1_P16=1u; \
                                         bFM4_GPIO_PFR1_P16=0u; \
                                         bFM4_GPIO_ADE_AN06=0u; }while(0)


/*---- GPIO bit P17 ----*/

#define GPIO1PIN_P17_GET             ( bFM4_GPIO_PDIR1_P17 )

#define GPIO1PIN_P17_PUT(v)          ( bFM4_GPIO_PDOR1_P17=(v) )

#define GPIO1PIN_P17_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P17_INITIN(v) \
                                                        : GPIO1PIN_P17_INITOUT(v) )

#define GPIO1PIN_P17_INITIN(v)       do{ bFM4_GPIO_PCR1_P17=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P17=0u; \
                                         bFM4_GPIO_PFR1_P17=0u; \
                                         bFM4_GPIO_ADE_AN07=0u; }while(0)


#define GPIO1PIN_P17_INITOUT(v)      do{ bFM4_GPIO_PDOR1_P17=(v).bInitVal; \
                                         bFM4_GPIO_DDR1_P17=1u; \
                                         bFM4_GPIO_PFR1_P17=0u; \
                                         bFM4_GPIO_ADE_AN07=0u; }while(0)


/*---- GPIO bit NP17 ----*/
#define GPIO1PIN_NP17_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR1_P17)) )

#define GPIO1PIN_NP17_PUT(v)         ( bFM4_GPIO_PDOR1_P17=(uint32_t)(!(v)) )

#define GPIO1PIN_NP17_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP17_INITIN(v) \
                                                        : GPIO1PIN_NP17_INITOUT(v) )

#define GPIO1PIN_NP17_INITIN(v)      do{ bFM4_GPIO_PCR1_P17=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P17=0u; \
                                         bFM4_GPIO_PFR1_P17=0u; \
                                         bFM4_GPIO_ADE_AN07=0u; }while(0)


#define GPIO1PIN_NP17_INITOUT(v)     do{ bFM4_GPIO_PDOR1_P17=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR1_P17=1u; \
                                         bFM4_GPIO_PFR1_P17=0u; \
                                         bFM4_GPIO_ADE_AN07=0u; }while(0)


/*---- GPIO bit P18 ----*/

#define GPIO1PIN_P18_GET             ( bFM4_GPIO_PDIR1_P18 )

#define GPIO1PIN_P18_PUT(v)          ( bFM4_GPIO_PDOR1_P18=(v) )

#define GPIO1PIN_P18_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P18_INITIN(v) \
                                                        : GPIO1PIN_P18_INITOUT(v) )

#define GPIO1PIN_P18_INITIN(v)       do{ bFM4_GPIO_PCR1_P18=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P18=0u; \
                                         bFM4_GPIO_PFR1_P18=0u; \
                                         bFM4_GPIO_ADE_AN08=0u; }while(0)


#define GPIO1PIN_P18_INITOUT(v)      do{ bFM4_GPIO_PDOR1_P18=(v).bInitVal; \
                                         bFM4_GPIO_DDR1_P18=1u; \
                                         bFM4_GPIO_PFR1_P18=0u; \
                                         bFM4_GPIO_ADE_AN08=0u; }while(0)


/*---- GPIO bit NP18 ----*/
#define GPIO1PIN_NP18_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR1_P18)) )

#define GPIO1PIN_NP18_PUT(v)         ( bFM4_GPIO_PDOR1_P18=(uint32_t)(!(v)) )

#define GPIO1PIN_NP18_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP18_INITIN(v) \
                                                        : GPIO1PIN_NP18_INITOUT(v) )

#define GPIO1PIN_NP18_INITIN(v)      do{ bFM4_GPIO_PCR1_P18=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P18=0u; \
                                         bFM4_GPIO_PFR1_P18=0u; \
                                         bFM4_GPIO_ADE_AN08=0u; }while(0)


#define GPIO1PIN_NP18_INITOUT(v)     do{ bFM4_GPIO_PDOR1_P18=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR1_P18=1u; \
                                         bFM4_GPIO_PFR1_P18=0u; \
                                         bFM4_GPIO_ADE_AN08=0u; }while(0)


/*---- GPIO bit P19 ----*/

#define GPIO1PIN_P19_GET             ( bFM4_GPIO_PDIR1_P19 )

#define GPIO1PIN_P19_PUT(v)          ( bFM4_GPIO_PDOR1_P19=(v) )

#define GPIO1PIN_P19_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P19_INITIN(v) \
                                                        : GPIO1PIN_P19_INITOUT(v) )

#define GPIO1PIN_P19_INITIN(v)       do{ bFM4_GPIO_PCR1_P19=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P19=0u; \
                                         bFM4_GPIO_PFR1_P19=0u; \
                                         bFM4_GPIO_ADE_AN09=0u; }while(0)


#define GPIO1PIN_P19_INITOUT(v)      do{ bFM4_GPIO_PDOR1_P19=(v).bInitVal; \
                                         bFM4_GPIO_DDR1_P19=1u; \
                                         bFM4_GPIO_PFR1_P19=0u; \
                                         bFM4_GPIO_ADE_AN09=0u; }while(0)


/*---- GPIO bit NP19 ----*/
#define GPIO1PIN_NP19_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR1_P19)) )

#define GPIO1PIN_NP19_PUT(v)         ( bFM4_GPIO_PDOR1_P19=(uint32_t)(!(v)) )

#define GPIO1PIN_NP19_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP19_INITIN(v) \
                                                        : GPIO1PIN_NP19_INITOUT(v) )

#define GPIO1PIN_NP19_INITIN(v)      do{ bFM4_GPIO_PCR1_P19=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P19=0u; \
                                         bFM4_GPIO_PFR1_P19=0u; \
                                         bFM4_GPIO_ADE_AN09=0u; }while(0)


#define GPIO1PIN_NP19_INITOUT(v)     do{ bFM4_GPIO_PDOR1_P19=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR1_P19=1u; \
                                         bFM4_GPIO_PFR1_P19=0u; \
                                         bFM4_GPIO_ADE_AN09=0u; }while(0)


/*---- GPIO bit P1A ----*/

#define GPIO1PIN_P1A_GET             ( bFM4_GPIO_PDIR1_P1A )

#define GPIO1PIN_P1A_PUT(v)          ( bFM4_GPIO_PDOR1_P1A=(v) )

#define GPIO1PIN_P1A_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P1A_INITIN(v) \
                                                        : GPIO1PIN_P1A_INITOUT(v) )

#define GPIO1PIN_P1A_INITIN(v)       do{ bFM4_GPIO_PCR1_P1A=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P1A=0u; \
                                         bFM4_GPIO_PFR1_P1A=0u; \
                                         bFM4_GPIO_ADE_AN10=0u; }while(0)


#define GPIO1PIN_P1A_INITOUT(v)      do{ bFM4_GPIO_PDOR1_P1A=(v).bInitVal; \
                                         bFM4_GPIO_DDR1_P1A=1u; \
                                         bFM4_GPIO_PFR1_P1A=0u; \
                                         bFM4_GPIO_ADE_AN10=0u; }while(0)


/*---- GPIO bit NP1A ----*/
#define GPIO1PIN_NP1A_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR1_P1A)) )

#define GPIO1PIN_NP1A_PUT(v)         ( bFM4_GPIO_PDOR1_P1A=(uint32_t)(!(v)) )

#define GPIO1PIN_NP1A_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP1A_INITIN(v) \
                                                        : GPIO1PIN_NP1A_INITOUT(v) )

#define GPIO1PIN_NP1A_INITIN(v)      do{ bFM4_GPIO_PCR1_P1A=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P1A=0u; \
                                         bFM4_GPIO_PFR1_P1A=0u; \
                                         bFM4_GPIO_ADE_AN10=0u; }while(0)


#define GPIO1PIN_NP1A_INITOUT(v)     do{ bFM4_GPIO_PDOR1_P1A=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR1_P1A=1u; \
                                         bFM4_GPIO_PFR1_P1A=0u; \
                                         bFM4_GPIO_ADE_AN10=0u; }while(0)


/*---- GPIO bit P1B ----*/

#define GPIO1PIN_P1B_GET             ( bFM4_GPIO_PDIR1_P1B )

#define GPIO1PIN_P1B_PUT(v)          ( bFM4_GPIO_PDOR1_P1B=(v) )

#define GPIO1PIN_P1B_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P1B_INITIN(v) \
                                                        : GPIO1PIN_P1B_INITOUT(v) )

#define GPIO1PIN_P1B_INITIN(v)       do{ bFM4_GPIO_PCR1_P1B=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P1B=0u; \
                                         bFM4_GPIO_PFR1_P1B=0u; \
                                         bFM4_GPIO_ADE_AN11=0u; }while(0)


#define GPIO1PIN_P1B_INITOUT(v)      do{ bFM4_GPIO_PDOR1_P1B=(v).bInitVal; \
                                         bFM4_GPIO_DDR1_P1B=1u; \
                                         bFM4_GPIO_PFR1_P1B=0u; \
                                         bFM4_GPIO_ADE_AN11=0u; }while(0)


/*---- GPIO bit NP1B ----*/
#define GPIO1PIN_NP1B_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR1_P1B)) )

#define GPIO1PIN_NP1B_PUT(v)         ( bFM4_GPIO_PDOR1_P1B=(uint32_t)(!(v)) )

#define GPIO1PIN_NP1B_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP1B_INITIN(v) \
                                                        : GPIO1PIN_NP1B_INITOUT(v) )

#define GPIO1PIN_NP1B_INITIN(v)      do{ bFM4_GPIO_PCR1_P1B=(v).bPullup; \
                                         bFM4_GPIO_DDR1_P1B=0u; \
                                         bFM4_GPIO_PFR1_P1B=0u; \
                                         bFM4_GPIO_ADE_AN11=0u; }while(0)


#define GPIO1PIN_NP1B_INITOUT(v)     do{ bFM4_GPIO_PDOR1_P1B=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR1_P1B=1u; \
                                         bFM4_GPIO_PFR1_P1B=0u; \
                                         bFM4_GPIO_ADE_AN11=0u; }while(0)


/*---- GPIO bit P21 ----*/

#define GPIO1PIN_P21_GET             ( bFM4_GPIO_PDIR2_P21 )

#define GPIO1PIN_P21_PUT(v)          ( bFM4_GPIO_PDOR2_P21=(v) )

#define GPIO1PIN_P21_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P21_INITIN(v) \
                                                        : GPIO1PIN_P21_INITOUT(v) )

#define GPIO1PIN_P21_INITIN(v)       do{ bFM4_GPIO_PCR2_P21=(v).bPullup; \
                                         bFM4_GPIO_DDR2_P21=0u; \
                                         bFM4_GPIO_PFR2_P21=0u; \
                                         bFM4_GPIO_ADE_AN17=0u; }while(0)


#define GPIO1PIN_P21_INITOUT(v)      do{ bFM4_GPIO_PDOR2_P21=(v).bInitVal; \
                                         bFM4_GPIO_DDR2_P21=1u; \
                                         bFM4_GPIO_PFR2_P21=0u; \
                                         bFM4_GPIO_ADE_AN17=0u; }while(0)


/*---- GPIO bit NP21 ----*/
#define GPIO1PIN_NP21_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR2_P21)) )

#define GPIO1PIN_NP21_PUT(v)         ( bFM4_GPIO_PDOR2_P21=(uint32_t)(!(v)) )

#define GPIO1PIN_NP21_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP21_INITIN(v) \
                                                        : GPIO1PIN_NP21_INITOUT(v) )

#define GPIO1PIN_NP21_INITIN(v)      do{ bFM4_GPIO_PCR2_P21=(v).bPullup; \
                                         bFM4_GPIO_DDR2_P21=0u; \
                                         bFM4_GPIO_PFR2_P21=0u; \
                                         bFM4_GPIO_ADE_AN17=0u; }while(0)


#define GPIO1PIN_NP21_INITOUT(v)     do{ bFM4_GPIO_PDOR2_P21=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR2_P21=1u; \
                                         bFM4_GPIO_PFR2_P21=0u; \
                                         bFM4_GPIO_ADE_AN17=0u; }while(0)


/*---- GPIO bit P22 ----*/

#define GPIO1PIN_P22_GET             ( bFM4_GPIO_PDIR2_P22 )

#define GPIO1PIN_P22_PUT(v)          ( bFM4_GPIO_PDOR2_P22=(v) )

#define GPIO1PIN_P22_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P22_INITIN(v) \
                                                        : GPIO1PIN_P22_INITOUT(v) )

#define GPIO1PIN_P22_INITIN(v)       do{ bFM4_GPIO_PCR2_P22=(v).bPullup; \
                                         bFM4_GPIO_DDR2_P22=0u; \
                                         bFM4_GPIO_PFR2_P22=0u; \
                                         bFM4_GPIO_ADE_AN16=0u; }while(0)


#define GPIO1PIN_P22_INITOUT(v)      do{ bFM4_GPIO_PDOR2_P22=(v).bInitVal; \
                                         bFM4_GPIO_DDR2_P22=1u; \
                                         bFM4_GPIO_PFR2_P22=0u; \
                                         bFM4_GPIO_ADE_AN16=0u; }while(0)


/*---- GPIO bit NP22 ----*/
#define GPIO1PIN_NP22_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR2_P22)) )

#define GPIO1PIN_NP22_PUT(v)         ( bFM4_GPIO_PDOR2_P22=(uint32_t)(!(v)) )

#define GPIO1PIN_NP22_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP22_INITIN(v) \
                                                        : GPIO1PIN_NP22_INITOUT(v) )

#define GPIO1PIN_NP22_INITIN(v)      do{ bFM4_GPIO_PCR2_P22=(v).bPullup; \
                                         bFM4_GPIO_DDR2_P22=0u; \
                                         bFM4_GPIO_PFR2_P22=0u; \
                                         bFM4_GPIO_ADE_AN16=0u; }while(0)


#define GPIO1PIN_NP22_INITOUT(v)     do{ bFM4_GPIO_PDOR2_P22=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR2_P22=1u; \
                                         bFM4_GPIO_PFR2_P22=0u; \
                                         bFM4_GPIO_ADE_AN16=0u; }while(0)


/*---- GPIO bit P23 ----*/

#define GPIO1PIN_P23_GET             ( bFM4_GPIO_PDIR2_P23 )

#define GPIO1PIN_P23_PUT(v)          ( bFM4_GPIO_PDOR2_P23=(v) )

#define GPIO1PIN_P23_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P23_INITIN(v) \
                                                        : GPIO1PIN_P23_INITOUT(v) )

#define GPIO1PIN_P23_INITIN(v)       do{ bFM4_GPIO_PCR2_P23=(v).bPullup; \
                                         bFM4_GPIO_DDR2_P23=0u; \
                                         bFM4_GPIO_PFR2_P23=0u; \
                                         bFM4_GPIO_ADE_AN15=0u; }while(0)


#define GPIO1PIN_P23_INITOUT(v)      do{ bFM4_GPIO_PDOR2_P23=(v).bInitVal; \
                                         bFM4_GPIO_DDR2_P23=1u; \
                                         bFM4_GPIO_PFR2_P23=0u; \
                                         bFM4_GPIO_ADE_AN15=0u; }while(0)


/*---- GPIO bit NP23 ----*/
#define GPIO1PIN_NP23_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR2_P23)) )

#define GPIO1PIN_NP23_PUT(v)         ( bFM4_GPIO_PDOR2_P23=(uint32_t)(!(v)) )

#define GPIO1PIN_NP23_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP23_INITIN(v) \
                                                        : GPIO1PIN_NP23_INITOUT(v) )

#define GPIO1PIN_NP23_INITIN(v)      do{ bFM4_GPIO_PCR2_P23=(v).bPullup; \
                                         bFM4_GPIO_DDR2_P23=0u; \
                                         bFM4_GPIO_PFR2_P23=0u; \
                                         bFM4_GPIO_ADE_AN15=0u; }while(0)


#define GPIO1PIN_NP23_INITOUT(v)     do{ bFM4_GPIO_PDOR2_P23=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR2_P23=1u; \
                                         bFM4_GPIO_PFR2_P23=0u; \
                                         bFM4_GPIO_ADE_AN15=0u; }while(0)


/*---- GPIO bit P30 ----*/

#define GPIO1PIN_P30_GET             ( bFM4_GPIO_PDIR3_P30 )

#define GPIO1PIN_P30_PUT(v)          ( bFM4_GPIO_PDOR3_P30=(v) )

#define GPIO1PIN_P30_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P30_INITIN(v) \
                                                        : GPIO1PIN_P30_INITOUT(v) )

#define GPIO1PIN_P30_INITIN(v)       do{ bFM4_GPIO_PCR3_P30=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P30=0u; \
                                         bFM4_GPIO_PFR3_P30=0u; }while(0)

#define GPIO1PIN_P30_INITOUT(v)      do{ bFM4_GPIO_PDOR3_P30=(v).bInitVal; \
                                         bFM4_GPIO_DDR3_P30=1u; \
                                         bFM4_GPIO_PFR3_P30=0u; }while(0)


/*---- GPIO bit NP30 ----*/
#define GPIO1PIN_NP30_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR3_P30)) )

#define GPIO1PIN_NP30_PUT(v)         ( bFM4_GPIO_PDOR3_P30=(uint32_t)(!(v)) )

#define GPIO1PIN_NP30_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP30_INITIN(v) \
                                                        : GPIO1PIN_NP30_INITOUT(v) )

#define GPIO1PIN_NP30_INITIN(v)      do{ bFM4_GPIO_PCR3_P30=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P30=0u; \
                                         bFM4_GPIO_PFR3_P30=0u; }while(0)

#define GPIO1PIN_NP30_INITOUT(v)     do{ bFM4_GPIO_PDOR3_P30=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR3_P30=1u; \
                                         bFM4_GPIO_PFR3_P30=0u; }while(0)


/*---- GPIO bit P31 ----*/

#define GPIO1PIN_P31_GET             ( bFM4_GPIO_PDIR3_P31 )

#define GPIO1PIN_P31_PUT(v)          ( bFM4_GPIO_PDOR3_P31=(v) )

#define GPIO1PIN_P31_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P31_INITIN(v) \
                                                        : GPIO1PIN_P31_INITOUT(v) )

#define GPIO1PIN_P31_INITIN(v)       do{ bFM4_GPIO_PCR3_P31=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P31=0u; \
                                         bFM4_GPIO_PFR3_P31=0u; }while(0)

#define GPIO1PIN_P31_INITOUT(v)      do{ bFM4_GPIO_PDOR3_P31=(v).bInitVal; \
                                         bFM4_GPIO_DDR3_P31=1u; \
                                         bFM4_GPIO_PFR3_P31=0u; }while(0)


/*---- GPIO bit NP31 ----*/
#define GPIO1PIN_NP31_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR3_P31)) )

#define GPIO1PIN_NP31_PUT(v)         ( bFM4_GPIO_PDOR3_P31=(uint32_t)(!(v)) )

#define GPIO1PIN_NP31_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP31_INITIN(v) \
                                                        : GPIO1PIN_NP31_INITOUT(v) )

#define GPIO1PIN_NP31_INITIN(v)      do{ bFM4_GPIO_PCR3_P31=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P31=0u; \
                                         bFM4_GPIO_PFR3_P31=0u; }while(0)

#define GPIO1PIN_NP31_INITOUT(v)     do{ bFM4_GPIO_PDOR3_P31=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR3_P31=1u; \
                                         bFM4_GPIO_PFR3_P31=0u; }while(0)


/*---- GPIO bit P32 ----*/

#define GPIO1PIN_P32_GET             ( bFM4_GPIO_PDIR3_P32 )

#define GPIO1PIN_P32_PUT(v)          ( bFM4_GPIO_PDOR3_P32=(v) )

#define GPIO1PIN_P32_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P32_INITIN(v) \
                                                        : GPIO1PIN_P32_INITOUT(v) )

#define GPIO1PIN_P32_INITIN(v)       do{ bFM4_GPIO_PCR3_P32=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P32=0u; \
                                         bFM4_GPIO_PFR3_P32=0u; }while(0)

#define GPIO1PIN_P32_INITOUT(v)      do{ bFM4_GPIO_PDOR3_P32=(v).bInitVal; \
                                         bFM4_GPIO_DDR3_P32=1u; \
                                         bFM4_GPIO_PFR3_P32=0u; }while(0)


/*---- GPIO bit NP32 ----*/
#define GPIO1PIN_NP32_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR3_P32)) )

#define GPIO1PIN_NP32_PUT(v)         ( bFM4_GPIO_PDOR3_P32=(uint32_t)(!(v)) )

#define GPIO1PIN_NP32_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP32_INITIN(v) \
                                                        : GPIO1PIN_NP32_INITOUT(v) )

#define GPIO1PIN_NP32_INITIN(v)      do{ bFM4_GPIO_PCR3_P32=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P32=0u; \
                                         bFM4_GPIO_PFR3_P32=0u; }while(0)

#define GPIO1PIN_NP32_INITOUT(v)     do{ bFM4_GPIO_PDOR3_P32=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR3_P32=1u; \
                                         bFM4_GPIO_PFR3_P32=0u; }while(0)


/*---- GPIO bit P33 ----*/

#define GPIO1PIN_P33_GET             ( bFM4_GPIO_PDIR3_P33 )

#define GPIO1PIN_P33_PUT(v)          ( bFM4_GPIO_PDOR3_P33=(v) )

#define GPIO1PIN_P33_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P33_INITIN(v) \
                                                        : GPIO1PIN_P33_INITOUT(v) )

#define GPIO1PIN_P33_INITIN(v)       do{ bFM4_GPIO_PCR3_P33=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P33=0u; \
                                         bFM4_GPIO_PFR3_P33=0u; }while(0)

#define GPIO1PIN_P33_INITOUT(v)      do{ bFM4_GPIO_PDOR3_P33=(v).bInitVal; \
                                         bFM4_GPIO_DDR3_P33=1u; \
                                         bFM4_GPIO_PFR3_P33=0u; }while(0)


/*---- GPIO bit NP33 ----*/
#define GPIO1PIN_NP33_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR3_P33)) )

#define GPIO1PIN_NP33_PUT(v)         ( bFM4_GPIO_PDOR3_P33=(uint32_t)(!(v)) )

#define GPIO1PIN_NP33_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP33_INITIN(v) \
                                                        : GPIO1PIN_NP33_INITOUT(v) )

#define GPIO1PIN_NP33_INITIN(v)      do{ bFM4_GPIO_PCR3_P33=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P33=0u; \
                                         bFM4_GPIO_PFR3_P33=0u; }while(0)

#define GPIO1PIN_NP33_INITOUT(v)     do{ bFM4_GPIO_PDOR3_P33=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR3_P33=1u; \
                                         bFM4_GPIO_PFR3_P33=0u; }while(0)


/*---- GPIO bit P39 ----*/

#define GPIO1PIN_P39_GET             ( bFM4_GPIO_PDIR3_P39 )

#define GPIO1PIN_P39_PUT(v)          ( bFM4_GPIO_PDOR3_P39=(v) )

#define GPIO1PIN_P39_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P39_INITIN(v) \
                                                        : GPIO1PIN_P39_INITOUT(v) )

#define GPIO1PIN_P39_INITIN(v)       do{ bFM4_GPIO_PCR3_P39=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P39=0u; \
                                         bFM4_GPIO_PFR3_P39=0u; }while(0)

#define GPIO1PIN_P39_INITOUT(v)      do{ bFM4_GPIO_PDOR3_P39=(v).bInitVal; \
                                         bFM4_GPIO_DDR3_P39=1u; \
                                         bFM4_GPIO_PFR3_P39=0u; }while(0)


/*---- GPIO bit NP39 ----*/
#define GPIO1PIN_NP39_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR3_P39)) )

#define GPIO1PIN_NP39_PUT(v)         ( bFM4_GPIO_PDOR3_P39=(uint32_t)(!(v)) )

#define GPIO1PIN_NP39_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP39_INITIN(v) \
                                                        : GPIO1PIN_NP39_INITOUT(v) )

#define GPIO1PIN_NP39_INITIN(v)      do{ bFM4_GPIO_PCR3_P39=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P39=0u; \
                                         bFM4_GPIO_PFR3_P39=0u; }while(0)

#define GPIO1PIN_NP39_INITOUT(v)     do{ bFM4_GPIO_PDOR3_P39=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR3_P39=1u; \
                                         bFM4_GPIO_PFR3_P39=0u; }while(0)


/*---- GPIO bit P3A ----*/

#define GPIO1PIN_P3A_GET             ( bFM4_GPIO_PDIR3_P3A )

#define GPIO1PIN_P3A_PUT(v)          ( bFM4_GPIO_PDOR3_P3A=(v) )

#define GPIO1PIN_P3A_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P3A_INITIN(v) \
                                                        : GPIO1PIN_P3A_INITOUT(v) )

#define GPIO1PIN_P3A_INITIN(v)       do{ bFM4_GPIO_PCR3_P3A=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P3A=0u; \
                                         bFM4_GPIO_PFR3_P3A=0u; }while(0)

#define GPIO1PIN_P3A_INITOUT(v)      do{ bFM4_GPIO_PDOR3_P3A=(v).bInitVal; \
                                         bFM4_GPIO_DDR3_P3A=1u; \
                                         bFM4_GPIO_PFR3_P3A=0u; }while(0)


/*---- GPIO bit NP3A ----*/
#define GPIO1PIN_NP3A_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR3_P3A)) )

#define GPIO1PIN_NP3A_PUT(v)         ( bFM4_GPIO_PDOR3_P3A=(uint32_t)(!(v)) )

#define GPIO1PIN_NP3A_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP3A_INITIN(v) \
                                                        : GPIO1PIN_NP3A_INITOUT(v) )

#define GPIO1PIN_NP3A_INITIN(v)      do{ bFM4_GPIO_PCR3_P3A=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P3A=0u; \
                                         bFM4_GPIO_PFR3_P3A=0u; }while(0)

#define GPIO1PIN_NP3A_INITOUT(v)     do{ bFM4_GPIO_PDOR3_P3A=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR3_P3A=1u; \
                                         bFM4_GPIO_PFR3_P3A=0u; }while(0)


/*---- GPIO bit P3B ----*/

#define GPIO1PIN_P3B_GET             ( bFM4_GPIO_PDIR3_P3B )

#define GPIO1PIN_P3B_PUT(v)          ( bFM4_GPIO_PDOR3_P3B=(v) )

#define GPIO1PIN_P3B_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P3B_INITIN(v) \
                                                        : GPIO1PIN_P3B_INITOUT(v) )

#define GPIO1PIN_P3B_INITIN(v)       do{ bFM4_GPIO_PCR3_P3B=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P3B=0u; \
                                         bFM4_GPIO_PFR3_P3B=0u; }while(0)

#define GPIO1PIN_P3B_INITOUT(v)      do{ bFM4_GPIO_PDOR3_P3B=(v).bInitVal; \
                                         bFM4_GPIO_DDR3_P3B=1u; \
                                         bFM4_GPIO_PFR3_P3B=0u; }while(0)


/*---- GPIO bit NP3B ----*/
#define GPIO1PIN_NP3B_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR3_P3B)) )

#define GPIO1PIN_NP3B_PUT(v)         ( bFM4_GPIO_PDOR3_P3B=(uint32_t)(!(v)) )

#define GPIO1PIN_NP3B_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP3B_INITIN(v) \
                                                        : GPIO1PIN_NP3B_INITOUT(v) )

#define GPIO1PIN_NP3B_INITIN(v)      do{ bFM4_GPIO_PCR3_P3B=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P3B=0u; \
                                         bFM4_GPIO_PFR3_P3B=0u; }while(0)

#define GPIO1PIN_NP3B_INITOUT(v)     do{ bFM4_GPIO_PDOR3_P3B=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR3_P3B=1u; \
                                         bFM4_GPIO_PFR3_P3B=0u; }while(0)


/*---- GPIO bit P3C ----*/

#define GPIO1PIN_P3C_GET             ( bFM4_GPIO_PDIR3_P3C )

#define GPIO1PIN_P3C_PUT(v)          ( bFM4_GPIO_PDOR3_P3C=(v) )

#define GPIO1PIN_P3C_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P3C_INITIN(v) \
                                                        : GPIO1PIN_P3C_INITOUT(v) )

#define GPIO1PIN_P3C_INITIN(v)       do{ bFM4_GPIO_PCR3_P3C=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P3C=0u; \
                                         bFM4_GPIO_PFR3_P3C=0u; }while(0)

#define GPIO1PIN_P3C_INITOUT(v)      do{ bFM4_GPIO_PDOR3_P3C=(v).bInitVal; \
                                         bFM4_GPIO_DDR3_P3C=1u; \
                                         bFM4_GPIO_PFR3_P3C=0u; }while(0)


/*---- GPIO bit NP3C ----*/
#define GPIO1PIN_NP3C_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR3_P3C)) )

#define GPIO1PIN_NP3C_PUT(v)         ( bFM4_GPIO_PDOR3_P3C=(uint32_t)(!(v)) )

#define GPIO1PIN_NP3C_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP3C_INITIN(v) \
                                                        : GPIO1PIN_NP3C_INITOUT(v) )

#define GPIO1PIN_NP3C_INITIN(v)      do{ bFM4_GPIO_PCR3_P3C=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P3C=0u; \
                                         bFM4_GPIO_PFR3_P3C=0u; }while(0)

#define GPIO1PIN_NP3C_INITOUT(v)     do{ bFM4_GPIO_PDOR3_P3C=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR3_P3C=1u; \
                                         bFM4_GPIO_PFR3_P3C=0u; }while(0)


/*---- GPIO bit P3D ----*/

#define GPIO1PIN_P3D_GET             ( bFM4_GPIO_PDIR3_P3D )

#define GPIO1PIN_P3D_PUT(v)          ( bFM4_GPIO_PDOR3_P3D=(v) )

#define GPIO1PIN_P3D_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P3D_INITIN(v) \
                                                        : GPIO1PIN_P3D_INITOUT(v) )

#define GPIO1PIN_P3D_INITIN(v)       do{ bFM4_GPIO_PCR3_P3D=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P3D=0u; \
                                         bFM4_GPIO_PFR3_P3D=0u; }while(0)

#define GPIO1PIN_P3D_INITOUT(v)      do{ bFM4_GPIO_PDOR3_P3D=(v).bInitVal; \
                                         bFM4_GPIO_DDR3_P3D=1u; \
                                         bFM4_GPIO_PFR3_P3D=0u; }while(0)


/*---- GPIO bit NP3D ----*/
#define GPIO1PIN_NP3D_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR3_P3D)) )

#define GPIO1PIN_NP3D_PUT(v)         ( bFM4_GPIO_PDOR3_P3D=(uint32_t)(!(v)) )

#define GPIO1PIN_NP3D_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP3D_INITIN(v) \
                                                        : GPIO1PIN_NP3D_INITOUT(v) )

#define GPIO1PIN_NP3D_INITIN(v)      do{ bFM4_GPIO_PCR3_P3D=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P3D=0u; \
                                         bFM4_GPIO_PFR3_P3D=0u; }while(0)

#define GPIO1PIN_NP3D_INITOUT(v)     do{ bFM4_GPIO_PDOR3_P3D=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR3_P3D=1u; \
                                         bFM4_GPIO_PFR3_P3D=0u; }while(0)


/*---- GPIO bit P3E ----*/

#define GPIO1PIN_P3E_GET             ( bFM4_GPIO_PDIR3_P3E )

#define GPIO1PIN_P3E_PUT(v)          ( bFM4_GPIO_PDOR3_P3E=(v) )

#define GPIO1PIN_P3E_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P3E_INITIN(v) \
                                                        : GPIO1PIN_P3E_INITOUT(v) )

#define GPIO1PIN_P3E_INITIN(v)       do{ bFM4_GPIO_PCR3_P3E=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P3E=0u; \
                                         bFM4_GPIO_PFR3_P3E=0u; }while(0)

#define GPIO1PIN_P3E_INITOUT(v)      do{ bFM4_GPIO_PDOR3_P3E=(v).bInitVal; \
                                         bFM4_GPIO_DDR3_P3E=1u; \
                                         bFM4_GPIO_PFR3_P3E=0u; }while(0)


/*---- GPIO bit NP3E ----*/
#define GPIO1PIN_NP3E_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR3_P3E)) )

#define GPIO1PIN_NP3E_PUT(v)         ( bFM4_GPIO_PDOR3_P3E=(uint32_t)(!(v)) )

#define GPIO1PIN_NP3E_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP3E_INITIN(v) \
                                                        : GPIO1PIN_NP3E_INITOUT(v) )

#define GPIO1PIN_NP3E_INITIN(v)      do{ bFM4_GPIO_PCR3_P3E=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P3E=0u; \
                                         bFM4_GPIO_PFR3_P3E=0u; }while(0)

#define GPIO1PIN_NP3E_INITOUT(v)     do{ bFM4_GPIO_PDOR3_P3E=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR3_P3E=1u; \
                                         bFM4_GPIO_PFR3_P3E=0u; }while(0)


/*---- GPIO bit P3F ----*/

#define GPIO1PIN_P3F_GET             ( bFM4_GPIO_PDIR3_P3F )

#define GPIO1PIN_P3F_PUT(v)          ( bFM4_GPIO_PDOR3_P3F=(v) )

#define GPIO1PIN_P3F_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P3F_INITIN(v) \
                                                        : GPIO1PIN_P3F_INITOUT(v) )

#define GPIO1PIN_P3F_INITIN(v)       do{ bFM4_GPIO_PCR3_P3F=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P3F=0u; \
                                         bFM4_GPIO_PFR3_P3F=0u; }while(0)

#define GPIO1PIN_P3F_INITOUT(v)      do{ bFM4_GPIO_PDOR3_P3F=(v).bInitVal; \
                                         bFM4_GPIO_DDR3_P3F=1u; \
                                         bFM4_GPIO_PFR3_P3F=0u; }while(0)


/*---- GPIO bit NP3F ----*/
#define GPIO1PIN_NP3F_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR3_P3F)) )

#define GPIO1PIN_NP3F_PUT(v)         ( bFM4_GPIO_PDOR3_P3F=(uint32_t)(!(v)) )

#define GPIO1PIN_NP3F_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP3F_INITIN(v) \
                                                        : GPIO1PIN_NP3F_INITOUT(v) )

#define GPIO1PIN_NP3F_INITIN(v)      do{ bFM4_GPIO_PCR3_P3F=(v).bPullup; \
                                         bFM4_GPIO_DDR3_P3F=0u; \
                                         bFM4_GPIO_PFR3_P3F=0u; }while(0)

#define GPIO1PIN_NP3F_INITOUT(v)     do{ bFM4_GPIO_PDOR3_P3F=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR3_P3F=1u; \
                                         bFM4_GPIO_PFR3_P3F=0u; }while(0)


/*---- GPIO bit P44 ----*/

#define GPIO1PIN_P44_GET             ( bFM4_GPIO_PDIR4_P44 )

#define GPIO1PIN_P44_PUT(v)          ( bFM4_GPIO_PDOR4_P44=(v) )

#define GPIO1PIN_P44_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P44_INITIN(v) \
                                                        : GPIO1PIN_P44_INITOUT(v) )

#define GPIO1PIN_P44_INITIN(v)       do{ bFM4_GPIO_PCR4_P44=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P44=0u; \
                                         bFM4_GPIO_PFR4_P44=0u; }while(0)

#define GPIO1PIN_P44_INITOUT(v)      do{ bFM4_GPIO_PDOR4_P44=(v).bInitVal; \
                                         bFM4_GPIO_DDR4_P44=1u; \
                                         bFM4_GPIO_PFR4_P44=0u; }while(0)


/*---- GPIO bit NP44 ----*/
#define GPIO1PIN_NP44_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR4_P44)) )

#define GPIO1PIN_NP44_PUT(v)         ( bFM4_GPIO_PDOR4_P44=(uint32_t)(!(v)) )

#define GPIO1PIN_NP44_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP44_INITIN(v) \
                                                        : GPIO1PIN_NP44_INITOUT(v) )

#define GPIO1PIN_NP44_INITIN(v)      do{ bFM4_GPIO_PCR4_P44=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P44=0u; \
                                         bFM4_GPIO_PFR4_P44=0u; }while(0)

#define GPIO1PIN_NP44_INITOUT(v)     do{ bFM4_GPIO_PDOR4_P44=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR4_P44=1u; \
                                         bFM4_GPIO_PFR4_P44=0u; }while(0)


/*---- GPIO bit P45 ----*/

#define GPIO1PIN_P45_GET             ( bFM4_GPIO_PDIR4_P45 )

#define GPIO1PIN_P45_PUT(v)          ( bFM4_GPIO_PDOR4_P45=(v) )

#define GPIO1PIN_P45_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P45_INITIN(v) \
                                                        : GPIO1PIN_P45_INITOUT(v) )

#define GPIO1PIN_P45_INITIN(v)       do{ bFM4_GPIO_PCR4_P45=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P45=0u; \
                                         bFM4_GPIO_PFR4_P45=0u; }while(0)

#define GPIO1PIN_P45_INITOUT(v)      do{ bFM4_GPIO_PDOR4_P45=(v).bInitVal; \
                                         bFM4_GPIO_DDR4_P45=1u; \
                                         bFM4_GPIO_PFR4_P45=0u; }while(0)


/*---- GPIO bit NP45 ----*/
#define GPIO1PIN_NP45_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR4_P45)) )

#define GPIO1PIN_NP45_PUT(v)         ( bFM4_GPIO_PDOR4_P45=(uint32_t)(!(v)) )

#define GPIO1PIN_NP45_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP45_INITIN(v) \
                                                        : GPIO1PIN_NP45_INITOUT(v) )

#define GPIO1PIN_NP45_INITIN(v)      do{ bFM4_GPIO_PCR4_P45=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P45=0u; \
                                         bFM4_GPIO_PFR4_P45=0u; }while(0)

#define GPIO1PIN_NP45_INITOUT(v)     do{ bFM4_GPIO_PDOR4_P45=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR4_P45=1u; \
                                         bFM4_GPIO_PFR4_P45=0u; }while(0)


/*---- GPIO bit P46 ----*/

#define GPIO1PIN_P46_GET             ( bFM4_GPIO_PDIR4_P46 )

#define GPIO1PIN_P46_PUT(v)          ( bFM4_GPIO_PDOR4_P46=(v) )

#define GPIO1PIN_P46_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P46_INITIN(v) \
                                                        : GPIO1PIN_P46_INITOUT(v) )

#define GPIO1PIN_P46_INITIN(v)       do{ bFM4_GPIO_PCR4_P46=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P46=0u; \
                                         bFM4_GPIO_PFR4_P46=0u; }while(0)

#define GPIO1PIN_P46_INITOUT(v)      do{ bFM4_GPIO_PDOR4_P46=(v).bInitVal; \
                                         bFM4_GPIO_DDR4_P46=1u; \
                                         bFM4_GPIO_PFR4_P46=0u; }while(0)


/*---- GPIO bit NP46 ----*/
#define GPIO1PIN_NP46_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR4_P46)) )

#define GPIO1PIN_NP46_PUT(v)         ( bFM4_GPIO_PDOR4_P46=(uint32_t)(!(v)) )

#define GPIO1PIN_NP46_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP46_INITIN(v) \
                                                        : GPIO1PIN_NP46_INITOUT(v) )

#define GPIO1PIN_NP46_INITIN(v)      do{ bFM4_GPIO_PCR4_P46=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P46=0u; \
                                         bFM4_GPIO_PFR4_P46=0u; }while(0)

#define GPIO1PIN_NP46_INITOUT(v)     do{ bFM4_GPIO_PDOR4_P46=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR4_P46=1u; \
                                         bFM4_GPIO_PFR4_P46=0u; }while(0)


/*---- GPIO bit P47 ----*/

#define GPIO1PIN_P47_GET             ( bFM4_GPIO_PDIR4_P47 )

#define GPIO1PIN_P47_PUT(v)          ( bFM4_GPIO_PDOR4_P47=(v) )

#define GPIO1PIN_P47_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P47_INITIN(v) \
                                                        : GPIO1PIN_P47_INITOUT(v) )

#define GPIO1PIN_P47_INITIN(v)       do{ bFM4_GPIO_PCR4_P47=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P47=0u; \
                                         bFM4_GPIO_PFR4_P47=0u; }while(0)

#define GPIO1PIN_P47_INITOUT(v)      do{ bFM4_GPIO_PDOR4_P47=(v).bInitVal; \
                                         bFM4_GPIO_DDR4_P47=1u; \
                                         bFM4_GPIO_PFR4_P47=0u; }while(0)


/*---- GPIO bit NP47 ----*/
#define GPIO1PIN_NP47_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR4_P47)) )

#define GPIO1PIN_NP47_PUT(v)         ( bFM4_GPIO_PDOR4_P47=(uint32_t)(!(v)) )

#define GPIO1PIN_NP47_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP47_INITIN(v) \
                                                        : GPIO1PIN_NP47_INITOUT(v) )

#define GPIO1PIN_NP47_INITIN(v)      do{ bFM4_GPIO_PCR4_P47=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P47=0u; \
                                         bFM4_GPIO_PFR4_P47=0u; }while(0)

#define GPIO1PIN_NP47_INITOUT(v)     do{ bFM4_GPIO_PDOR4_P47=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR4_P47=1u; \
                                         bFM4_GPIO_PFR4_P47=0u; }while(0)


/*---- GPIO bit P48 ----*/

#define GPIO1PIN_P48_GET             ( bFM4_GPIO_PDIR4_P48 )

#define GPIO1PIN_P48_PUT(v)          ( bFM4_GPIO_PDOR4_P48=(v) )

#define GPIO1PIN_P48_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P48_INITIN(v) \
                                                        : GPIO1PIN_P48_INITOUT(v) )

#define GPIO1PIN_P48_INITIN(v)       do{ bFM4_GPIO_PCR4_P48=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P48=0u; \
                                         bFM4_GPIO_PFR4_P48=0u; }while(0)

#define GPIO1PIN_P48_INITOUT(v)      do{ bFM4_GPIO_PDOR4_P48=(v).bInitVal; \
                                         bFM4_GPIO_DDR4_P48=1u; \
                                         bFM4_GPIO_PFR4_P48=0u; }while(0)


/*---- GPIO bit NP48 ----*/
#define GPIO1PIN_NP48_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR4_P48)) )

#define GPIO1PIN_NP48_PUT(v)         ( bFM4_GPIO_PDOR4_P48=(uint32_t)(!(v)) )

#define GPIO1PIN_NP48_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP48_INITIN(v) \
                                                        : GPIO1PIN_NP48_INITOUT(v) )

#define GPIO1PIN_NP48_INITIN(v)      do{ bFM4_GPIO_PCR4_P48=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P48=0u; \
                                         bFM4_GPIO_PFR4_P48=0u; }while(0)

#define GPIO1PIN_NP48_INITOUT(v)     do{ bFM4_GPIO_PDOR4_P48=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR4_P48=1u; \
                                         bFM4_GPIO_PFR4_P48=0u; }while(0)


/*---- GPIO bit P49 ----*/

#define GPIO1PIN_P49_GET             ( bFM4_GPIO_PDIR4_P49 )

#define GPIO1PIN_P49_PUT(v)          ( bFM4_GPIO_PDOR4_P49=(v) )

#define GPIO1PIN_P49_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P49_INITIN(v) \
                                                        : GPIO1PIN_P49_INITOUT(v) )

#define GPIO1PIN_P49_INITIN(v)       do{ bFM4_GPIO_PCR4_P49=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P49=0u; \
                                         bFM4_GPIO_PFR4_P49=0u; }while(0)

#define GPIO1PIN_P49_INITOUT(v)      do{ bFM4_GPIO_PDOR4_P49=(v).bInitVal; \
                                         bFM4_GPIO_DDR4_P49=1u; \
                                         bFM4_GPIO_PFR4_P49=0u; }while(0)


/*---- GPIO bit NP49 ----*/
#define GPIO1PIN_NP49_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR4_P49)) )

#define GPIO1PIN_NP49_PUT(v)         ( bFM4_GPIO_PDOR4_P49=(uint32_t)(!(v)) )

#define GPIO1PIN_NP49_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP49_INITIN(v) \
                                                        : GPIO1PIN_NP49_INITOUT(v) )

#define GPIO1PIN_NP49_INITIN(v)      do{ bFM4_GPIO_PCR4_P49=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P49=0u; \
                                         bFM4_GPIO_PFR4_P49=0u; }while(0)

#define GPIO1PIN_NP49_INITOUT(v)     do{ bFM4_GPIO_PDOR4_P49=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR4_P49=1u; \
                                         bFM4_GPIO_PFR4_P49=0u; }while(0)


/*---- GPIO bit P4B ----*/

#define GPIO1PIN_P4B_GET             ( bFM4_GPIO_PDIR4_P4B )

#define GPIO1PIN_P4B_PUT(v)          ( bFM4_GPIO_PDOR4_P4B=(v) )

#define GPIO1PIN_P4B_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P4B_INITIN(v) \
                                                        : GPIO1PIN_P4B_INITOUT(v) )

#define GPIO1PIN_P4B_INITIN(v)       do{ bFM4_GPIO_PCR4_P4B=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P4B=0u; \
                                         bFM4_GPIO_PFR4_P4B=0u; }while(0)

#define GPIO1PIN_P4B_INITOUT(v)      do{ bFM4_GPIO_PDOR4_P4B=(v).bInitVal; \
                                         bFM4_GPIO_DDR4_P4B=1u; \
                                         bFM4_GPIO_PFR4_P4B=0u; }while(0)


/*---- GPIO bit NP4B ----*/
#define GPIO1PIN_NP4B_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR4_P4B)) )

#define GPIO1PIN_NP4B_PUT(v)         ( bFM4_GPIO_PDOR4_P4B=(uint32_t)(!(v)) )

#define GPIO1PIN_NP4B_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP4B_INITIN(v) \
                                                        : GPIO1PIN_NP4B_INITOUT(v) )

#define GPIO1PIN_NP4B_INITIN(v)      do{ bFM4_GPIO_PCR4_P4B=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P4B=0u; \
                                         bFM4_GPIO_PFR4_P4B=0u; }while(0)

#define GPIO1PIN_NP4B_INITOUT(v)     do{ bFM4_GPIO_PDOR4_P4B=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR4_P4B=1u; \
                                         bFM4_GPIO_PFR4_P4B=0u; }while(0)


/*---- GPIO bit P4C ----*/

#define GPIO1PIN_P4C_GET             ( bFM4_GPIO_PDIR4_P4C )

#define GPIO1PIN_P4C_PUT(v)          ( bFM4_GPIO_PDOR4_P4C=(v) )

#define GPIO1PIN_P4C_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P4C_INITIN(v) \
                                                        : GPIO1PIN_P4C_INITOUT(v) )

#define GPIO1PIN_P4C_INITIN(v)       do{ bFM4_GPIO_PCR4_P4C=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P4C=0u; \
                                         bFM4_GPIO_PFR4_P4C=0u; }while(0)

#define GPIO1PIN_P4C_INITOUT(v)      do{ bFM4_GPIO_PDOR4_P4C=(v).bInitVal; \
                                         bFM4_GPIO_DDR4_P4C=1u; \
                                         bFM4_GPIO_PFR4_P4C=0u; }while(0)


/*---- GPIO bit NP4C ----*/
#define GPIO1PIN_NP4C_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR4_P4C)) )

#define GPIO1PIN_NP4C_PUT(v)         ( bFM4_GPIO_PDOR4_P4C=(uint32_t)(!(v)) )

#define GPIO1PIN_NP4C_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP4C_INITIN(v) \
                                                        : GPIO1PIN_NP4C_INITOUT(v) )

#define GPIO1PIN_NP4C_INITIN(v)      do{ bFM4_GPIO_PCR4_P4C=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P4C=0u; \
                                         bFM4_GPIO_PFR4_P4C=0u; }while(0)

#define GPIO1PIN_NP4C_INITOUT(v)     do{ bFM4_GPIO_PDOR4_P4C=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR4_P4C=1u; \
                                         bFM4_GPIO_PFR4_P4C=0u; }while(0)


/*---- GPIO bit P4D ----*/

#define GPIO1PIN_P4D_GET             ( bFM4_GPIO_PDIR4_P4D )

#define GPIO1PIN_P4D_PUT(v)          ( bFM4_GPIO_PDOR4_P4D=(v) )

#define GPIO1PIN_P4D_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P4D_INITIN(v) \
                                                        : GPIO1PIN_P4D_INITOUT(v) )

#define GPIO1PIN_P4D_INITIN(v)       do{ bFM4_GPIO_PCR4_P4D=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P4D=0u; \
                                         bFM4_GPIO_PFR4_P4D=0u; }while(0)

#define GPIO1PIN_P4D_INITOUT(v)      do{ bFM4_GPIO_PDOR4_P4D=(v).bInitVal; \
                                         bFM4_GPIO_DDR4_P4D=1u; \
                                         bFM4_GPIO_PFR4_P4D=0u; }while(0)


/*---- GPIO bit NP4D ----*/
#define GPIO1PIN_NP4D_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR4_P4D)) )

#define GPIO1PIN_NP4D_PUT(v)         ( bFM4_GPIO_PDOR4_P4D=(uint32_t)(!(v)) )

#define GPIO1PIN_NP4D_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP4D_INITIN(v) \
                                                        : GPIO1PIN_NP4D_INITOUT(v) )

#define GPIO1PIN_NP4D_INITIN(v)      do{ bFM4_GPIO_PCR4_P4D=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P4D=0u; \
                                         bFM4_GPIO_PFR4_P4D=0u; }while(0)

#define GPIO1PIN_NP4D_INITOUT(v)     do{ bFM4_GPIO_PDOR4_P4D=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR4_P4D=1u; \
                                         bFM4_GPIO_PFR4_P4D=0u; }while(0)


/*---- GPIO bit P4E ----*/

#define GPIO1PIN_P4E_GET             ( bFM4_GPIO_PDIR4_P4E )

#define GPIO1PIN_P4E_PUT(v)          ( bFM4_GPIO_PDOR4_P4E=(v) )

#define GPIO1PIN_P4E_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P4E_INITIN(v) \
                                                        : GPIO1PIN_P4E_INITOUT(v) )

#define GPIO1PIN_P4E_INITIN(v)       do{ bFM4_GPIO_PCR4_P4E=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P4E=0u; \
                                         bFM4_GPIO_PFR4_P4E=0u; }while(0)

#define GPIO1PIN_P4E_INITOUT(v)      do{ bFM4_GPIO_PDOR4_P4E=(v).bInitVal; \
                                         bFM4_GPIO_DDR4_P4E=1u; \
                                         bFM4_GPIO_PFR4_P4E=0u; }while(0)


/*---- GPIO bit NP4E ----*/
#define GPIO1PIN_NP4E_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR4_P4E)) )

#define GPIO1PIN_NP4E_PUT(v)         ( bFM4_GPIO_PDOR4_P4E=(uint32_t)(!(v)) )

#define GPIO1PIN_NP4E_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP4E_INITIN(v) \
                                                        : GPIO1PIN_NP4E_INITOUT(v) )

#define GPIO1PIN_NP4E_INITIN(v)      do{ bFM4_GPIO_PCR4_P4E=(v).bPullup; \
                                         bFM4_GPIO_DDR4_P4E=0u; \
                                         bFM4_GPIO_PFR4_P4E=0u; }while(0)

#define GPIO1PIN_NP4E_INITOUT(v)     do{ bFM4_GPIO_PDOR4_P4E=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR4_P4E=1u; \
                                         bFM4_GPIO_PFR4_P4E=0u; }while(0)


/*---- GPIO bit P50 ----*/

#define GPIO1PIN_P50_GET             ( bFM4_GPIO_PDIR5_P50 )

#define GPIO1PIN_P50_PUT(v)          ( bFM4_GPIO_PDOR5_P50=(v) )

#define GPIO1PIN_P50_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P50_INITIN(v) \
                                                        : GPIO1PIN_P50_INITOUT(v) )

#define GPIO1PIN_P50_INITIN(v)       do{ bFM4_GPIO_PCR5_P50=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P50=0u; \
                                         bFM4_GPIO_PFR5_P50=0u; }while(0)

#define GPIO1PIN_P50_INITOUT(v)      do{ bFM4_GPIO_PDOR5_P50=(v).bInitVal; \
                                         bFM4_GPIO_DDR5_P50=1u; \
                                         bFM4_GPIO_PFR5_P50=0u; }while(0)


/*---- GPIO bit NP50 ----*/
#define GPIO1PIN_NP50_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR5_P50)) )

#define GPIO1PIN_NP50_PUT(v)         ( bFM4_GPIO_PDOR5_P50=(uint32_t)(!(v)) )

#define GPIO1PIN_NP50_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP50_INITIN(v) \
                                                        : GPIO1PIN_NP50_INITOUT(v) )

#define GPIO1PIN_NP50_INITIN(v)      do{ bFM4_GPIO_PCR5_P50=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P50=0u; \
                                         bFM4_GPIO_PFR5_P50=0u; }while(0)

#define GPIO1PIN_NP50_INITOUT(v)     do{ bFM4_GPIO_PDOR5_P50=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR5_P50=1u; \
                                         bFM4_GPIO_PFR5_P50=0u; }while(0)


/*---- GPIO bit P51 ----*/

#define GPIO1PIN_P51_GET             ( bFM4_GPIO_PDIR5_P51 )

#define GPIO1PIN_P51_PUT(v)          ( bFM4_GPIO_PDOR5_P51=(v) )

#define GPIO1PIN_P51_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P51_INITIN(v) \
                                                        : GPIO1PIN_P51_INITOUT(v) )

#define GPIO1PIN_P51_INITIN(v)       do{ bFM4_GPIO_PCR5_P51=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P51=0u; \
                                         bFM4_GPIO_PFR5_P51=0u; }while(0)

#define GPIO1PIN_P51_INITOUT(v)      do{ bFM4_GPIO_PDOR5_P51=(v).bInitVal; \
                                         bFM4_GPIO_DDR5_P51=1u; \
                                         bFM4_GPIO_PFR5_P51=0u; }while(0)


/*---- GPIO bit NP51 ----*/
#define GPIO1PIN_NP51_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR5_P51)) )

#define GPIO1PIN_NP51_PUT(v)         ( bFM4_GPIO_PDOR5_P51=(uint32_t)(!(v)) )

#define GPIO1PIN_NP51_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP51_INITIN(v) \
                                                        : GPIO1PIN_NP51_INITOUT(v) )

#define GPIO1PIN_NP51_INITIN(v)      do{ bFM4_GPIO_PCR5_P51=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P51=0u; \
                                         bFM4_GPIO_PFR5_P51=0u; }while(0)

#define GPIO1PIN_NP51_INITOUT(v)     do{ bFM4_GPIO_PDOR5_P51=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR5_P51=1u; \
                                         bFM4_GPIO_PFR5_P51=0u; }while(0)


/*---- GPIO bit P52 ----*/

#define GPIO1PIN_P52_GET             ( bFM4_GPIO_PDIR5_P52 )

#define GPIO1PIN_P52_PUT(v)          ( bFM4_GPIO_PDOR5_P52=(v) )

#define GPIO1PIN_P52_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P52_INITIN(v) \
                                                        : GPIO1PIN_P52_INITOUT(v) )

#define GPIO1PIN_P52_INITIN(v)       do{ bFM4_GPIO_PCR5_P52=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P52=0u; \
                                         bFM4_GPIO_PFR5_P52=0u; }while(0)

#define GPIO1PIN_P52_INITOUT(v)      do{ bFM4_GPIO_PDOR5_P52=(v).bInitVal; \
                                         bFM4_GPIO_DDR5_P52=1u; \
                                         bFM4_GPIO_PFR5_P52=0u; }while(0)


/*---- GPIO bit NP52 ----*/
#define GPIO1PIN_NP52_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR5_P52)) )

#define GPIO1PIN_NP52_PUT(v)         ( bFM4_GPIO_PDOR5_P52=(uint32_t)(!(v)) )

#define GPIO1PIN_NP52_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP52_INITIN(v) \
                                                        : GPIO1PIN_NP52_INITOUT(v) )

#define GPIO1PIN_NP52_INITIN(v)      do{ bFM4_GPIO_PCR5_P52=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P52=0u; \
                                         bFM4_GPIO_PFR5_P52=0u; }while(0)

#define GPIO1PIN_NP52_INITOUT(v)     do{ bFM4_GPIO_PDOR5_P52=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR5_P52=1u; \
                                         bFM4_GPIO_PFR5_P52=0u; }while(0)


/*---- GPIO bit P53 ----*/

#define GPIO1PIN_P53_GET             ( bFM4_GPIO_PDIR5_P53 )

#define GPIO1PIN_P53_PUT(v)          ( bFM4_GPIO_PDOR5_P53=(v) )

#define GPIO1PIN_P53_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P53_INITIN(v) \
                                                        : GPIO1PIN_P53_INITOUT(v) )

#define GPIO1PIN_P53_INITIN(v)       do{ bFM4_GPIO_PCR5_P53=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P53=0u; \
                                         bFM4_GPIO_PFR5_P53=0u; }while(0)

#define GPIO1PIN_P53_INITOUT(v)      do{ bFM4_GPIO_PDOR5_P53=(v).bInitVal; \
                                         bFM4_GPIO_DDR5_P53=1u; \
                                         bFM4_GPIO_PFR5_P53=0u; }while(0)


/*---- GPIO bit NP53 ----*/
#define GPIO1PIN_NP53_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR5_P53)) )

#define GPIO1PIN_NP53_PUT(v)         ( bFM4_GPIO_PDOR5_P53=(uint32_t)(!(v)) )

#define GPIO1PIN_NP53_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP53_INITIN(v) \
                                                        : GPIO1PIN_NP53_INITOUT(v) )

#define GPIO1PIN_NP53_INITIN(v)      do{ bFM4_GPIO_PCR5_P53=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P53=0u; \
                                         bFM4_GPIO_PFR5_P53=0u; }while(0)

#define GPIO1PIN_NP53_INITOUT(v)     do{ bFM4_GPIO_PDOR5_P53=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR5_P53=1u; \
                                         bFM4_GPIO_PFR5_P53=0u; }while(0)


/*---- GPIO bit P54 ----*/

#define GPIO1PIN_P54_GET             ( bFM4_GPIO_PDIR5_P54 )

#define GPIO1PIN_P54_PUT(v)          ( bFM4_GPIO_PDOR5_P54=(v) )

#define GPIO1PIN_P54_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P54_INITIN(v) \
                                                        : GPIO1PIN_P54_INITOUT(v) )

#define GPIO1PIN_P54_INITIN(v)       do{ bFM4_GPIO_PCR5_P54=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P54=0u; \
                                         bFM4_GPIO_PFR5_P54=0u; }while(0)

#define GPIO1PIN_P54_INITOUT(v)      do{ bFM4_GPIO_PDOR5_P54=(v).bInitVal; \
                                         bFM4_GPIO_DDR5_P54=1u; \
                                         bFM4_GPIO_PFR5_P54=0u; }while(0)


/*---- GPIO bit NP54 ----*/
#define GPIO1PIN_NP54_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR5_P54)) )

#define GPIO1PIN_NP54_PUT(v)         ( bFM4_GPIO_PDOR5_P54=(uint32_t)(!(v)) )

#define GPIO1PIN_NP54_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP54_INITIN(v) \
                                                        : GPIO1PIN_NP54_INITOUT(v) )

#define GPIO1PIN_NP54_INITIN(v)      do{ bFM4_GPIO_PCR5_P54=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P54=0u; \
                                         bFM4_GPIO_PFR5_P54=0u; }while(0)

#define GPIO1PIN_NP54_INITOUT(v)     do{ bFM4_GPIO_PDOR5_P54=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR5_P54=1u; \
                                         bFM4_GPIO_PFR5_P54=0u; }while(0)


/*---- GPIO bit P55 ----*/

#define GPIO1PIN_P55_GET             ( bFM4_GPIO_PDIR5_P55 )

#define GPIO1PIN_P55_PUT(v)          ( bFM4_GPIO_PDOR5_P55=(v) )

#define GPIO1PIN_P55_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P55_INITIN(v) \
                                                        : GPIO1PIN_P55_INITOUT(v) )

#define GPIO1PIN_P55_INITIN(v)       do{ bFM4_GPIO_PCR5_P55=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P55=0u; \
                                         bFM4_GPIO_PFR5_P55=0u; }while(0)

#define GPIO1PIN_P55_INITOUT(v)      do{ bFM4_GPIO_PDOR5_P55=(v).bInitVal; \
                                         bFM4_GPIO_DDR5_P55=1u; \
                                         bFM4_GPIO_PFR5_P55=0u; }while(0)


/*---- GPIO bit NP55 ----*/
#define GPIO1PIN_NP55_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR5_P55)) )

#define GPIO1PIN_NP55_PUT(v)         ( bFM4_GPIO_PDOR5_P55=(uint32_t)(!(v)) )

#define GPIO1PIN_NP55_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP55_INITIN(v) \
                                                        : GPIO1PIN_NP55_INITOUT(v) )

#define GPIO1PIN_NP55_INITIN(v)      do{ bFM4_GPIO_PCR5_P55=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P55=0u; \
                                         bFM4_GPIO_PFR5_P55=0u; }while(0)

#define GPIO1PIN_NP55_INITOUT(v)     do{ bFM4_GPIO_PDOR5_P55=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR5_P55=1u; \
                                         bFM4_GPIO_PFR5_P55=0u; }while(0)


/*---- GPIO bit P56 ----*/

#define GPIO1PIN_P56_GET             ( bFM4_GPIO_PDIR5_P56 )

#define GPIO1PIN_P56_PUT(v)          ( bFM4_GPIO_PDOR5_P56=(v) )

#define GPIO1PIN_P56_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P56_INITIN(v) \
                                                        : GPIO1PIN_P56_INITOUT(v) )

#define GPIO1PIN_P56_INITIN(v)       do{ bFM4_GPIO_PCR5_P56=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P56=0u; \
                                         bFM4_GPIO_PFR5_P56=0u; }while(0)

#define GPIO1PIN_P56_INITOUT(v)      do{ bFM4_GPIO_PDOR5_P56=(v).bInitVal; \
                                         bFM4_GPIO_DDR5_P56=1u; \
                                         bFM4_GPIO_PFR5_P56=0u; }while(0)


/*---- GPIO bit NP56 ----*/
#define GPIO1PIN_NP56_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR5_P56)) )

#define GPIO1PIN_NP56_PUT(v)         ( bFM4_GPIO_PDOR5_P56=(uint32_t)(!(v)) )

#define GPIO1PIN_NP56_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP56_INITIN(v) \
                                                        : GPIO1PIN_NP56_INITOUT(v) )

#define GPIO1PIN_NP56_INITIN(v)      do{ bFM4_GPIO_PCR5_P56=(v).bPullup; \
                                         bFM4_GPIO_DDR5_P56=0u; \
                                         bFM4_GPIO_PFR5_P56=0u; }while(0)

#define GPIO1PIN_NP56_INITOUT(v)     do{ bFM4_GPIO_PDOR5_P56=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR5_P56=1u; \
                                         bFM4_GPIO_PFR5_P56=0u; }while(0)


/*---- GPIO bit P60 ----*/

#define GPIO1PIN_P60_GET             ( bFM4_GPIO_PDIR6_P60 )

#define GPIO1PIN_P60_PUT(v)          ( bFM4_GPIO_PDOR6_P60=(v) )

#define GPIO1PIN_P60_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P60_INITIN(v) \
                                                        : GPIO1PIN_P60_INITOUT(v) )

#define GPIO1PIN_P60_INITIN(v)       do{ bFM4_GPIO_PCR6_P60=(v).bPullup; \
                                         bFM4_GPIO_DDR6_P60=0u; \
                                         bFM4_GPIO_PFR6_P60=0u; }while(0)

#define GPIO1PIN_P60_INITOUT(v)      do{ bFM4_GPIO_PDOR6_P60=(v).bInitVal; \
                                         bFM4_GPIO_DDR6_P60=1u; \
                                         bFM4_GPIO_PFR6_P60=0u; }while(0)


/*---- GPIO bit NP60 ----*/
#define GPIO1PIN_NP60_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR6_P60)) )

#define GPIO1PIN_NP60_PUT(v)         ( bFM4_GPIO_PDOR6_P60=(uint32_t)(!(v)) )

#define GPIO1PIN_NP60_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP60_INITIN(v) \
                                                        : GPIO1PIN_NP60_INITOUT(v) )

#define GPIO1PIN_NP60_INITIN(v)      do{ bFM4_GPIO_PCR6_P60=(v).bPullup; \
                                         bFM4_GPIO_DDR6_P60=0u; \
                                         bFM4_GPIO_PFR6_P60=0u; }while(0)

#define GPIO1PIN_NP60_INITOUT(v)     do{ bFM4_GPIO_PDOR6_P60=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR6_P60=1u; \
                                         bFM4_GPIO_PFR6_P60=0u; }while(0)


/*---- GPIO bit P61 ----*/

#define GPIO1PIN_P61_GET             ( bFM4_GPIO_PDIR6_P61 )

#define GPIO1PIN_P61_PUT(v)          ( bFM4_GPIO_PDOR6_P61=(v) )

#define GPIO1PIN_P61_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P61_INITIN(v) \
                                                        : GPIO1PIN_P61_INITOUT(v) )

#define GPIO1PIN_P61_INITIN(v)       do{ bFM4_GPIO_PCR6_P61=(v).bPullup; \
                                         bFM4_GPIO_DDR6_P61=0u; \
                                         bFM4_GPIO_PFR6_P61=0u; }while(0)

#define GPIO1PIN_P61_INITOUT(v)      do{ bFM4_GPIO_PDOR6_P61=(v).bInitVal; \
                                         bFM4_GPIO_DDR6_P61=1u; \
                                         bFM4_GPIO_PFR6_P61=0u; }while(0)


/*---- GPIO bit NP61 ----*/
#define GPIO1PIN_NP61_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR6_P61)) )

#define GPIO1PIN_NP61_PUT(v)         ( bFM4_GPIO_PDOR6_P61=(uint32_t)(!(v)) )

#define GPIO1PIN_NP61_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP61_INITIN(v) \
                                                        : GPIO1PIN_NP61_INITOUT(v) )

#define GPIO1PIN_NP61_INITIN(v)      do{ bFM4_GPIO_PCR6_P61=(v).bPullup; \
                                         bFM4_GPIO_DDR6_P61=0u; \
                                         bFM4_GPIO_PFR6_P61=0u; }while(0)

#define GPIO1PIN_NP61_INITOUT(v)     do{ bFM4_GPIO_PDOR6_P61=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR6_P61=1u; \
                                         bFM4_GPIO_PFR6_P61=0u; }while(0)


/*---- GPIO bit P62 ----*/

#define GPIO1PIN_P62_GET             ( bFM4_GPIO_PDIR6_P62 )

#define GPIO1PIN_P62_PUT(v)          ( bFM4_GPIO_PDOR6_P62=(v) )

#define GPIO1PIN_P62_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P62_INITIN(v) \
                                                        : GPIO1PIN_P62_INITOUT(v) )

#define GPIO1PIN_P62_INITIN(v)       do{ bFM4_GPIO_PCR6_P62=(v).bPullup; \
                                         bFM4_GPIO_DDR6_P62=0u; \
                                         bFM4_GPIO_PFR6_P62=0u; }while(0)

#define GPIO1PIN_P62_INITOUT(v)      do{ bFM4_GPIO_PDOR6_P62=(v).bInitVal; \
                                         bFM4_GPIO_DDR6_P62=1u; \
                                         bFM4_GPIO_PFR6_P62=0u; }while(0)


/*---- GPIO bit NP62 ----*/
#define GPIO1PIN_NP62_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR6_P62)) )

#define GPIO1PIN_NP62_PUT(v)         ( bFM4_GPIO_PDOR6_P62=(uint32_t)(!(v)) )

#define GPIO1PIN_NP62_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP62_INITIN(v) \
                                                        : GPIO1PIN_NP62_INITOUT(v) )

#define GPIO1PIN_NP62_INITIN(v)      do{ bFM4_GPIO_PCR6_P62=(v).bPullup; \
                                         bFM4_GPIO_DDR6_P62=0u; \
                                         bFM4_GPIO_PFR6_P62=0u; }while(0)

#define GPIO1PIN_NP62_INITOUT(v)     do{ bFM4_GPIO_PDOR6_P62=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR6_P62=1u; \
                                         bFM4_GPIO_PFR6_P62=0u; }while(0)


/*---- GPIO bit P63 ----*/

#define GPIO1PIN_P63_GET             ( bFM4_GPIO_PDIR6_P63 )

#define GPIO1PIN_P63_PUT(v)          ( bFM4_GPIO_PDOR6_P63=(v) )

#define GPIO1PIN_P63_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P63_INITIN(v) \
                                                        : GPIO1PIN_P63_INITOUT(v) )

#define GPIO1PIN_P63_INITIN(v)       do{ bFM4_GPIO_PCR6_P63=(v).bPullup; \
                                         bFM4_GPIO_DDR6_P63=0u; \
                                         bFM4_GPIO_PFR6_P63=0u; }while(0)

#define GPIO1PIN_P63_INITOUT(v)      do{ bFM4_GPIO_PDOR6_P63=(v).bInitVal; \
                                         bFM4_GPIO_DDR6_P63=1u; \
                                         bFM4_GPIO_PFR6_P63=0u; }while(0)


/*---- GPIO bit NP63 ----*/
#define GPIO1PIN_NP63_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR6_P63)) )

#define GPIO1PIN_NP63_PUT(v)         ( bFM4_GPIO_PDOR6_P63=(uint32_t)(!(v)) )

#define GPIO1PIN_NP63_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP63_INITIN(v) \
                                                        : GPIO1PIN_NP63_INITOUT(v) )

#define GPIO1PIN_NP63_INITIN(v)      do{ bFM4_GPIO_PCR6_P63=(v).bPullup; \
                                         bFM4_GPIO_DDR6_P63=0u; \
                                         bFM4_GPIO_PFR6_P63=0u; }while(0)

#define GPIO1PIN_NP63_INITOUT(v)     do{ bFM4_GPIO_PDOR6_P63=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR6_P63=1u; \
                                         bFM4_GPIO_PFR6_P63=0u; }while(0)


/*---- GPIO bit P80 ----*/

#define GPIO1PIN_P80_GET             ( bFM4_GPIO_PDIR8_P80 )

#define GPIO1PIN_P80_PUT(v)          ( bFM4_GPIO_PDOR8_P80=(v) )

#define GPIO1PIN_P80_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P80_INITIN(v) \
                                                        : GPIO1PIN_P80_INITOUT(v) )

#define GPIO1PIN_P80_INITIN(v)       do{ bFM4_GPIO_PCR8_P80=(v).bPullup; \
                                         bFM4_GPIO_DDR8_P80=0u; \
                                         bFM4_GPIO_PFR8_P80=0u; }while(0)

#define GPIO1PIN_P80_INITOUT(v)      do{ bFM4_GPIO_PDOR8_P80=(v).bInitVal; \
                                         bFM4_GPIO_DDR8_P80=1u; \
                                         bFM4_GPIO_PFR8_P80=0u; }while(0)


/*---- GPIO bit NP80 ----*/
#define GPIO1PIN_NP80_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR8_P80)) )

#define GPIO1PIN_NP80_PUT(v)         ( bFM4_GPIO_PDOR8_P80=(uint32_t)(!(v)) )

#define GPIO1PIN_NP80_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP80_INITIN(v) \
                                                        : GPIO1PIN_NP80_INITOUT(v) )

#define GPIO1PIN_NP80_INITIN(v)      do{ bFM4_GPIO_PCR8_P80=(v).bPullup; \
                                         bFM4_GPIO_DDR8_P80=0u; \
                                         bFM4_GPIO_PFR8_P80=0u; }while(0)

#define GPIO1PIN_NP80_INITOUT(v)     do{ bFM4_GPIO_PDOR8_P80=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR8_P80=1u; \
                                         bFM4_GPIO_PFR8_P80=0u; }while(0)


/*---- GPIO bit P81 ----*/

#define GPIO1PIN_P81_GET             ( bFM4_GPIO_PDIR8_P81 )

#define GPIO1PIN_P81_PUT(v)          ( bFM4_GPIO_PDOR8_P81=(v) )

#define GPIO1PIN_P81_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_P81_INITIN(v) \
                                                        : GPIO1PIN_P81_INITOUT(v) )

#define GPIO1PIN_P81_INITIN(v)       do{ bFM4_GPIO_PCR8_P81=(v).bPullup; \
                                         bFM4_GPIO_DDR8_P81=0u; \
                                         bFM4_GPIO_PFR8_P81=0u; }while(0)

#define GPIO1PIN_P81_INITOUT(v)      do{ bFM4_GPIO_PDOR8_P81=(v).bInitVal; \
                                         bFM4_GPIO_DDR8_P81=1u; \
                                         bFM4_GPIO_PFR8_P81=0u; }while(0)


/*---- GPIO bit NP81 ----*/
#define GPIO1PIN_NP81_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIR8_P81)) )

#define GPIO1PIN_NP81_PUT(v)         ( bFM4_GPIO_PDOR8_P81=(uint32_t)(!(v)) )

#define GPIO1PIN_NP81_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NP81_INITIN(v) \
                                                        : GPIO1PIN_NP81_INITOUT(v) )

#define GPIO1PIN_NP81_INITIN(v)      do{ bFM4_GPIO_PCR8_P81=(v).bPullup; \
                                         bFM4_GPIO_DDR8_P81=0u; \
                                         bFM4_GPIO_PFR8_P81=0u; }while(0)

#define GPIO1PIN_NP81_INITOUT(v)     do{ bFM4_GPIO_PDOR8_P81=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDR8_P81=1u; \
                                         bFM4_GPIO_PFR8_P81=0u; }while(0)


/*---- GPIO bit PE0 ----*/

#define GPIO1PIN_PE0_GET             ( bFM4_GPIO_PDIRE_PE0 )

#define GPIO1PIN_PE0_PUT(v)          ( bFM4_GPIO_PDORE_PE0=(v) )

#define GPIO1PIN_PE0_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_PE0_INITIN(v) \
                                                        : GPIO1PIN_PE0_INITOUT(v) )

#define GPIO1PIN_PE0_INITIN(v)       do{ bFM4_GPIO_PCRE_PE0=(v).bPullup; \
                                         bFM4_GPIO_DDRE_PE0=0u; \
                                         bFM4_GPIO_PFRE_PE0=0u; }while(0)

#define GPIO1PIN_PE0_INITOUT(v)      do{ bFM4_GPIO_PDORE_PE0=(v).bInitVal; \
                                         bFM4_GPIO_DDRE_PE0=1u; \
                                         bFM4_GPIO_PFRE_PE0=0u; }while(0)


/*---- GPIO bit NPE0 ----*/
#define GPIO1PIN_NPE0_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIRE_PE0)) )

#define GPIO1PIN_NPE0_PUT(v)         ( bFM4_GPIO_PDORE_PE0=(uint32_t)(!(v)) )

#define GPIO1PIN_NPE0_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NPE0_INITIN(v) \
                                                        : GPIO1PIN_NPE0_INITOUT(v) )

#define GPIO1PIN_NPE0_INITIN(v)      do{ bFM4_GPIO_PCRE_PE0=(v).bPullup; \
                                         bFM4_GPIO_DDRE_PE0=0u; \
                                         bFM4_GPIO_PFRE_PE0=0u; }while(0)

#define GPIO1PIN_NPE0_INITOUT(v)     do{ bFM4_GPIO_PDORE_PE0=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDRE_PE0=1u; \
                                         bFM4_GPIO_PFRE_PE0=0u; }while(0)


/*---- GPIO bit PE2 ----*/

#define GPIO1PIN_PE2_GET             ( bFM4_GPIO_PDIRE_PE2 )

#define GPIO1PIN_PE2_PUT(v)          ( bFM4_GPIO_PDORE_PE2=(v) )

#define GPIO1PIN_PE2_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_PE2_INITIN(v) \
                                                        : GPIO1PIN_PE2_INITOUT(v) )

#define GPIO1PIN_PE2_INITIN(v)       do{ bFM4_GPIO_PCRE_PE2=(v).bPullup; \
                                         bFM4_GPIO_DDRE_PE2=0u; \
                                         bFM4_GPIO_PFRE_PE2=0u; }while(0)

#define GPIO1PIN_PE2_INITOUT(v)      do{ bFM4_GPIO_PDORE_PE2=(v).bInitVal; \
                                         bFM4_GPIO_DDRE_PE2=1u; \
                                         bFM4_GPIO_PFRE_PE2=0u; }while(0)


/*---- GPIO bit NPE2 ----*/
#define GPIO1PIN_NPE2_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIRE_PE2)) )

#define GPIO1PIN_NPE2_PUT(v)         ( bFM4_GPIO_PDORE_PE2=(uint32_t)(!(v)) )

#define GPIO1PIN_NPE2_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NPE2_INITIN(v) \
                                                        : GPIO1PIN_NPE2_INITOUT(v) )

#define GPIO1PIN_NPE2_INITIN(v)      do{ bFM4_GPIO_PCRE_PE2=(v).bPullup; \
                                         bFM4_GPIO_DDRE_PE2=0u; \
                                         bFM4_GPIO_PFRE_PE2=0u; }while(0)

#define GPIO1PIN_NPE2_INITOUT(v)     do{ bFM4_GPIO_PDORE_PE2=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDRE_PE2=1u; \
                                         bFM4_GPIO_PFRE_PE2=0u; }while(0)


/*---- GPIO bit PE3 ----*/

#define GPIO1PIN_PE3_GET             ( bFM4_GPIO_PDIRE_PE3 )

#define GPIO1PIN_PE3_PUT(v)          ( bFM4_GPIO_PDORE_PE3=(v) )

#define GPIO1PIN_PE3_INIT(v)         ( (0==(v).bOutput) ? GPIO1PIN_PE3_INITIN(v) \
                                                        : GPIO1PIN_PE3_INITOUT(v) )

#define GPIO1PIN_PE3_INITIN(v)       do{ bFM4_GPIO_PCRE_PE3=(v).bPullup; \
                                         bFM4_GPIO_DDRE_PE3=0u; \
                                         bFM4_GPIO_PFRE_PE3=0u; }while(0)

#define GPIO1PIN_PE3_INITOUT(v)      do{ bFM4_GPIO_PDORE_PE3=(v).bInitVal; \
                                         bFM4_GPIO_DDRE_PE3=1u; \
                                         bFM4_GPIO_PFRE_PE3=0u; }while(0)


/*---- GPIO bit NPE3 ----*/
#define GPIO1PIN_NPE3_GET            ( (uint32_t)(~(uint32_t)(bFM4_GPIO_PDIRE_PE3)) )

#define GPIO1PIN_NPE3_PUT(v)         ( bFM4_GPIO_PDORE_PE3=(uint32_t)(!(v)) )

#define GPIO1PIN_NPE3_INIT(v)        ( (0==(v).bOutput) ? GPIO1PIN_NPE3_INITIN(v) \
                                                        : GPIO1PIN_NPE3_INITOUT(v) )

#define GPIO1PIN_NPE3_INITIN(v)      do{ bFM4_GPIO_PCRE_PE3=(v).bPullup; \
                                         bFM4_GPIO_DDRE_PE3=0u; \
                                         bFM4_GPIO_PFRE_PE3=0u; }while(0)

#define GPIO1PIN_NPE3_INITOUT(v)     do{ bFM4_GPIO_PDORE_PE3=(uint32_t)(~((uint32_t)(v).bInitVal)); \
                                         bFM4_GPIO_DDRE_PE3=1u; \
                                         bFM4_GPIO_PFRE_PE3=0u; }while(0)



/******************************************************************************
   PIN RELOCATION
*******************************************************************************/

/*--- ADTG_1 for ADC#0 ---*/
#define SetPinFunc_ADTG_1_ADC0(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 12u, 4u, 0x02u ); \
                                                 bFM4_GPIO_PFR5_P55 = 1u; }while(0)

/*--- ADTG_1 for ADC#1 ---*/
#define SetPinFunc_ADTG_1_ADC1(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 16u, 4u, 0x02u ); \
                                                 bFM4_GPIO_PFR5_P55 = 1u; }while(0)

/*--- ADTG_1 for ADC#2 ---*/
#define SetPinFunc_ADTG_1_ADC2(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 20u, 4u, 0x02u ); \
                                                 bFM4_GPIO_PFR5_P55 = 1u; }while(0)

/*--- ADTG_2 for ADC#0 ---*/
#define SetPinFunc_ADTG_2_ADC0(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 12u, 4u, 0x03u ); \
                                                 bFM4_GPIO_PFR3_P39 = 1u; }while(0)

/*--- ADTG_2 for ADC#1 ---*/
#define SetPinFunc_ADTG_2_ADC1(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 16u, 4u, 0x03u ); \
                                                 bFM4_GPIO_PFR3_P39 = 1u; }while(0)

/*--- ADTG_2 for ADC#2 ---*/
#define SetPinFunc_ADTG_2_ADC2(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 20u, 4u, 0x03u ); \
                                                 bFM4_GPIO_PFR3_P39 = 1u; }while(0)

/*--- ADTG_3 for ADC#0 ---*/
#define SetPinFunc_ADTG_3_ADC0(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 12u, 4u, 0x04u ); \
                                                 bFM4_GPIO_PFR6_P62 = 1u; }while(0)

/*--- ADTG_3 for ADC#1 ---*/
#define SetPinFunc_ADTG_3_ADC1(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 16u, 4u, 0x04u ); \
                                                 bFM4_GPIO_PFR6_P62 = 1u; }while(0)

/*--- ADTG_3 for ADC#2 ---*/
#define SetPinFunc_ADTG_3_ADC2(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 20u, 4u, 0x04u ); \
                                                 bFM4_GPIO_PFR6_P62 = 1u; }while(0)

/*--- ADTG_6 for ADC#0 ---*/
#define SetPinFunc_ADTG_6_ADC0(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 12u, 4u, 0x07u ); \
                                                 bFM4_GPIO_PFR3_P33 = 1u; }while(0)

/*--- ADTG_6 for ADC#1 ---*/
#define SetPinFunc_ADTG_6_ADC1(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 16u, 4u, 0x07u ); \
                                                 bFM4_GPIO_PFR3_P33 = 1u; }while(0)

/*--- ADTG_6 for ADC#2 ---*/
#define SetPinFunc_ADTG_6_ADC2(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 20u, 4u, 0x07u ); \
                                                 bFM4_GPIO_PFR3_P33 = 1u; }while(0)

/*--- AIN0_0 ---*/
#define SetPinFunc_AIN0_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 0u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P3A = 1u; }while(0)

/*--- AIN0_2 ---*/
#define SetPinFunc_AIN0_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 0u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR5_P50 = 1u; }while(0)

/*--- AIN1_2 ---*/
#define SetPinFunc_AIN1_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 6u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR4_P4C = 1u; }while(0)

/*--- BIN0_0 ---*/
#define SetPinFunc_BIN0_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 2u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P3B = 1u; }while(0)

/*--- BIN0_2 ---*/
#define SetPinFunc_BIN0_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 2u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR5_P51 = 1u; }while(0)

/*--- BIN1_1 ---*/
#define SetPinFunc_BIN1_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 8u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR2_P21 = 1u; \
                                                 bFM4_GPIO_ADE_AN17 = 0u; }while(0)

/*--- BIN1_2 ---*/
#define SetPinFunc_BIN1_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 8u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR4_P4D = 1u; }while(0)

/*--- CROUT_0 ---*/
#define SetPinFunc_CROUT_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR00, 1u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR2_P22 = 1u; \
                                                 bFM4_GPIO_ADE_AN16 = 0u; }while(0)

/*--- CROUT_1 ---*/
#define SetPinFunc_CROUT_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR00, 1u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR6_P63 = 1u; }while(0)

/*--- CTS4_0 ---*/
#define SetPinFunc_CTS4_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 2u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P50 = 1u; }while(0)

/*--- DTTI0X_0 ---*/
#define SetPinFunc_DTTI0X_0(dummy)           do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 16u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P39 = 1u; }while(0)

/*--- DTTI1X_0 ---*/
#define SetPinFunc_DTTI1X_0(dummy)           do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 16u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P56 = 1u; }while(0)

/*--- FRCK0_2 ---*/
#define SetPinFunc_FRCK0_2(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 18u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR1_P10 = 1u; \
                                                 bFM4_GPIO_ADE_AN00 = 0u; }while(0)

/*--- FRCK1_0 ---*/
#define SetPinFunc_FRCK1_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 18u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0A = 1u; }while(0)

/*--- FRCK1_1 ---*/
#define SetPinFunc_FRCK1_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 18u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR4_P4E = 1u; }while(0)

/*--- IC00_1 ---*/
#define SetPinFunc_IC00_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 20u, 3u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P19 = 1u; \
                                                 bFM4_GPIO_ADE_AN09 = 0u; }while(0)

/*--- IC00_2 ---*/
#define SetPinFunc_IC00_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 20u, 3u, 0x03u ); \
                                                 bFM4_GPIO_PFR1_P11 = 1u; \
                                                 bFM4_GPIO_ADE_AN01 = 0u; }while(0)

/*--- IC01_1 ---*/
#define SetPinFunc_IC01_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 23u, 3u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P1A = 1u; \
                                                 bFM4_GPIO_ADE_AN10 = 0u; }while(0)

/*--- IC01_2 ---*/
#define SetPinFunc_IC01_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 23u, 3u, 0x03u ); \
                                                 bFM4_GPIO_PFR1_P12 = 1u; \
                                                 bFM4_GPIO_ADE_AN02 = 0u; }while(0)

/*--- IC02_1 ---*/
#define SetPinFunc_IC02_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 26u, 3u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P1B = 1u; \
                                                 bFM4_GPIO_ADE_AN11 = 0u; }while(0)

/*--- IC02_2 ---*/
#define SetPinFunc_IC02_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 26u, 3u, 0x03u ); \
                                                 bFM4_GPIO_PFR1_P13 = 1u; \
                                                 bFM4_GPIO_ADE_AN03 = 0u; }while(0)

/*--- IC03_2 ---*/
#define SetPinFunc_IC03_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 29u, 3u, 0x03u ); \
                                                 bFM4_GPIO_PFR1_P14 = 1u; \
                                                 bFM4_GPIO_ADE_AN04 = 0u; }while(0)

/*--- IC10_0 ---*/
#define SetPinFunc_IC10_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 20u, 3u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0B = 1u; }while(0)

/*--- IC11_0 ---*/
#define SetPinFunc_IC11_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 23u, 3u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0C = 1u; }while(0)

/*--- IC12_0 ---*/
#define SetPinFunc_IC12_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 26u, 3u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0D = 1u; }while(0)

/*--- IC13_0 ---*/
#define SetPinFunc_IC13_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 29u, 3u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0E = 1u; }while(0)

/*--- INT00_0 ---*/
#define SetPinFunc_INT00_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 0u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P50 = 1u; }while(0)

/*--- INT00_1 ---*/
#define SetPinFunc_INT00_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 0u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR0_P0B = 1u; }while(0)

/*--- INT01_0 ---*/
#define SetPinFunc_INT01_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 2u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P51 = 1u; }while(0)

/*--- INT02_0 ---*/
#define SetPinFunc_INT02_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 4u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P54 = 1u; }while(0)

/*--- INT02_1 ---*/
#define SetPinFunc_INT02_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 4u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P10 = 1u; \
                                                 bFM4_GPIO_ADE_AN00 = 0u; }while(0)

/*--- INT03_0 ---*/
#define SetPinFunc_INT03_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 6u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR6_P63 = 1u; }while(0)

/*--- INT03_1 ---*/
#define SetPinFunc_INT03_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 6u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P13 = 1u; \
                                                 bFM4_GPIO_ADE_AN03 = 0u; }while(0)

/*--- INT04_0 ---*/
#define SetPinFunc_INT04_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 8u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P33 = 1u; }while(0)

/*--- INT04_1 ---*/
#define SetPinFunc_INT04_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 8u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR6_P62 = 1u; }while(0)

/*--- INT05_1 ---*/
#define SetPinFunc_INT05_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 10u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P19 = 1u; \
                                                 bFM4_GPIO_ADE_AN09 = 0u; }while(0)

/*--- INT06_1 ---*/
#define SetPinFunc_INT06_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 12u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR2_P21 = 1u; \
                                                 bFM4_GPIO_ADE_AN17 = 0u; }while(0)

/*--- INT07_2 ---*/
#define SetPinFunc_INT07_2(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 14u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR5_P55 = 1u; }while(0)

/*--- INT08_2 ---*/
#define SetPinFunc_INT08_2(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 16u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR5_P56 = 1u; }while(0)

/*--- INT09_2 ---*/
#define SetPinFunc_INT09_2(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 18u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR3_P31 = 1u; }while(0)

/*--- INT10_1 ---*/
#define SetPinFunc_INT10_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 20u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P32 = 1u; }while(0)

/*--- INT11_1 ---*/
#define SetPinFunc_INT11_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 22u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR4_P4E = 1u; }while(0)

/*--- INT12_2 ---*/
#define SetPinFunc_INT12_2(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 24u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR0_P0A = 1u; }while(0)

/*--- INT13_2 ---*/
#define SetPinFunc_INT13_2(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 26u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR4_P4D = 1u; }while(0)

/*--- INT14_1 ---*/
#define SetPinFunc_INT14_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 28u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P16 = 1u; \
                                                 bFM4_GPIO_ADE_AN06 = 0u; }while(0)

/*--- INT15_2 ---*/
#define SetPinFunc_INT15_2(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR06, 30u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR3_P30 = 1u; }while(0)

/*--- MAD00_0 ---*/
#define SetPinFunc_MAD00_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 14u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P3D = 1u; }while(0)

/*--- MAD01_0 ---*/
#define SetPinFunc_MAD01_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 2u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P3E = 1u; }while(0)

/*--- MAD02_0 ---*/
#define SetPinFunc_MAD02_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 3u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P3F = 1u; }while(0)

/*--- MAD03_0 ---*/
#define SetPinFunc_MAD03_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 4u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR4_P4B = 1u; }while(0)

/*--- MAD04_0 ---*/
#define SetPinFunc_MAD04_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 5u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR4_P4C = 1u; }while(0)

/*--- MAD05_0 ---*/
#define SetPinFunc_MAD05_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 6u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR4_P4D = 1u; }while(0)

/*--- MAD06_0 ---*/
#define SetPinFunc_MAD06_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 7u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR4_P4E = 1u; }while(0)

/*--- MAD07_0 ---*/
#define SetPinFunc_MAD07_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 8u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR1_P10 = 1u; \
                                                 bFM4_GPIO_ADE_AN00 = 0u; }while(0)

/*--- MAD08_0 ---*/
#define SetPinFunc_MAD08_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 15u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR1_P11 = 1u; \
                                                 bFM4_GPIO_ADE_AN01 = 0u; }while(0)

/*--- MAD09_0 ---*/
#define SetPinFunc_MAD09_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 16u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR1_P12 = 1u; \
                                                 bFM4_GPIO_ADE_AN02 = 0u; }while(0)

/*--- MAD10_0 ---*/
#define SetPinFunc_MAD10_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 17u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR1_P13 = 1u; \
                                                 bFM4_GPIO_ADE_AN03 = 0u; }while(0)

/*--- MAD11_0 ---*/
#define SetPinFunc_MAD11_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 18u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR1_P14 = 1u; \
                                                 bFM4_GPIO_ADE_AN04 = 0u; }while(0)

/*--- MAD12_0 ---*/
#define SetPinFunc_MAD12_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 19u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR1_P15 = 1u; \
                                                 bFM4_GPIO_ADE_AN05 = 0u; }while(0)

/*--- MAD13_0 ---*/
#define SetPinFunc_MAD13_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 20u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR1_P16 = 1u; \
                                                 bFM4_GPIO_ADE_AN06 = 0u; }while(0)

/*--- MAD14_0 ---*/
#define SetPinFunc_MAD14_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 21u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR1_P17 = 1u; \
                                                 bFM4_GPIO_ADE_AN07 = 0u; }while(0)

/*--- MAD15_0 ---*/
#define SetPinFunc_MAD15_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 22u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR1_P18 = 1u; \
                                                 bFM4_GPIO_ADE_AN08 = 0u; }while(0)

/*--- MAD16_0 ---*/
#define SetPinFunc_MAD16_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 23u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR1_P19 = 1u; \
                                                 bFM4_GPIO_ADE_AN09 = 0u; }while(0)

/*--- MAD17_0 ---*/
#define SetPinFunc_MAD17_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 24u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR1_P1A = 1u; \
                                                 bFM4_GPIO_ADE_AN10 = 0u; }while(0)

/*--- MAD18_0 ---*/
#define SetPinFunc_MAD18_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 25u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR1_P1B = 1u; \
                                                 bFM4_GPIO_ADE_AN11 = 0u; }while(0)

/*--- MAD22_0 ---*/
#define SetPinFunc_MAD22_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 29u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR2_P23 = 1u; \
                                                 bFM4_GPIO_ADE_AN15 = 0u; }while(0)

/*--- MAD23_0 ---*/
#define SetPinFunc_MAD23_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 30u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR2_P21 = 1u; \
                                                 bFM4_GPIO_ADE_AN17 = 0u; }while(0)

/*--- MADATA00_0 ---*/
#define SetPinFunc_MADATA00_0(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 9u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P50 = 1u; }while(0)

/*--- MADATA01_0 ---*/
#define SetPinFunc_MADATA01_0(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 10u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P51 = 1u; }while(0)

/*--- MADATA02_0 ---*/
#define SetPinFunc_MADATA02_0(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 11u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P52 = 1u; }while(0)

/*--- MADATA03_0 ---*/
#define SetPinFunc_MADATA03_0(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 12u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P53 = 1u; }while(0)

/*--- MADATA04_0 ---*/
#define SetPinFunc_MADATA04_0(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 13u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P54 = 1u; }while(0)

/*--- MADATA05_0 ---*/
#define SetPinFunc_MADATA05_0(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 14u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P55 = 1u; }while(0)

/*--- MADATA06_0 ---*/
#define SetPinFunc_MADATA06_0(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 15u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P56 = 1u; }while(0)

/*--- MADATA07_0 ---*/
#define SetPinFunc_MADATA07_0(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 16u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P30 = 1u; }while(0)

/*--- MADATA08_0 ---*/
#define SetPinFunc_MADATA08_0(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 17u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P31 = 1u; }while(0)

/*--- MADATA09_0 ---*/
#define SetPinFunc_MADATA09_0(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 18u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P32 = 1u; }while(0)

/*--- MADATA10_0 ---*/
#define SetPinFunc_MADATA10_0(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 19u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P33 = 1u; }while(0)

/*--- MALE_0 ---*/
#define SetPinFunc_MALE_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 0u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0C = 1u; }while(0)

/*--- MCSX0_0 ---*/
#define SetPinFunc_MCSX0_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR11, 1u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0B = 1u; }while(0)

/*--- MCSX1_0 ---*/
#define SetPinFunc_MCSX1_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 7u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0A = 1u; }while(0)

/*--- MCSX5_0 ---*/
#define SetPinFunc_MCSX5_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 11u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P09 = 1u; \
                                                 bFM4_GPIO_ADE_AN19 = 0u; }while(0)

/*--- MCSX6_0 ---*/
#define SetPinFunc_MCSX6_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 12u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P02 = 1u; }while(0)

/*--- MCSX7_0 ---*/
#define SetPinFunc_MCSX7_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 13u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P00 = 1u; }while(0)

/*--- MDQM0_0 ---*/
#define SetPinFunc_MDQM0_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 4u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0D = 1u; }while(0)

/*--- MDQM1_0 ---*/
#define SetPinFunc_MDQM1_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 4u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0E = 1u; }while(0)

/*--- MOEX_0 ---*/
#define SetPinFunc_MOEX_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 5u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR6_P62 = 1u; }while(0)

/*--- MWEX_0 ---*/
#define SetPinFunc_MWEX_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR10, 3u, 1u, 0x01u ); \
                                                 bFM4_GPIO_PFR6_P63 = 1u; }while(0)

/*--- NMIX ---*/
#define SetPinFunc_NMIX(dummy)               do{ bFM4_GPIO_EPFR00_NMIS = 1; \
                                                 bFM4_GPIO_PFR6_P60 = 1u; }while(0)

/*--- RTCCO_0 ---*/
#define SetPinFunc_RTCCO_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR00, 4u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR6_P61 = 1u; }while(0)

/*--- RTCCO_1 ---*/
#define SetPinFunc_RTCCO_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR00, 4u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P12 = 1u; \
                                                 bFM4_GPIO_ADE_AN02 = 0u; }while(0)

/*--- RTCCO_2 ---*/
#define SetPinFunc_RTCCO_2(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR00, 4u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR3_P39 = 1u; }while(0)

/*--- RTO00_0 ---*/
#define SetPinFunc_RTO00_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 0u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P3A = 1u; }while(0)

/*--- RTO00_1 ---*/
#define SetPinFunc_RTO00_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 0u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR2_P23 = 1u; \
                                                 bFM4_GPIO_ADE_AN15 = 0u; }while(0)

/*--- RTO01_0 ---*/
#define SetPinFunc_RTO01_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 2u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P3B = 1u; }while(0)

/*--- RTO02_0 ---*/
#define SetPinFunc_RTO02_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 4u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P3C = 1u; }while(0)

/*--- RTO03_0 ---*/
#define SetPinFunc_RTO03_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 6u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P3D = 1u; }while(0)

/*--- RTO04_0 ---*/
#define SetPinFunc_RTO04_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 8u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P3E = 1u; }while(0)

/*--- RTO05_0 ---*/
#define SetPinFunc_RTO05_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR01, 10u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P3F = 1u; }while(0)

/*--- RTO10_0 ---*/
#define SetPinFunc_RTO10_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 0u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P50 = 1u; }while(0)

/*--- RTO11_0 ---*/
#define SetPinFunc_RTO11_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 2u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P51 = 1u; }while(0)

/*--- RTO12_0 ---*/
#define SetPinFunc_RTO12_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 4u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P52 = 1u; }while(0)

/*--- RTO13_0 ---*/
#define SetPinFunc_RTO13_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 6u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P53 = 1u; }while(0)

/*--- RTO14_0 ---*/
#define SetPinFunc_RTO14_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 8u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P54 = 1u; }while(0)

/*--- RTO14_1 ---*/
#define SetPinFunc_RTO14_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 8u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR4_P44 = 1u; }while(0)

/*--- RTO15_0 ---*/
#define SetPinFunc_RTO15_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 10u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P55 = 1u; }while(0)

/*--- RTO15_1 ---*/
#define SetPinFunc_RTO15_1(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR02, 10u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR4_P45 = 1u; }while(0)

/*--- RTS4_0 ---*/
#define SetPinFunc_RTS4_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 0u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P51 = 1u; }while(0)

/*--- RTS4_2 ---*/
#define SetPinFunc_RTS4_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 0u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR3_P30 = 1u; }while(0)

/*--- RX0_2 ---*/
#define SetPinFunc_RX0_2(dummy)              do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 24u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR6_P63 = 1u; }while(0)

/*--- RX1_2 ---*/
#define SetPinFunc_RX1_2(dummy)              do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 28u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR1_P10 = 1u; \
                                                 bFM4_GPIO_ADE_AN00 = 0u; }while(0)

/*--- SCK0_0 ---*/
#define SetPinFunc_SCK0_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 8u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR2_P23 = 1u; \
                                                 bFM4_GPIO_ADE_AN15 = 0u; }while(0)

/*--- SCK0_1 ---*/
#define SetPinFunc_SCK0_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 8u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P15 = 1u; \
                                                 bFM4_GPIO_ADE_AN05 = 0u; }while(0)

/*--- SCK1_1 ---*/
#define SetPinFunc_SCK1_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 14u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P12 = 1u; \
                                                 bFM4_GPIO_ADE_AN02 = 0u; }while(0)

/*--- SCK2_2 ---*/
#define SetPinFunc_SCK2_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 20u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR1_P18 = 1u; \
                                                 bFM4_GPIO_ADE_AN08 = 0u; }while(0)

/*--- SCK3_1 ---*/
#define SetPinFunc_SCK3_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 26u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P33 = 1u; }while(0)

/*--- SCK4_0 ---*/
#define SetPinFunc_SCK4_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 8u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P52 = 1u; }while(0)

/*--- SCK4_1 ---*/
#define SetPinFunc_SCK4_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 8u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P1B = 1u; \
                                                 bFM4_GPIO_ADE_AN11 = 0u; }while(0)

/*--- SCK5_0 ---*/
#define SetPinFunc_SCK5_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 14u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR6_P60 = 1u; }while(0)

/*--- SCK6_1 ---*/
#define SetPinFunc_SCK6_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 20u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR0_P0D = 1u; }while(0)

/*--- SCK7_1 ---*/
#define SetPinFunc_SCK7_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 26u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR4_P4C = 1u; }while(0)

/*--- SCS6_1 ---*/
#define SetPinFunc_SCS6_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR16, 0u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR0_P0E = 1u; }while(0)

/*--- SCS7_1 ---*/
#define SetPinFunc_SCS7_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR16, 2u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR4_P4B = 1u; }while(0)

/*--- SIN0_0 ---*/
#define SetPinFunc_SIN0_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 4u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR2_P21 = 1u; \
                                                 bFM4_GPIO_ADE_AN17 = 0u; }while(0)

/*--- SIN0_1 ---*/
#define SetPinFunc_SIN0_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 4u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P13 = 1u; \
                                                 bFM4_GPIO_ADE_AN03 = 0u; }while(0)

/*--- SIN1_0 ---*/
#define SetPinFunc_SIN1_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 10u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0A = 1u; }while(0)

/*--- SIN1_1 ---*/
#define SetPinFunc_SIN1_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 10u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P10 = 1u; \
                                                 bFM4_GPIO_ADE_AN00 = 0u; }while(0)

/*--- SIN2_2 ---*/
#define SetPinFunc_SIN2_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 16u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR1_P16 = 1u; \
                                                 bFM4_GPIO_ADE_AN06 = 0u; }while(0)

/*--- SIN3_1 ---*/
#define SetPinFunc_SIN3_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 22u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P31 = 1u; }while(0)

/*--- SIN4_0 ---*/
#define SetPinFunc_SIN4_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 4u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P54 = 1u; }while(0)

/*--- SIN4_1 ---*/
#define SetPinFunc_SIN4_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 4u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P19 = 1u; \
                                                 bFM4_GPIO_ADE_AN09 = 0u; }while(0)

/*--- SIN5_0 ---*/
#define SetPinFunc_SIN5_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 10u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR6_P62 = 1u; }while(0)

/*--- SIN6_0 ---*/
#define SetPinFunc_SIN6_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 16u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P55 = 1u; }while(0)

/*--- SIN6_1 ---*/
#define SetPinFunc_SIN6_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 16u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR0_P0B = 1u; }while(0)

/*--- SIN7_1 ---*/
#define SetPinFunc_SIN7_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 22u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR4_P4E = 1u; }while(0)

/*--- SOT0_0 ---*/
#define SetPinFunc_SOT0_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 6u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR2_P22 = 1u; \
                                                 bFM4_GPIO_ADE_AN16 = 0u; }while(0)

/*--- SOT0_1 ---*/
#define SetPinFunc_SOT0_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 6u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P14 = 1u; \
                                                 bFM4_GPIO_ADE_AN04 = 0u; }while(0)

/*--- SOT1_0 ---*/
#define SetPinFunc_SOT1_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 12u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P09 = 1u; \
                                                 bFM4_GPIO_ADE_AN19 = 0u; }while(0)

/*--- SOT1_1 ---*/
#define SetPinFunc_SOT1_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 12u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P11 = 1u; \
                                                 bFM4_GPIO_ADE_AN01 = 0u; }while(0)

/*--- SOT2_2 ---*/
#define SetPinFunc_SOT2_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 18u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR1_P17 = 1u; \
                                                 bFM4_GPIO_ADE_AN07 = 0u; }while(0)

/*--- SOT3_1 ---*/
#define SetPinFunc_SOT3_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR07, 24u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P32 = 1u; }while(0)

/*--- SOT4_0 ---*/
#define SetPinFunc_SOT4_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 6u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P53 = 1u; }while(0)

/*--- SOT4_1 ---*/
#define SetPinFunc_SOT4_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 6u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P1A = 1u; \
                                                 bFM4_GPIO_ADE_AN10 = 0u; }while(0)

/*--- SOT5_0 ---*/
#define SetPinFunc_SOT5_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 12u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR6_P61 = 1u; }while(0)

/*--- SOT6_0 ---*/
#define SetPinFunc_SOT6_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 18u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR5_P56 = 1u; }while(0)

/*--- SOT6_1 ---*/
#define SetPinFunc_SOT6_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 18u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR0_P0C = 1u; }while(0)

/*--- SOT7_1 ---*/
#define SetPinFunc_SOT7_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR08, 24u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR4_P4D = 1u; }while(0)

/*--- SUBOUT_0 ---*/
#define SetPinFunc_SUBOUT_0(dummy)           do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR00, 6u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR6_P61 = 1u; }while(0)

/*--- SUBOUT_1 ---*/
#define SetPinFunc_SUBOUT_1(dummy)           do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR00, 6u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR1_P12 = 1u; \
                                                 bFM4_GPIO_ADE_AN02 = 0u; }while(0)

/*--- SUBOUT_2 ---*/
#define SetPinFunc_SUBOUT_2(dummy)           do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR00, 6u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR3_P39 = 1u; }while(0)

/*--- S_CD_0 ---*/
#define SetPinFunc_S_CD_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR18, 26u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR6_P63 = 1u; }while(0)

/*--- S_CLK_0 ---*/
#define SetPinFunc_S_CLK_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR18, 14u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0E = 1u; }while(0)

/*--- S_CMD_0 ---*/
#define SetPinFunc_S_CMD_0(dummy)            do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR18, 16u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0D = 1u; }while(0)

/*--- S_DATA0_0 ---*/
#define SetPinFunc_S_DATA0_0(dummy)          do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR18, 18u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0B = 1u; }while(0)

/*--- S_DATA1_0 ---*/
#define SetPinFunc_S_DATA1_0(dummy)          do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR18, 20u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0C = 1u; }while(0)

/*--- S_DATA2_0 ---*/
#define SetPinFunc_S_DATA2_0(dummy)          do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR18, 22u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P09 = 1u; \
                                                 bFM4_GPIO_ADE_AN19 = 0u; }while(0)

/*--- S_DATA3_0 ---*/
#define SetPinFunc_S_DATA3_0(dummy)          do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR18, 24u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR0_P0A = 1u; }while(0)

/*--- TIOA0_1_OUT ---*/
#define SetPinFunc_TIOA0_1_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 2u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P3A = 1u; }while(0)

/*--- TIOA1_1_IN ---*/
#define SetPinFunc_TIOA1_1_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 8u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P3B = 1u; }while(0)

/*--- TIOA1_1_OUT ---*/
#define SetPinFunc_TIOA1_1_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 10u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P3B = 1u; }while(0)

/*--- TIOA1_2_IN ---*/
#define SetPinFunc_TIOA1_2_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 8u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR5_P53 = 1u; }while(0)

/*--- TIOA1_2_OUT ---*/
#define SetPinFunc_TIOA1_2_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 10u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR5_P53 = 1u; }while(0)

/*--- TIOA2_1_OUT ---*/
#define SetPinFunc_TIOA2_1_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 18u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P3C = 1u; }while(0)

/*--- TIOA2_2_OUT ---*/
#define SetPinFunc_TIOA2_2_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 18u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR6_P60 = 1u; }while(0)

/*--- TIOA3_1_IN ---*/
#define SetPinFunc_TIOA3_1_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 24u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P3D = 1u; }while(0)

/*--- TIOA3_1_OUT ---*/
#define SetPinFunc_TIOA3_1_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 26u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P3D = 1u; }while(0)

/*--- TIOA3_2_IN ---*/
#define SetPinFunc_TIOA3_2_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 24u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR0_P09 = 1u; \
                                                 bFM4_GPIO_ADE_AN19 = 0u; }while(0)

/*--- TIOA3_2_OUT ---*/
#define SetPinFunc_TIOA3_2_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 26u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR0_P09 = 1u; \
                                                 bFM4_GPIO_ADE_AN19 = 0u; }while(0)

/*--- TIOA4_0_OUT ---*/
#define SetPinFunc_TIOA4_0_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 2u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR4_P44 = 1u; }while(0)

/*--- TIOA4_1_OUT ---*/
#define SetPinFunc_TIOA4_1_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 2u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P3E = 1u; }while(0)

/*--- TIOA5_1_IN ---*/
#define SetPinFunc_TIOA5_1_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 8u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P3F = 1u; }while(0)

/*--- TIOA5_1_OUT ---*/
#define SetPinFunc_TIOA5_1_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 10u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P3F = 1u; }while(0)

/*--- TIOA5_2_IN ---*/
#define SetPinFunc_TIOA5_2_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 8u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR0_P0D = 1u; }while(0)

/*--- TIOA5_2_OUT ---*/
#define SetPinFunc_TIOA5_2_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 10u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR0_P0D = 1u; }while(0)

/*--- TIOA6_1_OUT ---*/
#define SetPinFunc_TIOA6_1_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 18u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR0_P0C = 1u; }while(0)

/*--- TIOA7_1_IN ---*/
#define SetPinFunc_TIOA7_1_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 24u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR2_P23 = 1u; \
                                                 bFM4_GPIO_ADE_AN15 = 0u; }while(0)

/*--- TIOA7_1_OUT ---*/
#define SetPinFunc_TIOA7_1_OUT(dummy)        do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 26u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR2_P23 = 1u; \
                                                 bFM4_GPIO_ADE_AN15 = 0u; }while(0)

/*--- TIOB0_0_IN ---*/
#define SetPinFunc_TIOB0_0_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 4u, 3u, 0x01u ); \
                                                 bFM4_GPIO_PFR4_P45 = 1u; }while(0)

/*--- TIOB0_1_IN ---*/
#define SetPinFunc_TIOB0_1_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 4u, 3u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P30 = 1u; }while(0)

/*--- TIOB1_0_IN ---*/
#define SetPinFunc_TIOB1_0_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 12u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR4_P4B = 1u; }while(0)

/*--- TIOB1_1_IN ---*/
#define SetPinFunc_TIOB1_1_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 12u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P31 = 1u; }while(0)

/*--- TIOB1_2_IN ---*/
#define SetPinFunc_TIOB1_2_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 12u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR5_P54 = 1u; }while(0)

/*--- TIOB2_0_IN ---*/
#define SetPinFunc_TIOB2_0_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 20u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR4_P4C = 1u; }while(0)

/*--- TIOB2_1_IN ---*/
#define SetPinFunc_TIOB2_1_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 20u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P32 = 1u; }while(0)

/*--- TIOB2_2_IN ---*/
#define SetPinFunc_TIOB2_2_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 20u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR6_P61 = 1u; }while(0)

/*--- TIOB3_0_IN ---*/
#define SetPinFunc_TIOB3_0_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 28u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR4_P4D = 1u; }while(0)

/*--- TIOB3_1_IN ---*/
#define SetPinFunc_TIOB3_1_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR04, 28u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR3_P33 = 1u; }while(0)

/*--- TIOB4_0_IN ---*/
#define SetPinFunc_TIOB4_0_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 4u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR4_P4E = 1u; }while(0)

/*--- TIOB5_2_IN ---*/
#define SetPinFunc_TIOB5_2_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 12u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR0_P0E = 1u; }while(0)

/*--- TIOB6_1_IN ---*/
#define SetPinFunc_TIOB6_1_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 20u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR0_P0B = 1u; }while(0)

/*--- TIOB7_1_IN ---*/
#define SetPinFunc_TIOB7_1_IN(dummy)         do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR05, 28u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR2_P22 = 1u; \
                                                 bFM4_GPIO_ADE_AN16 = 0u; }while(0)

/*--- TX0_2 ---*/
#define SetPinFunc_TX0_2(dummy)              do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 26u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR6_P62 = 1u; }while(0)

/*--- TX1_2 ---*/
#define SetPinFunc_TX1_2(dummy)              do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 30u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR1_P11 = 1u; \
                                                 bFM4_GPIO_ADE_AN01 = 0u; }while(0)

/*--- ZIN0_0 ---*/
#define SetPinFunc_ZIN0_0(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 4u, 2u, 0x01u ); \
                                                 bFM4_GPIO_PFR3_P3C = 1u; }while(0)

/*--- ZIN0_2 ---*/
#define SetPinFunc_ZIN0_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 4u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR5_P52 = 1u; }while(0)

/*--- ZIN1_1 ---*/
#define SetPinFunc_ZIN1_1(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 10u, 2u, 0x02u ); \
                                                 bFM4_GPIO_PFR2_P22 = 1u; \
                                                 bFM4_GPIO_ADE_AN16 = 0u; }while(0)

/*--- ZIN1_2 ---*/
#define SetPinFunc_ZIN1_2(dummy)             do{ PINRELOC_SET_EPFR( FM4_GPIO->EPFR09, 10u, 2u, 0x03u ); \
                                                 bFM4_GPIO_PFR4_P4E = 1u; }while(0)


#endif // #ifndef __GPIO_MB9BF56XM_H__


/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

