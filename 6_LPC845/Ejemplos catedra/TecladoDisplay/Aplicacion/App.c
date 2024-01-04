/*
 * App.c
 *
 *  Created on: 16 sep. 2021
 *      Author: d_lugano
 */

#include <PR_Teclado.h>
#include "DR_Init.h"
#include "PR_7Seg.h"

int main (void)
{
	uint8_t key=0;
	uint8_t estado = 0;

	InitHw();

	//Apago todos los leds:
	Leds(0,0);
	Leds(1,0);
	Leds(2,0);
	Leds(3,0);

	Display(0,0);
	Display(1,0);

	while(1)
	{
		key=getKey();

		if ( key != NO_KEY )
		switch( key )
		{
			case SW1:
			Leds(0,1);
			Leds(1,0);
			Leds(2,0);
			Leds(3,0);
			Display(0,1);
			Display(1,1);
			break;

			case SW2:
			Leds(0,0);
			Leds(1,1);
			Leds(2,0);
			Leds(3,0);
			Display(0,2);
			Display(1,2);
			break;

			case SW3:
			Leds(0,1);
			Leds(1,1);
			Leds(2,0);
			Leds(3,0);
			Display(0,3);
			Display(1,3);
			break;

			case SW4:
			Leds(0,0);
			Leds(1,0);
			Leds(2,1);
			Leds(3,0);
			Display(0,4);
			Display(1,4);
			break;

			case SW5:
			Leds(0,1);
			Leds(1,0);
			Leds(2,1);
			Leds(3,0);
			Display(0,5);
			Display(1,5);
			break;

			case SW6:
			Leds(0,0);
			Leds(1,1);
			Leds(2,1);
			Leds(3,0);
			Display(0,6);
			Display(1,6);
			break;

			default:
			Leds(0,1);
			Leds(1,1);
			Leds(2,1);
			Leds(3,1);
			Display(0,0);
			Display(1,0);
			break;

		}

		TimerEvent();
	}
	return 0;
}
