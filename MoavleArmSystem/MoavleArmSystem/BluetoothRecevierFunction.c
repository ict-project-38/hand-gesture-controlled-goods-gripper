#define F_CPU 8000000UL
#include <avr/io.h>
#include "USART_RS232_H_file.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void USART_Init(unsigned long BAUDRATE);
char USART_RxChar();
void USART_TxChar(char data);
int* getSensorValues();
char sensorValues[6],RightOrLeft,UporDown,Stable,FlexValue1,FlexValue2,SwitchVal;

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

int* getSensorValues()
{
	while(1)
	{
		char Data_in;
		USART_Init(9600);
		Data_in = USART_RxChar();
		int i=0;
		for(i;i<6;i++)
		{
			sensorValues[i]=Data_in;
		}
	}
	return sensorValues;


}


//4.5556778
//char string={'4','.','5','5','5','6','7','8'}
//4.55567
///char* string="4.5556778" 

/*if(i==0)
			{
				RightOrLeft=Data_in;
			}
			else if(i==1)
			{
				UporDown=Data_in;
			}
			else if(i==2)
			{
				Stable=Data_in;
			}
			else if(i==3)
			{
				FlexValue1=Data_in;
			}
			else if(i==4)
			{
				FlexValue2=Data_in;
			}
			else if(i==5)
			{
				SwitchVal=Data_in;
			}
			*/