/*
 * GloveControllerSystem.c
 *
 * Created: 5/19/2022 1:03:30 AM
 * Author : Thareejan
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "USART_RS232_H_file.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//Include Essential Functions related to the Modules
#include "Mpu6050Input.c"
#include "TriggerFunction.c"
#include "FlexFunctions.c"

//Declarations of Functions and Global Variables
void USART_Init(unsigned long BAUDRATE);
void USART_TxChar(char data);
void USART_SendSensorValue(char *SensorValues);
char out_arr[6];

void USART_Init(unsigned long BAUDRATE)
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1);
	UBRRL = BAUD_PRESCALE;
	UBRRH = (BAUD_PRESCALE >> 8);
}

void USART_TxChar(char data)
{
	UDR = data;
	while (!(UCSRA & (1<<UDRE)));
}

void USART_SendSensorValue(char *SensorValues)
{
	int i=0;
	for(i;i<6;i++)
	{
		USART_TxChar(*(SensorValues+i));
	}
}


int main(void)
{
	char Data_in;
	USART_Init(9600);
	
	while(1)
	{
		out_arr[0] =  *positionLogic();
		out_arr[1] = (*positionLogic()+1);
		out_arr[2] = (*positionLogic()+2);
		out_arr[3] = *getVoltage();
		out_arr[4] = *(getVoltage()+1);
		out_arr[5] = triggerSwitchVal();
		USART_SendSensorValue(out_arr);
		return 0;
	}
}
