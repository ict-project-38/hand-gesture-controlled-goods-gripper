
#define F_CPU 8000000UL		/* define Clock Frequency */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <util/delay.h>

void setup()
{
	 DDRA=0xFF;
  ADCSRA=0b10000001;
 ADMUX=0b01000000;
	 ADCSRA |= (1 << ADSC);
	TCNT1 = 0;		/* Set timer1 count zero */
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */

	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1)|(1<<COM1B1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	DDRD = 0b10110000;

}
