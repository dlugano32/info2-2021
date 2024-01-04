/*
===============================================================================
 Name        : TPOJustDance.c
 Author      : dlugano
 Date		 : 21/9/2021
===============================================================================
*/

#include "JustDanceMDE.h"
#include "../Drivers/DR_Init.h"

Paso cancion[CANT_PASOS];

int main (void)
{
	InitHw();
	InitJustDanceMDE();

	LED_OFF(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

	matrixInit();
	cleanAll();
	start();

	while(1)
	{
		JustDanceMDE();
		TimerEvent();
	}
	return 0;
}
