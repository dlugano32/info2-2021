/*
 * CtrlSalaMde.h
 *
 *  Created on: 22 jul. 2021
 *      Author: d_lugano
 */

#ifndef CTRLSALAMDE_H_
#define CTRLSALAMDE_H_

extern int dato;

#define REPOSO 0
#define ABIERTO 1
#define CERRADO_P 2
#define ALARMA_TIEMPO 3
#define ALARMA_TEMP 4
#define TIEMPO_EXTENDIDO 5
#define ALARMA_SUPERVISOR 6

void CtrlSalaMde(void);
void init_CtrlSalaMde(void);

#endif /* CTRLSALAMDE_H_ */
