/*
 * PR_Uart.h
 *
 *  Created on: 4 nov. 2021
 *      Author: USUARIO
 */

#ifndef PR_UART_H_
#define PR_UART_H_

#include "../Drivers/LPC845.h"
#include "../Drivers/DR_UART.h"

#define INICIO_TRAMA	0
#define DATO			1
#define FIN_TRAMA		2


int16_t RxSerie1 ( void );
void TxSerie1 ( uint8_t *);
void Tx1Byte ( uint8_t );
int16_t LecturaSerie (void);


#endif /* PR_UART_H_ */
