#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "servoFunctions.c"


float getVoltage(float val)
{
	return (5);
}
float fsr()
{
	if (fsr >= 5)
			{
			stopgripper();	
			}
       else if (fsr < 5)
			{
			shrinkgripper();
			}
}

