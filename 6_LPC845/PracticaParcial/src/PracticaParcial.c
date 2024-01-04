#include "LPC845.h"
#include "DR_USARTs.h"
#include "PR_USARTs.h"
#include "MDE.h"
#include "DR_Periferico.h"

void main ( void )
{
	int8_t datoUART0, datoUART1, datoUART2;

	InitPerifericoNuevo();	//Punto 1
	InitSystick_Displays();	//No hace falta desarrollarla
	InitUARTs();			//Solo desarrollar la UART2

	while ( 1 )
	{
		datoUART1 = RecibirDatoUART1();

		if ( datoUART1 != -1 )
			MdeRecepcion(datoUART1);

		TimerEvent();
	}
}

