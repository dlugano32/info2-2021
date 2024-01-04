#include "LPC845.h"

int main(void)
{
	InicializacionHw();

    while(1)
    {
    	MDERecepcion();
    	TimerEvent();
    }
}

void MDERecepcion(void)
{
	static uint8_t estado=ESPERANDO_TRAMA;
	static uint8_t ID, credito;
	uint8_t dato, key, buffer[5];

	dato=RxLGT();

	switch(estado)
	{
	case ESPERANDO_TRAMA:
		if(dato=='#')
			estado=ESPERANDO_ID;
		break;

	case ESPERANDO_ID:
		if(dato!=-1)
		{
			if( dato>0 && dato<=50)	//Verifico que la ID sea valida
			{
				ID=dato;
				estado=ESPERANDO_CREDITO;
			}
			else	//Error por ID
			{
				EncenderLR();
				Display(999999, 0);
				TitilarDisplay();
				estado=ERROR;
			}
		}
		break;

	case ESPERANDO_CREDITO:
		if( dato !=-1)
		{
			credito=dato;
			if(credito>0)
			{
				TitilarLV();
				Display(ID, 0);
				Display(credito, 1);

				estado=BOTONERA;

			}
			else if( checkRecarga() )	//Pregunto si es valida la recarga
			{
				Recarga(ID,credito);
				TitilarLV();
				Display(ID, 0);
				Display(credito, 1);

				estado=BOTONERA;
			}
			else	//Error por falta de credito
			{
				EncenderLR();
				Display(888888, 0);
				TitilarDisplay();
				estado=ERROR;
			}
		}
		break;

	case BOTONERA:
		key=getKey();

		if(key!=NO_KEY && key!=RESET)
		{
			//ExpulsarLata(key);	//Key le pasa A B C D o E y se expulsa la lata
			credito--;
			Recarga(ID);	//Recarga si es necesario
			Timer10seg();		//REVISAR
			estado=ESPERANDO_EXP;
		}
		break;

	case ESPERANDO_EXP:
		if(flagT0==1)
		{
			flagT0=0;
			ApagarLV();
			SetPin(EXP_TJTA, 1);
			estado=ESPERANDO_TRAMA;
		}
		break;

	case ERROR:
		key=getKey();

		if(key==RESET)
		{
			SetPin(EXP_TJTA, 1);
			ApagarDisplay();
			ApagarLR();
			estado=ESPERANDO_TRAMA;
		}

		break;

	default:
		estado=ESPERANDO_TRAMA;
	}
}

uint8_t checkRecarga(uint8_t ID,uint8_t credito)
{
	uint8_t ret=0;

	//Voy a tener en cuenta que existe un buffer con todos los registros de las ultimas recargas, que tiene el mismo formato que el registro
	uint8_t dia= DATE & 0x1F;	//Fecha actual
	uint8_t mes=( (DATE>>5) & (0xF) );
	uint16_t anio=( (DATE>>9) & (0xFFF) );

	uint8_t diaID=FechaRecarga[ID] & 0x1F;	//Ultima vez que se recargo
	uint8_t mesID=( (FechaRecarga[ID]>>5) & (0xF) );
	uint16_t anioID=( (FechaRecarga[ID]>>9) & (0xFFF) );

	if( mesID<mes && anioID==anio)
	{
		if(diaID<dia)
		{
			ret=1;
		}
	}
	else if(anioID<anio)
	{
		ret=1;
	}

	return ret;
}

void Recarga(uint8_t ID, uint8_t credito)
{
	FecharRecarga[ID]=DATE;

	credito+=25;
	buffer[0]='#';
	buffer[1]='$';
	buffer[2]=credito;
	buffer[3]='/';
	buffer[4]='\0';
	TxLGT(buffer);	//Se activa la interrupcion por Tx
}
