#define F_CPU 8000000UL		/* Define CPU Frequency e.g. here its 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */
#include <util/delay.h>		/* Include Delay header file */


unsigned int i;

void pwmsetup()
{

	DDRC=0xFF;
	DDRD = 0b00100000;

	TCNT1 = 0;		/* Set timer1 count zero */
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */

	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1)|(1<<COM1B1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
}


void servoRight(int pin)
{
	PORTC=pin;
	for(i=127;i<=255;i++)
	{
		_delay_ms(20);
		OCR1A = i;
	}
}

void servoLeft(int pin)
{
	PORTC=pin;
	for(i=255;i>=127;i--)
	{
		_delay_ms(20);
		OCR1A = i;
	}
	
}
void servoStop(int pin)
{
	PORTC=pin;
	PORTD=0xDF;
}
