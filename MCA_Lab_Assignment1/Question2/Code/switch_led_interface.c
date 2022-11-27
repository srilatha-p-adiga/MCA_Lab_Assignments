//2. Interface 1 led with P0.1 and switch SW to pin P0.4. On press of the switch make the LED to on and off.

#include<lpc214x.h>
int main()
{
	IO0DIR|= 0x0F;  //Configure P0.0-P0-3 as Output and P0.4-P0.7 as Input
  while(1)
    { 
				if((IO0PIN & (1<<4)) ==0)  //Check if the switch connected to P0.4 is pressed 
        IO0SET|=0xFF;    		       // Switch on the LED	
        else
        IO0CLR|=0xFF;			         //	Switch off the LED	
    }
}
