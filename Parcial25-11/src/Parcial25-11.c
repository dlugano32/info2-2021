//#include "DR_Init.h"
#include "PR_USART.h"
#include "PR_SensorDistancia.h"
#include "PR_TECLA.h"

int main(void)
{
	uint32_t aux;
	uint8_t key;

	InitHw();	//Asumo que inicializa todo lo necesario

    while(1)
    {
    	aux=LeerSensor();
    	key=getKey();

    	if(key==BOTONP04)
    	{
    		EnviarTrama(aux);	//Aca se envia la trama
    	}

    }
    return 0 ;
}
