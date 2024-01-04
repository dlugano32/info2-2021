/*
 * Inicializacion.c
 *
 *  Created on: 1 sep. 2021
 *      Author: chor
 */
#include "LPC845.h"

//Direccion de la funcion de ROM para setear la frecuencia del oscilador:
#define FRO_SET_FRECUENCY_FUNC (0x0F0026F5U)

//Genero una funcion a partir de un puntero a función que llame a esa posición de memoria:
void (*fro_set_frec) (int ) = FRO_SET_FRECUENCY_FUNC;


void InitHw (void)
{
	//Seteo la frecuencia del fro a 30MHz, llamando a la funcion de ROM:
	fro_set_frec(30000);

	//Selecciono la salida del FRO como el clk principal del sistema:

	SYSCON->FROOSCCTRL |= 1<<17;

	//Refresco el registro para habilitar el clk de 30MHz:
	SYSCON->FRODIRECTCLKUEN &= ~1;
	SYSCON->FRODIRECTCLKUEN |= 1;

	//Seteo FRO como el clkSrc del PLL:
	SYSCON->MAINCLKPLLSEL = 0;

	SYSCON->MAINCLKPLLUEN &= ~1;
	SYSCON->MAINCLKPLLUEN |= 1;

	//Seteo FRO como el clkSrc del PLL:
	SYSCON->SYSPLLCLKSEL = 0;

	SYSCON->SYSPLLCLKUEN &= ~1;
	SYSCON->SYSPLLCLKUEN |= 1;

	SYSCON->SYSAHBCLKDIV = 1;


	//Habilitación para los pines que manejan el LED RGB
	//Habilito el CLK para el GPIO1:
	SYSCON->SYSAHBCLKCTRL0 |= 1 << SYSCON_SYSAHBCLKCTRL0_GPIO1_SHIFT;

	//Pongo los pines 0, 1 y 2 del P1 como salida:
	GPIO->DIR[1] |= (0x01 << PIN_LEDR);
	GPIO->DIR[1] |= (0x01 << PIN_LEDG);
	GPIO->DIR[1] |= (0x01 << PIN_LEDB);

	//Configuro las salidas con el modo open-drain deshabilitado
	IOCON->PIO[ IOCON_INDEX_PIO1_0 ] &= ~(IOCON_PIO_OD_MASK);
	IOCON->PIO[ IOCON_INDEX_PIO1_1 ] &= ~(IOCON_PIO_OD_MASK);
	IOCON->PIO[ IOCON_INDEX_PIO1_2 ] &= ~(IOCON_PIO_OD_MASK);


}
