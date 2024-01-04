/*
 * EncoderMde_func.c
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */

#include "EncoderMde_func.h"

//Eventos
int s_HayLuz(void)
{
	return Entradas(3); 	//considero que el enconder esta conectado en la I/0 digital 3
}

//Acciones
void m_CalcularVel( int pulse)
{
	velocidad=pulse/10;	//La velocidad va a estar en cm/s
}

void m_IniciarT0_1s(void)
{
	TimerStart(0, 1, handler0, SEG);
}

void handler0(void)
{
	flagT0=1;
}
