/*
 * CtrlVelocidadMde_func.h
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */

#ifndef CTRLVELOCIDADMDE_FUNC_H_
#define CTRLVELOCIDADMDE_FUNC_H_

#define OFF 0
#define ON 1

//Eventos
int s_ArranqueParada(void);
int s_VelUP(void);
int s_VelDown(void);

//Acciones
void m_MotorVel1(int estado);
void m_MotorVel2(int estado);
void Display(char*);

#endif /* CTRLVELOCIDADMDE_FUNC_H_ */
