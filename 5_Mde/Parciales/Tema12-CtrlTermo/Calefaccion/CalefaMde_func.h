/*
 * CalefaMde_func.h
 *
 *  Created on: 23 jul. 2021
 *      Author: d_lugano
 */

#ifndef CALEFAMDE_FUNC_H_
#define CALEFAMDE_FUNC_H_

extern int flagT0;

//Eventos
uint8_t TempOperacion ( void );
uint8_t PulsadorReset ( void );

//Acciones
void Calentador (uint8_t estado);
void m_IniciarT0_30min (void);
void m_StopT0(void);
void handler0(void);

#endif /* CALEFAMDE_FUNC_H_ */

