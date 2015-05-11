/**
 * @file     IRremote.cpp
 * @version  1.0
 * @date     2014-Oct-21
 *
 *
 * @brief : spansion's DUAL TIMER interrupt code to collect raw data , decodes the received data using samsung's decoding format.
 *
 * @section Description : 	based on ON time and OFF time of the received pulse on GPIO pin which is connected to IR.
 * 							that received pulse is sampled at every 50us and records the time durations into the buffer.
 * 							and this buffer is given to the decode functions this will decode the data and returns an HEX for respective pulse received.
 *
 *
 * @section Improvements :
 *
 */


/*
 * Includes
 */
#include "IRremote.h"
#include "IRremoteInt.h"
#include <stdint.h>
#include <gpio.h>
#include "mcu.h"


#define CALBEE_REV_1 	0
#define CALBEE_REV_2 	0
#define EXP_GPIO_3 		0
#define CALBEE_REV_5	1

#define ERR 0

//decode_results results1;
//IRrecv irrecv2;
volatile irparams_t irparams;

int MATCH(int measured, int desired) {return measured >= TICKS_LOW(desired) && measured <= TICKS_HIGH(desired);}
int MATCH_MARK(int measured_ticks, int desired_us) {return MATCH(measured_ticks, (desired_us + MARK_EXCESS));}
int MATCH_SPACE(int measured_ticks, int desired_us) {return MATCH(measured_ticks, (desired_us - MARK_EXCESS));}


/*===================================================*/
/**
 * @fn			:IRrecv(int recvpin)
 * @brief		:This will be invoked with object is created for this class
 * @param 1[in]	:int recvpin , pin to which IR sensor is connected
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:none
 * @description :This will be invoked with object is created for this class
 */

IRrecv::IRrecv()
{

#if CALBEE_REV_1

	FM4_GPIO->ADE   = 0x00000000; 		// disabling the analog functionalities on the ports
	FM4_GPIO->PFR4_f.P40 = 0; 			// making P40 as a GPIO
	FM4_GPIO->DDR4_f.P40 = 0; 			// making P40 as a input
#endif

#if EXP_GPIO_3

	FM4_GPIO->ADE   = 0x00000000; 		// disabling the analog functionalities on the ports
	FM4_GPIO->PFR4_f.P41 = 0; 			// making P40 as a GPIO
	FM4_GPIO->DDR4_f.P41 = 0; 			// making P40 as a input

#endif

#if CALBEE_REV_2

	FM4_GPIO->ADE   = 0x00000000; 		// disabling the analog functionalities on the ports
	//FM4_GPIO->ADE_f.AN8 = 0;
	FM4_GPIO->PFR2_f.P26 = 0; 			// making P26 as a GPIO
	FM4_GPIO->DDR2_f.P26 = 0; 			// making P26 as a input

#endif

#if CALBEE_REV_5

	FM4_GPIO->ADE_f.AN0= 0;				// AN00 disable
	FM4_GPIO->PFR1_f.P10 = 0; 			// making P26 as a GPIO
	FM4_GPIO->DDR1_f.P10 = 0; 			// making P26 as a input
#endif
}


/*===================================================*/
/**
 * @fn			:enableIRIn()
 * @brief		:sets the initial values for the IR receiver's state machine
 * @param 1[in]	:none
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:none
 * @description :Makes the IR receiver's state at startup , makes state as IDLE and fills the buffer length as 0 .
 */

void IRrecv::enableIRIn()
{
	irparams.rcvstate = STATE_IDLE; 	// state as IDLE
	irparams.rawlen = 0; 				// initial raw length as zero.
}



/*===================================================*/
/**
 * @fn			:Ir_Isr_recieve(void)
 * @brief		:this records the time duration of the pulses and it will be invoked at evry 50us, based on timer reload value.
 * @param 1[in]	:none
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:none
 * @description : spansion's DUAL TIMER interrupt code to collect raw data.
				  Widths of alternating SPACE, MARK are recorded in rawbuf.
				  Recorded in ticks of 50 microseconds.
				  rawlen counts the number of entries recorded so far.
				  First entry is the SPACE between transmissions.
				  As soon as a SPACE gets long, ready is set, state switches to IDLE, timing of SPACE continues.
				  As soon as first MARK arrives, gap width is recorded, ready is cleared, and new logging starts */


