/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Dio.c
 *  DESCRIPTION:	Source file for Dio driver
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/Dio.h"

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Dio_ChannelType CurrentPin = ChannelId % PORT_PINS_NUMBER;
	Dio_PortType CurrentPort = CurrentPin / PORT_PINS_NUMBER;

	return (GET_BIT(GPIO(CurrentPort)->IDR, CurrentPin));
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	Dio_ChannelType CurrentPin = ChannelId % PORT_PINS_NUMBER;
	Dio_PortType CurrentPort = CurrentPin / PORT_PINS_NUMBER;

	SET_BIT_STATE(GPIO(CurrentPort)->ODR, CurrentPin, Level);
	/*if (Level == STD_HIGH)
	{
		SET_BIT_STATE(GPIO(CurrentPort)->BSRR, CurrentPin, STD_HIGH);
	}
	else
	{
		SET_BIT_STATE(GPIO(CurrentPort)->BSRR, (CurrentPin + 16), STD_HIGH);
	}*/
}

void Dio_ToggleChannel(Dio_ChannelType ChannelId)
{
	Dio_ChannelType CurrentPin = ChannelId % PORT_PINS_NUMBER;
	Dio_PortType CurrentPort = CurrentPin / PORT_PINS_NUMBER;

	TOGGLE_BIT(GPIO(CurrentPort)->ODR, CurrentPin);
}


Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	return (GET_VALUE(GPIO(PortId)->IDR, 0xFFFF, 0));
}

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	PLACE_VALUE(GPIO(PortId)->ODR, 0xFFFF, 0, Level);
}
