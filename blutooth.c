#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"


#define setbit(Reg,Pos) Reg|=1<<Pos
#define clrbit(Reg,Pos) Reg&=~(1<<Pos)
#define togglebit(Reg,Pos) Reg^=1<<Pos

#define FOSC 8000000
#define BAUD 38400 //default baud
#define UBRR ((FOSC/BAUD/16)-1)


// function to initialize USART
void usart_init()
{
  UBRRH=(unsigned char)(UBRR>>8); // shift the register right by 8 bits
  UBRRL=(unsigned char)(UBRR);// set baud rate
  UCSRB|=(1<<TXEN)|(1<<RXEN);// enable receiver and transmitter
  UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);   // 8bit data format
}
/The function is declared to transmit data./
void usart_data_transmit (unsigned char data)
{
  while(!(UCSRA)&(1<<UDRE));// wait while data is being received
  UDR = data; // load data in the register
}
/The function is declared to receive data./
unsigned char usart_data_receive(void)
{
    while(!(UCSRA) & (1<<RXC));                   // wait while data is being received
    return UDR;                                   // return 8-bit data
}
/The function is declared to transmit string./
void usart_string_transmit(char *string)
{
  while(*string)
    usart_data_transmit(*string++);
}
/The function is declared to receive string./
char *usart_string_receive(char *receive_string,unsigned char terminating_character)
{
  int i,temp=0;
  for(i=0;;i++)
  {
    *(receive_string+i)=usart_data_receive();
    if(*(receive_string+i)==terminating_character)
      break;
    else
      temp++;
  }
  *(receive_string+temp)='\0';
  return receive_string;
}
