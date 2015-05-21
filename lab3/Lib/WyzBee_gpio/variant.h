/**
 * @file     variant.h
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief : This file contains libc porting defines
 *
 *
 *
 * @section Improvements :
 *
 */


/*
 * Includes
 */


/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		12000000

/** Master clock frequency */
#define VARIANT_MCK			84000000

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WyzBee_kit.h"
#ifdef __cplusplus

#endif

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/**
 * Libc porting layers
 */
#if defined (  __GNUC__  ) /* GCC CS3 */
//#    include <syscalls.h> /** RedHat Newlib minimal stub */
#endif

#ifdef __cplusplus
}
#endif




