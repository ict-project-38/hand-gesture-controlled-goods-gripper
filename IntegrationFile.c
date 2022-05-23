#include "Mpu6050Input.c"
#include "ServoFlexFunctions.c"
#include "StepperFunctions.c"
#include "TriggerFunction.c"
#include "UltrasonicFunction.c"
#include "GripperFunction.c"
#include "BluetoothFunctions.c"


void Mpu6050Stepper();
void Mpu6050Servo();
void gripper();


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
		servoStop(3);
		servoStop(1);

	}
	else if ((*getSensorValues()==1)&& (*(getSensorValues()+6))==1)
	{
		servoRight(3);
	}
	else if((*getSensorValues()==2)&& (*(getSensorValues()+6))==1)
	{
		servoLeft(3);
	}
	if((*(getSensorValues()+2)==3)&& (*(getSensorValues()+6))==1)
	{
		servoRight(1);
	}
	else if((*(getSensorValues()+2)==4)&& (*(getSensorValues()+6))==1)
	{
		servoLeft(1);
	}

}

void gripper()
{


    int digitalVoltage;
    digitalVoltage=(*getVoltage()+*(getVoltage()+2))/2;

    if (digitalVoltage>=98)
    {
      servoRight(0);
    }  
    else
    {
      servoLeft(0);
    }                                                            //30 degree--50k----1.67V
    _delay_ms(500);                                               //45degree--62.5k---1.923V
}
