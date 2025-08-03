#include<htc.h>
#include"GPIO.h"
#ifndef USART_H
#define USART_H

void USART_init(unsigned long baud);
void USART_TX(unsigned char ch);
char USART_RX(void);
void USART_TXstr(unsigned char *str);
char* USART_RXstr(unsigned char *str,unsigned int size);
#endif