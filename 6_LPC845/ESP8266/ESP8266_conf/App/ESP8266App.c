/*
 * ESP8266App.c
 *
 *  Created on: 1 nov. 2021
 *      Author: d_lugano
 */
#include "ESP8266App.h"

void ESP8266_check(void)
{
	static uint8_t estado=ESPERANDO_TX;
	uint8_t key=NO_KEY;
	int16_t msg=-1;

	key=getKey();
	msg=RxSerie1();

	switch(estado)
	{
		case ESPERANDO_TX:

			if(key==PUSH)
			{
				LED_ON(ROJO);
				TxSerie1((uint8_t *)"AT\r\n");
				TxSerie0((uint8_t *)"AT\r\n");
				estado=ESPERANDO_O;
			}

			break;

		case ESPERANDO_O:

			if(msg=='O')
			{
				LED_OFF(ROJO);
				LED_ON(VERDE);
				Tx0Byte('O');
				estado=ESPERANDO_K;
			}
			break;

		case ESPERANDO_K:

			if(msg=='K')
			{
				Tx0Byte('K');
				estado=ESPERANDO_R;
			}
			break;

		case ESPERANDO_R:

			if(msg=='\r')
			{
				Tx0Byte('\r');
				estado=ESPERANDO_N;
			}
			break;

		case ESPERANDO_N:

			if(msg=='\n')
			{
				Tx0Byte('\n');
				estado=ESPERANDO_TX;
			}
			break;
	}
}
