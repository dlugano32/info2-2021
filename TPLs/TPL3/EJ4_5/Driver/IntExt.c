/*
 * IntExt.c
 *
 *  Created on: 9 sep. 2021
 *      Author: d_lugano
 */

#include "IntExt.h"

uint8_t flagAscendente=0;
uint8_t flagDescendente=0;

uint8_t i=1;

void InitIntExt(void)
{
	SYSCON->PINTSEL[ FUENTE_INT_0 ]=4;	//Le configuro la interrupcion 0 para el pin 4 del puerto 0, que seria el boton del stick
	SYSCON->PINTSEL[ FUENTE_INT_1 ]=6;

	SYSCON->SYSAHBCLKCTRL0|= (0x01<<28); 	//Habilito el clock del bloque de interrupciones de pines

	//Boton del stick
	INT_EXT->ISEL&= ~(0x01<<FUENTE_INT_0);	//Habilito el flanco
	INT_EXT->IENR|= (0x01<<FUENTE_INT_0);	//Habilito la deteccion por flanco ascendente
	INT_EXT->IENF&= ~(0x01<<FUENTE_INT_0);	//Deshabilito la deteccion por flanco descendente

	//Entrada de la señal
	INT_EXT->ISEL&= ~(0x01<<FUENTE_INT_1);	//Habilito el flanco
	INT_EXT->IENR|= (0x01<<FUENTE_INT_1);	//Habilito la deteccion por flanco ascendente
	INT_EXT->IENF|= (0x01<<FUENTE_INT_1);	//Habilito la deteccion por flanco descendente

	INT_EXT->IST|= (0x01<<FUENTE_INT_0);	//Cuando se activa la interrupcion hay que escribir un 1 en este registro para limpiar el pedido de interrupcion
	INT_EXT->IST|= (0x01<<FUENTE_INT_1);

	ISER0|= (0x01<<24); //Habilito el NVIC
	ISER0|= (0x01<<25); //Habilito el NVIC

}

void PININT0_IRQHandler(void)	//Interrupcion del boton
{
	INT_EXT->IST|= (0x01<<FUENTE_INT_0);	//Cuando se activa la interrupcion hay que escribir un 1 en este registro para limpiar el pedido de interrupcion

	i++;

	if(i==10)
		i=1;
}

void PININT1_IRQHandler(void)
{
	INT_EXT->IST|= (0x01<<FUENTE_INT_1);

	if( GetPIN(0,6) == 1)
	{
		flagAscendente=1;
		flagDescendente=0;
	}
	else if(GetPIN(0,6) == 0)
	{
		flagAscendente=0;
		flagDescendente=1;
	}

}

