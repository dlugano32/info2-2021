/*
 * DR_Init.h
 *
 *  Created on: 8 ago. 2021
 *      Author: chor
 */

#ifndef DR_INIT_H_
#define DR_INIT_H_

//Registros de control del FRO y del CLK

//Direccion de la funcion de ROM para setear la frecuencia del oscilador:
#define FRO_SET_FRECUENCY_FUNC (0x0F0026F5U)

//Registros para seteo del FRO:
#define FROOSCCTRL (*(unsigned int *)0x40048028)
#define FRODIRECTCLKUEN (*(unsigned int *)0x40048030)

#define MAINCLKPLLSEL (*(unsigned int *)0x40048048)
#define MAINCLKPLLUEN (*(unsigned int *)0x4004804C)

#define SYSPLLCLKSEL (*(unsigned int *)0x40048040)
#define SYSPLLCLKUEN (*(unsigned int *)0x40048044)

#define SYSAHBCLKDIV (*(unsigned int *)0x40048058)

//Registro para habilitacion del clk a diferentes periféricos:
#define SYSAHBCLKCTRL0 (*(unsigned int *)0x40048080)

//Registros y defines generales de GPIO:
#define BIT_GPIO1	20

#define GPIO0DIR (*(unsigned int *)0xA0002000)
#define GPIO1DIR (*(unsigned int *)0xA0002004)

void InitHw(void);

#endif /* DR_INIT_H_ */
