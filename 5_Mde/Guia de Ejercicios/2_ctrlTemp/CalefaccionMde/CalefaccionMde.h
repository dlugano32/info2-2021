/*
 * CalefaccionMde.h
 *
 *  Created on: 19 jul. 2021
 *      Author: d_lugano
 */

#ifndef CALEFACCIONMDE_H_
#define CALEFACCIONMDE_H_

#define STAND_BY 0
#define ENCENDIDO 1
#define APAGADO 2

#define TEMP_FINAL 100
#define BANDA_HISTERESIS 10

//Mde
void calefaccionMde(void);
void init_calefaccionMde(void);

//Eventos
int s_Boton(void);
int getTemperatura(void);

//Acciones
void m_calentadorOff(void);
void m_calentadorON(void);

#endif /* CALEFACCIONMDE_H_ */
