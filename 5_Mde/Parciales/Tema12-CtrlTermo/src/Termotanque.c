/*
===============================================================================
 Name        : Termotanque.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "CalefaMde.h"
#include "BombaMde.h"

int main(void)
{
	Inicializacion();
	init_BombaMde();
	init_CalefaMde();

    while(1)
    {
		BombaMde();
		CalefaMde();
		TimerEvent();
    }
    return 0 ;
}
