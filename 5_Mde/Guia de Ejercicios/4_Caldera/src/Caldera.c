/*
===============================================================================
 Name        : Caldera.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "TanqueMde.h"
#include "CalefaccionMde.h"

int main(void)
{
	Inicializacion();
	init_TanqueMde();
	init_CalefaccionMde();

    while(1)
    {
    	TanqueMde();
    	CalefaccionMde();
    }
    return 0 ;
}
