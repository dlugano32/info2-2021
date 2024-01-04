/*
 * funciones.c
 *
 *  Created on: 12 ago. 2021
 *      Author: d_lugano
 */


#include "funciones.h"

void SetearBit (unsigned long int * var, unsigned char nbit)
{
	*var|= (1<<nbit);
}

void BajarBit (unsigned long int *var, unsigned char nbit)
{
	*var&= ~(1<<nbit);
}

void ToggleBit (unsigned long int *var, unsigned char nbit)
{
	*var^= (1<<nbit);
}

void SetBit (unsigned long int *var, unsigned char nbit, unsigned char state)
{
	if(state == 0)
		BajarBit(var, nbit);
	else if(state == 1)
		SetearBit(var, nbit);
}
