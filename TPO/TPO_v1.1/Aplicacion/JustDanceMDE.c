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
//static uint8_t indice_dif=0;	//Esta es la variable a modificar para cambiar la dificultad

void JustDanceMDE(void)
{
	//Variables
	static uint8_t estado=MENU_PRINCIPAL;
	static uint8_t key=NO_KEY;

	key=getKey();

	switch(estado)
	{
		case MENU_PRINCIPAL:

			if(key==START)
			{
				TimerStart(0, 1, handlerT0, SEG);	//Timer para la cuenta atras, salta flagT0 despues de 3 seg
				//sincronizar con pc
				estado=CUENTA_ATRAS;
			}

			break;

		case CUENTA_ATRAS:

			if(flagT0==1)
			{
				flagT0=0;
				TimerStart(1, 1, handlerT1, MILI);
				TimerStart(4, 1, handlerT4, SEG);
				print(0);
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

			print(points);
			//Enviar datos compu (tecla correcta o incorrecta)

			if(key==SELECT)	//reset
			{
				TimerStop(1);
				TimerStop(4);
				print(0);
				//sincronizar pc
				clearMDE();
				TimerStart(0, 1, handlerT0, SEG);
				estado=CUENTA_ATRAS;
			}

			if(counter>=LARGO_CANCION || errores>=10) //game over
			{
				TimerStop(1);
				TimerStop(4);	//Es el contador de segundos
				TimerStart(2, 1, handlerT2, SEG);	//Cuento segundos
				estado=GAME_OVER;
			}

			break;

		case GAME_OVER:
			gameOver1();
			if( key==START )
			{
				//Enviar datos compu
				TimerStop(2);
				write(CLEAR);
				clearMDE();

				estado=MENU_PRINCIPAL;
			}
			break;

		default:
			estado=MENU_PRINCIPAL;

	}
}

void clearMDE(void)
{
	n_paso=0;
	flagT0=0;
	flagT3=0;
	counter=0;
	counter2=0;
	counter4=0;
	points=0;
	errores=0;
	TimerStop(0);
	TimerStop(1);
	TimerStop(2);
	TimerStop(3);
	TimerStop(4);
	Display(0);
	write(CLEAR);
}

void InitJustDanceMDE(void)
{
	InitArchivoMusica(cancion);
	clearMDE();
	//Algo del esp?
}
