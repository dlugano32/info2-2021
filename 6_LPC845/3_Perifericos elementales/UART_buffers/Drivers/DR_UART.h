/*
 * DR_UART.h
 *
 *  Created on: 26 oct. 2021
 *      Author: d_lugano
 */

#ifndef DR_UART_H_
#define DR_UART_H_

#include "LPC845.h"

#define TAM_RX 32
#define TAM_TX 32

#define FREQ_PRINCIPAL	30000000U
#define BAUDRATE		9600U

extern uint32_t in_tx;
extern uint32_t out_tx;
extern uint32_t in_rx;
extern uint32_t out_rx;

extern uint8_t buf_tx[TAM_TX];
extern uint8_t buf_rx[TAM_RX];

void InitUART0(void);
void UART0_IRQHandler (void);

void PushTx(uint8_t );
void PushRx(uint8_t );
int16_t PopRx(void);
int16_t PopTx(void);

#endif /* DR_UART_H_ */
