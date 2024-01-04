/*
 * TunelMde.c
 *
 *  Created on: 15 jul. 2021
 *      Author: d_lugano
 */
#include "TunelMde.h"
#include "TunelMde_funciones.h"
#include "../AlarmaMde/AlarmaMde.h"
#include "../AlarmaMde/AlarmaMde_funciones.h"
#include "../UARTMde/UARTMde.h"
#include "../UARTMde/UARTMde_funciones.h"


int flag_T0=0;

void TunelMde(void)
{
	static unsigned char estado=EMERGENCIA;

	int flag_alarma=1;

	switch(estado)
	{
		case VACIO:
					if( s_Sensor_entrada() )
					{
						m_Luz_verde_off();
						m_Luz_roja_on();
						m_Iniciar_T0_10s();
						estado=CIRCULANDO;
					}

			break;

		case CIRCULANDO:
						if(flag_T0 == 1)
						{
							m_Luz_roja_on();
							m_Luz_verde_off();
							flag_T0=0;

							init_AlarmaMde();
							init_UARTMde();
							estado=EMERGENCIA;
						}

						if( s_Sensor_salida() )
						{
							m_Luz_verde_on();
							m_Luz_roja_off();
							m_Stop_T0();
							estado=VACIO;
						}

			break;

		case EMERGENCIA:
						if (flag_alarma)
						{
							AlarmaMde();	//Se llama a la maquina de estado de la alarma
							UARTMde();	//Se llama a la maquina de estado de la uart
						}

						if( s_Boton_emergencia() || s_Sensor_salida() || flag_uart==1 )
						{
							m_Luz_verde_on();
							m_Luz_roja_off();
							m_Sirena_off();
							m_Stop_T1();

							estado=VACIO;
						}
			break;

		default:
				m_Luz_verde_off();
				m_Luz_roja_on();
				m_Stop_T0();
				m_Stop_T1();

				init_AlarmaMde();
				init_UARTMde();
				estado=EMERGENCIA;

	}
}

void init_TunelMde(void)
{
	init_AlarmaMde();
	init_UARTMde();

	m_Luz_roja_on();
	m_Luz_verde_off();
}
