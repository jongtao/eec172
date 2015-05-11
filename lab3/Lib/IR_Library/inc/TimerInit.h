/**
 * @file     TimerInit.h
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief 	: This file contains Spansion's Dual timer initialization functions prototypes.
 *
 * @section Description :
 *
 * @section Improvements :
 *
 */


/*
 * Includes
 */
#ifndef __TIMERINIT_H__
#define __TIMERINIT_H__
#include <stdint.h>
#ifdef __cplusplus
extern "C"{
#endif


void dual_timer0_init(uint32_t  timer_rl_val);
void Dt0Callback(void);

#ifdef __cplusplus
}
#endif

#endif // __TIMERINIT_H__

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
