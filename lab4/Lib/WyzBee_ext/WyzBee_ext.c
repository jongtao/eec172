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
 *											  External Interrupt Driver Source File
 *
 * File           : WyzBee_ext.c
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

#include <WyzBee_ext.h>
#include <exint.h>
#include <WyzBee.h>
#include <pdl.h>
/*
 *********************************************************************************************************
 *                                              LOCAL DEFINES
 *********************************************************************************************************
 */

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
 *                                             GLOBAL FUNCTIONS
 *********************************************************************************************************
 *********************************************************************************************************
 */



/**
 ******************************************************************************
 ** \brief Init External Interrupts
 **
 ** This function initializes the external interrupts according the given
 ** configuration.
 **
 ** \param [in]  Config        EXINT configuration parameters
 **
 ** \retval Ok                     EXINT initialized
 ** \retval ErrorInvalidParameter  pstcConfig == NULL or Illegal mode
 ******************************************************************************/

//define global interrupt struct 
stc_exint_config_t pstcConfig;

err_t WyzBee_Exint_Init(WyzBee_exint_config_t* Config)
{
   extern stc_exint_config_t pstcConfig;
   //uint8 ret;
   pstcConfig.abEnable[11]   =   Config->abEnable[11];
   pstcConfig.aenLevel[11]	 =	 Config->aenLevel[11];
   pstcConfig.apfnExintCallback[11]   =   Config->apfnExintCallback[11];
   WyzBeeSetPin_INT11_1(0u);
   if(!(Exint_Init(&pstcConfig)))
	   return ERR_NONE;
   else return ERR_INVALID_PARMS;
} 

err_t WyzBee_Exint_IR_Init(WyzBee_exint_config_t* Config)
{
   extern stc_exint_config_t pstcConfig;
   //uint8 ret;
   pstcConfig.abEnable[2]   =   Config->abEnable[2];
   pstcConfig.aenLevel[2]	 =	 Config->aenLevel[2];
   pstcConfig.apfnExintCallback[2]   =   Config->apfnExintCallback[2];
   WyzBeeSetPin_INT02_1(0u);
   if(!(Exint_Init(&pstcConfig)))
	   return ERR_NONE;
   else return ERR_INVALID_PARMS;
}


/**
 ******************************************************************************
 ** \brief DeInit External Interrupts
 **
 ** This function de-initializes all external interrupts.
 **
 ** \retval Ok                     EXINT sucessful disabled
 ******************************************************************************/
err_t WyzBee_Exint_DeInit(void)
{
  Exint_DeInit();
  return ERR_NONE;
} // Exint_DeInit

/**
 ******************************************************************************
 ** \brief Enable a single External Interrupt
 **
 ** This function enables a single External Interrupt.
 **
 ** \note This function does not set
 **       WyzBee_exint_config_t#abEnable[u8Channel]!
 **
 ** \param [in]  u8Channel         External Interrupt channel number
 **
 ** \retval ERR_NONE                     Channel enabled
 ** \retval ERR_INVALID_PARMS  Invalid channel number
 ******************************************************************************/
err_t WyzBee_Exint_EnableChannel(uint8_t u8Channel)
{
  if (u8Channel > 32)
  {
    return ERR_INVALID_PARMS;
  }

  Exint_EnableChannel(u8Channel);
  return ERR_NONE;

} // Exint_EnableChannel


/**
 ******************************************************************************
 ** \brief Disable a single External Interrupt
 **
 ** This function disables a single External Interrupt.
 **
 ** \note This function does not clear
 **       WyzBee_exint_config_t#abEnable[u8Channel]!
 **
 ** \param [in]  u8Channel         External Interrupt channel number
 **
 ** \retval ERR_NONE                     Channel enabled
 ** \retval ERR_INVALID_PARMS  Invalid channel number or channel
 ******************************************************************************/
err_t WyzBee_Exint_DisableChannel(uint8_t u8Channel)
{
  if (u8Channel > 32)
  {
    return ERR_INVALID_PARMS;
  }

  Exint_DisableChannel(u8Channel);

  return ERR_NONE;
} // Exint_DisableChannel

/**
 ******************************************************************************
 ** \brief Init Non-Maskable Interrupt (NMI)
 **
 ** This function initializes the NMI according to the given
 ** configuration.
 **
 ** \param [in]  Config        NMI configuration parameters
 **
 ** \retval ERR_NONE                     NMI initialized
 ** \retval ERR_INVALID_PARMS            Config == NULL
 **
 ** \note NMI shares the interrupt vector with the Hardware Watchog. To avoid
 **       cross influence of initialization of the NVIC use
 **       stc_exint_nmi_config_t#bTouchNVIC to determine whether to touch the
 **       corresponding NVIC registers or not.
 ******************************************************************************/
err_t WyzBee_Exint_Nmi_Init(WyzBee_exint_nmi_config_t* Config)
{
	stc_exint_nmi_config_t  pstcConfig;
	pstcConfig.bTouchNVIC = Config->bTouchNVIC;
	pstcConfig.pfnNMICallback= Config->pfnNMICallback;
  if ( &pstcConfig == NULL )
  {
    return ERR_UNINITIALIZED ;
  }

  if(!(Exint_Nmi_Init(&pstcConfig)))
	  return ERR_NONE;
  else return ERR_INVALID_PARMS;
} // Exint_Nmi_Init

/**
 ******************************************************************************
 ** \brief De-Init Non-Maskable Interrupt (NMI)
 **
 ** This function de-initializes the NMI according to the given
 ** configuration.
 **
 ** \param [in]  Config        NMI configuration parameters
 **
 ** \retval ERR_NONE                     NMI initialized
 ** \retval ERR_INVALID_PARAMS			 Config == NULL
 **
 ** \note NMI shares the interrupt vector with the Hardware Watchog. To avoid
 **       cross influence of initialization of the NVIC use
 **       stc_exint_nmi_config_t#bTouchNVIC to determine whether to touch the
 **       corresponding NVIC registers or not.
 ******************************************************************************/
err_t WyzBee_Exint_Nmi_DeInit(WyzBee_exint_nmi_config_t* Config)
{
	stc_exint_nmi_config_t* pstcConfig;
	pstcConfig->bTouchNVIC = Config->bTouchNVIC;
	pstcConfig->pfnNMICallback= Config->pfnNMICallback;
  if ( Config == NULL )
  {
    return ERR_UNINITIALIZED ;
  }

  if(!(Exint_Nmi_DeInit(pstcConfig)))
	  return ERR_NONE;
  else return ERR_INVALID_PARMS;
} // Exint_Nmi_DeInit

/*
 *********************************************************************************************************
 *                                           END
 *********************************************************************************************************
 */
