/*
Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "App.h"

int main(void)
{
	InitHw();

	LED_OFF(ROJO);
	LED_OFF(AZUL);
	LED_OFF(VERDE);

	while(1)
	{
		SerieMde();
		TimerEvent();
	}
}
