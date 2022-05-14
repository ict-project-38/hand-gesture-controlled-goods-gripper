
#include "FlexServoIntegration.c"






unsigned int i;	

void rotateRight()
{
   for(i=125;i<=250;i++)
	{	
	_delay_ms(1000);
	OCR1B = i;
	OCR1A = i;
	}
}

void rotateLeft()
{
   for(i=250;i>=125;i--)
	{
		_delay_ms(1000);
		OCR1B = i;
		OCR1A = i;
	
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