diff --git a/stepper.c b/stepper.c
--- stepper.c
+++ stepper.c
@@ -1,1 +1,58 @@
-
+diff --git a/stepper.c b/stepper.c
+--- stepper.c
++++ stepper.c
+@@ -1,1 +1,53 @@
++#define F_CPU 8000000UL		/* Define CPU Frequency 8MHz */
++#include <avr/io.h>		/* Include AVR std. library file */
++#include <util/delay.h>		/* Include delay header file */
+ 
++
++int main(void)
++{
++	int period;
++	DDRD = 0x0F;		/* Make PORTD lower pins as output */
++	period = 100;		/* Set period in between two steps */
++	while (1)
++	{
++		/* Rotate Stepper Motor clockwise with Half step sequence */
++		for(int i=0;i<12;i++)
++		{
++			PORTD = 0x09;
++			_delay_ms(period);
++			PORTD = 0x08;
++			_delay_ms(period);
++			PORTD = 0x0C;
++			_delay_ms(period);
++			PORTD = 0x04;
++			_delay_ms(period);
++			PORTD = 0x06;
++			_delay_ms(period);
++			PORTD = 0x02;
++			_delay_ms(period);
++			PORTD = 0x03;
++			_delay_ms(period);
++			PORTD = 0x01;
++			_delay_ms(period);
++		}
++		PORTD = 0x09;		/* Last step to initial position */ 
++		_delay_ms(period);
++		_delay_ms(1000);
++
++		/* Rotate Stepper Motor Anticlockwise with Full step sequence */
++		for(int i=0;i<12;i++)
++		{
++			PORTD = 0x09;
++			_delay_ms(period);
++			PORTD = 0x03;
++			_delay_ms(period);
++			PORTD = 0x06;
++			_delay_ms(period);
++			PORTD = 0x0C;
++			_delay_ms(period);
++		}
++		PORTD = 0x09;
++		_delay_ms(period);
++		_delay_ms(1000);
++	}
++}
+\ No newline at end of file
