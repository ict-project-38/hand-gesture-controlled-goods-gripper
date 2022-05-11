#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "servoFunctions.c"

float getVoltage(float val)
{
    return (val * 4.82 / 255.0);
}

int flex()
{

    reg1 |= (1 << reg2);
    while (reg1 & (1 << reg2));
    float tem, volt;
    tem = reg3 * 1.0;
    volt = getVoltage(tem);

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
            else if (volt <= 0.3)
            {
                stopGripper();
            }

            reg4 = 0X87;
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
            else if (volt <= 0.3)
            {
                stopGripper();
            }

            reg4 = 0X40;
            break;
    }
    _delay_ms(500);
}
