/*
 * CtrlAccesoMde_func.h
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */

#ifndef CTRLACCESOMDE_FUNC_H_
#define CTRLACCESOMDE_FUNC_H_

extern int flagT0;

void m_IniciarT0_10s(void);
void m_stopT0(void);
void handler0 (void);

int verificar(int id);
#endif /* CTRLACCESOMDE_FUNC_H_ */
