/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Fls.c
 *  DESCRIPTION:	Source file for Flash for STM32F104CC
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/Fls.h"

#if (FLS_SIMULATION_MODE)

Std_ReturnType Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    for (uint32 i = 0; i < Length; i++)
    {
		*( (volatile uint32 *)TargetAddress ) = 0xFFFF ;
		TargetAddress += 2 ;
    }

    return E_OK;
}

Std_ReturnType Fls_Write (Fls_AddressType TargetAddress, Fls_DataType* Data, Fls_LengthType Length)
{
    for (uint8 i = 0; i < Length; i++)
    {
    	*( (volatile uint32 *)TargetAddress ) = (Data[i] >> 8) | ( (Data[i] & 0x00FF) << 8 );
		TargetAddress += 2 ;
    }

    return E_OK;
}


Std_ReturnType Fls_EraseSector(Fls_SectorType Sector)
{
	uint32 SectorBaseAddress = FLS_MEMORY_BASE_ADDRESS + (Sector * FLS_SECTOR_SIZE);
	uint32 SectorLastAddress = ( FLS_MEMORY_BASE_ADDRESS + ((Sector+1) * FLS_SECTOR_SIZE) ) - 1;

    for (uint32* addr = (uint32*)SectorBaseAddress; addr < (uint32*)(SectorLastAddress); addr++) {
        *addr = 0xFFFFFFFF;
    }

    return E_OK;
}


#else

Std_ReturnType Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length)
{
	while( GET_BIT( FLS->SR, 16) == STD_HIGH );

	if( GET_BIT( FLS -> CR , 31 ) == STD_HIGH ){

		FLS -> KEYR = 0x45670123 ;
		FLS -> KEYR = 0xCDEF89AB ;

	}

	FLS->CR &= FLS_WRITE_SIZE_MASK ;

	FLS->CR |= (FLS_WRITE_HALF_WORD<<8) ;

	uint8 i;

	for( i = 0 ; i < Length ; i++ )
	{
		SET_BIT_STATE(FLS->CR, 0, STD_HIGH);

		*( (volatile uint16 *)TargetAddress ) = 0xFFFF;
		TargetAddress += 2 ;

		while( GET_BIT( FLS -> SR, 16 ) == 1 );

		SET_BIT_STATE( FLS -> SR , 0, STD_HIGH );

		SET_BIT_STATE( FLS -> CR , 0, STD_LOW);
	}

    return E_OK;
}

Std_ReturnType Fls_Write (Fls_AddressType TargetAddress, Fls_DataType* Data, Fls_LengthType Length)
{
	while( GET_BIT( FLS->SR, 16) == STD_HIGH );

	if( GET_BIT( FLS -> CR , 31 ) == STD_HIGH ){

		FLS -> KEYR = 0x45670123 ;
		FLS -> KEYR = 0xCDEF89AB ;

	}

	FLS->CR &= FLS_WRITE_SIZE_MASK ;

	FLS->CR |= (FLS_WRITE_HALF_WORD<<8) ;

	uint8 i;

	for( i = 0 ; i < Length ; i++ )
	{
		SET_BIT_STATE(FLS->CR, 0, STD_HIGH);

		*( (volatile uint32 *)TargetAddress ) = (Data[i] >> 8) | ( (Data[i] & 0x00FF) << 8 ) ;
		TargetAddress += 2 ;

		while( GET_BIT( FLS -> SR, 16 ) == 1 );

		SET_BIT_STATE( FLS -> SR , 0, STD_HIGH );

		SET_BIT_STATE( FLS -> CR , 0, STD_LOW);
	}

    return E_OK;
}


Std_ReturnType Fls_EraseSector(Fls_SectorType Sector)
{
	while( GET_BIT( FLS->SR ,16 ) == STD_HIGH );

	if( GET_BIT( FLS->CR , 31 ) == 1 )
	{
		FLS->KEYR = 0x45670123 ;
		FLS->KEYR = 0xCDEF89AB ;
	}

	SET_BIT_STATE( FLS->CR , 1, STD_HIGH);

	FLS->CR &= FLS_SECTOR_MASK ;

	FLS->CR |= (Sector<<3) ;

	SET_BIT_STATE(FLS->CR , 16, STD_HIGH);

	while( GET_BIT( FLS->SR ,16 ) == STD_HIGH );

	SET_BIT_STATE( FLS->SR , 0, STD_HIGH);

	SET_BIT_STATE( FLS->CR , 1, STD_LOW);

    return E_OK;
}

#endif
