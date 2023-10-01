/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Port.c
 *  DESCRIPTION:	Source file for Port.c for STM32F104CC
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/Port.h"

void Port_Init(const Port_ConfigType *ConfigPtr)
{
	uint8 i = 0;
	for (i = 0; i < PORT_USED_PINS_NUMBER; i++)
	{
		Port_PinType CurrentPin = ConfigPtr[i].PortPin % PORT_PINS_NUMBER;
		Port_PortType CurrentPort = CurrentPin / PORT_PINS_NUMBER;

		/* SET PIN MODES */
		PLACE_VALUE( GPIO(CurrentPort)->MODER, 0b11, CurrentPin * PORT_MODER_BITS, ConfigPtr[i].PortPinMode);

		/* IF OUTPUT, SET OUTPUT TYPE - PP OR OD */
		if (ConfigPtr[i].PortPinMode == PORT_MODE_OUTPUT)
			SET_BIT_STATE(GPIO(CurrentPort)->OTYPER, CurrentPin, ConfigPtr[i].PortPinOutputMode);
		else
		/* IF INPUT, SET INPUT RESSISTOR TYPE */
			PLACE_VALUE(GPIO(CurrentPort)->PUPDR, 0b11, CurrentPin * PORT_PUPDR_BITS, ConfigPtr[i].PortPinInputMode);

		/* SET ALT FUNC IF EXISTS */
		if (ConfigPtr[i].PortAltFunc != PORT_ALTFUN_NONE)
		{
			if (CurrentPin < 8)
			{
				PLACE_VALUE(GPIO(CurrentPort)->AFRL, 0b1111, (CurrentPin%8) * PORT_ALTFUN_BITS, ConfigPtr[i].PortAltFunc);
			}
			else
			{
				PLACE_VALUE(GPIO(CurrentPort)->AFRH, 0b1111, (CurrentPin%8) * PORT_ALTFUN_BITS, ConfigPtr[i].PortAltFunc);
			}
		}
	}
}
