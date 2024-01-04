/*
 * UARTMde.c
 *
 *  Created on: 17 jul. 2021
 *      Author: d_lugano
 */

#include "UARTMde.h"
#include "UARTMde_funciones.h"

static int cant_bytes=0;
static int dato=0;
static char buf[3];

void UARTMde(void)
{
	static unsigned char estado=WAIT_0XAA;

	dato=Recibir(0);	//Recibo un byte por la UART

	switch(estado)
	{
		case WAIT_0XAA:

			if( dato == 0xAA )
			{
				flag_uart=0;
				cant_bytes=0;
				estado=WAIT_DATO;
			}
			break;

		case WAIT_DATO:

			if( dato!= 0xAA && dato!=0xEE )
			{
				buf[cant_bytes]=dato;
				cant_bytes++;
				estado=WAIT_DATO;
			}

			if (dato == 0xAA)
			{
				cant_bytes=0;
				m_LimpiarBuf(buf);
				estado=WAIT_DATO;
			}

			if(dato == 0xEE)
			{
				cant_bytes=0;
				m_LimpiarBuf(buf);
				estado=WAIT_0XAA;
			}

			if(cant_bytes==3)
			{
				estado=WAIT_0XEE;
			}
			break;

		case  WAIT_0XEE:

			if(dato == 0xAA)
			{
				cant_bytes=0;
				m_LimpiarBuf(buf);
				estado=WAIT_DATO;
			}

			if(dato!=0xAA && dato!=0xEE)
			{
				cant_bytes=0;
				m_LimpiarBuf(buf);
				estado=WAIT_0XAA;
			}

			if(dato == 0xEE)
			{
				m_ValidarDato(buf);
				estado=WAIT_0XAA;
			}
			break;

		default:
			cant_bytes=0;
			m_LimpiarBuf(buf);
			estado=WAIT_0XAA;

	}
}

void init_UARTMde(void)
{
	m_LimpiarBuf(buf);
	cant_bytes=0;
	flag_uart=0;
}
