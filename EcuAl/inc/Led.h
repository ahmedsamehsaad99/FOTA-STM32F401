/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Led.h
 *  DESCRIPTION:	Header file for LED
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#ifndef LED_H
#define LED_H

/** INCLUDES
*****************************************************/
#include "../../Common/Std_Types.h"
#include "../../Mcal/inc/Dio.h"

/** DEFINITIONS
*****************************************************/


 /** TYPEDEFS
 *****************************************************/
typedef enum {
    LED_OFF = 0,
    LED_ON
} Led_StateType;

typedef uint8 Led_IdType;


/** FUNCTIONS PROTOTYPES
*****************************************************/
void Led_Init(void);
void Led_SetLedState(Led_IdType LedId, Led_StateType State);
Led_StateType Led_ReadLedState(Led_IdType LedId);

#endif

/** END OF FILE
 *****************************************************/
