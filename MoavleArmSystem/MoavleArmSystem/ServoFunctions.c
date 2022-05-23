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

/*int main()
{
	
}*/


void rotateRight()
{

	for(i=127;i<=255;i++)
	{
		_delay_ms(20);
		OCR1A = i;
	}
}


void rotateLeft()
{
	for(i=255;i>=127;i--)
	{
		_delay_ms(20);
		OCR1A = i;
	}
	
}


void stopGripper()
{
	PORTC=0x00;
	PORTC=0xF6;
	PORTD=0xDD;
	

}



void servo1Left()
{
	PORTC=0x03;
	rotateLeft();
}

void servo1Right()
{
	PORTC=0x03;
	rotateRight();
}
void servo2Up()
{
	PORTC=0x02;
	rotateRight();
}

void servo2Down()
{
	PORTC=0x02;
	rotateLeft();
}

void servo3Up()
{
	PORTC=0x01;
	rotateRight();
}

void servo3Down()
{
	PORTC=0x01;
	rotateLeft();
}

void expandGripper()
{
	PORTC=0x00;
	rotateRight();
}

void shrinkGripper()
{
	PORTC=0x00;
	rotateLeft();
}

void servo1Stop()
{
	PORTC=0x03;
	PORTC=0xF6;
	
}

void servo2Stop()
{
	PORTC=0x02;
	PORTC=0xF6;
	PORTD=0xDD;
	
}

void servo3Stop()
{
	PORTC=0x01;
	PORTC=0xF6;
	PORTD=0xDD;

}
