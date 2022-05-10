#include "Mpu6050Input.c"
#include "ServoFlexFunctions.c"
#include "StepperFunctions.c"
#include "TriggerFunction.c"




int int main()
{
	void loop()
	{
		if ((*positionLogic()==5)&& trigger==0))
		{
			StepStop();
		}
		else if ((*positionLogic()==1)&& trigger==0))
		{
			HorizontalStepRight();
		}
		else if((*positionLogic()==2)&& trigger==0)
		{
			HorizontalStepLeft();
		}
		else if((*(positionLogic()+2)==3)&& trigger==0))
		{
			VerticalStepUp();
		}
		else if((*(positionLogic()+2)==4)&& trigger==0))
		{
			VerticalStepDown();
		}

	}
	return 0;
}
