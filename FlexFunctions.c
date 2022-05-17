
#include "servoFunctions.c"
#include "FlexServoIntegration.c"


int  voltage[2];
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

   
    voltage[] = getVoltage();
    int finalVoltage;
    finalVoltage=(voltage[0]+voltage[1])/2;

    if (finalVoltage>=342)
    {
      shrinkGripper;
    }  
    else
    {
      expandGripper;
    }                                                            //30 degree--50k----1.67V
    _delay_ms(500);
}
