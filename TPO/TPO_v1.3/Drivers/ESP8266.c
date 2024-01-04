/*
 * ESP8266_conf.c
 *
 *  Created on: 17 nov. 2021
 *      Author: d_lugano
 */
#include "ESP8266.h"

uint8_t stage=0;

char * comando[CANT_COMANDOS]=
{	 	//"AT\r\n"
		//,"AT+CWMODE=1\r\n"
		//,"AT+CWJAP=\"Fibertel WiFi982 2.4GHz\",\"0141832376\"\r\n"
		//,"AT+CWJAP=\"DAMI\",\"zonaportatil\"\r\n"
		"AT+CIPMUX=1\r\n"
		//,"AT+CIPSTART=1,\"TCP\",\"192.168.43.180\",4000\r\n"
		,"AT+CIPSTART=1,\"TCP\",\"192.168.0.72\",4000\r\n"
		,"AT+CIPSEND=1,13\r\n"
		,"# JustDance @"
};

void InitESP8266_conf(void)
{
	flagT5=0;
	stage=0;
}


uint8_t Esp8266_conf(void)
{
	static uint8_t estado = TRANSMISION;
	uint8_t ret=0;
	static uint8_t stage=0;

	switch(estado)
	{
		case TRANSMISION:

			if(flagT5==1)
			{
				TxSerie1((uint8_t *)comando[stage]);
				TxSerie0((uint8_t *)comando[stage]);
				flagT5=0;
				stage++;
				estado=CHECKING;
			}

			break;

		case CHECKING:
			//while( ESP8266_check() != 1 );

			if(stage==CANT_COMANDOS)
			{
				ret=1;	//Aca es cuando salgo
				flagT5=0;
			}
			else
			{
				estado=TRANSMISION;
				TimerStart(5, 1000, handlerT5, MILI);
			}
			break;

		default:
			estado=CHECKING;
	}

	return ret;
}

uint8_t ESP8266_check(void)
{
	static uint8_t state=ESPERANDO_O;
	int16_t msg;
	uint8_t checked=0;

	msg=RxSerie1();

	if(msg!=-1)
	{
		switch(state)
		{
			case ESPERANDO_O:

				if(msg=='O')
				{
					state=ESPERANDO_K;
				}
				break;

			case ESPERANDO_K:

				if(msg=='K')
				{
					TxSerie0((uint8_t*)"OK\r\n");
					state=ESPERANDO_O;
					checked=1;
				}
				break;

			default:
				state=ESPERANDO_O;
		}
	}

	return checked;
}

