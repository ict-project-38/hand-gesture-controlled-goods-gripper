
#include "servoFunctions.c"
#include "FlexServoIntegration.c"


float  voltage[2];
unsigned int a[];
float getVoltage()                 
{
    ADCSRA=0b11000001; //start conversion
    ADMUX=0b01000000;  //set input channel to read
    while((ADCSRA & (0x10))==0);//wait for conversion
    a[0]=ADCL|ADCH<<8;                                                                                      //   Dout = Vin / step size.
     _delay_ms(10);


 //    //conversion saved in 10 bits


    ADCSRA=0b11000001;
    ADMUX=0b01000001;   /
    while ((ADCSRA & (0x10))==0);
     a[1]=ADCL|ADCH<<8;
     _delay_ms(10);
    return a[];


}









//function for integration of flex and gripper





void gripper(int a[])
{

   // tem = ADCH * 1.0;
    voltage[] = getVoltage();
    switch (ADMUX)
    {
        case 0b01100000:

            if (voltage[0] >=204.6 )          //   1/(5/1023)
            {
              expandGripper;
            }
            else if (voltage[0] <204.6 )
            {
              shrinkGripper;
            }
            ADMUX = 0b01100001;
            break;
        case 0b01100001:
            if (voltage[1] >=204.6)
            {
               expandGripper;
            }
            else if (voltage[1] <204.6)
            {
               shrinkGripper;
            }
            ADMUX = 0b01100000;
            break;
    }
    _delay_ms(500);
}
