/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Port.h
 *  DESCRIPTION:	Header file for Port.h for STM32F104CC
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#ifndef PORT_H
#define PORT_H


/** INCLUDES
*****************************************************/
#include "../../Common/Std_Types.h"
#include "../../Common/Registers_Map.h"
#include "../cfg/Port_Cfg.h"

/** DEFINITIONS
*****************************************************/

#define PORT_PINS_NUMBER		16
#define PORT_MODER_BITS			2
#define PORT_PUPDR_BITS			2
#define PORT_ALTFUN_BITS		4

#define	PORT_ALTFUN_NONE  -1

#define	PORT_ALTFUN_SYS_AF  0

#define	PORT_ALTFUN_TIM1  1
#define	PORT_ALTFUN_TIM2  1

#define	PORT_ALTFUN_TIM3  2
#define	PORT_ALTFUN_TIM4  2
#define	PORT_ALTFUN_TIM5  2

#define	PORT_ALTFUN_TIM9  3
#define PORT_ALTFUN_TIM10  3
#define	PORT_ALTFUN_TIM11  3

#define	PORT_ALTFUN_I2C1  4
#define	PORT_ALTFUN_I2C2  4
#define	PORT_ALTFUN_I2C3  4

#define	PORT_ALTFUN_SPI1  5
#define	PORT_ALTFUN_SPI2  5
#define	PORT_ALTFUN_I2S2  5
#define	PORT_ALTFUN_SPI3  5
#define	PORT_ALTFUN_I2S3  5
#define	PORT_ALTFUN_SPI4  5

#define	PORT_ALTFUN_USART1  7
#define	PORT_ALTFUN_USART2  7

#define	PORT_ALTFUN_USART6  8

#define	PORT_ALTFUN_OTG1_FS  10

#define	PORT_ALTFUN_SDIO  12


/** TYPEDEFS
 *****************************************************/

typedef enum
{
	PORT_A_PIN_0,
	PORT_A_PIN_1,
	PORT_A_PIN_2,
	PORT_A_PIN_3,
	PORT_A_PIN_4,
	PORT_A_PIN_5,
	PORT_A_PIN_6,
	PORT_A_PIN_7,
	PORT_A_PIN_8,
	PORT_A_PIN_9,
	PORT_A_PIN_10,
	PORT_A_PIN_11,
	PORT_A_PIN_12,
	PORT_A_PIN_13,
	PORT_A_PIN_14,
	PORT_A_PIN_15,

	PORT_B_PIN_0,
	PORT_B_PIN_1,
	PORT_B_PIN_2,
	PORT_B_PIN_3,
	PORT_B_PIN_4,
	PORT_B_PIN_5,
	PORT_B_PIN_6,
	PORT_B_PIN_7,
	PORT_B_PIN_8,
	PORT_B_PIN_9,
	PORT_B_PIN_10,
	PORT_B_PIN_11,
	PORT_B_PIN_12,
	PORT_B_PIN_13,
	PORT_B_PIN_14,
	PORT_B_PIN_15,

	PORT_C_PIN_13 = 45,
	PORT_C_PIN_14,
	PORT_C_PIN_15,
} Port_PinType;

typedef enum
{
	PORT_MODE_INPUT, PORT_MODE_OUTPUT, PORT_MODE_ALTFUN, PORT_MODE_ANALOG
} Port_PinModeType;

typedef sint8 Port_AltFuncType;

typedef enum
{
	PIN_LOW, PIN_HIGH
} Port_PinLevelType;

typedef enum
{
	PIN_OUTPUT_NONE = -1, PIN_OUTPUT_PUSHPULL, PIN_OUTPUT_OPENDRAIN
} Port_PinOutputType;


typedef enum
{
	PIN_INPUT_NONE = -1, PIN_INPUT_NOPULL, PIN_INPUT_PULLUP, PIN_INPUT_PULLDOWN
} Port_PinInputType;

typedef struct
{
	Port_PinType PortPin;
	Port_PinModeType PortPinMode;
	Port_PinOutputType	PortPinOutputMode;
	Port_PinInputType PortPinInputMode;
	Port_AltFuncType PortAltFunc;
} Port_ConfigType;

typedef enum
{
	PORTA, PORTB
} Port_PortType;


/** FUNCTION PROTOTYPES
 *****************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr);

#endif

/** END OF FILE
 *****************************************************/
