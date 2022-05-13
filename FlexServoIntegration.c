#define F_CPU 8000000UL		/* Define CPU Frequency e.g. here its 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */
#include <util/delay.h>		/* Include Delay header file */

void setup()
{
	 reg1 |= (1 << reg2);
    while (reg1 & (1 << reg2));
    float tem, volt;
    tem = reg3 * 1.0;
    volt = getVoltage(tem);

	
}
