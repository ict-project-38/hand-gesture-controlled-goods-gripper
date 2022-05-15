

#include <avr/io.h>
#include <util/delay.h>
#include <ServoFunction.c>

float getFsrVoltage(int data);
float val;

void setup()
{
	
	unsigned int data=a,;
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

	return (val);
}
float fsrvalue()
{
		if (val>= 5)
		{
			Gripperstop();

		}
		else if (val < 5)
		{
			Gripper();
		}
		
	
	_delay_ms(500);
}
