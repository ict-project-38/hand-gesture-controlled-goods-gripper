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
	
			if (volt >= 5)
			{
				
			}
			else if (volt < 5)
			{
				
			}
		}
		_delay_ms(500);
	}
}
