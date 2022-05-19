/*
 * USART_RS232_H_file.h
 * http://www.electronicwings.com
 *
 */ 


#ifndef USART_RS232_H_FILE_H_				/* Define library H file if not defined */
#define USART_RS232_H_FILE_H_

#define F_CPU 8000000UL						/* Define CPU clock Frequency e.g. here its 8MHz */
#include <avr/io.h>							/* Include AVR std. library file */
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1)	/* Define prescale value */

                            				/* USART initialize function */
						                   /* Data receiving function */
void USART_Init(unsigned long BAUDRATE)             /* USART initialize function */
{ 
    UCSRB |= (1 << RXEN) | (1 << TXEN);             /* Enable USART transmitter and receiver */
    UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1); /* Write USCRC for 8 bit data and 1 stop bit */ 
    UBRRL = BAUD_PRESCALE;                          /* Load UBRRL with lower 8 bit of prescale value */
    UBRRH = (BAUD_PRESCALE >> 8);                   /* Load UBRRH with upper 8 bit of prescale value */
}

char USART_RxChar()                                 /* Data receiving function */
{
    while (!(UCSRA & (1 << RXC)));                  /* Wait until new data receive */
    return(UDR);                                    /* Get and return received data */ 
}

void USART_TxChar(char data)                        /* Data transmitting function */
{
    UDR = data;                                     /* Write data to be transmitting in UDR */
    while (!(UCSRA & (1<<UDRE)));                   /* Wait until data transmit and buffer get empty */
}

void USART_SendString(char *str)                    /* Send string of USART data function */ 
{
    int i=0;                                                                    
    while (str[i]!=0)
    {
        USART_TxChar(str[i]);                       /* Send each char of string till the NULL */
        i++;
    }
}


                                			/* Send string of USART data function */


#endif										/* USART_RS232_H_FILE_H_ */