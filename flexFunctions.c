
#include "servoFunctions.c"
#include "FlexServoIntegration.c"

float getVoltage(float val)
{
    return (val * 4.82 / 255.0);
}

int flex()
{

    switch (reg4)
    {
        case 0X40:
            if (volt >= 1.6)
            {
                expandGripper();

            }
            else if ((volt < 1.6)&& (volt >0.3))
            {
                shrinkGripper();
            }
           

            reg4 = 0X87;
            break;
        case 0X87:
            if (volt >= 1.6)
            {
                expandGripper();
            }
            else if ((volt < 1.6) && (volt >0.3))
            {
                shrinkGripper();
            }
          

            reg4 = 0X40;
            break;
    }
    _delay_ms(500);
}
