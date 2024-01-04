/*
 * TunelMde_funciones.c
 *
 *  Created on: 15 jul. 2021
 *      Author: d_lugano
 */

#include "TunelMde_funciones.h"

//Eventos
int s_Sensor_entrada (void)
{
	return Entradas(0);
}

int s_Sensor_salida (void)
{
	return Entradas(1);
}
int s_Boton_emergencia (void)
{
	return Entradas(2);
}

//Acciones
void m_Luz_verde_off(void)
{
	LedsRGB( 2, 0);	// Apaga el led verde
}

void m_Luz_roja_off(void)
{
	LedsRGB( 1, 0);	// Apaga el led verde
}

void m_Luz_verde_on(void)
{
	LedsRGB( 2, 1);
}

void m_Luz_roja_on(void)
{
	LedsRGB( 1, 1);
}

void m_Iniciar_T0_10s(void)
{
	TimerStart( 0, 10, handler0, SEG);
}

void m_Stop_T0 (void)
{
	TimerStop(0);
}

void handler0(void)
{
	flag_T0=1;
}


