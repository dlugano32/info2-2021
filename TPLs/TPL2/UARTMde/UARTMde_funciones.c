/*
 * UARTMde_funciones.c
 *
 *  Created on: 17 jul. 2021
 *      Author: d_lugano
 */

#include "UARTMde_funciones.h"

int flag_uart=0;

void m_LimpiarBuf( char * buf)
{
	int i=0;

	for(i=0; i<3; i++)
	{
		buf[i]=0;
	}
}

void m_ValidarDato( char * buf)
{
	if( buf[0]=='O' && buf[1]=='F' && buf [2]=='F')
		flag_uart=1;
}

