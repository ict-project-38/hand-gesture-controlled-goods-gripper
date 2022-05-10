#include <util/delay.h>



void HorizontalStepRight(char port, char pin) // Clockwise
{
    int dtime=15;
    
	port = 0x0F;		/* Make pin lower pins as output */
                        /* Set dtime in between two steps */
	while (1)
	{
		
		for(int i=0;i<12;i++)
		{
			pin = 0x09;
			_delay_ms(dtime);
			pin = 0x0C;
			_delay_ms(dtime);
			pin = 0x06;
			_delay_ms(dtime);
			pin = 0x03;
			_delay_ms(dtime);
		}
		//pin = 0x09;		/* Last step to initial position */ 
		//_delay_ms(dtime);
		//_delay_ms(1000);
    }
    
    
}

void HorizontalStepLeft(char port, char pin){	//AntiClocwise
    int dtime=15;
	port = 0x0F;		/* Make pin lower pins as output */
			/* Set dtime in between two steps */
	while (1)
	{
        /* Rotate Stepper Motor Anticlockwise with Full step sequence */
		for(int i=0;i<12;i++)
		{
			pin = 0x09;
			_delay_ms(dtime);
			pin = 0x03;
			_delay_ms(dtime);
			pin = 0x06;
			_delay_ms(dtime);
			pin = 0x0C;
			_delay_ms(dtime);
		}
		//pin = 0x09;
		//_delay_ms(dtime);
		//_delay_ms(1000);
    }
    
}

void VerticalStepUp(char port, char pin) // Clockwise
{
    int dtime=15;
    
	port = 0x0F;		/* Make pin lower pins as output */
                        /* Set dtime in between two steps */
	while (1)
	{
		
		for(int i=0;i<12;i++)
		{
			pin = 0x09;
			_delay_ms(dtime);
			pin = 0x0C;
			_delay_ms(dtime);
			pin = 0x06;
			_delay_ms(dtime);
			pin = 0x03;
			_delay_ms(dtime);
		}
		//pin = 0x09;		/* Last step to initial position */ 
		//_delay_ms(dtime);
		//_delay_ms(1000);
    }
    
    
}


void VerticalStepDown(char port, char pin){	//AntiClocwise
    int dtime=15;
	port = 0x0F;		/* Make pin lower pins as output */
			/* Set dtime in between two steps */
	while (1)
	{
        /* Rotate Stepper Motor Anticlockwise with Full step sequence */
		for(int i=0;i<12;i++)
		{
			pin = 0x09;
			_delay_ms(dtime);
			pin = 0x03;
			_delay_ms(dtime);
			pin = 0x06;
			_delay_ms(dtime);
			pin = 0x0C;
			_delay_ms(dtime);
		}
		//pin = 0x09;
		//_delay_ms(dtime);
		//_delay_ms(1000);
    }
    
}

void StepStop(char port,char pin){
	port = 0x0F;		/* Make pin lower pins as output */

	pin = 0x00;
}