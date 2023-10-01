/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			EcuM.c
 *  DESCRIPTION:	Source file for ECUM driver
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/EcuM.h"

extern const Mcu_ConfigType MCU_CONFIGURATIONS;
extern const Mcu_PeripheralType MCU_PERIPHERALS_ARR[];
extern const Port_ConfigType PORT_CONFIGURATIONS[];
extern const Usart_ConfigType USART_CONFIGURATIONS[];
extern const Esp8266_ConfigType ESP8266_CONFIGURATIONS;

void EcuM_Init(void)
{
	Mcu_Init(MCU_CONFIGURATIONS, MCU_PERIPHERALS_ARR);
	Port_Init(PORT_CONFIGURATIONS);
	Usart_Init(USART_CONFIGURATIONS);
	Esp8266_Init(&ESP8266_CONFIGURATIONS);
}
