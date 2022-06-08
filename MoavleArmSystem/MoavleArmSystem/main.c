/*
 * MoavleArmSystem.c
 *
 * Created: 5/13/2022 6:11:43 PM
 * Author : Thareejan
 */

#define F_CPU 8000000UL /* define Clock Frequency */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <util/delay.h>

#include "ServoFunctions.c"
#include "StepperFunctions.c"
#include "UltrasonicFunction.c"
#include "BluetoothRecevierFunction.c"
#include "FsrFunction.c"

void Mpu6050Stepper();
void Mpu6050Servo();
void gripper();

int main()
{
        if (ultrasonicValue() > 10)
        {
            Mpu6050Stepper();
            Mpu6050Servo();
        }
        else
        {
            if (fsrValue() < 200)
            {
                servoStop(1, 128);
                servoStop(2, 128);
                servoStop(3, 128);
                gripper();
            }
            else
            {
                int n = *getSensorValues() + 7;
                if (n == 6)
                {
                    servoStop(0, 128);
                }
                else if (n == 7)
                {
                    gripper();
                }
            }
            Mpu6050Stepper();
            Mpu6050Servo();
        }
    
     return 0;
}

void Mpu6050Stepper()
{
    if ((*getSensorValues() == 5) && (*(getSensorValues() + 6)) == 0)
    {
        StepStop();
    }
    if ((*getSensorValues() == 1) && (*(getSensorValues() + 6)) == 0)
    {
        HorizontalStepRight();
    }
    if ((*getSensorValues() == 2) && (*(getSensorValues() + 6)) == 0)
    {
        HorizontalStepLeft();
    }
    if ((*(getSensorValues() + 2) == 3) && (*(getSensorValues() + 6)) == 0)
    {
        VerticalStepUp();
    }
    if ((*(getSensorValues() + 2) == 4) && (*(getSensorValues() + 6)) == 0)
    {
        VerticalStepDown();
    }
}

void Mpu6050Servo()
{
    if ((*(getSensorValues() + 3) == 5) && (*(getSensorValues() + 6)) == 1)
    {
        servoStop(3, 128);
        servoStop(1, 128);
        servoStop(2, 128);
    }
    else if ((*getSensorValues() == 1) && (*(getSensorValues() + 6)) == 1)
    {
		servoStop(1, 128);
		servoStop(2, 128);
        servoRight(3, 128);
    }
    else if ((*getSensorValues() == 2) && (*(getSensorValues() + 6)) == 1)
    {
        servoStop(1, 128);
        servoStop(2, 128);
		servoLeft(3, 128);
    }
    if ((*(getSensorValues() + 2) == 3) && (*(getSensorValues() + 6)) == 1 && (*(getSensorValues() + 7)) == 7)
    {
        servoStop(3, 128);
        servoStop(2, 128);
		servoRight(1, 128);
    }
    else if ((*(getSensorValues() + 2) == 4) && (*(getSensorValues() + 6)) == 1 && (*(getSensorValues() + 7)) == 7)
    {
        servoStop(3, 128);
        servoStop(2, 128);
		servoLeft(1, 128);
    }
    if ((*(getSensorValues() + 2) == 3) && (*(getSensorValues() + 6)) == 1 && (*(getSensorValues() + 7)) == 6)
    {
        servoStop(1, 128);
        servoStop(3, 128);
		servoRight(2, 128);
    }
    else if ((*(getSensorValues() + 2) == 4) && (*(getSensorValues() + 6)) == 1 && (*(getSensorValues() + 7)) == 6)
    {
        servoLeft(2, 128);
    }
}

void gripper()
{

    int digitalVoltage;
    digitalVoltage = (*(getSensorValues() + 4) + *(getSensorValues() + 5) / 2);
    servoRight(0, digitalVoltage);
    _delay_ms(500); 
}
