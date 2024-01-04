/*
===============================================================================
 Name        : CintaTransportadora.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "CtrlVelocidadMde.h"
#include "EncoderMde.h"

int main(void)
{
	Inicializacion();
	init_CtrlVelocidadMde();
	init_EncoderMde();

    while(1)
    {
    	CtrlVelocidadMde();
    	EncoderMde();
    	TimerEvent();
    }
    return 0 ;
}
