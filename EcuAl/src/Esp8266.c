/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			Esp8266.c
 *  DESCRIPTION:	Source file for ESP8266 driver
 *	AUTHOR:			Ahmed Sameh Saad
 *****************************************************************************/

#include "../inc/Esp8266.h"

static Std_ReturnType Esp8266_ValidateCommand(void)
{
	Usart_DataType Char1 = Usart_Receive(USART_1);

	if (Char1 == 'O')
	{
		return E_OK;
	}
	else
	{
		return E_NOT_OK;
	}
}

static Std_ReturnType Esp8266_ConnectToWiFi(Esp8266_StringType SSID, Esp8266_StringType Password)
{
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, "AT+CWJAP=");
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, SSID);
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, ",");
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, Password);
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, "\"\r\n");

	return E_OK;
}

static Std_ReturnType Esp8266_ConnectToServerTcp(Esp8266_StringType Domain , Esp8266_StringType Port)
{
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, "AT+CIPSTART=");
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, "TCP,");
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, Domain);
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, ",");
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, Port);

	return E_OK;
}

void Esp8266_Init(const Esp8266_ConfigType *ConfigPtr)
{
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, "AT\r\n");
	while (Esp8266_ValidateCommand() == E_NOT_OK);

	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, "AT+CWMODE=1\r\n");
	while (Esp8266_ValidateCommand() == E_NOT_OK);

	Esp8266_ConnectToWiFi(ConfigPtr->SSID, ConfigPtr->Password);

	Esp8266_ConnectToServerTcp(ConfigPtr->Domain, ConfigPtr->Port);
}


Std_ReturnType Esp8266_InitWebPageReception(Esp8266_StringType Domain)
{
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, "GET ");
	Usart_TransmitString(ESP8266_USED_USART_CONTROLLER, Domain);

	return E_OK;
}

Std_ReturnType Esp8266_ReceiveFromWebPage(Esp8266_DataType *DataToReturn)
{
	Std_ReturnType RxStatus = Usart_ReceiveSync(ESP8266_USED_USART_CONTROLLER, DataToReturn);

	return RxStatus;
}
