/*
 * 7seg.c
 *
 *  Created on: 6 oct. 2021
 *      Author: d_lugano
 */

#include "PR_7seg.h"


void Display(uint32_t numero)
{
	int8_t i=0;

	if(numero>limite)
	{
		numero=limite;
	}

	for(i=N_DIGITOS; i>0; i--)
	{
		Digito_Display[i-1]=numero%10;
		numero/=10;
	}
}

