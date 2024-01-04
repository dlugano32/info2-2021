/*
 * Leds.c
 *
 *  Created on: 25 ago. 2021
 *      Author: marup
 */

#include "Leds.h"
#include "gpio.h"

void prenderLed( uint8_t led )
{
	if(led == VERDE)
	{
		SetPIN(LED_VERDE, 0);
	}
	else if(led == ROJO)
	{
		SetPIN(LED_ROJO, 0);
	}
	else if( led == AZUL )
	{
		SetPIN(LED_AZUL, 0);
	}
}

void apagarLed( uint8_t led )
{
	if(led == VERDE)
	{
		SetPIN(LED_VERDE, 1);
	}
	else if(led == ROJO)
	{
		SetPIN(LED_ROJO, 1);
	}
	else if( led == AZUL )
	{
		SetPIN(LED_AZUL, 1);
	}
}
