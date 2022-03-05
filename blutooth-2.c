#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "HC05.h"
#include "USART.h"


char hc_05_buffer1[25], hc_05_buffer2[50];
char temp;

void hc_05_bluetooth_transmit_byte(char data_byte)
{
  usart_data_transmit(data_byte);
}

char hc_05_bluetooth_receive_byte(void)
{
  return usart_data_receive();
}

void hc_05_bluetooth_transmit_string(char *transmit_string)
{
  usart_string_transmit(transmit_string);
}

char *hc_05_bluetooth_receive_string(char *receive_string, unsigned char terminating_character)
{
  return usart_string_receive(receive_string,terminating_character);
}

unsigned char hc_05_bluetooth_at_command_mode_test(void)
{
  _delay_ms(500);
  usart_string_transmit("AT");
  usart_data_transmit(13);  //Enter terminator must addeed after command
  usart_data_transmit(10); //Enter terminator must addeed after command
  usart_string_receive(hc_05_buffer1,13);
  temp=usart_data_receive();
  if(!(strcmp(hc_05_buffer1,"OK")))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

unsigned char hc_05_bluetooth_device_name_change(char *device_name)
{
  _delay_ms(500);
  usart_string_transmit("AT+NAME=");
  usart_string_transmit(device_name);
  usart_data_transmit(13);
  usart_data_transmit(10);
  usart_string_receive(hc_05_buffer1,13);
  temp=usart_data_receive();
  if(!(strcmp(hc_05_buffer1,"OK")))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
unsigned char hc_05_bluetooth_get_version(void)
{
  unsigned char i=9,j=0;
  _delay_ms(500);
  usart_string_transmit("AT+VERSION?");
  usart_data_transmit(13);
  usart_data_transmit(10);
  usart_string_receive(hc_05_buffer2,13);
  for(i=9;hc_05_buffer2[i]!=0;i++)//i=9 b/c there is 9 words reserved for "+VERSION:"
  {
    hc_05_buffer2[j]=hc_05_buffer2[i];
    j++;
  }
  hc_05_buffer2[j]=0;
  if(!(strcmp(hc_05_buffer1,"OK")))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
unsigned  char hc_05_bluetooth_pin_change(char *new_pin)
{
  _delay_ms(500);
  usart_string_transmit("AT+PSWD=");
  usart_string_transmit(new_pin);
  usart_data_transmit(13);
  usart_data_transmit(10);

  usart_string_receive(hc_05_buffer1,13);
  temp=usart_data_receive();

  if(!(strcmp(hc_05_buffer1,"OK")))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

main



/*
 * Bluetooth.c
 *
 *  Created on: Mar 26, 2016
 *      Author: Mohamed
 */

#include <avr/io.h>
#include <util/delay.h>
#include "HC05.h"


#define setbit(Reg,Pos) Reg|=1<<Pos
#define clrbit(Reg,Pos) Reg&=~(1<<Pos)
#define togglebit(Reg,Pos) Reg^=1<<Pos

int main()
{
  usart_init();

  _delay_ms(500);
  _delay_ms(500);


  //send AT
  hc_05_bluetooth_transmit_string("Rabah");

  hc_05_bluetooth_transmit_byte(13);
  //Transmits Carriage return to Bluetooth Module/

  hc_05_bluetooth_transmit_byte(10);
  //Transmits New Line to Bluetooth Module for new line/

}
