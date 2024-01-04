#include "DR_Init.h"
#include "Tecla.h"
#include "PR_7seg.h"

int main(void)
{
	uint8_t key=NO_KEY;

	InitHw();

	TimerStart(0,1, HandlerT0, SEG);

	while(1)
	{
		key=getKey();

		if ( key != NO_KEY )
		switch( key )
		{
			case SW0:
				Display(CONTADOR, 0);
				break;

			case SW1:
				Display_mas(1);
				break;

			case SW2:
				Display_mas(10);
				break;

			case SW3:
				Display_mas(100);
				break;

			case SW4:
				Display_mas(1000);
				break;

			case SW5:
				Display_menos(1);
				break;

			case SW6:
				Display_menos(10);
				break;

			case SW7:
				Display_menos(100);
				break;

			case SW8:
				Display_menos(1000);
				break;

			case SW9:
				Display(CONTADOR,9999);
				break;

			case SWast:
				Display_mas(1);
				break;

			case SWhash:
				Display_menos(1);
				break;

			default:
				key=NO_KEY;
		}

		TimerEvent();
	}

	return 0;
}
