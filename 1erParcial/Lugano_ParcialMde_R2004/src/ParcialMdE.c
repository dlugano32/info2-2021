/*
===============================================================================
 Name        : ParcialMdE.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "OperacionMde.h"

int main(void)
{
	Inicializar();
	init_OperacionMde();

    while(1)
    {
    	OperacionMde();
    	TimerEvent();
    }
    return 0 ;
}
