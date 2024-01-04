/*
 * funciones.h
 *
 *  Created on: 19 ago. 2021
 *      Author: d_lugano
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void SetDIR (uint32_t Puerto, uint32_t Pin, uint32_t Direccion);	//Setea la dirección del pin especificado
void SetPIN (uint32_t Puerto, uint32_t Pin, uint32_t Estado);	//Setea el Estado (0 o 1) indicado en el pin especificado
uint32_t GetPIN (uint32_t Puerto, uint32_t Pin); //Devuelve el valor del pin especificado
void SetPINMODE_IN (uint32_t Pin, uint32_t Modo); 	//Pull-Down o Pull-Up
void SetPINMODE_OUT (uint32_t Pin, uint32_t Modo);	//Drain Mode



#endif /* FUNCIONES_H_ */
