/*
 * PR_UART.c
 *
 *  Created on: 28 oct. 2021
 *      Author: d_lugano
 */
#include "PR_Uart.h"
#include "Leds.h"

int16_t RxSerie0(void)
{
	return PopRx0();
}

void TxSerie0(uint8_t* buffer)
{
	uint32_t i=0;

	for(i=0; *(buffer+i)!='\0'; i++)
		PushTx0(buffer[i]);
}

void Tx0Byte(uint8_t byte)
{
	PushTx0(byte);
}

int16_t LecturaSerie (void)
{
	static uint8_t estado = INICIO_TRAMA;
	static int16_t dato;
	int16_t aux = 0;
	int16_t lectura = -1;

	aux = PopRx0();

	if ( aux != -1)
	{
		switch (estado)
		{
			case INICIO_TRAMA:
				if ( aux == '#' )
				{
					estado = DATO;
				}
				break;

			case DATO:
				dato = aux;
				estado = FIN_TRAMA;
				break;

			case FIN_TRAMA:
				if ( aux == '$' )
				{
					if ( dato >= 1 && dato <= 3 )
					{
						lectura = dato;
					}

					estado = INICIO_TRAMA;
				}
				break;
		}
	}

	return lectura;
}
