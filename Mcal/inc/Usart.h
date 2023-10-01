/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Usart.h
 *  DESCRIPTION:	Header file for Usart for STM32F104CC
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#ifndef USART_H_
#define USART_H_

#include "../../Common/Std_Types.h"
#include "../../Common/Registers_Map.h"
#include "../cfg/Usart_Cfg.h"

 /** TYPEDEFS
 *****************************************************/

typedef enum
{
	USART_1 = 1, USART_2 = 2, USART_6 = 6
} Usart_ControllerNumber;

typedef enum
{
	USART_STOPBIT_1, USART_STOPBIT_HALF, USART_STOPBIT_2, USART_STOPBIT_1_HALF
} Usart_StopBitType;

typedef float32 Usart_BaudrateType;

typedef uint16	Usart_DataType;

typedef enum
{
	USART_DATABITS_8, USART_DATABITS_9
} Usart_DataBitsType;

typedef uint8*	Usart_StringType;

typedef enum {
	USART_NOTIFICATION_DISABLED, USART_NOTIFICATION_ENABLED
}	Usart_NotificationType;

typedef enum
{
	USART_PE, USART_IDLE, USART_RXNE, USART_TC, USART_TXE
} Usart_FlagType;

typedef void (*Usart_CallBackFuncType)(void);

typedef struct
{
	Usart_ControllerNumber Controller;
	Usart_BaudrateType	Baudrate;
	Usart_StopBitType	Stopbits;
	Usart_DataBitsType	Databits;
	Usart_NotificationType Notification;
} Usart_ConfigType;



 /** FUNCTIONS PROTOTYPES
 *****************************************************/
void Usart_Init(const Usart_ConfigType* ConfigPtr);
void Usart_Transmit(Usart_ControllerNumber ContNumber, Usart_DataType Data);
void Usart_TransmitString(Usart_ControllerNumber ContNumber, Usart_StringType String);
Std_ReturnType Usart_GetFlag(Usart_ControllerNumber ContNumber, Usart_FlagType Flag);
Usart_DataType Usart_Receive(Usart_ControllerNumber ContNumber);
Std_ReturnType Usart_ReceiveSync(Usart_ControllerNumber ContNumber, Usart_DataType* DataBuffer);
void Usart_SetCallBackFunction(Usart_ControllerNumber ContNumber, Usart_FlagType Flag, Usart_CallBackFuncType CallBck);

#endif

 /** END OF FILE: Usart.h
  *****************************************************/
