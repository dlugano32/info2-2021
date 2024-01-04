/*
 * PR_UART.c
 *
 *  Created on: 28 oct. 2021
 *      Author: d_lugano
 */
#include "PR_UART.h"

void TransmitirSerie(uint8_t* buffer, uint32_t size)
{
	uint32_t i=0;

	for(i=0; i<size; i++)
		PushTx(buffer[i]);
}

void TransmitirByte(uint8_t byte)
{
	PushTx(byte);
}

int16_t RecibirSerie(void)
{
	return PopRx();
}
