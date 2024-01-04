/*
 * DR_Teclado.c
 *
 *  Created on: 16 nov. 2021
 *      Author: d_lugano
 */

#include "DR_Teclado.h"

uint8_t TeclaPresionada=NO_KEY;

void BarridoTeclado(void)
{
	uint8_t key=TecladoHw();

	TeclaPresionada=TecladoSw(key);	//Aca se tiene en cuenta el debounce
	//La tecla presionada se guarda en una variable global y solo se reinicia cuando se lee
}

void TecladoHw(void)
{
	SetPIN(COL0, 0);
	SetPIN(COL1, 1);

	if(!GetPIN(FIL0))
		return MAXT;
	if(!GetPIN(FIL1))
		return MAXH;

	SetPIN(COL0,1);
	SetPIN(COL1,0);

	if(!GetPIN(FIL0))
		return MINT;
	if(!GetPIN(FIL1))
		return MINH;
	if(!GetPIN(FIL2))
		return RESET;

	return NO_KEY;

}
