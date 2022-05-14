

#define F_CPU 1000000UL		/* Define CPU Frequency e.g. here its 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */
#include <util/delay.h>		/* Include Delay header file */
unsigned int duty;	
 int servoSetup()
{
	
	TCNT1 = 0;		/* Set timer1 count zero */
	ICR1 = 19999;		/* Set TOP count for timer1 in ICR1 register */
	DDRD |= (1<<PD5);
	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);	
	}
	
	int main(void)
	{
			/* Make OC1A pin as output */
		
		//DDRD = 0xFF;
		servoSetup();
	
	while(1)
	{	
		
			
				//OCR1A=22.5; 
		/*
		OCR1A = 65;	// Set servo shaft at -90° position 
		_delay_ms(150);
	
		
		OCR1A = 175;	// Set servo shaft at 0° position 
		
		_delay_ms(1500);
		
		OCR1A = 300;	// Set servo at +90° position 
		_delay_ms(1500);*/
		
		for(duty=14; duty<32; duty++)   // 0 to max duty cycle
		{
			OCR1A=duty;
		    //slowly increase the LED brightness
			_delay_ms(1000);
		//	OCR1A=0x00; 

		}
		
		for(duty=31; duty>=14; duty--)   // max to 0 duty cycle
		{
			OCR1A=duty;     //slowly decrease the LED brightness
			_delay_ms(1000);
		}
		
	
	}
	
}
