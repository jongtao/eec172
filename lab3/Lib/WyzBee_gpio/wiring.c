/**
 * @file     wiring.c
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief  wiring.c: This file contains delay related functions.
 *
 * @section Description : the functions delay and millis will produce a delay based systems ticks it can be used in any where , where delay is required.
 *
 *
 * @section Improvements :
 *  *
 */


/*
 * Includes
 */
#include "Wyzbee_kit.h"
#include <core_cm4.h>



#ifdef __cplusplus
extern "C" {
#endif


/*===================================================*/
/**
 * @fn			:millis( void )
 * @brief		:This function uses the system ticks and returns each tick of worth 1ms
 * @param 1[in]	:none
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:none
 * @description :This function uses the system ticks and returns each tick of worth 1ms
 */
uint32_t millis( void )
{
// todo: ensure no interrupts
    return GetTickCount() ;
}

/*===================================================*/
/**
 * @fn			:delay( uint32_t ms )
 * @brief		:This API is used to produce the delay in ms.
 * @param 1[in]	:uint32_t ms , delay to be produced in milli seconds
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:none
 * @description :This API uses the system ticks and produces the delay according to the user wish.
 */
uint32_t start;
void delay( uint32_t ms )
{
    if (ms == 0)
        return;
    start = GetTickCount();
    do {
        //yield();
    } while (GetTickCount() - start < ms);
}


#ifdef __cplusplus
}
#endif
