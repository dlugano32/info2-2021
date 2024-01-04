/*
 * CalefaMde_func.c
 *
 *  Created on: 23 jul. 2021
 *      Author: d_lugano
 */


#include "CalefaMde_func.h"

//Eventos
uint8_t TempOperacion ( void )
{

}

uint8_t PulsadorReset ( void )
{
	return Entradas(0);
}

//Acciones
void Calentador (uint8_t estado)
{
	Relays(0, estado);
}

void m_IniciarT0_30min (void)
{
	TimerStart(0, 30, handler0, MIN);
}

void m_StopT0(void)
{
	TimerStop(0);
}

void handler0(void)
{
	flagT0=1;
}
