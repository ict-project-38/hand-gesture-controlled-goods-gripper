#include <util/delay.h>
int pin;
float getVoltage(float val)
{
	return (val * 4.82 / 255.0);
}

void rotateZero()
{
	
	pin = 175;	/* Set servo shaft at 0° position */
	_delay_ms(1500);
}


void rotateNinty()
{
	pin = 300;	/* Set servo at +90° position */
	_delay_ms(1500);
}

void rotateMinusNinty()
{
	pin = 65;	/* Set servo shaft at -90° position */
	_delay_ms(1500);
}
