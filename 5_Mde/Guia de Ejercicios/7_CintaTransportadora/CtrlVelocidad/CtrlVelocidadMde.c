/*
 * CtrlVelocidadMde.c
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */

#include "CtrlVelocidadMde.h"
#include "CtrlVelocidadMde_func.h"
#include "EncoderMde_func.h"

void CtrlVelocidadMde(void)
{
	static unsigned char estado=DETENIDO;

	switch (estado)
	{
		case DETENIDO:
			if(s_ArranqueParada())
			{
				m_MotorVel1(ON);
				Display(velocidad);
				estado=VEL1;
			}
			break;

		case VEL1:
			if(s_VelUP())
			{
				m_MotorVel1(OFF);
				m_MotorVel2(ON);
				Display(velocidad);
				estado=VEL2;
			}

			if(s_ArranqueParada())
			{
				m_MotorVel1(OFF);
				Display("Detenido");
				estado=DETENIDO;
			}

			if(velocidad==0)
			{
				m_MotorVel1(OFF);
				m_MotorVel2(OFF);
				Display("Emergencia");
				estado=EMERGENCIA;
			}
			break;

		case VEL2:
			if(s_VelDown())
			{
				m_MotorVel1(ON);
				m_MotorVel2(OFF);
				Display(velocidad);
				estado=VEL1;
			}

			if(s_ArranqueParada())
			{
				m_MotorVel2(OFF);
				Display("Detenido");
				estado=DETENIDO;
			}

			if(velocidad==0)
			{
				m_MotorVel1(OFF);
				m_MotorVel2(OFF);
				Display("Emergencia");
				estado=EMERGENCIA;
			}

			break;

		case EMERGENCIA:
			if(s_ArranqueParada())
			{
				Display("Detenido");
				estado=DETENIDO;
			}
			break;

		default:
			m_MotorVel1(OFF);
			m_MotorVel2(OFF);
			Display("Emergencia");
			estado=EMERGENCIA;

	}
}

void init_CtrlVelocidadMde(void)
{
	m_MotorVel1(OFF);
	m_MotorVel2(OFF);
	Display("Detenido");
}
