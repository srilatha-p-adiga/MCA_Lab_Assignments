//3. Interface an LCD and display MSIS. On press of the switch SW make the display to blink.

#include<lpc21xx.h>
#include "lcd_header.h"
int main()
{
    IO0DIR|=0XFFF;                  // Port 0 (P0.0 - P0.11) is configured as OUTPUT
    lcd_init();                     // Call initialization function for LCD initialization
    lcd_dis("MSIS");                // Display the string by calling the lcd_dis function
    while(1) 
		{
				if((IO1PIN & (1<<16)) ==0)  //Check if the switch connected to P1.16 is pressed 
        {
				lcd_cmd(0x08);              // LCD command for display OFF cursor OFF
        delay(10000);               // Call Delay
				lcd_cmd(0x0C);              // LCD command for display ON cursor OFF
				}	
		}
		
}