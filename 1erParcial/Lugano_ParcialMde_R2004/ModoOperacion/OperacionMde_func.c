/*
 * OperacionMde_func.c
 *
 *  Created on: 24 jul. 2021
 *      Author: d_lugano
 */


#include "OperacionMde_func.h"

unsigned char s_LlaveIncendio(void)
{
	return Entradas(INCENDIO);
}

unsigned char s_LlaveModo(void)
{
	return Entradas(AUT);
}
