#define F_CPU 8000000UL		/* Define CPU Frequency e.g. here its 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */
#include <util/delay.h>		/* Include Delay header file */


int pin;
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

void stopGripper()
{
    _delay_ms(15000000000);
    pin = 175;	/* Set servo shaft at 0° position */




void servo1left()
{
    rotateMinusNinty();
}

void servo1Right()
{
    rotateNinty();
}

void servo3Up()
{
    rotateNinty();
}

void servo3Down()
{
    rotateMinusNinty();
}

void expandGripper()
{
    rotateNinty();
}

void shrinkGripper()
{
    rotateMinusNinty();
}

void servoStop()
{
    rotateZero();
}
