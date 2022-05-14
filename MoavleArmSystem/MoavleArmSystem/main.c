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
#include <util/delay.h>
void HorizontalStepRight() // Clockwise
{
	int dtime=15;
	DDRB = 0x0F;		/* Make PORTB lower PORTBs as output */
	/* Set dtime in between two steps */
	while (1)
	{
		
		for(int i=0;i<12;i++)
		{
			PORTB = 0x09;
			_delay_ms(dtime);
			PORTB = 0x0C;
			_delay_ms(dtime);
			PORTB = 0x06;
			_delay_ms(dtime);
			PORTB = 0x03;
			_delay_ms(dtime);
		}
		//PORTB = 0x09;		/* Last step to initial position */
		//_delay_ms(dtime);
		//_delay_ms(1000);
	}
	
	
}

void HorizontalStepLeft(){	//AntiClocwise
	int dtime=15;
	DDRB = 0x0F;		/* Make PORTB lower PORTBs as output */
	/* Set dtime in between two steps */
	while (1)
	{
		/* Rotate Stepper Motor Anticlockwise with Full step sequence */
		for(int i=0;i<12;i++)
		{
			PORTB = 0x09;
			_delay_ms(dtime);
			PORTB = 0x03;
			_delay_ms(dtime);
			PORTB = 0x06;
			_delay_ms(dtime);
			PORTB = 0x0C;
			_delay_ms(dtime);
		}
		//PORTB = 0x09;
		//_delay_ms(dtime);
		//_delay_ms(1000);
	}
	
}

void VerticalStepUp() // Clockwise
{
	int dtime=15;
	
	DDRB = 0xF0;		/* Make PORTB lower PORTBs as output */
	/* Set dtime in between two steps */
	while (1)
	{
		
		for(int i=0;i<12;i++)
		{
			PORTB = 0x90;
			_delay_ms(dtime);
			PORTB = 0xC0;
			_delay_ms(dtime);
			PORTB = 0x60;
			_delay_ms(dtime);
			PORTB = 0x30;
			_delay_ms(dtime);
		}
		//PORTB = 0x09;		/* Last step to initial position */
		//_delay_ms(dtime);
		//_delay_ms(1000);
	}
	
	
}


void VerticalStepDown(){	//AntiClocwise
	int dtime=15;
	DDRB = 0xF0;		/* Make PORTB lower PORTBs as output */
	/* Set dtime in between two steps */
	while (1)
	{
		/* Rotate Stepper Motor Anticlockwise with Full step sequence */
		for(int i=0;i<12;i++)
		{
			PORTB = 0x90;
			_delay_ms(dtime);
			PORTB = 0x30;
			_delay_ms(dtime);
			PORTB = 0x60;
			_delay_ms(dtime);
			PORTB = 0xC0;
			_delay_ms(dtime);
		}
		//PORTB = 0x09;
		//_delay_ms(dtime);
		//_delay_ms(1000);
	}
	
}

void StepStop(){
	DDRB = 0xFF;		/* Make PORTB lower PORTBs as output */
	PORTB = 0x00;
}

void pwmsetup()
{
	
	TCNT1 = 0;		/* Set timer1 count zero */
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */

	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1)|(1<<COM1B1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
}
int main()
{
	unsigned int i;
	pwmsetup();
	DDRC=0xFF;
	DDRD = 0b10110000;
	while(1)
	{
		HorizontalStepLeft();
		//VerticalStepUp();
		PORTC=0x00;
		for(i=127;i<=255;i++)
		{
			_delay_ms(20);
			OCR1B = i;
			OCR1A = i;
		}
		//_delay_ms(5000);
		PORTC=0x01;
		for(i=127;i<=255;i++)
		{
			_delay_ms(20);
			OCR1B = i;
			OCR1A = i;
		}
		PORTC=0x02;
		for(i=127;i<=255;i++)
		{
			_delay_ms(20);
			OCR1B = i;
			OCR1A = i;
		}
		PORTC=0x03;
		for(i=127;i<=255;i++)
		{
			_delay_ms(20);
			OCR1B = i;
			OCR1A = i;
		}	
	}
return 0;
}




