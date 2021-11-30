/*
 * servo.c
 * Created: 11/29/2021 6:22:06 PM
 * Author : Thareejan
 */
#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz clock speed
#endif
#include <avr/io.h> //Including necessery libraries
#include <util/delay.h>
int main(void)
{
	DDRC = 0x01;  //Makes PC0 as output pin
	PORTC = 0x00; //Initial Value Declaration
	while(1)
	{
		//Rotate Motor to 0 degree
		PORTC = 0x01; //Assign Value PC0 pin
		_delay_us(1000); //Delaying 1 seconds
		PORTC = 0x00;
		_delay_ms(2000); //Delaying 2 Seconds
		//Rotate Motor to 90 degree
		PORTC = 0x01;
		_delay_us(1500);
		PORTC = 0x00;
		_delay_ms(2000);
		//Rotate Motor to 180 degree
		PORTC = 0x01;
		_delay_us(2000);
		PORTC = 0x00;
		_delay_ms(2000);
	}
}
