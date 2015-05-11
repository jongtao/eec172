/**
 * @file     variant.c
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief  variant.cpp: This file contains system initialization related functions.
 *
 * @section Description : this function will initialize the whole system clocks and C++ support library functions .
 *
 *
 * @section Improvements :
 *  *
 */


/*
 * Includes
 */
 
#include <mb9abxxx.h>
#include <system_mb9abxxx.h>
#include "variant.h"
#include "core_cm4.h"



#ifdef __cplusplus
extern "C" {
#endif


void SystemInit (void);

void sys_ticks_init( void )
{
  //SystemInit(); // initialization

  if (SysTick_Config(SystemCoreClock / 1000))
  {
    // Capture error

    while (1);
  }

  
}

#ifdef __cplusplus
}
#endif

