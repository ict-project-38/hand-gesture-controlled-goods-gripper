#include <avr/io.h>
#include <util/delay.h>

int fsrValue()

{
	int val;
	ADCSRA=0X87;
	ADMUX=0X38;
	
	while(1)
	{
		ADMUX=0X38;
		ADCSRA|=(1<<ADSC);
		while((ADCSRA&(1<<ADIF))==0);
		val=ADCH;
		val=ADCL|ADCH<<8;
	}
	return val;
}
 

