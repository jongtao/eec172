#ifndef INFRARED_H
#define INFRARED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pdl.h"


// TIMER Constants
#define TIMEOUT 0xFFFF // ~0.21 Seconds Timeout

// NEC Protocol Constants
// in units of ticks
// 312500 ticks with 256 prescale = 1 second
#define IR_WORD_SIZE 32 // bits

#define HEAD_MARK 2813 // 9ms
#define HEAD2DATA_SPACE 1406 // 4.5ms
#define HEAD2REPEAT_SPACE 703

#define DATA_MARK 175 // 0.56ms
#define DATA_0_SPACE 175 // 0.56ms
#define DATA_1_SPACE 525 // 1.69ms

#define REPEAT_MARK 2813

#define END_MARK 175

#define TOLERANCE 50

// GPIO Constants
#define PIN_IR P10
#define IR_INT_CHAN 2


#define BIT_MASK 0x80000000u



// IR State Machine
typedef enum
{
	WAIT,
	HEAD,
	DATA,
	REPEAT,
	END
} State;


typedef struct
{
	uint8_t type;
	uint8_t address;
	uint8_t data;
} Element;


typedef enum
{
	START,
	STOP
} El_type;


volatile extern uint32_t buffer;



void infrared_init(void);

#ifdef __cplusplus
}
#endif

#endif // INFRARED_H
