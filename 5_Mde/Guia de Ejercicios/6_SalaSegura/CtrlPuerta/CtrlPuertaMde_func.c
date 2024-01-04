/*
 * CtrlPuertaMde_func.c
 *
 *  Created on: 21 jul. 2021
 *      Author: d_lugano
 */


#include "CtrlPuertaMde_func.h"

static int huella=0;

//Eventos
int s_HuellaOK(void)
{
	int ret=0;

	huella=leerSensorHuella();

	if(huella==NO_HUELLA || huella==HUELLA_INVALIDA)
		ret=0;
	else
		ret=1;

	return ret;
}

int s_HuellaInvalida(void)
{
	int ret=0;

	huella=leerSensorHuella();

	if(huella == HUELLA_INVALIDA)
		ret=1;
	else
		ret=0;

	return ret;
}

int s_BotonAbrir(void)
{
	return Entradas(0);
}

//Acciones
void m_Puerta(int estado)
{
	Relays(0, estado);
}

void m_LuzRoja(int estado)
{
	LedsRGB(1, estado);
}

void m_EnviarID(void)
{
	Transmitir(UART0, huella, 1);
}

void m_IniciarT0_5s(void)
{
	TimerStart(0, 5, handler0, SEG);
}

void m_IniciarT1_10s(void)
{
	TimerStart(1, 10, hanlder1, SEG);
}

void m_StopT0(void)
{
	TimerStop(0);
}

void m_StopT1(void)
{
	TimerStop(1);
}

void handler0(void)
{
	flagT0=0;
}

void handler1(void)
{
	flagT1=0;
}
