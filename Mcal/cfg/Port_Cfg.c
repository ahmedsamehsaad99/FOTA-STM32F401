/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Port_Cfg.c
 *  DESCRIPTION:	Source file for Port Driver Configurations for STM32F104CC
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/Port.h"

#if (PORT_USED_PINS_NUMBER)

const Port_ConfigType PORT_CONFIGURATIONS[PORT_USED_PINS_NUMBER] = {
		{PORT_A_PIN_0, PORT_MODE_OUTPUT, PIN_OUTPUT_PUSHPULL, PIN_INPUT_NONE, PORT_ALTFUN_NONE},
		{PORT_A_PIN_0, PORT_MODE_OUTPUT, PIN_OUTPUT_PUSHPULL, PIN_INPUT_NONE, PORT_ALTFUN_NONE},

		{PORT_A_PIN_9, PORT_MODE_ALTFUN, PIN_OUTPUT_NONE, PIN_INPUT_NONE, PORT_ALTFUN_USART1},
		{PORT_A_PIN_10, PORT_MODE_ALTFUN, PIN_OUTPUT_NONE, PIN_INPUT_NONE, PORT_ALTFUN_USART1},
};

#else

const Port_ConfigType *PORT_CONFIGURATIONS;

#endif
