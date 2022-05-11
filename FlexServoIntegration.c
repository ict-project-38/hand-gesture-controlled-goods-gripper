#define F_CPU 8000000UL		/* Define CPU Frequency e.g. here its 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */
#include <util/delay.h>		/* Include Delay header file */
/*void setup()
{
	DDRC=0XFF;                          //make c port as output
	DDRD=0XFF;                          //make D port as output
	DDRA=0x00;                             //make ADC port as input
	reg1=0X87;                        //Enable ADC,fr/128
	reg4=0X40;


	DDRD |= (1<<PD5);	//Make OC1A pin as output
	TCNT1 = 0;		//Set timer1 count zero
	ICR1 = 2499;		//Set TOP count for timer1 in ICR1 register

//Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	reg1 |= (1 << reg2);

}
*/

void loop()
{
	while(1)
	{

		reg1 |= (1 << reg2);

		while (reg1 & (1 << reg2))
		;



		float tem, volt;


		tem = reg3 * 1.0;
		volt = getVoltage(tem);


		switch (reg4)
		{
			case 0X40:

			if (volt >= 1.6)
			{

			}
			else if (volt < 1.6)
			{

			}


			reg4 = 0X87;

			break;

			case 0X87:

			if (volt >= 1.5)
			{

			}
			else if (volt < 1.5)
			{

			}



			reg4 = 0X40;
			break;
		}
		_delay_ms(500);
	}
}
