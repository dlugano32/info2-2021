/*
 * funciones.c
 *
 *  Created on: 19 ago. 2021
 *      Author: d_lugano
 */

#include "Registros.h"

void SetDIR (uint32_t Puerto, uint32_t Pin, uint32_t Direccion)	//Setea los pines como Entradas o salidas 0=entrada - 1=salida
{
	if(Direccion == 1)
		GPIO->DIR[Puerto] |= (1<<Pin);
	else
		GPIO->DIR[Puerto] &= ~(1<<Pin);
}

void SetPIN (uint32_t Puerto, uint32_t Pin, uint32_t Estado)	//Setea el Estado (0 o 1) indicado en el pin especificado
{
	if(Estado == 1)
		GPIO->PIN[Puerto] |= (1<<Pin);	//Set
	else
		GPIO->PIN[Puerto] &= ~(1<<Pin);	//Clear
}

uint32_t GetPIN (uint32_t Puerto, uint32_t Pin) //Devuelve el valor del pin especificado
{
	uint8_t ret=0;
	ret= GPIO->PIN[Puerto] | (1<<Pin);
	return ret;
}

void SetPINMODE_IN (uint32_t Pin, uint32_t Modo) 	//0=Pull-Down o 1=Pull-Up
{
	if(Modo == 1)
		IOCON->PIO[Pin]=  (IOCON->PIO[Pin] & (~(0x18))) | ((0x2) << IOCON_PIO_MODE_SHIFT); //0x2 Pull-up resistor enabled.
	else
		IOCON->PIO[Pin]=  (IOCON->PIO[Pin] & (~(0x18))) | ((0x1)<< IOCON_PIO_MODE_SHIFT);
}

void SetPINMODE_OUT (uint32_t Pin, uint32_t Modo)	//Drain Mode
{
	if(Modo == 1)
		IOCON->PIO[Pin] |= (1<<IOCON_PIO_OD_SHIFT);
	else
		IOCON->PIO[Pin] &= ~(1<<IOCON_PIO_OD_SHIFT);
}
