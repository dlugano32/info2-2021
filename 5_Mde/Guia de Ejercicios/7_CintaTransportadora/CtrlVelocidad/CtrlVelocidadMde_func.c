/*
 * CtrlVelocidadMde_func.c
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */


//Eventos
int s_ArranqueParada(void)
{
	return Entradas(0);
}

int s_VelUP(void)
{
	return Entradas(1);
}

int s_VelDown(void)
{
	return Entradas(2);
}

//Acciones
void m_MotorVel1(int estado)
{
	Relays(0,estado);
}

void m_MotorVel2(int estado)
{
	Relays(1,estado);
}
