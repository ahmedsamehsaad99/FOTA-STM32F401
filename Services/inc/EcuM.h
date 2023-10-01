/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			EcuM.h
 *  DESCRIPTION:	Header file for EcuM
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#ifndef EcuM_H
#define EcuM_H

/** INCLUDES
*****************************************************/
#include "../../Common/Std_Types.h"
#include "../../Mcal/inc/Mcu.h"
#include "../../Mcal/inc/Fls.h"
#include "../../Mcal/inc/Port.h"
#include "../../Mcal/inc/Dio.h"
#include "../../Mcal/inc/Usart.h"
#include "../../CDD/inc/HexParser.h"
#include "../../EcuAl/inc/Led.h"
#include "../../EcuAl/inc/Esp8266.h"

/** FUNCTIONS PROTOTYPES
*****************************************************/
void EcuM_Init(void);


#endif

/** END OF FILE
 *****************************************************/
