
#include "servoFunctions.c"
#include "FlexServoIntegration.c"


float val[2];
float tem, voltage;
float volt[2];
unsigned int a;
float getVoltage(float val[])
{
    ADCSRA=0b11000001; //start conversion
    ADMUX=0b01000000;
    while((ADCSRA & (0x10))==0);//wait for conversion
    a=ADCL|ADCH<<8;
    volt[0]=((val[0]) * 5 / 1024);

 //    //conversion saved in 10 bits


    ADCSRA=0b11000001;
    ADMUX=0b01000001;
    while ((ADCSRA & (0x10))==0);
     a=ADCL|ADCH<<8;
    volt[1]=(val[1] * 5 / 1024);
    return volt[];


}

void gripper()
{

    tem = ADCH * 1.0;
    voltage = getVoltage(tem);
    switch (ADMUX)
    {
        case 0b01100000:

            if (voltage >= 1)
            {
              
            }
            else if (voltage < 1.6)
            {
              
            }
            ADMUX = 0b01100001;
            break;
        case 0b01100001:
            if (voltage >= 1)
            {
               
            }
            else if (voltage < 1.5)
            {
               
            }
            ADMUX = 0b01100000;
            break;
    }
    _delay_ms(500);
}
