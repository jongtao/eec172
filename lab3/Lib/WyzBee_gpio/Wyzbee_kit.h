/**
 *
 * Copyright(C) Redpine Signals 2013
 * All rights reserved by Redpine Signals.
 *
 * @section License
 * This program should be used on your own responsibility.
 * Redpine Signals assumes no responsibility for any losses
 * incurred by customers or third parties arising from the use of this file.
 *
 * @brief : contains basic definitions.
 *
 * @section 
 *
 *
 * @section Improvements :
 *
 */


/*
 * Includes
 */
#ifndef WyzBee_kit_h
#define WyzBee_kit_h


#ifdef __cplusplus
 extern "C" {

#endif

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
extern void setup( void ) ;
extern void loop( void ) ;
// Include board variant
#include "variant.h"
#include "wiring.h"
#include "chip.h"
#ifdef __cplusplus
}
#endif
#include "pdl.h"
#include <string.h>

#define ERR 0

#endif // Arduino_h
