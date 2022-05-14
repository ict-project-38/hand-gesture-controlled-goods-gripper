#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "servoFunctions.c"


float getFsrVoltage(float val);
fsr=getFsrVoltage();
{
	return (5);
}
float fsr()
{
	 ADCSRA |= (1 << ADSC);

        while (ADCSRA & (1 << ADSC));
	if (fsr >= 5)
			{
			stopgripper();	
			}
       else if (fsr < 5)
			{
			shrinkgripper();
			}
}

