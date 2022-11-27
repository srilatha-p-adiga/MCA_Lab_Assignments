#include<lpc214x.h>
#include"header.h"
#define bit(x) (1<<x)

void seven_seg(int a,int b)
{ 
	IO0SET|=0xF000;      //Set P0.12-P0.15
	IO0CLR|=0xFF0000;    // Clear P0.16 to P0.23
	switch(b)
	{ 
		 case 1: IO0CLR|=bit(12);   // Clear P0.12
						 IO0SET|=a<<16;     // Send corresponding data (hex value) from P0.16
						 break;
		 case 2: IO0CLR|=bit(13);   // Clear P0.13 
						 IO0SET|=a<<16;     // Send corresponding data (hex value) from P0.16
						 break;
		 case 3: IO0CLR|=bit(14);   // Clear P0.14
						 IO0SET|=a<<16;     // Send corresponding data (hex value) from P0.16
						 break;
		 case 4: IO0CLR|=bit(15);   // Clear P0.15 
						 IO0SET|=a<<16;     // Send corresponding data (hex value) from P0.16
						 break;
		 default: break;
	 }
}

void pll_init(void)                  
{
    PLL0CON=0x01;
    PLL0CFG=0x24;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    while(!(PLL0STAT&(1<<10)));
    PLL0CON=0x03;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    VPBDIV=0x01;
}

void delay_ms(unsigned int ms)
{
   T0CTCR = 0x0;      //Select the timer mode
	 T0TCR = 0x00;      //Timer off
	 T0PR = 59999;      //Prescale value
	 T0TCR = 0x02;      //Timer reset
	 T0TCR = 0x01;      //Timer on
	 while(T0TC < ms);  //Check for the count of time
	 T0TCR = 0x00;      //Timer off
	 T0TC = 0;          //Clear the TC  
}
