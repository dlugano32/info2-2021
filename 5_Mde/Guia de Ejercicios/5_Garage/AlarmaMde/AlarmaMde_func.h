/*
 * AlarmaMde_func.h
 *
 *  Created on: 20 jul. 2021
 *      Author: d_lugano
 */

#ifndef ALARMAMDE_FUNC_H_
#define ALARMAMDE_FUNC_H_

extern int flagT0;

void m_SirenaON(void);
void m_SirenaOff(void);
void m_IniciarT0_10s (void);
void m_StopT0(void);
void handlerT0(void);

#endif /* ALARMAMDE_FUNC_H_ */
