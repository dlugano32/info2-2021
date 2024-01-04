/*
 * App.c
 *
 *  Created on: 6 sep. 2021
 *      Author: d_lugano
 */


#include "LPC845.h"
#include "DR_Init.h"
#include "gpio.h"
#include "Leds.h"
#include "Tecla.h"


int main ( void )
{
	InitHw();

	//Arranco con todos los leds apagados
	LED_OFF(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

	while ( 1 )
	{
		//Mientras esté presionado el pulsador
		if ( getKey() == 0 )
		{
			LED_ON(ROJO);
		}
		//Si no está presionado:
		else
		{
			LED_OFF(ROJO);
		}
	}

	return 0;
}