void Ir_Isr_receive(void)
{

#if CALBEE_REV_1

	volatile uint8_t irdata ;
	irdata = Gpio1pin_Get(GPIO1PIN_P40);
#endif

#if CALBEE_REV_2

	volatile uint8_t irdata ;
	irdata = Gpio1pin_Get(GPIO1PIN_P26);
#endif

#if EXP_GPIO_3

	volatile uint8_t irdata ;
	irdata = Gpio1pin_Get(GPIO1PIN_P41);
#endif

#if CALBEE_REV_5
	volatile uint8_t irdata ;
	irdata = Gpio1pin_Get(GPIO1PIN_P10);
#endif

	irparams.timer++; // One more 50us tick
	if (irparams.rawlen >= RAWBUF) {
		// Buffer overflow
		irparams.rcvstate = STATE_STOP;
	}
	switch(irparams.rcvstate) {
	case STATE_IDLE: // In the middle of a gap
		if (irdata == MARK) {
			if (irparams.timer < GAP_TICKS) {
				// Not big enough to be a gap.
				irparams.timer = 0;
			}
			else {
				// gap just ended, record duration and start recording transmission
				irparams.rawlen = 0;
				irparams.rawbuf[irparams.rawlen++] = irparams.timer;
				irparams.timer = 0;
				irparams.rcvstate = STATE_MARK;
			}
		}
		break;
	case STATE_MARK: // timing MARK
		if (irdata == SPACE) {   // MARK ended, record time
			irparams.rawbuf[irparams.rawlen++] = irparams.timer;
			irparams.timer = 0;
			irparams.rcvstate = STATE_SPACE;
		}
		break;
	case STATE_SPACE: // timing SPACE
		if (irdata == MARK) { // SPACE just ended, record it
			irparams.rawbuf[irparams.rawlen++] = irparams.timer;
			irparams.timer = 0;
			irparams.rcvstate = STATE_MARK;
		}
		else { // SPACE
			if (irparams.timer > GAP_TICKS) {
				// big SPACE, indicates gap between codes
				// Mark current code as ready for processing
				// Switch to STOP
				// Don't reset timer; keep counting space width
				irparams.rcvstate = STATE_STOP;
			}
		}
		/// Dt_DisableInt( DtChannel0);
		break;
	case STATE_STOP: // waiting, measuring gap
		if (irdata == MARK) {
			// reset gap timer
			irparams.timer = 0;
		}

		break;
	}
}

/*===================================================*/
/**
 * @fn			:resume()
 * @brief		:This function will be called followed by decode function.
 * @param 1[in]	:none
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:none
 * @description :After receiving one KEY data from the remote, this function will keep the ISR state to receive next KEY pulse from the remote.
 */
void IRrecv::resume() {
	irparams.rcvstate = STATE_IDLE;
	irparams.rawlen = 0;
}

#define  AT_T_REMOTE

/*===================================================*/
/**
 * @fn			:decode(decode_results *results)
 * @brief		:Decodes the received IR message
 * @param 1[in]	:decode_results *results ,  pointer to the decode results class
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:ERR, DECODED.based on data availability function will return anyone of these
 * @description :Decodes the received IR message
				 Returns 0 if no data ready, 1 if data ready.
				 Results of decoding are stored in results */
int IRrecv::decode(decode_results *results)
{
	results->rawbuf = irparams.rawbuf;
	results->rawlen = irparams.rawlen;
	if (irparams.rcvstate != STATE_STOP) {
		return ERR;
	}

#ifdef AT_T_REMOTE
   if (decodeNEC(results)) {     //decodeSAMSUNG, decodeNEC
		return DECODED;
	}
#endif
   
#ifdef SAMSUNG_REMOTE
   if (decodeSAMSUNG(results)) {     //decodeSAMSUNG, decodeNEC
		return DECODED;
	}
#endif
	

	// Throw away and start over
	resume();
	return ERR;
}


