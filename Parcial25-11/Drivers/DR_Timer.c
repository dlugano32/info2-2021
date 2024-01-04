/*
 * DR_Timer.c
 *
 *  Created on: 25 nov. 2021
 *      Author: d_lugano
 */


#include "DR_Timer.h"

void InitTimer(void)
{
	TIMER->CFG= (1<<0)
			|	(1<<1)
			| 	(0<<2)	//(Deshabilitado->Arranca a contar cuando el bit 1 esta en 1
			|	(34<<3)	//Aclaro que para que tenga espacio para 64 bits, el registro deberia ser de 3:8 ->2^6=64
			;	//Los bits reservados (9:31) se ponen en 0, la consigna pedia que no se pongan en 1

	TIMER->DIV= 30;	//Configurado para contar de a 1useg // 1/1us=1MHz -> 30MHz/1MHz=30 //No aclara si le resto 1

	TIMER->CFG&= ~ 1;	//Habilito el periferico
}
