//1.Interface 8 Led with Port 0 and make it glow alternatively.

#include <lpc214x.h>
#include "header.h"

int main()
{
    IO0DIR = 0xFFFFFFFF;     // Configure Port 0 as output
	  init_pll();              // pll initialization         
	  while(1)
	{
	  IO0SET = 0x00000055;      // Set (LEDs 1,3,5,7 - ON) Ports P0.0, P0.2, P0.4, P0.6
	  delay_milliseconds(200);  // Call Delay
	  IO0CLR = 0x000000055;     // Clear (LEDs 1,3,5,7 - OFF) Ports P0.0, P0.2, P0.4, P0.6
		IO0SET = 0x0000000AA;     // Set (LEDs 2,4,6,8 - ON) Ports P0.1, P0.3, P0.5, P0.7
	  delay_milliseconds(200);  // Call Delay
    IO0CLR = 0x000000AA;      // Clear (LEDs 2,4,6,8 - OFF) Ports P0.1, P0.3, P0.5, P0.7
		
	}return 0;
}