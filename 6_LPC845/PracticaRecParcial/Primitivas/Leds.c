/*
 * Leds.c
 *
 *  Created on: 19 nov. 2021
 *      Author: d_lugano
 */

#include "Leds.h"

void TitilarLV(void)
{
	flag500ms=1;
	LedV=1;
}

void ApagarLV(void)
{
	flag500ms=0;
	LedV=0;
}

void EncenderLR(void)
{
	flag500ms=1;
	LedV=1;
}

void ApagarLV(void)
{
	flag500ms=0;
	LedR=0;
}
