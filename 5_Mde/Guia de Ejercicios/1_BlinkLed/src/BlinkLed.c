/*
===============================================================================
 Name        : BlinkLed.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "LedMde.h"
#include "FreqMde.h"

int main(void)
{
	Inicializacion();
	init_LedMde();
	init_FreqMde();

    while(1)
    {
    	LedMde();
    	FreqMde();
    	TimerEvent();
    }
    return 0 ;
}
