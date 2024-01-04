/*
 * DR_serie.c
 *
 *  Created on: 16 nov. 2021
 *      Author: d_lugano
 */

#include "DR_serie.h"

void UART0_IRQHandler(void)
{
	uint32_t status=USART0->STAT;	//Registro de status
	int32_t aux;

	if( status & (1<<0))	//Caso Rx
	{
		PushRx(USART0->RXDAT);
	}

	if( status & (1<<2))
	{
		aux=PopTx();

		if(aux!=-1)
		{
			USART0->TXDAT=aux;
		}
		else
		{
			USART0->INTENCLR|=(1<<2);	//Desactivo las interrupciones por tx cuando dejo de tener datos para transmitir
		}								//Fueron activas cuando se hizo PushTx
	}
}

uint8_t LeerBT(void)
{
	static uint8_t estado=ESPERANDO_TRAMA;
	static uint8_t cont=0;
	static int32_t dato;
	int32_t aux=-1;
	int8_t ret=-1;

	aux=PopRx();

	if(aux!=-1)
	{
		switch(estado)
		{
			case ESPERANDO_TRAMA:
				if(aux=='#')
				{
					estado=ESPERANDO_DATOS;
				}
			break;

			case ESPERANDO_DATOS:
				if(aux=='#')
					estado=ESPERANDO_DATOS;	//Error en trama

				if(aux=='$')
				{
					estado=ESPERANDO_TRAMA;	//Error en trama
				}

				if(aux!='#' && aux!='$')
				{
					dato=aux;
					cont++;

					if(dato=='D' && cont ==1)	//Secuencia "#D$"
					{
						estado=ESPERANDO_FIN;
						cont=0;
					}
					else if(dato=='R' && cont==1)
					{
						estado=ESPERANDO_DATOS;	//Todavia falta otro caracter
					}
					else if(dato=='H' && cont==2) //Secuencia "#RH$"
					{
						cont=0;
						estado=ESPERANDO_FIN;
					}
					else if(dato=='T' && cont==2)	//Secuencia "#RT$"
					{
						cont=0;
						estado=ESPERANDO_FIN;
					}
					else
					{
						cont=0;	//No llego ningun dato que me interese
						estado=ESPERAND_TRAMA;
					}
				}

				break;

			case ESPERANDO_FIN:
				if(aux=='$')
				{
					switch(dato)	//Dependiendo que trama llego
					{
						case 'D': ret=1;
							break;

						case 'H': ret=2;
							break;

						case 'T': ret=3;
							break;
					}

					estado=ESPERANDO_TRAMA;
				}
				break;
		}
	}

	return ret;
}

void PushTx(uint8_t dato)
{

}

void PushRx(uint8_t dato)
{

}

int16_t PopRx(void)
{
	return 0;
}

int16_t PopTx(void)
{
	return 0;
}
