/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Mcu.h
 *  DESCRIPTION:	Header file for Mcu for STM32F104CC
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#ifndef MCU_H
#define MCU_H

/** INCLUDES
*****************************************************/
#include "../../Common/Std_Types.h"
#include "../../Common/Registers_Map.h"
#include "../cfg/Mcu_Cfg.h"

/** DEFINITIONS
*****************************************************/
#define RCC_REG_SIZE 32


 /** TYPEDEFS
 *****************************************************/
typedef enum {
	MCU_CLOCK_HSE, MCU_CLOCK_HSI
} Mcu_ClockType;

typedef enum {
	/* 0 - 31 AHB1ENR*/
	RCC_GPIOA = 0,
	RCC_GPIOB,
	RCC_GPIOC,
	RCC_FPEC = 15,

	/* 32 - 63 AHB2ENR */
	RCC_OTGFS = 39,

	/* 64 - 96 APB1ENR */
	RCC_TIM2 = 64,
	RCC_TIM3 = 65,
	RCC_TIM4 = 66,
	RCC_TIM5 = 64,
	RCC_WWDG = 75,
	RCC_SPI2 = 78,
	RCC_SPI3 = 79,
	RCC_USART2 = 81,
	RCC_I2C1 = 85,
	RCC_I2C2 = 86,
	RCC_I2C3 = 87,
	RCC_PWRON = 92,

	/* 96 - 128 for APB2ENR */
	RCC_TIM1 = 96,
	RCC_USART1 = 100,
	RCC_USART6 = 101,
	RCC_ADC1 = 104,
	RCC_SDIO = 107,
	RCC_SPI1 = 108,
	RCC_SPI4 = 109,
	RCC_SYSCFG = 110,
	RCC_TIM9 = 112,
	RCC_TIM10 = 113,
	RCC_TIM11 = 114,
} Mcu_PeripheralType;

typedef struct{
	Mcu_ClockType SystemClock;
} Mcu_ConfigType;


/** FUNCTIONS PROTOTYPES
*****************************************************/
void Mcu_Init(const Mcu_ConfigType ConfigPtr, const Mcu_PeripheralType PeripheralsUsed[]);
void Mcu_ClockInit(Mcu_ClockType Clock);
void Mcu_EnablePeripheralClock(Mcu_PeripheralType Peripheral);
void Mcu_DisablePeripheralClock(Mcu_PeripheralType Peripheral);

#endif

/** END OF FILE
 *****************************************************/
