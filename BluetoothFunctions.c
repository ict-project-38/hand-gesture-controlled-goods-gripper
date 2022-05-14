#define F_CPU 8000000UL
#include <avr/io.h>
#include "USART_RS232_H_file.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void USART_Init(unsigned long BAUDRATE);
char USART_RxChar();
void USART_TxChar(char data);
int out_arr[6];



void USART_Init(unsigned long BAUDRATE)
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1);
	UBRRL = BAUD_PRESCALE;
	UBRRH = (BAUD_PRESCALE >> 8);
}

char USART_RxChar()
{
	while (!(UCSRA & (1 << RXC)));
	return(UDR);
}

void USART_TxChar(char data)
{
	UDR = data;
	while (!(UCSRA & (1<<UDRE)));
}



int DataOut(void)
{

	USART_Init(9600);
	
	while(1)
	{
		double x= ultrasonic();
		char value= (char)x;
		USART_SendString(value);
		
		return 0;
	}
}

int DataIn(void)
{
	int Data_in;
	USART_Init(9600);
	
	while(1)
	{
		Data_in = USART_RxChar();
		out_arr[0] =  *positionLogic();
		out_arr[1] = (*positionLogic()+1);
		out_arr[2] = (*positionLogic()+2);
		out_arr[3] = *getVoltage();
		out_arr[4] = *(getVoltage()+1);
		out_arr[5] = triggerSwitchVal();
		
		return out_arr;

	}
}