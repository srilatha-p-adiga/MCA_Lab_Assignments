void lcd_init();                //LCD initialization function
void lcd_data(unsigned char);   //Function to send DATA into the LCD
void lcd_cmd(unsigned char);    //Function to send COMMAND into the LCD
void lcd_dis(char *);           //LCD string display function
void delay();                   //Function to generate a delay
void init_pll();                // PLL Initialization
void init_uart0();              //initialize uart0
void displayString(char *);     // display string
char recieve_char_uart0();      //recieve character on UART0
void isPalindrome(unsigned char*); //Palindrome check