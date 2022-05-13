#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "servoFunctions.c"
#include "Gripper.c"

float getVoltage(float val)
{
	return (5);
}
int fsr()
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

