/*
 * DR_Periferico.c
 *
 *  Created on: 18 nov. 2021
 *      Author: d_lugano
 */

#include "DR_Periferico.h"

#define SQRCFG (* ((uint32_t *) 0x400BC004u) )

void InitPerifericoNuevo(void)
{
	SQRCFG=	 (1<<0)
			|(1<<1)
			|(90<<3)
			|(25<<10)
			|(30000<<15);	//DIV=30000 a 30MHz para que la frecuencia sea 1000 Hz

	ISER0|=(1<<23);	//Habilitacion en el NVIC

	SQRCFG&= ~1;	//Habilito el periferico una vez que esta todo configurado

}

/*Ejercicio 2*/

void Periferico_Handler(void)
{
	if(  (SQRCFG & (1<<2)) == 0 )	//Estado bajo
	{
		BarridoDisplays();
	}

}
