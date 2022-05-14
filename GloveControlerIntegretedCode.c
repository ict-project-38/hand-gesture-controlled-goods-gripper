#include "ServoFlexFunctions.c"
#include "StepperFunctions.c"
#include "UltrasonicFunction.c"
#include "GripperFunction.c"
#include "BluetoothFunctions.c"




void Mpu6050Stepper();
void Mpu6050Servo();
void gripper();

int main()
{
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

}