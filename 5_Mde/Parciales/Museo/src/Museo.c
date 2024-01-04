/*
===============================================================================
 Name        : Museo.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/
#include "AlarmaMde.h"

int main(void)
{
	Inicilizacion();
	init_AlarmaMde();

    while(1)
    {
    	AlarmaMde();
    	TimerEvent();
    }
    return 0 ;
}
