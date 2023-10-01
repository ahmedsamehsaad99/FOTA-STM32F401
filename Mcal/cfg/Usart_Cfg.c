/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Port_Cfg.c
 *  DESCRIPTION:	Source file for Port Driver Configurations for STM32F104CC
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/Usart.h"

#if (USART_USED_CONTROLLERS)

const Usart_ConfigType USART_CONFIGURATIONS[USART_USED_CONTROLLERS] = {
		{USART_1, 9600, USART_STOPBIT_1, USART_DATABITS_8, USART_NOTIFICATION_ENABLED},
		//{USART_2, 11520, USART_STOPBIT_1, USART_DATABITS_8, USART_NOTIFICATION_ENABLED},
};

#else

const Usart_ConfigType *USART_CONFIGURATIONS;

#endif
