#include "timer0.h"
#include <lpc214x.h>

void delay_milliseconds(int milliseconds)
{
   T0CTCR = 0x0;  //Select the timer mode
	 T0TCR = 0x00;  //Timer off
	 T0PR = 59999;  //Prescale value
	 T0TCR = 0x02;  //Timer reset
	 T0TCR = 0x01;  // Timer on
	 while(T0TC < milliseconds); //Check for the count of time
	 T0TCR = 0x00;     //Timer off
	 T0TC = 0;        // Clear the TC
}
