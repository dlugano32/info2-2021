/*
 * DR_Init.c
 *
 *  Created on: 8 ago. 2021
 *      Author: chor
 */

#include "DR_Init.h"
#include "LPC845.h"
#include "gpio.h"
#include "DR_IntExt.h"
#include "Leds.h"

void InitPLL(void);
void InitGPIO(void);

//Genero una funcion a partir de un puntero a función que llame a esa posición de memoria:
void (*fro_set_frec) (int ) = FRO_SET_FRECUENCY_FUNC;


void InitHw(void)
{

	InitPLL();
	InitIntExt();
	InitGPIO();

}




void InitGPIO(void)
{
	//Habilitación para los pines que manejan el LED RGB
	//Habilito el CLK para el GPIO1:
	SYSCON->SYSAHBCLKCTRL0 |= 1 << SYSCON_SYSAHBCLKCTRL0_GPIO1_SHIFT;

	//Pongo los pines 0, 1 y 2 del P1 como salida:

	SetDIR( LED_AZUL, SALIDA);
	SetDIR( LED_VERDE, SALIDA);
    SetDIR(	LED_ROJO, SALIDA);

	//Configuro las salidas con el modo open-drain deshabilitado
    SetPINMODE_OUT( IOCON_INDEX_PIO1_0, 0 );
    SetPINMODE_OUT( IOCON_INDEX_PIO1_1, 0 );
    SetPINMODE_OUT( IOCON_INDEX_PIO1_2, 0 );



}

void InitPLL(void)
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
}
