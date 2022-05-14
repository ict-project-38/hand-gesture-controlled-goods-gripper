/*
 * GccApplication29.c
 *
 * Created: 5/14/2022 6:16:29 PM
 * Author : User
 */ 

# include<avr/io.h>
#include "USART_RS232_H_file.h"  /* include USART library */

/* #define LED PORTB      connected LED on PORT pin */
#include "USART_RS232_H_file.h"      /* Include USART header file */


void USART_Init(unsigned long BAUDRATE)    /* USART initialize function */
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);    /* Enable USART transmitter and receiver */
	UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1); /* Write USCRC for 8 bit data and 1 stop bit */
	UBRRL = BAUD_PRESCALE;       /* Load UBRRL with lower 8 bit of prescale value */
	UBRRH = (BAUD_PRESCALE >> 8);     /* Load UBRRH with upper 8 bit of prescale value */
}

char USART_RxChar()         /* Data receiving function */
{
	while (!(UCSRA & (1 << RXC)));     /* Wait until new data receive */
	return(UDR);         /* Get and return received data */
}

void USART_TxChar(char data)      /* Data transmitting function */
{
	UDR = data;          /* Write data to be transmitting in UDR */
	while (!(UCSRA & (1<<UDRE)));     /* Wait until data transmit and buffer get empty */
}

void USART_SendString(char *str)     /* Send string of USART data function */
{
	int i=0;
	while (str[i]!=0)
	{
		USART_TxChar(str[i]);      /* Send each char of string till the NULL */
		i++;
	}
}

int main(void)
{
	char Data_in;
	DDRB = 0xff;       /* make PORT as output port */
	USART_Init(9600);      /* initialize USART with 9600 baud rate */
	LED = 0;
	
	while(1)
	{
		Data_in = USART_RxChar();      /* receive data from Bluetooth device*/
		if(Data_in =='1')
		{
			LED |= (1<<PB0);       /* Turn ON LED */
			USART_SendString("LED_ON");     /* send status of LED i.e. LED ON */
			
		}
		else if(Data_in =='2')
		{
			LED &= ~(1<<PB0);       /* Turn OFF LED */
			USART_SendString("LED_OFF");     /* send status of LED i.e. LED OFF */
		}
		else if(Data_in =='3')
		{
			LED |= (1<<PB1);       /* Turn ON LED */
			USART_SendString("LED_ON");     /* send status of LED i.e. LED ON */
			
		}
		else if(Data_in =='4')
		{
			LED &= ~(1<<PB1);       /* Turn OFF LED */
			USART_SendString("LED_OFF");     /* send status of LED i.e. LED OFF */
		}
		else if(Data_in =='5')
		{
			LED |= (1<<PB2);       /* Turn ON LED */
			USART_SendString("LED_ON");     /* send status of LED i.e. LED ON */
			
		}
		else if(Data_in =='6')
		{
			LED &= ~(1<<PB2);       /* Turn OFF LED */
			USART_SendString("LED_OFF");     /* send status of LED i.e. LED OFF */
		}
		else
		USART_SendString("Select proper option"); /* send message for selecting proper option */
	}
	return 0;
}
