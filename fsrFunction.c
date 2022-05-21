
#include <avr/io.h>
#include <util/delay.h>

float fsrValue()

{
	float val;
	ADCSRA=0X87;
	ADMUX=0X40;
	
	while(1)
	{
		ADMUX=0X40;
		ADCSRA|=(1<<ADSC);
		while((ADCSRA&(1<<ADIF))==0);
		val=ADCH;
		val=ADCL|ADCH<<8;
	}
	return val;
}
 
