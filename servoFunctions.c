#define F_CPU 1000000UL		/* Define CPU Frequency e.g. here its 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */
#include <util/delay.h>		/* Include Delay header file */







unsigned int duty;	

void rotateRight()
{
   	for(duty=14; duty<32; duty++)  
		{
			OCR1A=duty;
			_delay_ms(1000);
		}
}

void rotateLeft()
{
   for(duty=31; duty>=14; duty--)  
		{
			OCR1A=duty;   
			_delay_ms(1000);
		}
}

void stopGripper()
{
    gripperPin=0x00;
}



void servo1left()
{
    rotateLeft();
}

void servo1Right()
{
    rotateRight();
}

void servo3Up()
{
    rotateRight();
}

void servo3Down()
{
    rotateLeft();
}

void expandGripper()
{
    rotateRight();
}

void shrinkGripper()
{
    rotateLeft();
}

void servo1Stop()
{
  servo1Pin=0x00;
}

void servo3Stop()
{
   servo3Pin=0x00;
}