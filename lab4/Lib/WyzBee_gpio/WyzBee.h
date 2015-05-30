/*
*********************************************************************************************************
*
*                           (c) Copyright 2015-2020 RedPine Signals Inc. Hyderabad, INDIA
*                                           All rights reserved.
*
*               This file is protected by international copyright laws. This file can only be used in
*               accordance with a license and should not be redistributed in any way without written
*               permission by Redpine Signals.
*
*                                            www.redpinesignals.com
*
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*								         WyzBee Standard Defines Header File
*
* File           : WyzBee.h
* Version        : V1.00
* Programmer(s)  :
*********************************************************************************************************
* Note(s)		 :
*********************************************************************************************************
*/

#ifndef   WyzBee_H
#define   WyzBee_H


/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                                 DEFINES
*********************************************************************************************************
*/
#define ENABLE              1u						// Enable
#define DISABLE             0u						// Disable

#define TRUE				1u						// True
#define FALSE				0u						// False


/*
*********************************************************************************************************
*                                               General Error Codes
*********************************************************************************************************
*/

#define	ERR_NONE            			0u			// NO Error
#define ERR_UNKNOWN         			1u			// Undefined Error occurred
#define ERR_INVALID_PARMS				2u			// Invalid function parameters
#define ERR_BUFFER_OVERFLOW 			3u			// Buffer Over Flow

/*
*********************************************************************************************************
*                                               DATA TYPES
*********************************************************************************************************
*/

typedef unsigned char       uint8;

typedef unsigned short      uint16;

typedef unsigned int        uint32;

typedef char                int8;

typedef short               int16;

typedef long                int32;

typedef char      			bool_t;

typedef unsigned short      err_t;


/*
*********************************************************************************************************
*                                           END
*********************************************************************************************************
*/

#endif //WyzBee_H
