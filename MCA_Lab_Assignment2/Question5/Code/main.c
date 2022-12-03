#include "header.h"
#include<stdio.h>
#include<lpc214x.h>

int main()
{ 
	IO1DIR=0xFFFFFFFF;
	PINSEL1 = 0x01000000;
	adc_init();
	lcd_init();
	while(1)
	{ 
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_dis("Voltage:");
		printVoltage();
		delay(100);
	}	
 return 0;
}
