/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Bootloader.h
 *  DESCRIPTION:	Header file for Bootloader Application
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#include "../../Services/inc/EcuM.h"
#include "../../EcuAl/inc/Led.h"
#include "../../EcuAl/inc/Esp8266.h"

#define	FLASHING_RED_LED		DIO_PORT_A_CHANNEL_0
#define FLASHING_GREEN_LED		DIO_PORT_A_CHANNEL_1
#define SCB_VTOR  				*((volatile uint32 *)0xE000ED08)
#define SCB_AIRCR				*((volatile uint32 *)0xE000ED0C)
#define RESET_HANDLER_ADDRESS	(0x08004004)
#define VECTOR_TABLE_NEW_ADDR	(0x08004000)
#define	WEBSITE_STRING			"http://itiwebproj.freevar.com/HexFile.hex"

typedef void (*Bootloader_FuncPtrType)(void) ;

void Bootloader_Run(void);

#endif
