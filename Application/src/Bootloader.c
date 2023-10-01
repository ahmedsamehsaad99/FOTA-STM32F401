/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Bootloader.c
 *  DESCRIPTION:	Source file for Bootloader Application
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/Bootloader.h"

Bootloader_FuncPtrType RESET_Pointer = NULL;

static void Bootloader_ClearApplicationSector(void)
{
	Fls_SectorType SectorIterator = 1;

	for (; SectorIterator < 5; SectorIterator++)
	{
		Fls_EraseSector(SectorIterator);
	}
}

static void Bootloader_JumpToApp(void)
{
	for (uint32 i = 0; i < 10000000; i++);

	Led_SetLedState(FLASHING_RED_LED, STD_LOW);

	SCB_VTOR = VECTOR_TABLE_NEW_ADDR;

	RESET_Pointer = (Bootloader_FuncPtrType)(*(volatile uint32 *)(RESET_HANDLER_ADDRESS));

    RESET_Pointer();
}

void Bootloader_Run(void)
{

	EcuM_Init();

	uint8 RecordCharCounter = 0;
	uint8 Hex_Str[100] = {0};
	Bootloader_ClearApplicationSector();

	for (uint32 i = 0; i < 10000000; i++);

	Esp8266_InitWebPageReception(WEBSITE_STRING);

	while (1)
	{
		Std_ReturnType RxStatus = Esp8266_ReceiveFromWebPage(&Hex_Str[RecordCharCounter]);

		if (RxStatus == E_NOT_OK)
			continue;
		else
		{
			Led_SetLedState(FLASHING_RED_LED, STD_HIGH);

			if (Hex_Str[8] == '1')
			{
				Bootloader_JumpToApp();
				break;
			}

			if (Hex_Str[RecordCharCounter] == 0xA)
			{
				HexParser_HexDetailsType HexDetails = {0};

				HexParser_ReturnType HEX_STATUS = HexParser_ParseRecord((HexParser_RecordType)Hex_Str, &HexDetails);

				Std_ReturnType FLS_STATUS = E_NOT_OK;

				if (HEX_STATUS == PARSING_OK)
					FLS_STATUS = Fls_Write(HexDetails.HexTargAddr, (Fls_DataType*)HexDetails.HexData, (HexDetails.HexLength)/2);

				RecordCharCounter = 0;
			}
			else
			{
				RecordCharCounter++;
			}
		}
	}
}
