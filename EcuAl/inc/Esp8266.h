/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Esp8266.h
 *  DESCRIPTION:	Header file for Esp8266 driver
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#ifndef Esp8266_H
#define Esp8266_H

/** INCLUDES
*****************************************************/
#include "../../Common/Std_Types.h"
#include "../../Mcal/inc/Usart.h"
#include "../cfg/Esp8266_Cfg.h"

/** DEFINITIONS
*****************************************************/


 /** TYPEDEFS
 *****************************************************/
typedef uint8*	Esp8266_StringType;
typedef uint8	Esp8266_DataType;

typedef struct {
	Esp8266_StringType SSID;
	Esp8266_StringType Password;
	Esp8266_StringType Domain;
	Esp8266_StringType Port;
} Esp8266_ConfigType;

/** FUNCTIONS PROTOTYPES
*****************************************************/

void Esp8266_Init(const Esp8266_ConfigType *ConfigPtr);

Std_ReturnType Esp8266_InitWebPageReception(Esp8266_StringType Domain);

Std_ReturnType Esp8266_ReceiveFromWebPage(Esp8266_DataType *DataToReturn);

#endif
