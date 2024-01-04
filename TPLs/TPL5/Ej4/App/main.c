/*
Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "../Drivers/DR_Init.h"
#include "../Drivers/DR_UART.h"
#include "../Primitivas/PR_Uart.h"
#include "../Drivers/LPC845.h"
#include "../Primitivas/Tecla.h"
#include "../Primitivas/Leds.h"

int main(void)
{
	int16_t dato=-1;

	InitHw();

	LED_OFF(ROJO);
	LED_OFF(AZUL);
	LED_OFF(VERDE);

	while(1)
	{
		dato = LecturaSerie();

		if ( dato != -1 )
		{
			switch(dato)
			{
				case 1:
					LED_ON(ROJO);
					LED_OFF(AZUL);
					LED_OFF(VERDE);
					break;
				case 2:
					LED_OFF(ROJO);
					LED_OFF(AZUL);
					LED_ON(VERDE);
					break;
				case 3:
					LED_OFF(ROJO);
					LED_ON(AZUL);
					LED_OFF(VERDE);
				break;
			}
		}
		TimerEvent();
	}
}
