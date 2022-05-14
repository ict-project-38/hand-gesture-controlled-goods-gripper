/*
 * MoavleArmSystem.c
 *
 * Created: 5/13/2022 6:11:43 PM
 * Author : Thareejan
 */ 
#define F_CPU 8000000UL		/* define Clock Frequency */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <util/delay.h>
int main()
{
	unsigned int i;
	TCNT1 = 0;		/* Set timer1 count zero */
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */

	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1)|(1<<COM1B1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	DDRD = 0b10110000;
	while(1)
	{
	for(i=125;i<=250;i++)
	{	
	_delay_ms(1000);
	OCR1B = i;
	OCR1A = i;
	OCR2  =i;
	}
	}
	return 0;

}