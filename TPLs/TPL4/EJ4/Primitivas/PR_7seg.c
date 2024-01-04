/*
 * 7seg.c
 *
 *  Created on: 6 oct. 2021
 *      Author: d_lugano
 */

#include "PR_7seg.h"

int32_t num_disp=0;

void Display(uint32_t nro_display, uint32_t valor)
{
	int8_t i=0;

	if(valor>99)
		valor=99;

	num_disp=valor;


	if(nro_display==0)	//Contador
	{
		for(i=N_DIGITOS/2; i>0; i--)
		{
			Digito_Display[i-1]=valor%10;
			valor/=10;
		}
	}
	else if(nro_display==1)		//Timer
	{
		for(i=N_DIGITOS; i>N_DIGITOS/2; i--)
		{
				Digito_Display[i-1]=valor%10;
				valor/=10;
		}
	}
}

void Display_mas(uint32_t numero)
{
	num_disp+=numero;

	if(num_disp > 99)
	{
		num_disp=0;
	}

	Display(CONTADOR, num_disp);
}

void Display_menos(uint32_t numero)
{
	num_disp-=numero;

	if(num_disp < 0)
	{
		num_disp=99;
	}

	Display(CONTADOR, num_disp);
}
