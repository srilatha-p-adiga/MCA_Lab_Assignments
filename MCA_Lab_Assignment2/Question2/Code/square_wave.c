//2. Using TIMER of LPC21xx, on reading a ‘0’ on the SW, generate a square wave of delay 1 sec and on ‘1’ generate the delay of ½ sec. 

#include <lpc214x.h>
#include "timer0.h"
#include "pll.h"

int main()
{
	init_pll();
	IO0DIR|= 0xFFFFFFFF;   // Port 0 is configured as output
  IO1DIR|= 0x00000000;     // Port 1 is configured as input
	while(1)
	{
		if((IO1PIN & (1<<16)) ==0)  //Check if the switch is pressed (i.e. SW=1)
		{
			IO0SET|=0xFFFFFFFF;			       //Set Port 0
			delay_milliseconds(1000);       //Call Delay of 1000ms=1s
			IO0CLR|=0xFFFFFFFF;			       //Clear the Port 0
			delay_milliseconds(1000);       //Call Delay of 1000ms=1s
		}
		else                             //If the sw/Clear the Port 0itch is not pressed (i.e. SW=0)
		{
			IO0SET|=0xFFFFFFFF;			       //Set Port 0 
			delay_milliseconds(500);      //Call Delay of 500ms=0.5s      
			IO0CLR|=0xFFFFFFFF;			       //Clear the Port 0
			delay_milliseconds(500);      //Call Delay of 500ms=0.5s
		}
	}
	return 0;
}