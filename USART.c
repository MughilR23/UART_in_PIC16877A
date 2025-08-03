#include"USART.h"
#define _XTAL_FREQ 20000000
void USART_init(unsigned long baud)
{
pinMode(3,6,OUTPUT);			// RC6 FOR TX
pinMode(3,7,INPUT);				// RC7 FOR RX
BRGH=1;							// HIGH SPEED MODE FOR ACCURACY
SPBRG=129;						// BAUD RATE GENERATOR
SYNC=0;							// ASYNCHRONOUS MODE
SPEN=1;							// SERIAL PORT ENABLE
TXEN=1;							// TRANSMISSION ENABLE
CREN=1;							// CONTINUOUS RECEPTION
TXIE=1;							// TRANSMISSION INTERRUOPT ENABLE
RCIE=1;							// RECEPTION INTERRUPT ENABLE
GIE=1;							// GLOBAL INTERRUPT ENABLE
PEIE=1;							// PERIPHERAL INTERRUPT ENABLE
}

void USART_TX(unsigned char ch)
{
while(TXIF==0);						// CHECKS FOR THE FLAG
TXREG=ch;
TXIF=0;						// STORES THE DATA TO THE TXREG
}

char USART_RX(void)				
{
while(RCIF==0);						// CHECKS FOR THE FLAG
RCIF=0;
return RCREG;					// RETURNS THE VALUE STORED IN THE RCREG

}

void USART_TXstr(unsigned char *str)
{
while(*str !='\0')
{while(!TXIF);
USART_TX(*str);
str++;
}
}

char* USART_RXstr(unsigned char *str,unsigned int size)
{
for(int i=0;i<size-1;i++)
{
str[i]=USART_RX();
if(str[i]=='\n'||str[i]=='\r')
{
break;
}
}
return str;
}