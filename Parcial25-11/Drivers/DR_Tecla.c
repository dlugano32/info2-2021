/*
 * DR_Tecla.c
 *
 *  Created on: 25 nov. 2021
 *      Author: d_lugano
 */

#include "DR_Tecla.h"

uint8_t Tecla=NO_KEY;

void BarridoTecla(void)	//Funcin que se invocaria en el systick
{
	uint8_t key;
	static uint8_t lastKey=NO_KEY, count=0;

	if(!GetPIN(0,4))	//Osea se apreto
		key=BOTONP04;
	else
		key=NO_KEY;

	if(lastKey==key && count<DEBOUNCE)
	{
		count ++;
		if(count>DEBOUNCE)
		{
			Tecla=key;
		}
	}
	else
	{
		count=0;
	}

	lastKey=key;
}
