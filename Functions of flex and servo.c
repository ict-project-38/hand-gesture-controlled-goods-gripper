/*
 * flex and servo integration-electro.c
 *
 * Created: 5/8/2022 10:17:13 PM
 * Author : Danuraha Theva
 */ 

#define F_CPU 8000000UL		/* Define CPU Frequency e.g. here its 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */
#include <util/delay.h>		/* Include Delay header file */


void setup();
float getVoltage(float val);
void rotateZero();
void rotateNinty();
void rotateMinusNinty();
void loop();

int main()
{
	
}

float getVoltage(float val)
{
	return (val * 4.82 / 255.0);
}

void setup()
{
	
	
	DDRC=0XFF;                          //make c port as output
	DDRD=0XFF;                          //make D port as output
	DDRA=0x00;                             //make ADC port as input
	ADCSRA=0X87;                        //Enable ADC,fr/128
	ADMUX=0X40;
	

	DDRD |= (1<<PD5);	/* Make OC1A pin as output */
	TCNT1 = 0;		/* Set timer1 count zero */
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */

	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	ADCSRA |= (1 << ADSC);
	

}


void rotateZero()
{
	_delay_ms(1500);
	OCR1A = 175;	/* Set servo shaft at 0° position */
	_delay_ms(1500);
}


void rotateNinty()
{
	OCR1A = 300;	/* Set servo at +90° position */
	_delay_ms(1500);
}

void rotateMinusNinty()
{
	OCR1A = 65;	/* Set servo shaft at -90° position */
	_delay_ms(1500);
}

void loop()
{
	while(1)
	{
		
		ADCSRA |= (1 << ADSC);

		while (ADCSRA & (1 << ADSC))
		;


	
		float tem, volt;


		tem = ADCH * 1.0;
		volt = getVoltage(tem);


		switch (ADMUX)
		{
			case 0X40:

			if (volt >= 1.6)
			{
				
			}
			else if (volt < 1.6)
			{
				
			}


			ADMUX = 0X87;

			break;

			case 0X87:

			if (volt >= 1.5)
			{
				
			}
			else if (volt < 1.5)
			{
				
			}



			ADMUX = 0X40;
			break;
		}
		_delay_ms(500);
	}
}



