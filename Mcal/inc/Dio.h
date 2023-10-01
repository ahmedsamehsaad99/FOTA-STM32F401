/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Dio.h
 *  DESCRIPTION:	Header file for Dio for STM32F104CC
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#ifndef DIO_H
#define DIO_H

/** INCLUDES
*****************************************************/
#include "../../Common/Std_Types.h"
#include "../../Common/Registers_Map.h"
#include "../cfg/Dio_Cfg.h"

/** DEFINITIONS
*****************************************************/
#define PORT_PINS_NUMBER		16

/* PORT SYMBOLIC NAMES */

#define DIO_PORT_A				(Dio_PortType)0
#define DIO_PORT_B				(Dio_PortType)1
#define DIO_PORT_C				(Dio_PortType)2

 /** TYPEDEFS
 *****************************************************/
/* CHANNELS SYMBOLIC NAMES */

typedef enum
{
	 DIO_PORT_A_CHANNEL_0,
	 DIO_PORT_A_CHANNEL_1,
	 DIO_PORT_A_CHANNEL_2,
	 DIO_PORT_A_CHANNEL_3,
	 DIO_PORT_A_CHANNEL_4,
	 DIO_PORT_A_CHANNEL_5,
	 DIO_PORT_A_CHANNEL_6,
	 DIO_PORT_A_CHANNEL_7,
	 DIO_PORT_A_CHANNEL_8,
	 DIO_PORT_A_CHANNEL_9,
	 DIO_PORT_A_CHANNEL_10,
	 DIO_PORT_A_CHANNEL_11,
	 DIO_PORT_A_CHANNEL_12,
	 DIO_PORT_A_CHANNEL_13,
	 DIO_PORT_A_CHANNEL_14,
	 DIO_PORT_A_CHANNEL_15,

	 DIO_PORT_B_CHANNEL_0,
	 DIO_PORT_B_CHANNEL_1,
	 DIO_PORT_B_CHANNEL_2,
	 DIO_PORT_B_CHANNEL_3,
	 DIO_PORT_B_CHANNEL_4,
	 DIO_PORT_B_CHANNEL_5,
	 DIO_PORT_B_CHANNEL_6,
	 DIO_PORT_B_CHANNEL_7,
	 DIO_PORT_B_CHANNEL_8,
	 DIO_PORT_B_CHANNEL_9,
	 DIO_PORT_B_CHANNEL_10,
	 DIO_PORT_B_CHANNEL_11,
	 DIO_PORT_B_CHANNEL_12,
	 DIO_PORT_B_CHANNEL_13,
	 DIO_PORT_B_CHANNEL_14,
	 DIO_PORT_B_CHANNEL_15,

	 DIO_PORT_C_CHANNEL_13,
	 DIO_PORT_D_CHANNEL_14,
	 DIO_PORT_D_CHANNEL_15
} Dio_ChannelType;

typedef uint8 Dio_PortType;

typedef uint8 Dio_LevelType;

typedef uint16 Dio_PortLevelType;


/** FUNCTIONS PROTOTYPES
*****************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
void Dio_ToggleChannel(Dio_ChannelType ChannelId);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);


#endif

/** END OF FILE
 *****************************************************/
