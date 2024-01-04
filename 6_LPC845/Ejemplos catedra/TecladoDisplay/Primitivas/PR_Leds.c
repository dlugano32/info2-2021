/*
 * Leds.c
 *
 *  Created on: 26 ago. 2021
 *      Author: d_lugano
 */

#include <DR_GPIO.h>
#include <PR_Leds.h>
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

void Leds ( uint8_t nled , uint8_t estado )
{

	switch(nled)
	{
		case 0:
			SetPIN(PIN_LED0,estado);
			break;

		case 1:
			SetPIN(PIN_LED1,estado);
			break;

		case 2:
			SetPIN(PIN_LED2,estado);
			break;

		case 3:
			SetPIN(PIN_LED3,estado);
			break;

	}
}
