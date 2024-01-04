/*
 * DR_teclado.c
 *
 *  Created on: 16 sep. 2021
 *      Author: d_lugano
 */

#include "DR_teclado.h"
#include "../Primitivas/Tecla.h"

uint8_t Tecla=NO_KEY;

void DriverTecladoSW(void)
{
	uint8_t key=NO_KEY;	//Tecla no presionada
	static uint8_t cont=0;

	key=GetPIN(BOTON_STICK);	//Me fijo el estado de la tecla

	if( key == PUSH && cont < DEBOUNCE_COUNT)
	{
		cont++;	//Cuenta cuantos milisegundos esta presionada la tecla
		if(cont == DEBOUNCE_COUNT)
		{
			Tecla=PUSH;	//Es decir, se esta presionando el boton. La variable Tecla es global y es la que va a estar devolviendo mi primitiva
		}
	}
	else if(key== NO_KEY)
	{
		cont=0;
	}
}


