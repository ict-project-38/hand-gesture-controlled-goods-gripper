#include <avr/io.h>             // This header file includes the appropriate Input/output definitions for the device 
#include <util/delay.h>         // to use delay function we need to include this library
#include <stdlib.h>             // we'll be using itoa() function to convert integer to character array that resides in this library

#define lcd_port PORTD          // we have connected the lcd on port D
#define lcd_data_dir  DDRD      // we're defining the direction of the pins, weather it is input or output
#define rs PD0                  // we need total six pin to show output on the LCD. Datapin 4, 5, 6, and 7 for sending the data to the lcd and Enable and RS pin for controlling 
                                // the behavior of the LCD we have connected RS pin of LCD to port D pin 0
#define en PD1                  // we have connected Enable pin of LCD to port D pin 1

#define US_PORT PORTC           // we have connected the Ultrasonic sensor on port C. to use the ultrasonic we need two pins of the ultrasonic to be connected on port C
#define US_PIN PINC            // we need to initialize the pin resistor when we want to take input.
#define US_DDR  DDRC            // we need data-direction-resistor (DDR) to set the direction of data flow. input or output. we will define it later, now we're just naming it.

#define US_TRIG_POS PC0         // the trigger pin of ultrasonic sound sensor is connected to port C pin 0
#define US_ECHO_POS PC1         // the echo pin of the ultrasonic sound sensor is connected to port C pin 1

#define led1 PC2                // we've connected four of the LEDs to port C and one LED to port D. The first LED is connected to port C pin 2
#define led2 PC3                // The second LED is connected to port C pin 3 and so on for the rest of the LEDs....
#define led3 PC4
#define led4 PC5
#define led5 PD2

#define US_ERROR  -1      // we're defining two more variables two know if the ultrasonic sensor is working or not 
#define US_NO_OBSTACLE -2

int distance, previous_distance;


/*
We need total three functions to use the ultrasonic sound sensor. First we will initialize it, then generate ultrasonic sound wave and the 
third step is measuring the time between generated wave and echo back wave after hitting an object. The complete reference to use the ultrasonic 
sound sensor with math will be available on this link:  https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
Though the tutorial is for arduino but the concept is all the same. Please read the article throughly to have a clear understanding.

*/

void HCSR04Init();
void HCSR04Trigger();

void lcd_command( unsigned char );

void HCSR04Init()
{
 
 // we're setting the trigger pin as output as it will generate ultrasonic sound wave
 US_DDR|=(1<<US_TRIG_POS);
}

void HCSR04Trigger()
{   // this function will generate ultrasonic sound wave for 15 microseconds 
 //Send a 10uS pulse on trigger line
 
 US_PORT|=(1<<US_TRIG_POS); //high
 
 _delay_us(15);    //wait 15uS
 
 US_PORT&=~(1<<US_TRIG_POS); //low
}

uint16_t GetPulseWidth()
{
 // this function will be used to measure the pulse duration. When the ultra sound echo back after hitting an object
 // the microcontroller will read the pulse using the echo pin of the ultrasonic sensor connected to it. 
 
 uint32_t i,result;

 // Section - 1: the following lines of code before the section - 2 is checking if the ultrasonic is working or not
 // it check the echo pin for a certain amount of time. If there is no signal it means the sensor is not working or not connect properly
 for(i=0;i<600000;i++)
 {
  if(!(US_PIN & (1<<US_ECHO_POS)))
  continue; //Line is still low, so wait
  else
  break;  //High edge detected, so break.
 }

 if(i==600000)
 return US_ERROR; //Indicates time out
