/*
 * LedMde.h
 *
 *  Created on: 19 jul. 2021
 *      Author: d_lugano
 */

#ifndef LEDMDE_H_
#define LEDMDE_H_

#define PAUSA 0
#define LED_ON 1
#define LED_OFF 2

//flags
int flag_Led;
int flagT0;

//Mde
void init_LedMde(void);
void LedMde(void);

//Eventos
int s_Boton(void);

//Acciones
void m_LedON (void);
void m_LedOff(void);
void m_iniciarT0 (void);
void m_StopT0(void);
void handler0(void);

#endif /* LEDMDE_H_ */
