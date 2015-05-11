/**
 * @file    IRremoteInt.h
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief IRremoteInt.h	: This file contains the standard decoding constants for Samsung remote and state machine structure.
 *
 * @section Description : "irparams_t" is an structure which will hold the updated state and buffer parameters used by ISR.
 *
 *
 * @section Improvements :
 *
 */


/*
 * Includes
 */
#ifndef IRremoteint_h
#define IRremoteint_h

#ifdef __cplusplus
extern "C"{
#endif


#include <stdint.h>
//#include <Calbee_kit.h>

#define DECODED 1


// Pulse parms are *50-100 for the Mark and *50+100 for the space
// First MARK is the one after the long gap
// pulse parameters in usec

#define NEC_HDR_MARK	9000
#define NEC_HDR_SPACE	4500
#define NEC_BIT_MARK	560
#define NEC_ONE_SPACE	1600
#define NEC_ZERO_SPACE	560
#define NEC_RPT_SPACE	2250


//samsung
#define SAMSUNG_HDR_MARK  5000
#define SAMSUNG_HDR_SPACE 5000
#define SAMSUNG_BIT_MARK  560
#define SAMSUNG_ONE_SPACE 1600
#define SAMSUNG_ZERO_SPACE  560
#define SAMSUNG_RPT_SPACE 2250



#define SHARP_BITS 15
#define DISH_BITS 16
#define NEC_BITS 32

#define TOLERANCE 25  // percent tolerance in measurements
#define LTOL (1.0 - TOLERANCE/100.) 
#define UTOL (1.0 + TOLERANCE/100.) 

#define _GAP 5000 // Minimum map between transmissions
#define GAP_TICKS (_GAP/USECPERTICK)

#define TICKS_LOW(us) (int) (((us)*LTOL/USECPERTICK))
#define TICKS_HIGH(us) (int) (((us)*UTOL/USECPERTICK + 1))

// receiver states
#define STATE_IDLE     2
#define STATE_MARK     3
#define STATE_SPACE    4
#define STATE_STOP     5


#define RAWBUF   100
// information for the intERRORupt handler
typedef struct {
  uint8_t recvpin;           // pin for IR data from detector
  uint8_t rcvstate;          // state machine
  uint8_t blinkflag;         // TRUE to enable blinking of pin 13 on IR processing
  unsigned int timer;     // state timer, counts 50uS ticks.
  unsigned int rawbuf[RAWBUF]; // raw data
  uint8_t rawlen;         // counter of entries in rawbuf
} 
irparams_t;

// Defined in IRremote.cpp
extern volatile irparams_t irparams;

// IR detector output is active low
#define MARK  0
#define SPACE 1

#define TOPBIT 0x80000000

#define SAMSUNG_BITS 32

#define TIMER_RESET
void Ir_Isr_receive(void);

#ifdef __cplusplus
}
#endif
#endif

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
