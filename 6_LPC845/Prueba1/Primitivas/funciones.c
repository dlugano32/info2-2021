/*
 * funciones.c
 *
 *  Created on: 19 ago. 2021
 *      Author: d_lugano
 */

#include "LPC845.h"

void SetearBit (uint32_t * var, uint8_t nbit)
{
	*var|= (1<<nbit);
}

void BajarBit (uint32_t *var, uint8_t nbit)
{
	*var&= ~(1<<nbit);
}

void ToggleBit (uint32_t *var, uint8_t nbit)
{
	*var^= (1<<nbit);
}

void SetBit (uint32_t *var, uint8_t nbit, uint8_t state)
{
	if(state == 0)
		BajarBit(var, nbit);
	else if(state == 1)
		SetearBit(var, nbit);
}
