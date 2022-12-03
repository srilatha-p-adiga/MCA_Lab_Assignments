//4. Generate a sine wave using DAC
#include "header.h"
#include <lpc214x.h>

int main()
{	
	PINSEL1=0x0080000;  //P0.25 as DAC output
	int i=0,sine;
	while(i<50)
	{  
		 sine=get_sine(i);
		 write_to_dac(sine);
		 delay_microseconds(10);
		i++;
	}
	return 0;
}
