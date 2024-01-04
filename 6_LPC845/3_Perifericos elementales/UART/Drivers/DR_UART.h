/*
 * DR_UART.h
 *
 *  Created on: 26 oct. 2021
 *      Author: d_lugano
 */

#ifndef DR_UART_H_
#define DR_UART_H_

#include "LPC845.h"

#define FREQ_PRINCIPAL	30000000U
#define BAUDRATE		9600U

void InitUART0(void);
void UART0_IRQHandler (void);

#endif /* DR_UART_H_ */
