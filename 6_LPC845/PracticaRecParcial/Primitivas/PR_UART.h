/*
 * PR_UART.h
 *
 *  Created on: 19 nov. 2021
 *      Author: d_lugano
 */

#ifndef PR_UART_H_
#define PR_UART_H_

#include "LPC845.h"
#include "DR_UART.h"

uint8_t RxLGT(void);
void TxLGT(uint8_t *buffer);

#endif /* PR_UART_H_ */
