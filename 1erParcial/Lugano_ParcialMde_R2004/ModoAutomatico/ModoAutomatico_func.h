/*
 * ModoAutomatico_func.h
 *
 *  Created on: 24 jul. 2021
 *      Author: d_lugano
 */

#ifndef MODOAUTOMATICO_FUNC_H_
#define MODOAUTOMATICO_FUNC_H_

#define OFF 0
#define ON 1

#define PISO 0
#define P_CERRADA 1
#define P_ABIERTA 2
#define B_CERRAR 3
#define B_ABRIR 4
#define BARRERA 5
#define ABRIR 0
#define CERRAR 1

extern int flagTPA;
extern int flagT1;

//Eventos
unsigned char s_LlegoPiso(void);
unsigned char s_PuertaAbierta(void);
unsigned char s_PuertaCerrada(void);
unsigned char s_BotonCerrar(void);
unsigned char s_BotonAbrir(void);
unsigned char s_Barrera(void);

//Acciones
void m_MotorCerrarPuerta (unsigned char estado);
void m_MotorAbrirPuerta (unsigned char estado);
void m_IniciarT0_TPAseg(void);
void m_IniciarT1_10seg(void);
void m_StopT0(void);
void m_StopT1(void);
void handler0(void);
void handler1(void);

#endif /* MODOAUTOMATICO_FUNC_H_ */
