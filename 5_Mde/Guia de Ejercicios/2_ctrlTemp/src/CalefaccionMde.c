/*
===============================================================================
 Name        : CalefaccionMde.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/
#include "CalefaccionMde.h"

int main(void)
{
	Inicializacion();
	init_calefaccionMde();

    while(1)
    {
    	calefaccionMde();
    	TimerEvent();
    }
    return 0 ;
}
