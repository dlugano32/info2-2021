/*
 * AlarmaMde_func.h
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */

#ifndef ALARMAMDE_FUNC_H_
#define ALARMAMDE_FUNC_H_

extern int flagT0;

#define OFF 0
#define ON 1

//Eventos
int s_Barrera(void); //Entrada 0
int s_Peso(void);	//ADC
int s_PulsadorExt(void);	//Tecla 0

//Acciones
void m_AlarmaSilenciosa(int estado);
void m_AlarmaSonora(int estado);
void m_Camara(int estado);
void m_IniciarT0_10s(void);
void m_StopT0(void);
void handler0(void);

#endif /* ALARMAMDE_FUNC_H_ */
