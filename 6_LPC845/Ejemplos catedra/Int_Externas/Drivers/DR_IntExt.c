/*
 * DR_IntExt.c
 *
 *  Created on: 1 sep. 2021
 *      Author: marup
 */

#include "DR_IntExt.h"

uint8_t interrupcion = 0;

#define FUENTE_INT_0	0

void InitIntExt(void)
{
	//Fuente de interrupcion! Pulsador de la placa P0.4
	//Fuente de interrupcion 0
	SYSCON->PINTSEL[ FUENTE_INT_0 ] = 4;

	//Habilito el clk del perisferico PIN INTERRUPT
	SYSCON->SYSAHBCLKCTRL0 |= 1 << 28;

	// Flanco descendente habilitado
	INT_EXT->ISEL &= ~(0x01 << FUENTE_INT_0); //Habilitamos Flanco
	INT_EXT->IENR &= ~(0x01 << FUENTE_INT_0); //Deshabilitamos Ascendente
	INT_EXT->IENF |= (0x01 << FUENTE_INT_0); //Habilitamos Descendente

//	INT_EXT->ISEL &= ~( 0x01 < < 0);
//	INT_EXT->IENR |= ( 0x01 << 0);
//	INT_EXT->IENR &= ~( 0x01 << 0);

	INT_EXT->IST |= (0x01 << FUENTE_INT_0);

	//Habilito NVIC
	ISER0 |= (0x01 << 24);

}

void PININT0_IRQHandler(void)
{
	INT_EXT->IST |= (0x01 << FUENTE_INT_0);

	//Mi código de la función!
	//APAGAR UN MOTOR CRITICO
	//CUALQUIER ACCION CRITICA
	interrupcion = 1;
}
