/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			HexParser.h
 *  DESCRIPTION:	Header file for HexParser
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#ifndef HEXPARSER_H
#define HEXPARSER_H

#include "../../Common/Std_Types.h"
#include "../cfg/HexParser_Cfg.h"

 /** TYPEDEFS
 *****************************************************/
typedef uint8 HexParser_AsciiType;
typedef uint16 HexParser_DataType;
typedef uint8* HexParser_StringType;
typedef uint8* HexParser_RecordType;

typedef enum
{
	PARSING_OK, PARSING_HIGHADDR, PARSING_END
} HexParser_ReturnType;

typedef struct
{
	uint8	HexLength;
	uint32	HexTargAddr;
	uint16*	HexData;
} HexParser_HexDetailsType;

 /** FUNCTIONS PROTOTYPES
 *****************************************************/
HexParser_DataType HexParser_AsciiToHex(HexParser_AsciiType Ascii);
HexParser_ReturnType HexParser_ParseRecord(HexParser_RecordType Record, HexParser_HexDetailsType* ToReturn);

#endif

 /** END OF FILE: HexParser.h
  *****************************************************/
