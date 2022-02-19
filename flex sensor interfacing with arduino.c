#include <avr/io.h>
#include <util/delay.h>

void display(int data,int a);

int main()
{
	char arr[10];
	unsigned int a,i;
	DDRC=0XFF;                          //make c port as output
	DDRD=0XFF;                          //make D port as output
	DDRA=0x00;                             //make ADC port as input
	ADCSRA=0X87;                        //Enable ADC,fr/128
	ADMUX=0X40;                         // Vref : AVCC,ADC channel:0
	display(0x0e,0);
	display(0x38,0);
	display('a',1);
	while(1)
	{
		ADMUX=0X40;
		ADCSRA|=(1<<ADSC);                 //Start conversion
		while((ADCSRA&(1<<ADIF))==0);      //Monitor end of conversion interrupt
		a=ADCH;                            //Read higher byte
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








