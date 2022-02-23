/*
 * fsr.c
 *
 * Created: 06/12/2021 19:37:33
 * Author : Tharanika_P.
 */ 

#include <avr/io.h>
#include <util/delay.h>

void display(int data,int a);

int main()
{
	char arr[10];
	unsigned int a,i;
	DDRC=0XFF;
	DDRD=0XFF;
	DDRA=0;
	ADCSRA=0X87;
	ADMUX=0X40;
	display(0x0e,0);
	display(0x38,0);
	display('a',1);
	while(1)
	{
		ADMUX=0X40;
		ADCSRA|=(1<<ADSC);
		while((ADCSRA&(1<<ADIF))==0);
		a=ADCH;
		a=ADCL|ADCH<<8;
		sprintf(arr,"%04d",a);
		display(0x80,0);
		for(i=0;arr[i]!='\0';i++)
		{
			display(arr[i],1);
		}

		
	}
}

void display(int data,int a)
{
	PORTC=data;
	if(a==1)
	PORTD|=1;
	else
	PORTD&=~1;

	PORTD|=1<<1;
	_delay_ms(10);
	PORTD&=~(1<<1);
	_delay_ms(10);
}

