/*
 * DR_Teclado.c
 *
 *  Created on: 19 nov. 2021
 *      Author: d_lugano
 */

uint8_t Tecla=NO_KEY;

void BarridoTeclado(void)
{
	uint8_t key;
	static uint8_t lastKey=NO_KEY, cont=0;

	key=TecladoHw();

	if(lastKey==key && cont<DEBOUNCE)
	{
		cont++;
		if(cont==DEBOUNCE)
		{
			Tecla=key;
		}
	}
	else if(key!=lastKey)
	{
		cont=0;
	}

	lastKey=key;
}

void TecladoHw(void)
{
	SetPIN(COL1,0);
	SetPIN(COL2,1);
	SetPIN(COL3,1);

	if(!GetPIN(FILA1))
		return TECLA_A;
	if(!GetPIN(FILA2))
		return TECLA_D;

	SetPIN(COL1,1);
	SetPIN(COL2,0);
	SetPIN(COL3,1);

	if(!GetPIN(FILA1))
		return TECLA_B;
	if(!GetPIN(FILA2))
		return TECLA_E;

	SetPIN(COL1,1);
	SetPIN(COL2,1);
	SetPIN(COL3,0);

	if(!GetPIN(FILA1))
		return TECLA_C;
	if(!GetPIN(FILA2))
		return RESET;

	return NO_KEY;
}
