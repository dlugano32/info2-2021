/*
 * DR_UART.h
 *
 *  Created on: 26 oct. 2021
 *      Author: d_lugano
 */

#ifndef DR_UART_H_
#define DR_UART_H_

#include "LPC845.h"

#define TAM_RX 256
#define TAM_TX 256
#define TAM_RX1 256
#define TAM_TX1 256

#define FREQ_PRINCIPAL	30000000U
#define BAUDRATE0		115200U
#define BAUDRATE1		115200U

void InitUART0(void);
void InitUART1(void);


extern uint32_t in_tx;
extern uint32_t out_tx;
extern uint32_t in_rx;
extern uint32_t out_rx;

extern uint8_t buf_tx[TAM_TX];
extern uint8_t buf_rx[TAM_RX];

extern uint32_t in_tx1;
extern uint32_t out_tx1;
extern uint32_t in_rx1;
extern uint32_t out_rx1;

extern uint8_t buf_tx1[TAM_TX1];
extern uint8_t buf_rx1[TAM_RX1];



extern uint8_t datoRx;
extern uint8_t flagRx;
extern uint8_t flagTx;



void PushTx0(uint8_t );
void PushRx0(uint8_t );
int16_t PopRx0(void);
int16_t PopTx0(void);

void PushTx1 ( uint8_t dato);
int16_t PopTx1( void );
void PushRx1(uint8_t );
int16_t PopRx1(void);

#endif /* DR_UART_H_ */
