/*
 * MDE_funciones.c
 *
 *  Created on: 11 oct. 2021
 *      Author: d_lugano
 */

#include "JustDanceMDE_func.h"
#include "Systick.h"

int32_t points=0;
uint8_t errores=0;

uint8_t Puntaje(uint32_t counter, uint32_t timestap , uint32_t dificultad )
{
	//Legend 	500 	counter=timestap
	//Perfect  	100 	+-0.4*dificultad
	//Good   	50		+-0.8*dificultad
	//Regular 	10 		+-dificultad
	//Bad		-20

	if(timestap==counter)
	{
		points+=500;
		return 0;
	}
	else if ( ( (timestap-dificultad*0.4) < counter ) && ( (timestap + dificultad*0.4) > counter) )
	{
		points+=100;
		return 0;
	}
	else if( ( (timestap-dificultad*0.8) < counter ) && ( (timestap + dificultad*0.8) > counter) )
	{
		points+=50;
		return 0;
	}
	else if( ( (timestap-dificultad) < counter ) && ( (timestap + dificultad) > counter) )
	{
		points+=10;
		return 0;
	}
	//print(points);

	return 0;
}

void Puntaje_restar(void)
{
	points-=20;

	if(points<0)
		points=0;

	errores++;
	//print(points);
}

void EnviarStart(void)
{
	uint8_t aux=0;
	uint8_t buffer1[20]="AT+CIPSEND=1,9\r\n";
	uint8_t buffer2[10]="# START @";

	TxSerie0((uint8_t *)buffer1);
	TxSerie1((uint8_t *)buffer1);
/*
	while(aux!='>')
	{
		aux=RxSerie1();
	}
*/
	while(flagRx!=1);

	TxSerie0((uint8_t *)buffer2);
	TxSerie1((uint8_t *)buffer2);

	while(flagTx!=1);
}

void EnviarDatos(uint8_t key, uint32_t timestap)
{
	uint8_t buffer1[20]="AT+CIPSEND=1,";
	uint8_t buffer2[20], buf_aux1[10], buf_aux2[10], buf_aux2_1[10], buf_aux1_1[10], i=0, len2=0, len1=0;
	uint32_t aux=0, aux1=0;

	buffer2[0]='#';
	buffer2[1]=' ';
	buffer2[2]=key+48;
	buffer2[3]=' ';
	buffer2[4]='\0';

	for(i=0, aux=timestap ; aux>0; i++)
	{
		buf_aux2[i]=(aux%10) +48 ;
		aux/=10;
	}
	buf_aux2[i]='\0';

	my_revstr(buf_aux2, buf_aux2_1);
	my_strcat(buffer2, buf_aux2_1);
	len2=my_strlen(buffer2);

	buffer2[len2++]=' ';
	buffer2[len2++]='@';
	buffer2[len2]='\0';	//El null no cuenta como el largo pero tiene que estar


	for(i=0, aux=len2; aux>0; i++)
	{
		buf_aux1[i]=(aux%10) +48 ;
		aux/=10;
	}

	my_revstr(buf_aux1, buf_aux1_1);
	my_strcat(buffer1, buf_aux1_1);
	len1=my_strlen(buffer1);
	buffer1[len1++]='\r';
	buffer1[len1++]='\n';
	buffer1[len1]='\0';

	TxSerie0(buffer1);
	TxSerie1(buffer1);

	/*
	while(aux1!='>')
	{
		aux1=RxSerie1();

	}
	*/

	while(flagRx!=1);

	TxSerie0(buffer2);
	TxSerie1(buffer2);

	while(flagTx!=1);

}


void my_revstr (uint8_t *str, uint8_t *str_r)
{
       int i=0, j=0, length=0;

       while(*(str+i)!='\0')
       {
              i++;
       }
       length=i;

       for(i=0, j= (length-1) ; i < length ; i++, j--)
       {
              *(str_r+i)=*(str+j); //copio en str_r el string invertido
       }

       str_r[length]= '\0'; //le seteo el null

}

void my_strcat (uint8_t *destino, uint8_t *origen)
{
       int length=0, i=0;

       while(*(destino+i)!='\0')
       {
              i++;
       }
       length=i;

       for(i=0; *(origen+i)!='\0'; i++)
       {
              *(destino+ (length+i) )= *(origen+i); //piso el NULL en la primera pasada
       }

       destino[length+i]='\0';
}

uint8_t my_strlen(uint8_t* str1)
{
        uint8_t i=0;

    while(*(str1+i)!= '\0')
    	i++;

    return i;
}


void InitArchivoMusica( Paso* steps)
{
	steps[0].timestap=1000;
	steps[0].tecla=UP_ARROW;

	steps[1].timestap=2000;
	steps[1].tecla=RIGHT_ARROW;

	steps[2].timestap=3000;
	steps[2].tecla=DOWN_ARROW;

	steps[3].timestap=4000;
	steps[3].tecla=LEFT_ARROW;

	steps[4].timestap=5000;
	steps[4].tecla=UP_ARROW;

	steps[5].timestap=6000;
	steps[5].tecla=RIGHT_ARROW;

	steps[6].timestap=7000;
	steps[6].tecla=DOWN_ARROW;

	steps[7].timestap=8000;
	steps[7].tecla=LEFT_ARROW;
}
