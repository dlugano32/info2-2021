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
void InitUART1(void);

extern uint32_t in_tx1;
extern uint32_t out_tx1;
extern uint32_t in_rx1;
extern uint32_t out_rx1;

extern uint8_t buf_tx1[TAM_TX1];
extern uint8_t buf_rx1[TAM_RX1];

void PushTx1 ( uint8_t dato);
int16_t PopTx1( void );
void PushRx1(uint8_t );
int16_t PopRx1(void);

#endif /* DR_UART_H_ */
