#define F_CPU 8000000UL 
#include <avr/io.h> 
#include <stdio.h> 
#include <avr/interrupt.h> 
#include <util/delay.h> 
#define Trigger_pin PA0
  
int TimerOverflow=0;

 ISR(TIMER1_OVF_vect) 
 { 	
    TimerOverflow++; 
 } 
	 

double ultrasonicValue()
{
			long count; 	
			double distance; 	
			DDRA = 0x01; 	
			PORTD= 0xFF; 	
			sei(); 	
			TIMSK=(1<<TOIE1); 	
			TCCR1A=0; 	 	
			PORTA|=(1<<Trigger_pin); 	
			_delay_us(10); 	
			PORTA&=(~(1<<Trigger_pin)); 	
			TCNT1=0; 	
			TCCR1B=0x41; 	
			TIFR=1<<ICF1; 	
			TIFR=1<<TOV1; 
	 
 while((TIFR&(1<<ICF1))==0);
					TCNT1=0;
					TCCR1B=0x01;
					TIFR=1<<ICF1;
					TIFR=1<<TOV1;
					TimerOverflow=0;
					while((TIFR&(1<<ICF1))==0);
					count=ICR1+(65535*TimerOverflow);
					distance=(double)count/466.67;
					DDRA=0x00;
					return distance;
	
  }
