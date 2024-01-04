/*
 * Leds.c
 *
 *  Created on: 26 ago. 2021
 *      Author: d_lugano
 */

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
