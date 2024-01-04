/*
 * AlarmaMde_funciones.h
 *
 *  Created on: 20 jul. 2021
 *      Author: d_lugano
 */

#ifndef ALARMAMDE_FUNCIONES_H_
#define ALARMAMDE_FUNCIONES_H_

extern int flag_T1;

//acciones
void m_Sirena_off(void);
void m_Sirena_on(void);
void m_Iniciar_T1_0_5s(void);
void m_Stop_T1 (void);
void handler1(void);

#endif /* ALARMAMDE_FUNCIONES_H_ */
