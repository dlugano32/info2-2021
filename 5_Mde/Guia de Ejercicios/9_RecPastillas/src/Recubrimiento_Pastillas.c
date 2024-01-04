/*
===============================================================================
 Name        : Recubrimiento_Pastillas.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "../Paila/PailaMde.h"
#include "../Calefa/CalefaMde.h"
#include "../Spray/SprayMde.h"

int main(void)
{
	Inicilizacion();
	init_PailaMde();
	init_CalefaMde();
	init_SprayMde();

    while(1)
    {
    	PailaMde();
		CalefaMde();
		SprayMde();
    	TimerEvent();
    }
    return 0 ;
}
