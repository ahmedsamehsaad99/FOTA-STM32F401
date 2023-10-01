/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			HexParser.c
 *  DESCRIPTION:	Source file for HexParser
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/HexParser.h"

static uint16 Address_High = 0x0800;

static HexParser_DataType HexParser_GetValue(HexParser_StringType Str, uint8 size)
{
    uint16 toReturn = 0;

    for (uint8 i = 0; i < size; i++) {
        int digitValue = HexParser_AsciiToHex(Str[i]);

        toReturn = toReturn * 16 + digitValue;
    }

   return toReturn;
}

HexParser_DataType HexParser_AsciiToHex(HexParser_AsciiType Ascii)
{
	 if (Ascii >= '0' && Ascii <= '9')
		return Ascii - '0';

	 else if (Ascii >= 'A' && Ascii <= 'F')
		return 10 + (Ascii - 'A');

	 else if (Ascii >= 'a' && Ascii <= 'f')
		return 10 + (Ascii - 'a');

	 else
		return -1;
}

HexParser_ReturnType HexParser_ParseRecord(HexParser_RecordType Record, HexParser_HexDetailsType* ToReturn)
{
	if (Record[8] == '4')
	{
	    uint8 Address_HighStr[] = {Record[3], Record[4], Record[5], Record[6]};
		Address_High = HexParser_GetValue(Address_HighStr, 4);
		return PARSING_HIGHADDR;
	}

	else if (Record[8] == '0')
	{
		uint8 ByteCount_Str[] = {Record[1], Record[2]};
		uint8 Address_LowStr[] = {Record[3], Record[4], Record[5], Record[6]};

		uint8 ByteCount = (uint8)HexParser_GetValue(ByteCount_Str, 2);
	    uint16 Address_Low = HexParser_GetValue(Address_LowStr, 4);

	    uint32 TargetAddress = (Address_High << 16) | Address_Low;

	    uint8 Data_Str[32] = {0};
	    uint16 Data_Arr[8] = {0};

	    for (uint8 i = 9, j = 0; i < (9+ByteCount*2); i++, j++)
	    {
	    	Data_Str[j] = Record[i];
	    }

	    for (uint8 i = 0, j = 0; i < ByteCount*2; i++)
		{
			uint8 Data_Str_Temp[4];

			Data_Str_Temp[i%4] = Data_Str[i];

			if (i % 4 == 3)
			{
				Data_Arr[j] = HexParser_GetValue(Data_Str_Temp, 4);
				ToReturn->HexData[j] = Data_Arr[j];
				j++;
			}
		}

	    ToReturn->HexTargAddr = TargetAddress;
	    ToReturn->HexLength = ByteCount;

	    return PARSING_OK;
	}

	else
	{
		return PARSING_END;
	}
}
