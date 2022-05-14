
#include "servoFunctions.c"
#include "FlexServoIntegration.c"

float getVoltage(float val)
{
    return (val * 4.82 / 255.0);
}

int flex()
{

    switch (ADMUX)
    {
         ADCSRA |= (1 << ADSC);

        while (ADCSRA & (1 << ADSC));

         tem = ADCH * 1.0;
        volt = getVoltage(tem);
        
        case 0X40:
            if (volt >= 1.6)
            {
                expandGripper();

            }
            else if (volt < 1.6)
            {
                shrinkGripper();
            }
           

            ADMUX = 0X87;
            break;
        case 0X87:
            if (volt >= 1.6)
            {
                expandGripper();
            }
            else if (volt < 1.6)
            {
                shrinkGripper();
            }
          

            ADMUX = 0X40;
            break;
    }
    _delay_ms(500);
}
