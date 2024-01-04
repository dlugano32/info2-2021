/*
 * ESP8266App.c
 *
 *  Created on: 1 nov. 2021
 *      Author: d_lugano
 */
#include "ESP8266App.h"

uint8_t ESP8266_check(void)
{
	static uint8_t estado=ESPERANDO_O;
	int16_t msg=-1;
	uint8_t checked=0;

	msg=RxSerie1();	//Leo lo que envia el ESP8266

	if(msg!=-1)
	{
		switch(estado)
		{
			case ESPERANDO_O:

				if(msg=='O')
				{
					estado=ESPERANDO_K;
				}
				break;

			case ESPERANDO_K:

				if(msg=='K')
				{
					TxSerie0((uint8_t*)"OK\r\n");
					estado=ESPERANDO_O;
					checked=1;
				}
				else
				{
					estado=ESPERANDO_O;
					checked=0;
				}
				break;
		}
	}

	return checked;
}
