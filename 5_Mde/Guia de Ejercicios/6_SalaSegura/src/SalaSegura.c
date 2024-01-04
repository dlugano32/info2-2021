/*
===============================================================================
 Name        : SalaSegura.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "../CtrlPuerta/CtrlPuertaMde.h"

int main(void)
{
	Inicializacion();
	init_CtrlPuertaMde();

    while(1)
    {
    	CtrlPuertaMde();
    	TimerEvent();
    }
    return 0 ;
}
