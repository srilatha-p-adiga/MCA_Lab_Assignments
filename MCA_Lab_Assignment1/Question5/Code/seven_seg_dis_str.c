//5. Interface a four 7-segment display, and display MSIS in a scrolling passion. (or) just display MSIS.

#include<lpc214x.h>
#include"header.h"
int main(void)
{ 
	
	IO0DIR=0xFFFFFFFF;           //Port 0 is configured as output port
	//MSIS in hex (M = 0x37, S=0x6D , I=0x06)
	int arr[4][4]={{0x37,0x6D,0x06,0x6D},{0x6D,0x06,0x6D,0x37},{0x06,0x6D,0x37,0x6D},{0x6D,0x37,0x6D,0x06}};
	int i=1, j=1;
	while(1)
	{
	  while(j<=4)
	  {		
	   	for(i=1;i<=4;i++)
		  { 
			    seven_seg(arr[j-1][i-1],i);
		      delay_ms(20);
		   }
	   }
	   j++;
	 }
	return 0;
}
