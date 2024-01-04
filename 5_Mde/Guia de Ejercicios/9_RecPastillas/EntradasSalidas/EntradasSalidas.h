/*
 * EntradasSalidas.h
 *
 *  Created on: 21 jul. 2021
 *      Author: d_lugano
 */

#ifndef ENTRADASSALIDAS_H_
#define ENTRADASSALIDAS_H_

#define OFF 0
#define ON 1

//Eventos
int OnOff(void);
int Parada(void);
int TempOK(void);

//Salidas
void Motor (int estado);
void Pistolas (int estado);
void Calefaccion (int estado);

#endif /* ENTRADASSALIDAS_H_ */
