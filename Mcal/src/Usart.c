/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Usart.c
 *  DESCRIPTION:	Source file for Usart driver
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/Usart.h"

Usart_CallBackFuncType Usart1_CallBacks[5] = {NULL, NULL, NULL, NULL, NULL};
Usart_CallBackFuncType Usart2_CallBacks[5] = {NULL, NULL, NULL, NULL, NULL};
Usart_CallBackFuncType Usart6_CallBacks[5] = {NULL, NULL, NULL, NULL, NULL};

static uint32 Usart_GetBrrValue(Usart_BaudrateType Baudrate)
{
	float32 USARTDIV = (F_CPU) / (16.0 * Baudrate);
	uint16 Mantissa = (uint16) USARTDIV;
	uint16 Fraction = round(16.0 * (USARTDIV * 1.0 - Mantissa));

	if (Fraction == 16)
	{
		Fraction = 0;
		Mantissa++;
	}

	return ((Mantissa << 4) + Fraction);
}

void Usart_Init(const Usart_ConfigType* ConfigPtr)
{
	uint8 i = 0;

	for (i = 0; i < USART_USED_CONTROLLERS; i++)
	{
		Usart_ControllerNumber Controller = ConfigPtr[i].Controller;

		/* ENABLE USART */
		SET_BIT_STATE(USART(Controller)->CR1, 13, STD_HIGH);

		/* SET DATA BITS NUMBER */
		SET_BIT_STATE(USART(Controller)->CR1, 12, ConfigPtr[i].Databits);

		/* SET STOP BITS */
		PLACE_VALUE(USART(Controller)->CR2, 0b11, 12, ConfigPtr[i].Stopbits);

		/* SELECT BAUDRATE  */
		USART(Controller)->BRR = Usart_GetBrrValue(ConfigPtr[i].Baudrate);

		/* ENABLE TRANSMIT */
		SET_BIT_STATE(USART(Controller)->CR1, 3, STD_HIGH);

		/* ENABLE RECEIVE  */
		SET_BIT_STATE(USART(Controller)->CR1, 2, STD_HIGH);

		/* ENABLE INTERRUPTS */
		SET_BIT_STATE(USART(Controller)->CR1, 6, ConfigPtr[i].Notification);
		SET_BIT_STATE(USART(Controller)->CR1, 5, ConfigPtr[i].Notification);
	}
}

void Usart_Transmit(Usart_ControllerNumber ContNumber, Usart_DataType Data)
{
	while (! GET_BIT (USART(ContNumber)->SR, 7));
	/* FILL THE DATA REGISTER */
	USART(ContNumber)->DR = Data;
}

void Usart_TransmitString(Usart_ControllerNumber ContNumber, Usart_StringType String)
{
	while (*String != '\0')
	{
		Usart_Transmit(ContNumber ,*String);
		String++;
	}
}

Std_ReturnType Usart_ReceiveSync(Usart_ControllerNumber ContNumber, Usart_DataType* DataBuffer)
{
	if( GET_BIT(USART(ContNumber)->SR, 5) == STD_HIGH )
	{
		*DataBuffer = USART(ContNumber)->DR ;
		SET_BIT_STATE(USART(ContNumber)->SR, 5, STD_LOW);
	}
	else
	{
		return E_NOT_OK;
	}

	return E_OK ;
}

Usart_DataType Usart_Receive(Usart_ControllerNumber ContNumber)
{
	Usart_DataType ReceivedData = 0;

	while (! GET_BIT(USART(ContNumber)->SR, 5) );

	ReceivedData = USART(ContNumber)->DR;

	return ReceivedData;
}

uint8 Usart_GetFlag(Usart_ControllerNumber ContNumber, Usart_FlagType Flag)
{
	return (GET_BIT (USART(ContNumber)->SR, Flag) );
}

void Usart_SetCallBackFunction(Usart_ControllerNumber ContNumber, Usart_FlagType Flag, Usart_CallBackFuncType CallBck)
{
	switch (ContNumber)
	{
	case USART_1:
		Usart1_CallBacks[Flag] = CallBck;
		break;
	case USART_2:
		Usart2_CallBacks[Flag] = CallBck;
		break;
	case USART_6:
		Usart6_CallBacks[Flag] = CallBck;
		break;
	}
}

void USART1_IRQHandler(void)
{
	if (GET_BIT(USART(1)->SR, 0))
		Usart1_CallBacks[0]();
	if (GET_BIT (USART(1)->SR, 4))
		Usart1_CallBacks[1]();
	if (GET_BIT (USART(1)->SR, 5))
		Usart1_CallBacks[2]();
	if (GET_BIT (USART(1)->SR, 6))
		Usart1_CallBacks[3]();
	if (GET_BIT (USART(1)->SR, 7))
		Usart1_CallBacks[4]();
}

void USART2_IRQHandler(void)
{
	if (Usart_GetFlag(USART_2, USART_PE))
		Usart2_CallBacks[0]();
	if (Usart_GetFlag(USART_2, USART_IDLE))
		Usart2_CallBacks[1]();
	if (Usart_GetFlag(USART_2, USART_RXNE))
		Usart2_CallBacks[2]();
	if (Usart_GetFlag(USART_2, USART_TC))
		Usart2_CallBacks[3]();
	if (Usart_GetFlag(USART_2, USART_TXE))
		Usart2_CallBacks[4]();
}

void USART6_IRQHandler(void)
{
	if (Usart_GetFlag(USART_6, USART_PE))
		Usart6_CallBacks[0]();
	if (Usart_GetFlag(USART_6, USART_IDLE))
		Usart6_CallBacks[1]();
	if (Usart_GetFlag(USART_6, USART_RXNE))
		Usart6_CallBacks[2]();
	if (Usart_GetFlag(USART_6, USART_TC))
		Usart6_CallBacks[3]();
	if (Usart_GetFlag(USART_6, USART_TXE))
		Usart6_CallBacks[4]();
}
