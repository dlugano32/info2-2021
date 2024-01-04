/*
===============================================================================
 Name        : Puerta_automatica.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>

// TODO: insert other include files here
#include "Mde_Puerta_automatica_funciones.h"
#include "MdE_Puerta_automatica.h"
// TODO: insert other definitions and declarations here

int main(void)
{

	inicializacion();	//Init de la libreria de la catedra
	Mde_init();	//inicializacion de mi maquina de estado

	while(1)
	{
		MdE_Puerta_automatica();
		TimerEvent();	//Controla si se vence alguno de los timer para llamar a los callback
    }
    return 0 ;
}
