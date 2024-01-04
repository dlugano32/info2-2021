/*
 * TunelMde_funciones.h
 *
 *  Created on: 20 jul. 2021
 *      Author: d_lugano
 */

#ifndef TUNELMDE_FUNCIONES_H_
#define TUNELMDE_FUNCIONES_H_

extern int flag_T0;

//Eventos
int s_Sensor_entrada (void);
int s_Sensor_salida (void);
int s_Boton_emergencia (void);

//Acciones
void m_Luz_verde_off(void);
void m_Luz_roja_off(void);
void m_Luz_verde_on(void);
void m_Luz_roja_on(void);
void m_Iniciar_T0_10s(void);
void m_Stop_T0 (void);
void handler0(void);

#endif /* TUNELMDE_FUNCIONES_H_ */
