/*
 * DR_Init.c
 *
 *  Created on: 8 ago. 2021
 *      Author: chor
 */

#include "DR_Init.h"

//Genero una funcion a partir de un puntero a función que llame a esa posición de memoria:
void (*fro_set_frec) (int ) = FRO_SET_FRECUENCY_FUNC;


void InitHw(void)
{
	//Seteo la frecuencia del fro a 30MHz, llamando a la funcion de ROM:
	fro_set_frec(30000);

	//Selecciono la salida del FRO como el clk principal del sistema:
	FROOSCCTRL |= 1<<17;

	//Refresco el registro para habilitar el clk de 30MHz:
	FRODIRECTCLKUEN &= ~1;
	FRODIRECTCLKUEN |= 1;

	//Seteo FRO como el clkSrc del PLL:
	MAINCLKPLLSEL = 0;

	MAINCLKPLLUEN &= ~1;
	MAINCLKPLLUEN |= 1;

	//Seteo FRO como el clkSrc del PLL:
	SYSPLLCLKSEL = 0;

	SYSPLLCLKUEN &= ~1;
	SYSPLLCLKUEN |= 1;

	SYSAHBCLKDIV = 1;

	//Habilito el CLK para el GPIO1:
	SYSAHBCLKCTRL0 |= 1 << BIT_GPIO1;

	//Pongo los pines 0, 1 y 2 del P1 como salida:
	GPIO1DIR |= 0;
	GPIO1DIR |= 1;
	GPIO1DIR |= 2;

}
