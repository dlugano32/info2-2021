/*
===============================================================================
 Name        : Ej1_2.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "DR_Init.h"
#include "DR_UART.h"
#include "LPC845.h"
#include "Tecla.h"
#include "Leds.h"

int main(void)
{
	static uint8_t aux=0;

	InitHw();

	LED_OFF(ROJO);
	LED_OFF(AZUL);
	LED_OFF(VERDE);

	while(1)
	{
		if( getKey() == PUSH)
		{
			aux++;
			if(aux ==4)
				aux=1;
			USART1->TXDAT=aux;
		}
	}
}
