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
 *  									  External Interrupt Driver Header File
 *
 * File           : WyzBee_ext.h
 * Version        : V1.00
 * Programmer(s)  :
 *********************************************************************************************************
 * Note(s)		 :
 *********************************************************************************************************
 */

#ifndef WyzBee_EXT_H
#define WyzBee_EXT_H

#ifdef __cplusplus
extern "C"{
#endif
	
/*
 *********************************************************************************************************
 *                                              INCLUDE FILES
 *********************************************************************************************************
 */

#include <WyzBee.h>
#include <exint.h>


/*
 *********************************************************************************************************
 *                                                 DEFINES
 *********************************************************************************************************
 */
/// Macro for initializing local structures to zero
#define WyzBee_PDL_ZERO(x) PDL_ZERO_STRUCT(x)

#define WyzBeeSetPin_INT11_1(x) SetPinFunc_INT11_1(x);
#define WyzBeeSetPin_INT02_1(x) SetPinFunc_INT02_1(x);
/*
*********************************************************************************************************
*********************************************************************************************************
*                                                Error Codes
*********************************************************************************************************
*********************************************************************************************************
*/



/*
 *********************************************************************************************************
 *                                               DATA TYPES
 *********************************************************************************************************
 */
/**
 *****************************************************************************
 ** \brief External Interrupt configuration
 **
 ** The EXINT configuration
 *****************************************************************************/
typedef struct WyzBee_exint_config            /*-------------EXTERNAL INTERRUPT STRUCTURE CONFIG----*/
{
  boolean_t         abEnable[32u];           ///< TRUE: External Interrupt enable
  en_exint_level_t  aenLevel[32u];           ///< level detection, see #WyzBee_exint_level_t for details
  func_ptr_t        apfnExintCallback[32u];  ///< Callback pointers
} WyzBee_exint_config_t;

typedef enum WyzBee_exint_level                  /*-------------EXTERNAL INTERRUPT LEVEL----*/
{
  CalExIntLowLevel     = 0,  ///< "L" level detection
  CalExIntHighLevel    = 1,  ///< "H" level detection
  CalExIntRisingEdge   = 2,  ///< Rising edge detection
  CalExIntFallingEdge  = 3   ///< Falling edge detection
} WyzBee_exint_level_t;

/*
*****************************************************************************
** \brief NMI configuration
**
** The NMI configuration
*****************************************************************************/
typedef struct WyzBee_exint_nmi_config                   /*-------------NMNI STRUCTURE CONFIG----*/
{
 boolean_t         bTouchNVIC;
 func_ptr_t        pfnNMICallback;   ///< NMI Callback pointers
} WyzBee_exint_nmi_config_t;

/*
 *********************************************************************************************************
 *                                           FUNCTION PROTOTYPES
 *********************************************************************************************************
 */


err_t WyzBee_Exint_Init(WyzBee_exint_config_t* Config) ;
err_t WyzBee_Exint_IR_Init(WyzBee_exint_config_t* Config) ;

err_t WyzBee_Exint_DeInit(void) ;

err_t WyzBee_Exint_EnableChannel(uint8_t u8Channel) ;

err_t WyzBee_Exint_DisableChannel(uint8_t u8Channel) ;

err_t WyzBee_Exint_Nmi_Init(WyzBee_exint_nmi_config_t* Config) ;

err_t WyzBee_Exint_Nmi_DeInit(WyzBee_exint_nmi_config_t* Config) ;
/*
 *********************************************************************************************************
 *                                           END
 *********************************************************************************************************
 */
 
#ifdef __cplusplus
}
#endif

#endif // WyzBee_ext_H
