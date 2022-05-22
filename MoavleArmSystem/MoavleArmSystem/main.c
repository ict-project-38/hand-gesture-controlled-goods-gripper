/*
 * MoavleArmSystem.c
 *
 * Created: 5/13/2022 6:11:43 PM
 * Author : Thareejan
 */ 
#define F_CPU 8000000UL		/* define Clock Frequency */
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
	pwmsetup();
	void loop()
	{
		if (ultrasonicValue()>10)
		{
			Mpu6050Stepper();
			Mpu6050Servo();
		}
		else
		{
			if (fsrValue()<5)
			gripper();
			else
			gripperStop();
			if(*(getSensorValues()+6)==0)
			Mpu6050Stepper();
			
		}
		

	}
	return 0;
}


void Mpu6050Stepper()
{
	if ((*getSensorValues()==5)&& (*(getSensorValues()+6))==0)
	{
		StepStop();
	}
	else if ((*getSensorValues()==1)&& (*(getSensorValues()+6))==0)
	{
		HorizontalStepRight();
	}
	else if((*getSensorValues()==2)&& (*(getSensorValues()+6))==0)
	{
		HorizontalStepLeft();
	}
	else if((*(getSensorValues()+2)==3)&& (*(getSensorValues()+6))==0)
	{
		VerticalStepUp();
	}
	else if((*(getSensorValues()+2)==4)&& (*(getSensorValues()+6))==0)
	{
		VerticalStepDown();
	}
}

void Mpu6050Servo()
{
	if ((*(getSensorValues()+3)==5)&& (*(getSensorValues()+6))==1)
	{
		Servo1Stop();
		Servo3Stop();
	}
	else if ((*getSensorValues()==1)&& (*(getSensorValues()+6))==1)
	{
		Servo1Right();
	}
	else if((*getSensorValues()==2)&& (*(getSensorValues()+6))==1)
	{
		Servo1Left();
	}
	if((*(getSensorValues()+2)==3)&& (*(getSensorValues()+6))==1)
	{
		Servo3up();
	}
	else if((*(getSensorValues()+2)==4)&& (*(getSensorValues()+6))==1)
	{
		Servo3Down();
	}

}

void gripper()
{
	char voltage[2];
	voltage[0] = *(getSensorValues()+3);
	voltage[1] = *(getSensorValues()+4);
	int finalVoltage;
	finalVoltage=(voltage[0]+voltage[1])/2;
	if (finalVoltage>=342)
	{
		shrinkGripper();
	}
	else
	{
		expandGripper();
	}                                                            //30 degree--50k----1.67V
	_delay_ms(500);

}
