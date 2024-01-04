/*
===============================================================================
 Name        : Prueba845_Systick.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>
#include "LPC845.h"

unsigned char flag_systick = 0;

int main(void) {

	InitHw();

	//Configuro el Systick cada 1mseg: Si el clk que alimenta el Systick es de 30 millones de ciclos por segundo,
	//y quiero que la interrupcion se genere 1000 veces por segundo, tengo que contar 30000 pulsos de clk antes
	//de generar una interrupción:
	SYSTICK->RVR = 30000-1;
	SYSTICK->CVR = SYSTICK->RVR;
	SYSTICK->CSR = 7;

	//Empiezo con los 3 leds apagados (se apagan con 1):
	GPIO->PIN[1] |= 1<<PIN_LEDR;
	GPIO->PIN[1] |= 1<<PIN_LEDG;
	GPIO->PIN[1] |= 1<<PIN_LEDB;

	while(1) {

		//cuando i llega a un determinado valor cambio de estado el led:
		if ( flag_systick == 1)
		{
			//Cambio de estado el bit del registro correspondiente al led:
			GPIO->PIN[1] ^= 1<<PIN_LEDG;
			flag_systick = 0;
		}
	}
    return 0 ;
}


void SysTick_Handler(void)
{
	static unsigned int contador = 0;

	//Leo el registro de estado para limpiar el flag de interrupciones:
	unsigned int auxiliar = SYSTICK->CSR;

	//Cada 1milisegundo sumo un contador
	contador++;

	//1 vez por segundo, levanto el flag_systick:
	if ( contador >= 1000 )
	{
		flag_systick = 1;
		contador = 0;
	}
}
