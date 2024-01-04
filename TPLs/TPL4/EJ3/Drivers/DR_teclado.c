/*
 * DR_teclado.c
 *
 *  Created on: 16 sep. 2021
 *      Author: d_lugano
 */

#include "DR_teclado.h"

uint8_t Tecla;

void InitTeclado(void)
{
	//Columnas (Salidas)
	SetDIR(COL1, SALIDA);
	SetDIR(COL2, SALIDA);
	SetDIR(COL3, SALIDA);

	SetPINMODE_OUT(IOCON_INDEX_PIO0_16, 0);
	SetPINMODE_OUT(IOCON_INDEX_PIO0_17, 0);
	SetPINMODE_OUT(IOCON_INDEX_PIO0_18, 0);

	//Filas (Entradas)

	SetDIR(FIL1, ENTRADA);
	SetDIR(FIL2, ENTRADA);
	SetDIR(FIL3, ENTRADA);
	SetDIR(FIL4, ENTRADA);

	SetPINMODE_IN (IOCON_INDEX_PIO0_19, 0x02);	//Configuro pull-up interno para todas las filas
	SetPINMODE_IN (IOCON_INDEX_PIO0_20, 0x02);
	SetPINMODE_IN (IOCON_INDEX_PIO0_21, 0x02);
	SetPINMODE_IN (IOCON_INDEX_PIO0_22, 0x02);

	//Arranco con todas las salidas en 1
	SetPIN(COL1, 1);
	SetPIN(COL2, 1);
	SetPIN(COL3, 1);
}

void DriverTecladoSW(void)
{
	static uint8_t lastKey=NO_KEY;
	static uint8_t cont=0;
	uint8_t key;	//Tecla no presionada


	key=DriverTecladoHW();	//Devuelve la tecla que esta siendo presionada

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
	//Habilito solo la columna 1
	SetPIN(COL1,0);
	SetPIN(COL2,1);
	SetPIN(COL3,1);

	if(!GetPIN(FIL1))
		return SW1;
	if(!GetPIN(FIL2))
		return SW4;
	if(!GetPIN(FIL3))
		return SW7;
	if(!GetPIN(FIL4))
		return SWast;

	//Habilito solo la columna 2
	SetPIN(COL1,1);
	SetPIN(COL2,0);
	SetPIN(COL3,1);

	if(!GetPIN(FIL1))
		return SW2;
	if(!GetPIN(FIL2))
		return SW5;
	if(!GetPIN(FIL3))
		return SW8;
	if(!GetPIN(FIL4))
		return SW0;

	//Habilito solo la columna 3
	SetPIN(COL1,1);
	SetPIN(COL2,1);
	SetPIN(COL3,0);

	if(!GetPIN(FIL1))
		return SW3;
	if(!GetPIN(FIL2))
		return SW6;
	if(!GetPIN(FIL3))
		return SW9;
	if(!GetPIN(FIL4))
		return SWhash;

	return NO_KEY;
}



