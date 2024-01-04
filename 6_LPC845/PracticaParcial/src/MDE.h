/*
 * MDE.h
 *
 *  Created on: 17 nov. 2021
 *      Author: d_lugano
 */

#ifndef MDE_H_
#define MDE_H_

#define INICIO_TRAMA 0
#define RX_TEMP 1

extern uint8_t FlagT0;

void MdeRecepcion(uint8_t dato);
void HandlerT0(void);

#endif /* MDE_H_ */
