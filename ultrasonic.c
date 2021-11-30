#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#define Trigger_pin PA1
#define Echo_pin PD6
int TimerOverflow = 0;
ISR(TIMER1_OVF_vect){
TimerOverflow++;
Overflow count
int main(void){
long count;
double distance;
DDRA |= (1 << Trigger_pin);
DDRD &= ~(1 << Echo_pin);
Page 10 of 18
PORTD |= (1 << Echo_pin);
sei();
TIMSK = (1 << TOIE1);
TCCR1A = 0;
while(1){
/* Give 10us trigger pulse on trig. pin to HC-SR04 */
PORTA |= (1 << Trigger_pin);
_delay_us(10);
PORTA &= (~(1 << Trigger_pin));
TCNT1 = 0;
TCCR1B = 0x41;
TIFR = 1<<ICF1;
TIFR = 1<<TOV1;
while ((TIFR & (1 << ICF1)) == 0);
TCNT1 = 0;
TCCR1B = 0b00000001;
TIFR = 1<<ICF1;
TIFR = 1<<TOV1;
TimerOverflow = 0;
while ((TIFR & (1 << ICF1)) == 0);
count = ICR1 + (65535 * TimerOverflow);
distance = (double)count / 466.47;
_delay_ms(200);
}}
