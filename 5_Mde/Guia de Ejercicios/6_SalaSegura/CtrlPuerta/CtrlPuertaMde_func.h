/*
 * CtrlPuertaMde_func.h
 *
 *  Created on: 21 jul. 2021
 *      Author: d_lugano
 */

#ifndef CTRLPUERTAMDE_FUNC_H_
#define CTRLPUERTAMDE_FUNC_H_

extern int flagT0;
extern int flagT1;
#define OFF 0
#define ON 1
#define NO_HUELLA 0
#define HUELLA_INVALIDA -1

//Eventos
int s_HuellaOK(void);
int s_HuellaInvalida(void);
int s_BotonAbrir(void);
int leerSensorHuella(void);

//Acciones
void m_Puerta(int estado);
void m_LuzRoja(int estado);
void m_EnviarID(void);
void Display(char *str);
void m_IniciarT0_5s(void);
void m_IniciarT1_10s(void);
void m_StopT0(void);
void m_StopT1(void);
void handler0(void);
void handler1(void);

#endif
