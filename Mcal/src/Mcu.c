/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Mcu.c
 *  DESCRIPTION:	Source file for Mcu driver
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/Mcu.h"

void Mcu_Init(const Mcu_ConfigType ConfigPtr, const Mcu_PeripheralType PeripheralsUsed[])
{
	Mcu_ClockInit(ConfigPtr.SystemClock);

	Mcu_EnablePeripheralClock(RCC_USART1);
	uint8 i = 0;
	for (i = 0; i < MCU_USED_PERIPHERALS-1; i++)
	{
		Mcu_EnablePeripheralClock(PeripheralsUsed[i]);
	}
}

void Mcu_ClockInit(Mcu_ClockType Clock)
{
	if (Clock == MCU_CLOCK_HSE)
	{
		SET_BIT_STATE(RCC->CR, 16, STD_HIGH);
		SET_BIT_STATE(RCC->CR, 0, STD_LOW);
		SET_BIT_STATE(RCC->CR, 24, STD_LOW);
	}
	else
	{
		SET_BIT_STATE(RCC->CR, 0, STD_HIGH);
		SET_BIT_STATE(RCC->CR, 24, STD_LOW);
	}
}

void Mcu_EnablePeripheralClock(Mcu_PeripheralType Peripheral)
{
	switch (Peripheral / RCC_REG_SIZE)
	{
	case 0:
		SET_BIT_STATE(RCC->AHB1ENR, Peripheral%RCC_REG_SIZE, STD_HIGH);
		break;
	case 1:
		SET_BIT_STATE(RCC->AHB2ENR, Peripheral%RCC_REG_SIZE, STD_HIGH);
		break;
	case 2:
		SET_BIT_STATE(RCC->APB1ENR, Peripheral%RCC_REG_SIZE, STD_HIGH);
		break;
	case 3:
		SET_BIT_STATE(RCC->APB2ENR, Peripheral%RCC_REG_SIZE, STD_HIGH);
		break;
	}
}

void Mcu_DisablePeripheralClock(Mcu_PeripheralType Peripheral)
{
	switch (Peripheral / RCC_REG_SIZE)
	{
	case 0:
		SET_BIT_STATE(RCC->AHB1ENR, Peripheral%RCC_REG_SIZE, STD_LOW);
		break;
	case 1:
		SET_BIT_STATE(RCC->AHB2ENR, Peripheral%RCC_REG_SIZE, STD_LOW);
		break;
	case 2:
		SET_BIT_STATE(RCC->APB1ENR, Peripheral%RCC_REG_SIZE, STD_LOW);
		break;
	case 3:
		SET_BIT_STATE(RCC->APB2ENR, Peripheral%RCC_REG_SIZE, STD_LOW);
		break;
	}
}
