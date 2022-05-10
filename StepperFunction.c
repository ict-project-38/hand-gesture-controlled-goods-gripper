#include <util/delay.h>
void Clockwise(char port, char pin)
{
    int dtime=15;
    
	port = 0x0F;		/* Make pin lower pins as output */
                        /* Set dtime in between two steps */
	while (1)
	{
		/* Rotate Stepper Motor clockwise with Full step sequence */
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

void AntiClockwise(char port, char pin){
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

void Stop(char port,char pin){
	port = 0x0F;		/* Make pin lower pins as output */

	pin = 0x00;
}