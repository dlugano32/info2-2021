/*
 * Registros.c
 *
 *  Created on: 19 ago. 2021
 *      Author: d_lugano
 */

#include "DR_Init.h"


int main (void)
{
	static uint8_t estado=1;
	InitHw();

	LED_ON(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

	TimerStart(0,1,HandlerT0,SEG);

	while(1)
	{
		switch(estado)
		{
		case 1:
			if(flagT0==1)
			{
				flagT0=0;
				TimerStart(0,1,HandlerT0,SEG);
				SetPIN(PIN0, 1);
				LED_OFF(ROJO);
				estado=2;
			}
			break;
		case 2:
			if(flagT0==1)
			{
				flagT0=0;
				TimerStart(0,1,HandlerT0,SEG);
				SetPIN(PIN0, 0);
				LED_ON(ROJO);
				estado=1;
			}
		}

		TimerEvent();
	}
	return 0;
}

