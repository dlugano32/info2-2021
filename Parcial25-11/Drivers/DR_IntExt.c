/*
 * DR_IntExt.c
 *
 *  Created on: 25 nov. 2021
 *      Author: d_lugano
 */

#include "DR_IntExt.h"
#include "DR_Timer.h"
#include "DR_Sensor.h"

void InitIntExt(void)
{
	SYSCON_>SYSAHBCLKCTRL0|=(1<<28);	//Habilito el CLK de las interrupciones de pines

	//CONFIGURO PININTSEL0

	SYSCON->PINTSEL0&= ~(0x1F);	//Limpio el registro
	SYSCON->PINTSEL0|= (34<<0);	//Le configuro el PIO1.3

	PININTERRUPT->ISEL&= ~(1<<0);	//Configuro la interrupcion por flanco
	PININTERRUPT->IENR&= ~(1<<0);	//Deshabilito el flanco ascedente
	PININTERRUPT->IENF|= (1<<0);	//Habilito el flanco descedente

	PININTERRUPT->IST|=(1<<0);	//Escribo un 1 para limpiar el flag de interrupcion

	ISER0|=(1<<24);	//Habilito en el NVIC la interrupcion PININT0

}

void PININT0_IRQHandler(void)
{
	PININTERRUPT->IST|=(1<<0);	//Escribo un 1 para limpiar el flag de interrupcion

	DR_SensorDistancia(TIMER->VALUE);

	TIMER->VALUE=0;	//Reseteo el timer por las dudas que no lo haga el periferico automaticamente
}
