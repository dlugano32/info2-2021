#include "LPC845.h"
#include "DR_Init.h"
#include "gpio.h"
#include "Leds.h"

int main ( void )
{
	InitHw();

	//Arranco con todos los leds apagados
	LED_OFF(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

	SetPIN(0,8,0);

	while ( 1 )
	{
		//Mientras esté presionado el pulsador
		if ( GetPIN(0,8) == 0 )
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
