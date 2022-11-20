#include"lcd.h"

int main(void)
{	unsigned char c;
	int i=0;
	char string[16]; 
	IO1DIR=0XFFFFFFFF; 
	pll_init(); 
	uart_int(); 
	lcd_int(); 
	
	while(1)
	{ i=0; 
		c=recieve_char(); 
		while(c!=13 && i<14)  
			{ string[i++]=c;  
				c=recieve_char();
			}
	  string[i]='\0'; 
		cmd(0x01);  
		displayString("STRING RECIEVED:"); 
		cmd(0xC0); 
		displayString(&string[0]); 
		cmd(0x80); 
		delay_ms(10);
	}
	return 0;
}