#define F_CPU 8000000UL		
#include <avr/io.h>		
#include <stdio.h>		
#include <util/delay.h>		


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