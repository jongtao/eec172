#ifndef INFRARED_H
#define INFRARED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pdl.h"


// TIMER Constants
#define TIMEOUT 0x8647 // 110 ms

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

// event queue
#define Q_LENGTH 16



// IR State Machine
typedef enum
{
	WAIT,
	DATA,
	END
} State;


typedef struct
{
	uint8_t pressing;
	uint8_t addr;
	uint8_t cmd;
} Button;


extern volatile uint32_t buffer; 
extern Button key;


void IR_ISR(void);
void timer_ISR(void);

uint8_t extract(uint32_t word, volatile Button* button);

void infrared_init(void);

#ifdef __cplusplus
}
#endif

#endif // INFRARED_H
