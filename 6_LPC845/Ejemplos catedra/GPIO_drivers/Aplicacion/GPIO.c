/*
===============================================================================
 Name        : GPIO.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>
#include "LPC845.h"
#include "Leds.h"
#include "Tecla.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {

    // TODO: insert code here

	InitHw();



     uint8_t presionada = 0 ;
     uint8_t led_prendido = 0;

     apagarLed(VERDE);
     apagarLed(ROJO);
     apagarLed(AZUL);

    while(1) {

        if( !getKey() && !presionada )
        {
        	if( led_prendido )
        	{
        		led_prendido = 0;
        		apagarLed(VERDE);
        	}
        	else
        	{
        		led_prendido = 1;
        		prenderLed(VERDE);
        	}
        	presionada = 1;
        }
        else if( getKey() )
        {
        	presionada = 0;
        }

    }
    return 0 ;
}
