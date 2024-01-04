/*
===============================================================================
 Name        : Garage.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "GarageMde.h"
#include "AlarmaMde.h"

int main(void)
{
	Inicializacion();
	init_TanqueMde();
	init_AlarmMde();

    while(1)
    {
    	GarageMde();
    	AlarmaMde();
    	TimerEvent();
    }

    return 0 ;
}
