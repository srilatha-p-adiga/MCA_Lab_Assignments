#include <lpc214x.h>
#include "header.h"
#define bit(x) (1<<x)

void lcd_cmd(unsigned char a)  //Function to send COMMAND into the LCD
{
    IO1PIN&=0x00;             // Pins of Port0 set to 0    
    IO1PIN|=(a<<16);          // Shift data to Port P0.16
    IO1CLR|=bit(25);          //To send the COMMANDS into the LCD, Register Select has to be 0 ; rs=0
    IO1CLR|=bit(26);          //For writing into the LCD rw=0
    IO1SET|=bit(27);          //To latch the command/data sent into the LCD a high to low pulse is given; en=1
    delay();                  //Call a delay
    IO1CLR|=bit(27);          //en=0
}

void lcd_init()              //LCD initialization function
{
    lcd_cmd(0x30);           //8-bit mode
	  lcd_cmd(0x38);           //activate two rows of LCD crystal
    lcd_cmd(0x0c);           //Display ON Cursor OFF
		lcd_cmd(0x06);           //turn on display , turn off cusor
    lcd_cmd(0x01);           //clear the screen
    lcd_cmd(0x80);           //set the cursor to the beginning of the first line
}

void lcd_data(unsigned char b)  //Function to send DATA into the LCD
{
    IO1PIN&=0x00;              // Pins of Port0 set to 0
    IO1PIN|=(b<<16);           // Shift data to Port P0.16
    IO1SET|=bit(25);           //To send the DATA into the LCD, Register Select has to be 1 ; rs=1
    IO1CLR|=bit(26);           //For writing into the LCD rw=0
    IO1SET|=bit(27);          //To latch the command/data sent into the LCD a high to low pulse is given; en=1
    delay();                  //Call delay
    IO1CLR|=bit(27);          //en=0
}

void lcd_dis(char *p)         // LCD string display function
{
    while(*p!='\0')             
			{
        lcd_data(*p++);       // Pass the character into the data function using pointer
      }
}

void delay()                  //Delay function
{   
    unsigned int i;	
    for(i=0;i<5000;i++);
}

void init_uart0()
{
	PINSEL0=0x5;
	U0LCR = 0x83;
	U0DLL = 135;
	U0DLM = 0x1;
	U0LCR = 0x03;
}

char recieve_char_uart0()
{	
  unsigned char f;
  while((U0LSR&(1<<0))==0);         //Checking RDR bit
  f=U0RBR;
  return f;
}


void init_pll()
{
  PLL0CON = 0x01;
  PLL0CFG = 0x24;
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;
  while(!(PLL0STAT & (1<<10)));
  PLL0CON = 0x03;
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;
	VPBDIV = 0x01;
}

void isPalindrome(unsigned char* word)   //Palindrome check function
{
    unsigned char *ptr, *rev;
    ptr = word;
    while (*ptr != '\0') 
			{
        ++ptr;
      }
    --ptr;
 
    for (rev = word; ptr >= rev;) 
			{
        if (*ptr == *rev) 
				{
            --ptr;
            rev++;
        }
        else
            break;
       }
 
    if (rev > ptr)                   //if the word is a palindrome
		{
	    lcd_cmd(0xC0);                 //Force cursor to the second line
		  lcd_dis("PALINDROME");         //Display "PALINDROME" on LCD 
		}
    else                            //if the word is not a palindrome
		{
	    lcd_cmd(0xC0);                //Force cursor to the second line
		  lcd_dis("NOT A PALINDROME");  //Display "NOT A PALINDROME" on LCD 
		}
		
}