#include "DR_Init.h"
#include "Tecla.h"
#include "PR_7seg.h"

int main(void)
{
	uint8_t key=NO_KEY;

	InitHw();

	LED_OFF(ROJO);
	LED_OFF(AZUL);
	LED_OFF(VERDE);

	while(1)
	{
		key=getKey();

		if ( key != NO_KEY )
		switch( key )
		{
			case SW0:
				Display(0);
				break;

			case SW1:
				Display(1);
				break;

			case SW2:
				Display(2);
				break;

			case SW3:
				Display(3);
				break;

			case SW4:
				Display(4);
				break;

			case SW5:
				Display(5);
				break;

			case SW6:
				Display(6);
				break;

			case SW7:
				Display(7);
				break;

			case SW8:
				Display(8);
				break;

			case SW9:
				Display(9);
				break;

			case SWast:
				Display_mas();
				break;

			case SWhash:
				Display_menos();
				break;

			default:
				key=NO_KEY;
		}

		TimerEvent();
	}

	return 0;
}
