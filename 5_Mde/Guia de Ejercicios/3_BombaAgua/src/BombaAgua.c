/*
===============================================================================
 Name        : BombaAgua.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "TanqueMde.h"

int main(void)
{

	Inicializacion();
	init_TanqueMde();

    while(1)
    {
    	TanqueMde();
    	TimerEvent();
    }
    return 0 ;
}
