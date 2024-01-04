/*
===============================================================================
 Name        : Tunel.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>

#include "../TunelMde/TunelMde.h"
#include "../AlarmaMde/AlarmaMde.h"
#include "../UARTMde/UARTMde.h"

int main(void)
{
	Inicializacion();
	init_TunelMde();

    while(1)
    {
    	TunelMde();
    	TimerEvent();
    }
    return 0 ;
}
