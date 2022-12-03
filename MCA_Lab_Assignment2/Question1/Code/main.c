//1. Check whether a received string from the UART0 is a palindrome or not. Display the same on the LCD.

#include <lpc214x.h>
#include "header.h"

int main()
{	
	  unsigned char c;
	  int i=0;
	  char string[16];          //char array to store the string recv from UART
	  IO1DIR=0xFFFFFFFF;        //Port 0 is configured as output 
	  init_pll();               //initialise the pll
	  init_uart0();             //initilaise the uart0
	  lcd_init();               //initilaise the lcd
    while(1)
	{ 
		 i=0;                     //count that holds number of characters recieved
		 c=recieve_char_uart0();  //recieve one character
		 while(c!=13 && i<14)     //13 is ascii value for "enter" whenever enter is encountered loop stops 
			{ 
				string[i++]=c;  
				c=recieve_char_uart0();
			}
	  string[i]='\0';                     //make ith element the end of string
		lcd_cmd(0x01);                      //LCD Command to clear LCD screen
		lcd_dis(&string[0]);                //Display the string
		isPalindrome(string);               //Call palindrome function and check if the given string is palindrome or not                 
		delay(10);
	 }
     return 0;
}