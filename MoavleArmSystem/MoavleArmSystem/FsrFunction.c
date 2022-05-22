#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int fsrValue()
{
	int Vin,VinLow;
	DDRA=0x38;			       /* Make ADC port as input */
	ADCSRA = 0x87;			   /* Enable ADC, fr/128  */
	ADMUX = 0x38;			   /* Vref: Avcc, ADC channel: 0 */
	
	ADCSRA |= (1<<ADSC);		    /* Start conversion */
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */
	
	_delay_us(10);
	VinLow = (int)ADCL;	        /* Read lower byte*/
	Vin = (int)ADCH*256;		/* Read higher 2 bits and Multiply with weight */
	Vin = Vin + VinLow;				
	return(Vin);			    /* Return digital value*/
}


