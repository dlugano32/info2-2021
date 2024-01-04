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

	if(numero>99)
	{
		numero=99;
	}

	num_disp=numero;

	for(i=N_DIGITOS; i>0; i--)
	{
		Digito_Display[i-1]=numero%10;
		numero/=10;
	}
}

void Display_mas(void)
{
	num_disp++;

	if(num_disp > 99)
	{
		num_disp=0;
	}

	Display(num_disp);
}

void Display_menos(void)
{
	num_disp--;

	if(num_disp < 0)
	{
		num_disp=99;
	}

	Display(num_disp);
}
