/*
 * FreqMde_funciones.c
 *
 *  Created on: 19 jul. 2021
 *      Author: d_lugano
 */
#include "FreqMde.h"

//Mde
void init_FreqMde()
{
	time=1;
}

//Eventos

int s_Boton_LowFreq(void)
{
	return Entradas(1);
}

int s_Boton_HighFreq(void)
{
	return Entradas(2);
}
