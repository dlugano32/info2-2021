#include "DR_Init.h"
#include "Tecla.h"
#include "PR_7seg.h"

int main(void)
{
	static int32_t counter=0;
	uint8_t key=255;

	InitHw();

	while(1)
	{
		key=getKey();

		if(key==PUSH)
		{
			counter++;

			if(counter > 99)
			{
				counter=0;
			}

			Display(counter);
		}
	}
}
