#include <util/delay.h>
void HorizontalStepRight() // Clockwise
{
	int dtime=15;
	DDRB = 0x0F;		/* Make PORTB lower PORTBs as output */
	/* Set dtime in between two steps */
	while (1)
	{
		
		for(int i=0;i<12;i++)
		{
			PORTB = 0x09;
			_delay_ms(dtime);
			PORTB = 0x0C;
			_delay_ms(dtime);
			PORTB = 0x06;
			_delay_ms(dtime);
			PORTB = 0x03;
			_delay_ms(dtime);
		}
		//PORTB = 0x09;		/* Last step to initial position */
		//_delay_ms(dtime);
		//_delay_ms(1000);
	}
	
	
}

void HorizontalStepLeft(){	//AntiClocwise
	int dtime=15;
	DDRB = 0x0F;		/* Make PORTB lower PORTBs as output */
	/* Set dtime in between two steps */
	while (1)
	{
		/* Rotate Stepper Motor Anticlockwise with Full step sequence */
		for(int i=0;i<12;i++)
		{
			PORTB = 0x09;
			_delay_ms(dtime);
			PORTB = 0x03;
			_delay_ms(dtime);
			PORTB = 0x06;
			_delay_ms(dtime);
			PORTB = 0x0C;
			_delay_ms(dtime);
		}
		//PORTB = 0x09;
		//_delay_ms(dtime);
		//_delay_ms(1000);
	}
	
}

void VerticalStepUp() // Clockwise
{
	int dtime=15;
	
	DDRB = 0x0F;		/* Make PORTB lower PORTBs as output */
	/* Set dtime in between two steps */
	while (1)
	{
		
		for(int i=0;i<12;i++)
		{
			PORTB = 0x09;
			_delay_ms(dtime);
			PORTB = 0x0C;
			_delay_ms(dtime);
			PORTB = 0x06;
			_delay_ms(dtime);
			PORTB = 0x03;
			_delay_ms(dtime);
		}
		//PORTB = 0x09;		/* Last step to initial position */
		//_delay_ms(dtime);
		//_delay_ms(1000);
	}
	
	
}


void VerticalStepDown(){	//AntiClocwise
	int dtime=15;
	DDRB = 0x0F;		/* Make PORTB lower PORTBs as output */
	/* Set dtime in between two steps */
	while (1)
	{
		/* Rotate Stepper Motor Anticlockwise with Full step sequence */
		for(int i=0;i<12;i++)
		{
			PORTB = 0x09;
			_delay_ms(dtime);
			PORTB = 0x03;
			_delay_ms(dtime);
			PORTB = 0x06;
			_delay_ms(dtime);
			PORTB = 0x0C;
			_delay_ms(dtime);
		}
		//PORTB = 0x09;
		//_delay_ms(dtime);
		//_delay_ms(1000);
	}
	
}

void StepStop(){
	DDRB = 0x0F;		/* Make PORTB lower PORTBs as output */
	PORTB = 0x00;
}
