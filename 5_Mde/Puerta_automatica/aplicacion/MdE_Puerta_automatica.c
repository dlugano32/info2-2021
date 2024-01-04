/*
 * MdE_Puerta_automatica.c
 *
 *  Created on: 4 jul. 2021
 *      Author: d_lugano
 */

/*
 * Eventos: s_
 * Acciones: m_
 *
 * */

#include "Mde_Puerta_automatica_funciones.h"
#include "MdE_Puerta_automatica.h"

void MdE_Puerta_automatica(void)
{
	static unsigned char estado;	//Tiene que ser estatica para que cada vez que se entre, guarde el ultimo valor que tenia

	switch (estado)
	{
		case CERRADO:
						if( s_Presencia() )
						{
							m_motor_abrir();
							m_iniciarT1_10s();
							estado=ABRIENDO;
						}

						break;

		case ABRIENDO:
						if(flag_timer1==1)
						{
							flag_timer1=0;
							m_motor_freno();
							m_DetenerT1();
							m_prender_chicharra();
							estado=EMERGENCIA;
						}
						else if( s_Puerta_abierta() )
						{
							m_motor_freno();
							m_deteneT1();
							m_iniciarT0_5s();
							estado=ABIERTO;
						}

						break;

		case ABIERTO:
						if( s_Presencia() )
						{
							m_iniciarT0_5s;
							estado=ABIERTO;
						}

						if( flag_timer0==1 && !s_Presencia() )
						{
							flag_timer0=0;
							m_motor_cerrar();
							m_iniciarT1_10s();
							estado=CERRANDO;
						}
						break;

		case CERRANDO:
						if( flag_timer1==1 )
						{
							flag_timer1=0;
							m_motor_freno();
							m_DetenerT1();
							m_prender_chicharra();
							estado=EMERGENCIA;
						}
						else if ( s_puerta_cerrada() )
						{
							m_motor_freno();
							m_DetenerT0();
							m_DetenerT1();
							estado=CERRADO;
						}
						break;

		case EMERGENCIA:
						if( s_button_OK() && s_puerta_cerrada() )
						{
							m_apagar_chicharra();
							estado=CERRADO;
						}

						break;

		default:
						m_motor_freno();
						m_DetenerT0();
						m_DetenerT1();
						m_prender_chicharra();
						flag_timer0=0;
						flag_timer1=0;
						estado=EMERGENCIA;
	}
}
