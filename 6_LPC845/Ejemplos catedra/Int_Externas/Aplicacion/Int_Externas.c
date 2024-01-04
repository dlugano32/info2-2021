/*
===============================================================================
 Name        : Int_Externas.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>

// TODO: insert other include files here
#include "DR_Init.h"
#include "Leds.h"
#include "PR_IntExt.h"
// TODO: insert other definitions and declarations here

int main(void) {

    // TODO: insert code here

	uint8_t led=0;
	InitHw();

	apagarLed(ROJO);

    while(1) {
    	if( TeclaInterrupcion() ) //Viendo el estado del flag interrupcion
    	{
    		if(led)
    		{
    			apagarLed(ROJO);
    			led = 0;
    		}
    		else
    		{
    			prenderLed(ROJO);
    			led = 1;
    		}

    	}
    }
    return 0 ;
}
