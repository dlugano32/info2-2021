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
#include "DR_Init.h"
#include "funciones.h"

#include <cr_section_macros.h>


int main(void) {

	//Genero una variable para usar como contador:
	unsigned int i = 0;

	InitHw();

	//Empiezo con los 3 leds apagados (se apagan con 1):

	/*
	SetearBit(GPIO1PIN, 0);
	SetearBit(GPIO1PIN, 1);
	SetearBit(GPIO1PIN, 2);
	 */

	*GPIO1PIN|= (7<<0);


	while(1)
	{
		i++;
		//cuando i llega a un determinado valor cambio de estado el led:
		if ( i == 1500000 )
		{
			//ToggleBit(GPIO1PIN, 1);
			*GPIO1PIN^= (7<<0);


			i = 0;
		}
	}
    return 0 ;
}
