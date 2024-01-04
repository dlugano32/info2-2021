/*
 * DR_serie.h
 *
 *  Created on: 16 nov. 2021
 *      Author: d_lugano
 */

#ifndef DR_SERIE_H_
#define DR_SERIE_H_

#include "LPC845.h"

#define ESPERANDO_TRAMA 1
#define ESPERANDO_DATOS 2
#define ESPERANDO_FIN 3

uint8_t LeerBT(void);

void PushTx(uint8_t );
void PushRx(uint8_t );
int16_t PopRx(void);
int16_t PopTx(void);

#endif /* DR_SERIE_H_ */
