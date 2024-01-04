/*
 * AlarmaMde_func.c
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */
#include "AlarmaMde_func.h"

//Eventos
int s_Barrera(void) //Entrada 0
{
	return Entradas(0);
}

int s_Peso(void)	//ADC
{
	int cuentas=0;

	cuentas=Potencimetro(); //Aca se harian cuentas que desconocemos

	return cuentas;
}

int s_PulsadorExt(void)	//Tecla 0
{
	return GetKey(0);
}

//Acciones
void m_AlarmaSilenciosa(int estado)	//SD0
{
	Relays(0, estado);
}

void m_AlarmaSonora(int estado)
{
	Relays(1, estado);

void m_Camara(int estado)
{
	Relays(3, estado);
}

void m_IniciarT0_10s(void)
{
	TimerStart(0,10, handler0, SEG);
}

void m_StopT0(void)
{
	TimerStop(0);
}

void handler0(void)
{
	flagT0=1;
}
