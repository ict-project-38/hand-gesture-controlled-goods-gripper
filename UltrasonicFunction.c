#define F_CPU 8000000UL 
#include <avr/io.h> 
#include <stdio.h> 
#include <avr/interrupt.h> 
#include <util/delay.h> 
#define Trigger_pin PD7
  
int TimerOverflow=0;
 ISR(TIMER1_OVF_vect) 
 { 	
    TimerOverflow++; 
 } 
	 
double ultrasonic()
{long count; 	
 double distance; 	
  DDRD =0b10000000; 	
  PORTD= 0b01111111; 	
sei(); 	
TIMSK=(1<<TOIE1); 	
TCCR1A=0; 	 	
PORTD|=(1<<Trigger_pin); 	
_delay_us(10); 	
PORTD &=(~(1<<Trigger_pin)); 	
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
	DDRD=0x00;
	return distance;
	
     }
       
