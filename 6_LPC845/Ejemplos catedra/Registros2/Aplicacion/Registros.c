/*
===============================================================================
 Name        : Prueba845.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "Registros.h"
#include "DR_I//nit.h"

#include <cr_section_macros.h>


int main(void) {

	//Genero una variable para usar como contador:
	unsigned int i = 0;

	InitHw();

	//Empiezo con los 3 leds apagados (se apagan con 1):

	GPIO->PIN[1] |= (1<<PIN_LEDR);
	GPIO->PIN[1] |= (1<<PIN_LEDG);
	GPIO->PIN[1] |= (1<<PIN_LEDB);


	while(1) {

		i++;
		//cuando i llega a un determinado valor cambio de estado el led:
		if ( i == 1500000 )
		{
			//Cambio de estado el bit del registro correspondiente al led:
			//GPIO->PIN[1] ^= 1<<PIN_LEDR;
			//GPIO->PIN[1] ^= 1<<PIN_LEDG;
			GPIO->PIN[1] ^= 1<<PIN_LEDB;
			//GPIO1PIN ^= 1<<PIN_LEDG;
			i = 0;
		}
	}
    return 0 ;
}
