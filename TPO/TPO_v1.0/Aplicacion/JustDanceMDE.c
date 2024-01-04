/*
 * JustDanceMDE.c
 *
 *  Created on: 7 oct. 2021
 *      Author: d_lugano
 */

#include "JustDanceMDE.h"
#include "MDE_funciones.h"

//Variables del juego
static uint8_t n_paso=0;
const uint32_t dificultad[2]={FACIL, DIFICIL};
static uint8_t indice_dif=0;	//Esta es la variable a modificar para cambiar la dificultad

void JustDanceMDE(void)
{
	//Variables
	static uint8_t estado=MENU_PRINCIPAL;
	uint8_t key=NO_KEY;

	key=getKey();

	switch(estado)
	{
		case MENU_PRINCIPAL:

			if(key==START)
			{
				TimerStart(0, 3, handlerT0, SEG);
				//sincronizar con pc
				estado=CUENTA_ATRAS;
			}

			break;

		case CUENTA_ATRAS:

			if(flagT0==1)
			{
				flagT0=0;
				TimerStart(1, 1, handlerT1, MILI);
				estado=ESPERANDO_TECLA;
			}
			break;

		case ESPERANDO_TECLA:

			if( ((cancion[n_paso].timestap-dificultad[0]) < counter ) && ((cancion[n_paso].timestap + dificultad[0]) > counter) ) 	//Tiempo en el que deberia haber una tecla apretada
			{
				//Estas dentro del timepo correcto
				if(key==cancion[n_paso].tecla)
				{
					//Apretaste la tecla bien

					Puntaje( counter, cancion[n_paso].timestap, dificultad[0] );

					n_paso++;
				}
				else if(key!=NO_KEY)
				{
					//Apretaste cualquier tecla
					Puntaje_restar();
					n_paso++;
				}
			}
			else if( key!=NO_KEY )
			{
				//Apretaste fuera de tiempo
				Puntaje_restar();
				n_paso++;
			}

			if( ( cancion[n_paso].timestap+dificultad[0] ) < counter )
			{
				//Te olvidaste de apretar
				Puntaje_restar();
				n_paso++;
			}

			//Actualizar el display
			//Enviar datos compu (tecla correcta o incorrecta)

			if(key==SELECT)	//reset
			{
				InitJustDanceMDE();
				//resetear el display
				//sincronizar pc
				TimerStart(0, 3, handlerT0, SEG);
				estado=CUENTA_ATRAS;
			}

			if(counter>=LARGO_CANCION || errores>=10) //game over
			{
				TimerStop(1);
				estado=GAME_OVER;
			}

			break;

		case GAME_OVER:

			//Mostrar cartel de game over
			//Mostrar puntaje

			if( key==START )
			{
				//Enviar datos compu
				//Apagar display o ponerlo todo en cero
				estado=MENU_PRINCIPAL;
			}
			break;

		default:
			estado=MENU_PRINCIPAL;

	}
}

void InitJustDanceMDE(void)
{
	n_paso=0;
	flagT0=0;
	counter=0;
	points=0;
	errores=0;
}
