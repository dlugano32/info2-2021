/*
 * PR_UART.h
 *
 *  Created on: 28 oct. 2021
 *      Author: d_lugano
 */

#ifndef PR_UART_H_
#define PR_UART_H_

#include "LPC845.h"
#include "DR_UART.h"

int16_t RxSerie0 ( void );
int16_t RxSerie1 ( void );
void TxSerie0 ( uint8_t *);
void TxSerie1 ( uint8_t *);
void Tx0Byte ( uint8_t );

#endif /* PR_UART_H_ */
