/**
 * @file     variant.cpp
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
#include "variant.h"
#include "chip.h"

#ifdef __cplusplus
extern "C" {
#endif

void __libc_init_array(void);
void SystemInit (void);

void sys_ticks_init( void )
{
  //SystemInit(); // initialization

  if (SysTick_Config(SystemCoreClock / 1000))
  {
    // Capture error
    while (true);
  }
  //__libc_init_array();  // c++ support
  
}

#ifdef __cplusplus
}
#endif

