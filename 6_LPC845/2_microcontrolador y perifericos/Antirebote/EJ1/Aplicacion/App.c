/*
 * App.c
 *
 *  Created on: 16 sep. 2021
 *      Author: d_lugano
 */

#include "DR_Init.h"

int main (void)
{
	uint8_t key=0;

	static uint8_t led0=0;
	static uint8_t led1=0;
	static uint8_t led2=0;

	InitHw();

	LED_OFF(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

	while(1)
	{
		key=getKey();

		switch(key)
		{
			case SW0:
				if(led0==0)
				{
					LED_ON(ROJO);
					led0=1;
				}

				else if(led0==1)
				{
					LED_OFF(ROJO);
					led0=0;
				}

				break;

			case SW1:
				if(led1==0)
				{
					LED_ON(VERDE);
					led1=1;
				}

				else if(led1==1)
				{
					LED_OFF(VERDE);
					led1=0;
				}

				break;

			case SW2:

				if(led2==0)
				{
					LED_ON(AZUL);
					led2=1;
				}

				else if(led2==1)
				{
					LED_OFF(AZUL);
					led2=0;
				}

				break;

			default:
				key=NO_KEY;
		}

		TimerEvent();
	}
	return 0;
}
