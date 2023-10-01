/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			STM32F401_Registers.h
 *  DESCRIPTION:	Header file for STM32F401 Registers
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#ifndef REGISTERS_MAP_H_
#define REGISTERS_MAP_H_

#include "Std_Types.h"

/* FLASH REGISTERS */

typedef struct{

	uint32 ACR;
	uint32 KEYR;
	uint32 OPTKEYR;
	uint32 SR;
	uint32 CR;
	uint32 OPTCR;
}FLS_MemMap_t;

#define FLS_SECTOR_MASK            	0xFFFFFF87
#define FLS_Flash_WRITE_SIZE_MASK   0xFFFFFCFF
#define FLS_BASE_ADDR				0x40023C00
#define FLS  ((volatile FLS_MemMap_t*)(FLS_BASE_ADDR))


/* RCC REGISTERS */

typedef struct {
	uint32 CR;
	uint32 PLLCFGR;
	uint32 CFGR;
	uint32 CIR;
	uint32 AHB1RSTR;
	uint32 AHB2RSTR;
	uint32 RESERVED1;
	uint32 RESERVED2;
	uint32 APB1RSTR;
	uint32 APB2RSTR;
	uint32 RESERVED3;
	uint32 RESERVED4;
	uint32 AHB1ENR;
	uint32 AHB2ENR;
	uint32 RESERVED5;
	uint32 RESERVED6;
	uint32 APB1ENR;
	uint32 APB2ENR;
	uint32 Reserved7;
	uint32 Reserved8;
} RCC_MemMap_t;

#define RCC_BASE_ADDR 	0x40023800
#define RCC ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))

/* GPIO REGISTERS */
typedef struct {
	uint32 MODER;
	uint32 OTYPER;
	uint32 OSPEEDR;
	uint32 PUPDR;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
} GPIO_MemMap_t;

#define GPIOA_BASE_ADDR 0x40020000
#define GPIOB_BASE_ADDR 0x40020400
#define GPIOC_BASE_ADDR 0x40020800
#define GPIO(PORT_NUM) ((volatile GPIO_MemMap_t*)(GPIOA_BASE_ADDR + (0x400 * PORT_NUM)))

/* USART REGISTERS */

#define USART2_BASE_ADDR	0x40004400
#define USART1_BASE_ADDR 	0x40011000
#define USART6_BASE_ADDR	0x40011400

#define USART_REGISTER_SIZE 32

typedef struct {
	uint32 SR;
	uint32 DR;
	uint32 BRR;
	uint32 CR1;
	uint32 CR2;
	uint32 CR3;
	uint32 GTPR;
} USART_MemMap_t;


#define USART_PTR(BASE)	((volatile USART_MemMap_t*)(BASE))

//#define USART(ContNum) ( (ContNum == 1) ? (USART_PTR(USART1_BASE_ADDR)) : ( (ContNum == 2) ? (USART_PTR(USART2_BASE_ADDR)) ) : ( (ContNum == 6) ? (USART_PTR(USART6_BASE_ADDR)) ) )

//#define USART(CONT)		((volatile USART_MemMap_t*)(BASE))

#define USART(CONT) \
    ((CONT) == 1 ? ((volatile USART_MemMap_t*)(0x40011000)) : \
    ((CONT) == 2 ? ((volatile USART_MemMap_t*)(0x40004400)) : \
    ((CONT) == 6 ? ((volatile USART_MemMap_t*)(0x40011400)) : 0)))

///////////////////////////////////////////////////////////////////////////

#endif
