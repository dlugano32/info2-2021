/*
 * UART.h
 *
 *  Created on: 19 nov. 2021
 *      Author: d_lugano
 */

#ifndef DR_UART_H_
#define DR_UART_H_

#include "LPC845.h"

#define TAM 32


extern uint8_t indiceTx_in;
extern uint8_t indiceTx_out;
extern uint8_t indiceRx_in;
extern uint8_t indiceRx_out;
extern uint8_t bufferRx[TAM];
extern uint8_t bufferTx[TAM];

void InitUART1(void);

void PushRx(uint8_t dato);
uint8_t PopRx(void);
uint8_t PopTx(void);
void PushTx(uint8_t dato);

#endif /* DR_UART_H_ */
