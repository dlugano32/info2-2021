/*
 * Mde_Puerta_automatica_funciones.h
 *
 *  Created on: 4 jul. 2021
 *      Author: d_lugano
 */

#ifndef MDE_PUERTA_AUTOMATICA_FUNCIONES_H_
#define MDE_PUERTA_AUTOMATICA_FUNCIONES_H_

extern int flag_timer0;
extern int flag_timer1;	//Es para que se pueda usar en otras funciones de otros programas asociadas (definida de forma global)


//Eventos
int s_presencia(void);
int s_puerta_abierta(void);
int s_puerta_cerrada (void);
int s_button_OK(void);

//Acciones
void m_motor_freno(void);
void m_motor_abrir(void);
void m_motor_cerrar(void);
void m_prender_chicharra(void);
void m_apagar_chicharra(void);
void m_iniciarT0_5s(void);
void m_iniciarT1_10s(void);
void m_DetenerT0(void);
void m_DetenerT1(void);

#endif /* MDE_PUERTA_AUTOMATICA_FUNCIONES_H_ */
