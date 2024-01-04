/*
===============================================================================
 Name        : TPOJustDance.c
 Author      : dlugano
 Date		 : 21/9/2021
===============================================================================
*/

#include "JustDanceMDE.h"
#include "DR_Init.h"

Paso cancion[CANT_PASOS];

int main (void)
{
	InitArchivoMusica(cancion);
	InitHw();
	InitJustDanceMDE();

	LED_OFF(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

	while(1)
	{
		JustDanceMDE();
		TimerEvent();
	}
	return 0;
}