/*===================================================*/
/**
 * @fn			:decodeNEC(decode_results *results)
 * @brief		:decodes the buffer which is filled in ISR
 * @param 1[in]	:decode_results *results ,  pointer to the decode results class
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:DECODED , decoded HEX will be returned
 * @description :decodes the buffer which is filled in ISR , it uses the standard Samsung's remote timing sequence.
 */

// NECs have a repeat only 4 items long
long IRrecv::decodeNEC(decode_results *results) {
  long data = 0;
  int offset = 1; // Skip first space
  // Initial mark
  if (!MATCH_MARK(results->rawbuf[offset], NEC_HDR_MARK)) {
    return ERR;
  }
  offset++;
  // Check for repeat
  if (irparams.rawlen == 4 &&
    MATCH_SPACE(results->rawbuf[offset], NEC_RPT_SPACE) &&
    MATCH_MARK(results->rawbuf[offset+1], NEC_BIT_MARK)) {
    results->bits = 0;
    results->value = REPEAT;
    results->decode_type = NEC;
    return ERR;
  }
  if (irparams.rawlen < 2 * NEC_BITS + 4) {
    return ERR;
  }
  // Initial space
  if (!MATCH_SPACE(results->rawbuf[offset], NEC_HDR_SPACE)) {
    return ERR;
  }
  offset++;
  for (int i = 0; i < NEC_BITS; i++) {
    if (!MATCH_MARK(results->rawbuf[offset], NEC_BIT_MARK)) {
      return ERR;
    }
    offset++;
    if (MATCH_SPACE(results->rawbuf[offset], NEC_ONE_SPACE)) {
      data = (data << 1) | 1;
    }
    else if (MATCH_SPACE(results->rawbuf[offset], NEC_ZERO_SPACE)) {
      data <<= 1;
    }
    else {
      return ERR;
    }
    offset++;
  }
  // Success
  results->bits = NEC_BITS;
  results->value = data;
  results->decode_type = NEC;
  return DECODED;
}

/*===================================================*/
/**
 * @fn			:decodeSAMSUNG(decode_results *results)
 * @brief		:decodes the buffer which is filled in ISR
 * @param 1[in]	:decode_results *results ,  pointer to the decode results class
 * @param 2[in]	:none
 * @param[out]	:none
 * @return		:DECODED , decoded HEX will be returned
 * @description :decodes the buffer which is filled in ISR , it uses the standard Samsung's remote timing sequence.
 */

// SAMSUNGs have a repeat only 4 items long
long IRrecv::decodeSAMSUNG(decode_results *results) {
	long data = 0;
	int offset = 1; // Skip first space
	// Initial mark
	if (!MATCH_MARK(results->rawbuf[offset], SAMSUNG_HDR_MARK)) {
		return ERR;
	}
	offset++;
	// Check for repeat
	if (irparams.rawlen == 4 &&
			MATCH_SPACE(results->rawbuf[offset], SAMSUNG_RPT_SPACE) &&
			MATCH_MARK(results->rawbuf[offset+1], SAMSUNG_BIT_MARK)) {
		results->bits = 0;
		results->value = REPEAT;
		results->decode_type = SAMSUNG;
		return DECODED;
	}
	if (irparams.rawlen < 2 * SAMSUNG_BITS + 4) {
		return ERR;
	}
	// Initial space
	if (!MATCH_SPACE(results->rawbuf[offset], SAMSUNG_HDR_SPACE)) {
		return ERR;
	}
	offset++;
	for (int i = 0; i < SAMSUNG_BITS; i++) {
		if (!MATCH_MARK(results->rawbuf[offset], SAMSUNG_BIT_MARK)) {
			return ERR;
		}
		offset++;
		if (MATCH_SPACE(results->rawbuf[offset], SAMSUNG_ONE_SPACE)) {
			data = (data << 1) | 1;
		}
		else if (MATCH_SPACE(results->rawbuf[offset], SAMSUNG_ZERO_SPACE)) {
			data <<= 1;
		}
		else {
			return ERR;
		}
		offset++;
	}
	// Success
	results->bits = SAMSUNG_BITS;
	results->value = data;
	results->decode_type = SAMSUNG;
	return DECODED;
}


/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
