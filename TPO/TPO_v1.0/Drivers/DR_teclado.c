/*
 * DR_teclado.c
 *
 *  Created on: 16 sep. 2021
 *      Author: d_lugano
 */

#include "DR_teclado.h"

uint8_t Tecla=NO_KEY;

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
	if( !GetPIN(SW0) )
		return SELECT;

	if( !GetPIN(SW1) )
		return CROSS;

	if( !GetPIN(SW2) )
		return LEFT_ARROW;

	if( !GetPIN(SW3) )
		return TRIANGLE;

	if( !GetPIN(SW4) )
		return DOWN_ARROW;

	if( !GetPIN(SW5) )
		return UP_ARROW;

	if( !GetPIN(SW6) )
		return SQUARE;

	if( !GetPIN(SW7) )
		return RIGHT_ARROW;

	if( !GetPIN(SW8) )
		return CIRCLE;

	if( !GetPIN(SW9) )
			return START;

	return NO_KEY;
}



