

#include <avr/io.h>
#include <util/delay.h>
#include <ServoFunction.c>

float getFsrVoltage(int data);
float val;

void setup()
{
	
	unsigned int a,i;
	DDRC=0XFF;
	DDRD=0XFF;
	DDRA=0;
	ADCSRA=0X87;
	ADMUX=0X40;
	
	while(1)
	{
		ADMUX=0X40;
		ADCSRA|=(1<<ADSC);
		while((ADCSRA&(1<<ADIF))==0);
		a=ADCH;
		a=ADCL|ADCH<<8;
	}
}

float getFsrVoltage(int data)
{
	
	PORTA=data;

	PORTD|=1;

	PORTD&=~1;

	PORTD|=1<<1;
	_delay_ms(10);
	PORTD&=~(1<<1);
	_delay_ms(10);

	return (val);
}
int fsr()
{
		if (val>= 5)
		{
			stopGripper();

		}
		else if (val < 5)
		{
			shrinkGripper();
		}
		
	
	_delay_ms(500);
}
