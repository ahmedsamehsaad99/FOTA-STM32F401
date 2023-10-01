/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Std_Types.h
 *  DESCRIPTION:	Header file for the used data types/bitwise operations
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include <stdio.h>

typedef unsigned char	uint8;
typedef signed char		sint8;

typedef unsigned short	uint16;
typedef signed short	sint16;

typedef unsigned int	uint32;
typedef signed int		sint32;

typedef unsigned long	uint64;
typedef signed long		sint64;

typedef float			float32;
typedef double			float64;


#define SET_BIT_STATE(REGISTER, BITNUM, BITSTATE)	((BITSTATE == 1) ? (REGISTER |= (1<<BITNUM)) : (REGISTER &= ~(1<<BITNUM)))
#define GET_BIT(REGISTER, BITNUM) 					((REGISTER & (1<<BITNUM)) >> BITNUM)
#define TOGGLE_BIT(REGISTER, BITNUM) 				(REGISTER ^= (1<<BITNUM))

#define PLACE_VALUE(REG, MASK, BITNUM, VALUE)		(REG &= ~((MASK) << (BITNUM)));(REG |= (VALUE << BITNUM))
#define GET_VALUE(REGISTER, MASK, BITNUM)			((REGISTER & (MASK<<BITNUM)) >> BITNUM)


#define F_CPU							16000000UL
//#define NULL							((void*)0)

#define round(x)						((x)>=0?(long)((x)+0.5):(long)((x)-0.5))

#define STD_HIGH	0x01u
#define STD_LOW		0x00u

typedef enum
{
	E_OK, E_NOT_OK
} Std_ReturnType;


#endif

/** END OF FILE: Std_types.h
 *****************************************************/
