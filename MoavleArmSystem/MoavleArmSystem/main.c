/*
 * MoavleArmSystem.c
 *
 * Created: 5/13/2022 6:11:43 PM
 * Author : Thareejan
 */ 


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
			{
				servoStop(1,128);
				servoStop(2,128);
				servoStop(3,128);
				gripper();
			}
			else
			{
				if (*(getSensorValues()+7)==6)
					servoStop(0,128);
				else(*(getSensorValues()+7)==7)
					gripper();	
			}
			Mpu6050Stepper();
			Mpu6050Servo();	
			
			
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
	if ((*(getSensorValues()+3)==5)&& (*(getSensorValues()+6))==1 )
	{
		servoStop(3,128);
		servoStop(1,128);
		servoStop(2,128);
		

	}
	else if ((*getSensorValues()==1)&& (*(getSensorValues()+6))==1)
	{
		servoRight(3,128);
	}
	else if((*getSensorValues()==2)&& (*(getSensorValues()+6))==1)
	{
		servoLeft(3,128);
	}
	if((*(getSensorValues()+2)==3)&& (*(getSensorValues()+6))==1 && (*(getSensorValues()+7))==7)
	{
		servoRight(1,128);
	}
	else if((*(getSensorValues()+2)==4)&& (*(getSensorValues()+6))==1 && (*(getSensorValues()+7))==7)
	{
		servoLeft(1,128);
	}
	if((*(getSensorValues()+2)==3)&& (*(getSensorValues()+6))==1 && (*(getSensorValues()+7))==6)
	{
		servoRight(2,128);
	}
	else if((*(getSensorValues()+2)==4)&& (*(getSensorValues()+6))==1 && (*(getSensorValues()+7))==6)
	{
		servoLeft(2,128);
	}

}

void gripper()
{


    int digitalVoltage;
    digitalVoltage=(*getVoltage()+*(getVoltage()+2))/2;
    servoRight(0,int(digitalVoltage)); 
                                                             //30 degree--50k----1.67V
    _delay_ms(500);                                               //45degree--62.5k---1.923V
}
