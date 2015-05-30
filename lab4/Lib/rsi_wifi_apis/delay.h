
#ifndef _delay_
#define _delay_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
	
/**
 *
 */
extern void sys_ticks_init( void ) ;

/**
 * \brief Returns the number of milliseconds since the Arduino board began running the current program.
 *
 * This number will overflow (go back to zero), after approximately 50 days.
 *
 * \return Number of milliseconds since the program started (uint32_t)
 */
extern uint32_t millis( void ) ;

/**
 * \brief Returns the number of microseconds since the Arduino board began running the current program.
 *
 * This number will overflow (go back to zero), after approximately 70 minutes. On 16 MHz Arduino boards
 * (e.g. Duemilanove and Nano), this function has a resolution of four microseconds (i.e. the value returned is
 * always a multiple of four). On 8 MHz Arduino boards (e.g. the LilyPad), this function has a resolution
 * of eight microseconds.
 *
 * \note There are 1,000 microseconds in a millisecond and 1,000,000 microseconds in a second.
 */
extern uint32_t micros( void ) ;

/**
 * \brief Pauses the program for the amount of time (in miliseconds) specified as parameter.
 * (There are 1000 milliseconds in a second.)
 *
 * \param dwMs the number of milliseconds to pause (uint32_t)
 */
extern void delay( uint32_t dwMs ) ;

/**
 * \brief Pauses the program for the amount of time (in microseconds) specified as parameter.
 *
 * \param dwUs the number of microseconds to pause (uint32_t)
 */
//static inline void delayMicroseconds(uint32_t) __attribute__((always_inline, unused));
/*static inline void delayMicroseconds(uint32_t usec){
    if (usec == 0) return;
    uint32_t n = usec * (VARIANT_MCK / 3000000);
    asm volatile(
        "L_%=_delayMicroseconds:"       "\n\t"
        "subs   %0, #1"                 "\n\t"
        "bne    L_%=_delayMicroseconds" "\n"
        : "+r" (n) :
    );
}*/

#ifdef __cplusplus
}
#endif

#endif /* _delay_ */
