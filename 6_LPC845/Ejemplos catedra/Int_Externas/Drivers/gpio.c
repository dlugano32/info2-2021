/*
 * gpio.c
 *
 *  Created on: 5 ago. 2021
 *      Author: root
 */
#include "LPC845.h"


void SetPIN(uint32_t Puerto, uint32_t Pin, uint32_t Estado)
{
	if(Estado)
		GPIO->PIN[Puerto] |= (1 << Pin);
	else
		GPIO->PIN[Puerto] &= ~(1 << Pin);
}

void SetDIR(uint32_t Puerto, uint32_t Pin, uint32_t Direccion)
{
	if(Direccion)
		GPIO->DIR[Puerto] |= (1 << Pin);
	else
		GPIO->DIR[Puerto] &= ~(1 << Pin);
}

uint32_t GetPIN(uint32_t Puerto, uint32_t Pin)
{
	if(GPIO->PIN[Puerto] & (1 << Pin))
	{
		// Entro por 1
		return 1;
	}
	else
	{
		// Entro por 0
		return 0;
	}
}


void SetPINMODE_IN(uint32_t Pin, uint32_t Modo){
	IOCON->PIO[Pin] = ( (IOCON->PIO[Pin] & (~(0x18)) ) | ( Modo << IOCON_PIO_MODE_SHIFT));
}


void SetPINMODE_OUT(uint32_t Pin, uint32_t Modo){
    IOCON->PIO[Pin] = ((IOCON->PIO[Pin] & (~(0x400))) | (Modo << IOCON_PIO_OD_SHIFT));
}
