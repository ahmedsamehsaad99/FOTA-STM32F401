/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Fls.h
 *  DESCRIPTION:	Header file for Flash driver for STM32F104CC
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#ifndef FLS_H
#define FLS_H


/** INCLUDES
*****************************************************/
#include "../../Common/Std_Types.h"
#include "../../Common/Registers_Map.h"
#include "../cfg/Fls_Cfg.h"

/** DEFINITIONS
*****************************************************/
#define FLS_MEMORY_BASE_ADDRESS			(0x08000000)
#define FLS_SECTOR_SIZE					(0x4000)
#define FLS_WRITE_SIZE_MASK   			(0xFFFFFCFF)
#define FLS_WRITE_BYTE         		    0
#define FLS_WRITE_HALF_WORD      		1
#define FLS_WRITE_WORD            		2
#define FLS_WRITE_DOUBLE_WORD      		3

/** TYPEDEFS
 *****************************************************/
typedef uint32 Fls_AddressType;
typedef uint16 Fls_LengthType;
typedef uint16 Fls_DataType;

typedef enum {
	FLS_SECTOR_0,
	FLS_SECTOR_1,
	FLS_SECTOR_2,
	FLS_SECTOR_3,
	FLS_SECTOR_4
} Fls_SectorType;

typedef struct {

} Fls_ConfigType;

/** FUNCTION PROTOTYPES
 *****************************************************/
void Fls_Init();
Std_ReturnType Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length);
Std_ReturnType Fls_Write (Fls_AddressType TargetAddress, Fls_DataType* Data, Fls_LengthType Length);
Std_ReturnType Fls_EraseSector(Fls_SectorType Sector);

#endif

/** END OF FILE
 *****************************************************/
