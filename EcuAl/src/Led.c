/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Led.c
 *  DESCRIPTION:	C file for LED driver
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/Led.h"

void Led_SetLedState(Led_IdType LedId, Led_StateType State)
{
	Dio_WriteChannel(LedId, State);
}

Led_StateType Led_ReadLedState(Led_IdType LedId)
{
	return (Dio_ReadChannel(LedId));
}
