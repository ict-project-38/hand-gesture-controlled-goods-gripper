/*
 * IntegretedCode.c
 *
 * Created: 5/13/2022 3:43:49 PM
 * Author : Thareejan
 */ 

#include <avr/io.h>
#include "Mpu6050Input.c"
//#include "ServoFlexFunctions.c"
#include "StepperFunctions.c"
//#include "TriggerFunction.c"
#include "UltrasonicFunction.c"
//#include "GripperFunction.c"
//#include "BluetoothFunctions.c"


//Function Declarations
void Mpu6050Stepper();
void Mpu6050Servo();
void gripper();
int trigger=1;

int main()
{
	void loop()
	{
		Mpu6050Stepper();
		Mpu6050Servo();	
	}
	return 0;
}


void Mpu6050Stepper()
{
	if ((*positionLogic()==5)&& trigger==0)
	{
		StepStop();
	}
	else if ((*positionLogic()==1)&& trigger==0)
	{
		HorizontalStepRight();
	}
	else if((*positionLogic()==2)&& trigger==0)
	{
		HorizontalStepLeft();
	}
	else if((*(positionLogic()+2)==3)&& trigger==0)
	{
		VerticalStepUp();
	}
	else if((*(positionLogic()+2)==4)&& trigger==0)
	{
		VerticalStepDown();
	}
}

void Mpu6050Servo()
{
	if ((*positionLogic()==5)&& trigger==1)
	{
		Servo1Stop();
		Servo3Stop();
	}
	else if ((*positionLogic()==1)&& trigger==1)
	{
		Servo1Right();
	}
	else if((*positionLogic()==2)&& trigger==1)
	{
		Servo1Left();
	}
	if((*(positionLogic()+2)==3)&& trigger==1)
	{
		Servo3up();
	}
	else if((*(positionLogic()+2)==4)&& trigger==1)
	{
		Servo3Down();
	}

}

void gripper()
{

}

