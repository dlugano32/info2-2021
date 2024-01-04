/*
 * ModoAutomatico_func.c
 *
 *  Created on: 24 jul. 2021
 *      Author: d_lugano
 */

#include "ModoAutomatico_func.h"

//Eventos
unsigned char s_LlegoPiso(void)
{
	return Entradas ( PISO );
}

unsigned char s_PuertaAbierta(void)
{
	return Entradas( P_ABIERTA);
}

unsigned char s_PuertaCerrada(void)
{
	return Entradas (P_CERRADA);
}

unsigned char s_BotonCerrar(void)
{
	return Entradas(B_CERRAR);
}

unsigned char s_BotonAbrir(void)
{
	return Entradas(B_ABRIR);
}

unsigned char s_Barrera(void)
{
	return Entradas(BARRERA);
}

//Acciones
void m_MotorCerrarPuerta (unsigned char estado)
{
	Salidas(CERRAR, estado);
}

void m_MotorAbrirPuerta (unsigned char estado)
{
	Salidas(ABRIR, estado);
}

void m_IniciarT0_TPAseg(void)
{
	unsigned int configurado;	//Aca definiria el valor configurado //Siempre menor a 10 seg

	TimerStart(0, configurado, handler0, SEG);
}

void m_IniciarT1_10seg(void)
{
	TimerStart(1, 10, handler1, SEG);
}

void m_StopT0(void)
{
	Timer_Stop(0);
}

void m_StopT1(void)
{
	Timer_Stop(1);
}

void handler0(void)
{
	flagTPA=1;
}

void handler1(void)
{
	flagT1=1;
}
