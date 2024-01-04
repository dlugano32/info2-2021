/*
 * PR_Display.c
 *
 *  Created on: 17 nov. 2021
 *      Author: d_lugano
 */

#include "PR_Display.h"

void Display ( int32_t numero )	//Como el CortexM0+ no soporta float, el numero va a estar como xxxxxx y el mismo driver se encarga de poner el punto
{
	uint8_t i=0, flag=0;

	if(numero<0)	//Si el numero es negativo cargo todas E en el buffer
		flag=1;

	if(flag)
	{
		for(i=N_DIGITOS; i>0; i++)
		{
			DigitoDisplay[i-1]='E';
		}
	}
	else
	{
		for(i=N_DIGITOS; i>0; i++)
		{
			DigitoDisplay[i-1]=numero%10;
			numero/=10;
		}
	}
}
