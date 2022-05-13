#define F_CPU 1000000UL		/* Define CPU Frequency e.g. here its 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */
#include <util/delay.h>		/* Include Delay header file */

void setup()
{
	 reg1 |= (1 << reg2);
    while (reg1 & (1 << reg2));
    float tem, volt;
    tem = reg3 * 1.0;
    volt = getVoltage(tem);

	TCNT1 = 0;		/* Set timer1 count zero */
	ICR1 = 19999;		/* Set TOP count for timer1 in ICR1 register */
	DDRD |= (1<<PD5);
	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);	

}
