/*
 * DR_teclado.c
 *
 *  Created on: 16 sep. 2021
 *      Author: d_lugano
 */

#include "DR_teclado.h"

uint8_t Tecla;

void DriverTecladoSW(void)
{
	static uint8_t lastKey=NO_KEY;
	static uint8_t cont=0;
	uint8_t key;	//Tecla no presionada

	key=DriverTecladoMatricialHW();	//Devuelve la tecla que esta siendo presionada

	if( lastKey==key && cont < DEBOUNCE_COUNT)
	{
		cont++;	//Cuenta cuantos milisegundos esta presionada la tecla
		if(cont == DEBOUNCE_COUNT)
		{
			Tecla=key;	//Es decir, se esta presionando el boton. La variable Tecla es global y es la que va a estar devolviendo mi primitiva
		}
	}
	else if(key!= lastKey)
	{
		cont=0;
	}

	lastKey=key;
}

uint8_t DriverTecladoHW(void)
{
	if( !GetPIN(0,SW0) )
		return SW0;

	if( !GetPIN(0,SW1) )
		return SW1;

	if( !GetPIN(0,SW2) )
		return SW2;

	return NO_KEY;
}

uint8_t DriverTecladoMatricialHW(void)
{
	//Primero selecciono la columna 0:
	SetPIN(COL0,0);
	SetPIN(COL1,1);
	if ( !GetPIN(FILA0) )
		return SW1;
	if ( !GetPIN(FILA1) )
		return SW3;
	if ( !GetPIN(FILA2) )
		return SW2;

	//Ahora selecciono la columna 1:
	SetPIN(COL0,1);
	SetPIN(COL1,0);
	if ( !GetPIN(FILA0) )
		return SW4;
	if ( !GetPIN(FILA1) )
		return SW6;
	if ( !GetPIN(FILA2) )
		return SW5;

	return NO_KEY;
}

void InitTecladoMatricial ( void )
{
	//Deshabilito la funcion especial del pin 1.9:
	PINENABLE1 |= 1<<6;


	//FILAS (ENTRADAS): P0.8, P0.30 y P0.31
	SetDIR(FILA0,ENTRADA);
	SetDIR(FILA1,ENTRADA);
	SetDIR(FILA2,ENTRADA);

	//Pongo R_PULLUP en las entradas:
	SetPINMODE_IN(IOCON_INDEX_FILA0, 3 );
	SetPINMODE_IN(IOCON_INDEX_FILA1, 3 );
	SetPINMODE_IN(IOCON_INDEX_FILA2, 3 );

	//COLUMNAS (SALIDAS): P0.27 y P0.28
	SetDIR(COL0,SALIDA);
	SetDIR(COL1,SALIDA);

	//Deshabilito las 2 columnas:
	SetPIN(COL0,1);
	SetPIN(COL1,1);

}

