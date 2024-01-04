/*
 * EncoderMde_func.h
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */

#ifndef ENCODERMDE_FUNC_H_
#define ENCODERMDE_FUNC_H_

extern int flagT0;
extern int velocidad;

//Eventos
int s_HayLuz(void);

//Acciones
void m_CalcularVel(int pulse);
void m_IniciarT0_1s(void);
void handler0(void);

#endif /* ENCODERMDE_FUNC_H_ */
