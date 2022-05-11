int Anti-Clockwise(period){
    int period;
	DDRD = 0x0F;		/* Make PORTD lower pins as output */
			/* Set period in between two steps */
	while (1)
	{
        /* Rotate Stepper Motor Anticlockwise with Full step sequence */
		for(int i=0;i<12;i++)
		{
			PORTD = 0x09;
			_delay_ms(period);
			PORTD = 0x03;
			_delay_ms(period);
			PORTD = 0x06;
			_delay_ms(period);
			PORTD = 0x0C;
			_delay_ms(period);
		}
		PORTD = 0x09;
		_delay_ms(period);
		_delay_ms(1000);
    }
    
}

