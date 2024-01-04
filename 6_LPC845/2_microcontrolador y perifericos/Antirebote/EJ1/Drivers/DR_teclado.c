/*
 * DR_teclado.c
 *
 *  Created on: 16 sep. 2021
 *      Author: d_lugano
 */

#include "DR_teclado.h"

uint8_t Tecla;

void DriverTecladoSW(void)
{
	static uint8_t lastKey=NO_KEY;
	static uint8_t cont=0;
	uint8_t key;	//Tecla no presionada

	key=DriverTecladoHW();	//Devuelve la tecla que esta siendo presionada

	if( lastKey==key && cont < DEBOUNCE_COUNT)
	{
		cont++;	//Cuenta cuantos milisegundos esta presionada la tecla
		if(cont == DEBOUNCE_COUNT)
		{
			Tecla=key;	//Es decir, se esta presionando el boton. La variable Tecla es global y es la que va a estar devolviendo mi primitiva
		}
	}
	else if(key!= lastKey)
	{
		cont=0;
	}

	lastKey=key;
}

uint8_t DriverTecladoHW(void)
{
	if( !GetPIN(0,SW0) )
		return SW0;

	if( !GetPIN(0,SW1) )
		return SW1;

	if( !GetPIN(0,SW2) )
		return SW2;

	return NO_KEY;
}



