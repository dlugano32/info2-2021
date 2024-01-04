/*
 * Mde_Puerta_automatica_funciones.c
 *
 *  Created on: 4 jul. 2021
 *      Author: d_lugano
 */

#include "Mde_Puerta_automatica_funciones.h"

int flag_timer0=0;
int flag_timer1=0;

void Mde_init(void)
{
	m_motor_freno();
	m_DetenerT0();
	m_DetenerT1();
	flag_timer0=0;
	flag_timer1=0;
}

//Eventos o señales

//(uso mas de una entrada para lo mismo porque son los switchs que tiene el stick)

//IN 1: presencia y button_OK
//IN 2: finales de carreras puerta abierta y puerta cerrada

int s_presencia(void)
{
	int res;

	res=LeerEntrada(IN1);

	return res;
}

int s_puerta_abierta(void)
{
	int res;

	res=LeerEntrada(IN2);

	return res;
}

int s_puerta_cerrada (void)
{
	int res;

	res=LeerEntradas(IN2);

	return res;
}

int s_button_OK(void)
{
	int res;

	res=LeerEntrada(IN1);

	return res;
}

//Acciones

void m_motor_freno(void)
{
	LedOff( LED_VERDE );
	LedON( LED_AZUL );
}
void m_motor_abrir(void)
{
	LedOff( LED_AZUL );
	LedON( LED_VERDE );
}

void m_motor_cerrar(void)
{
	LedOff( LED_AZUL );
	LedON( LED_VERDE );
}

void m_prender_chicharra(void)
{
	LedON( LED_ROJO);
}

void m_apagar_chicharra(void)
{
	LedOff( LED_ROJO);
}

//Cuando los timer terminan de contar el tiempo propuesto, entran a las funciones callback
void callback0 (void)
{
	flag_timer0=1;
}

void callback1 (void)
{
	flag_timer1=1;
}

void m_iniciarT0_5s(void)
{
	TimerStart(0, 5, callback0, SEG);
}

void m_iniciarT1_10s(void)
{
	TimerStart(1, 10, callback1, SEG);
}

void m_DetenerT0(void)
{
	TimerStop(0);
}

void m_DetenerT1(void)
{
	TimerStop(1);
}

