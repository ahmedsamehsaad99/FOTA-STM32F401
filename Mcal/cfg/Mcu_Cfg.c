/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Mcu_Cfg.c
 *  DESCRIPTION:	Source file for Mcu Driver Configurations for STM32F104CC
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/Mcu.h"

const Mcu_ConfigType MCU_CONFIGURATIONS = {MCU_CLOCK_HSI};

const Mcu_PeripheralType MCU_PERIPHERALS_ARR[MCU_USED_PERIPHERALS] = {
		RCC_GPIOA,
		RCC_USART1,
};
