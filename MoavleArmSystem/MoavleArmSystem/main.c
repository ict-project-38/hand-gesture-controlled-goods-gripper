/*
 * MoavleArmSystem.c
 *
 * Created: 5/13/2022 6:11:43 PM
 * Author : Thareejan
 */ 

//#include <avr/io.h>


#ifndef F_CPU#define F_CPU 8000000UL#endif	/* Define CPU Frequency e.g. here its 8MHz */
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
		servoSetup();
	
	while(1)
	{	
		
		for(duty=14; duty<32; duty++)   // 0 to max duty cycle
		{
			OCR1A=duty;
			_delay_ms(1000);
		//	OCR1A=0x00; 

		}
		
		for(duty=31; duty>=14; duty--)   // max to 0 duty cycle
		{
			OCR1A=duty;
			_delay_ms(1000);
		}
		
	
	}
	
}
