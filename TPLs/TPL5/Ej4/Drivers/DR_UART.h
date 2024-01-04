/*
 * DR_UART.h
 *
 *  Created on: 26 oct. 2021
 *      Author: d_lugano
 */

#ifndef DR_UART_H_
#define DR_UART_H_

#include "LPC845.h"

#define TAM_RX 64
#define TAM_TX 64
#define TAM_RX1 64
#define TAM_TX1 64

#define FREQ_PRINCIPAL	30000000U
#define BAUDRATE0		115200U
#define BAUDRATE1		115200U

void InitUART0(void);

extern uint32_t in_tx;
extern uint32_t out_tx;
extern uint32_t in_rx;
extern uint32_t out_rx;

extern uint8_t buf_tx[TAM_TX];
extern uint8_t buf_rx[TAM_RX];

void PushTx0 ( uint8_t dato);
int16_t PopTx0( void );
void PushRx0(uint8_t );
int16_t PopRx0(void);

#endif /* DR_UART_H_ */
