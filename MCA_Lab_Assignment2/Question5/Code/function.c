#include<lpc214x.h>
#include "header.h"
#define bit(x) (1<<x)

void lcd_cmd(unsigned char a)  //Function to send COMMAND into the LCD
{
    IO1PIN&=0x00;             //Pins of PORT 0 set to 0     
    IO1PIN|=(a<<16);           //Shift data to the port P0.0
    IO1CLR|=bit(25);           //To send the COMMANDS into the LCD, Register Select has to be 0 ; rs=0
    IO1CLR|=bit(26);           //For writing into the LCD rw=0
    IO1SET|=bit(27);          //To latch the command/data sent into the LCD a high to low pulse is given; en=1
    delay();                  //Call a delay
    IO1CLR|=bit(27);          //en=0
}

void lcd_init()              //LCD initialization function
{
    lcd_cmd(0x30);           // 8-bit mode
	  lcd_cmd(0x38);           //activate two rows of LCD crystal
    lcd_cmd(0x0c);           //turn on display , turn off cusor
    lcd_cmd(0x06);           //increment cursor
    lcd_cmd(0x01);           //clear the screen
    lcd_cmd(0x80);           //set the cursor to the beginning of the first line
}

void lcd_data(unsigned char b)  //Function to send DATA into the LCD
{
    IO1PIN&=0x00;             //Pins of PORT 0 set to 0
    IO1PIN|=(b<<16);           //Shift data to the port P0.0
    IO1SET|=bit(25);           //To send the DATA into the LCD, Register Select has to be 1 ; rs=1
    IO1CLR|=bit(26);           //For writing into the LCD rw=0
    IO1SET|=bit(27);          //To latch the command/data sent into the LCD a high to low pulse is given; en=1
    delay();                  //Call delay
    IO1CLR|=bit(27);          //en=0
}

void lcd_dis(unsigned char *p)  // LCD string display function
{
    while(*p!='\0')             
			{
        lcd_data(*p++);       // Pass the character into the data function using pointer
      }
}

void delay()                  //Delay function
{   
    unsigned int i;	
    for(i=0;i<10000;i++);
}


int readVolt()
{ 
	int result;
	AD0CR = AD0CR | (1<<24);
	while ( !(AD0GDR & 0x80000000)); 
	AD0CR&=~0X01000000;
	result = AD0GDR;
	result = (result>>6);
	result = (result & 0x000003FF);
	return  result*100*3.3/1023;
}
 

void adc_init()
{ 
	AD0CR = 0x00200402;
}


void printVoltage()
{
	int volt,i,voltD;
	char str[20];
	volt=readVolt();
	i=volt/100;
	voltD=volt-i*100;
	sprintf(str,"%d.%d V",i,voltD);
	lcd_dis(str);
}
