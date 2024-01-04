/*
 * Leds.c
 *
 *  Created on: 26 ago. 2021
 *      Author: d_lugano
 */

#include <GPIO.h>
#include "Leds.h"
#include "LPC845.h"

void LED_OFF( uint32_t Color)
{
	SetPIN(PUERTO1, Color, L_OFF);
}

void LED_ON( uint32_t Color)
{
	SetPIN(PUERTO1, Color, L_ON);
}

void SwapEstadoLed(uint32_t Color)
{

	if( GetPIN(PUERTO1, Color) == 1)	//Osea esta apagado
		LED_ON(Color);
	else
		LED_OFF(Color);
}

uint32_t ReadLed(uint32_t Color)
{
	return GetPIN(PUERTO1, Color);
}
