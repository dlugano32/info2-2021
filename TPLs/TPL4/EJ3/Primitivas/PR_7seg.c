/*
 * 7seg.c
 *
 *  Created on: 6 oct. 2021
 *      Author: d_lugano
 */

#include "PR_7seg.h"

int32_t num_disp=0;

void Display(uint32_t numero)
{
	int8_t i=0;

	if(numero>limite)
	{
		numero=limite;
	}

	num_disp=numero;

	for(i=N_DIGITOS; i>0; i--)
	{
		Digito_Display[i-1]=numero%10;
		numero/=10;
	}
}

void Display_mas(uint32_t numero)
{
	num_disp+=numero;

	if(num_disp > limite)
	{
		num_disp=0;
	}

	Display(num_disp);
}

void Display_menos(uint32_t numero)
{
	num_disp-=numero;

	if(num_disp < 0)
	{
		num_disp=limite;
	}

	Display(num_disp);
}
