#include "servoFunctions.c"
#include "flexFunctions.c"
#include "FsrGripperIntegration.c"
#include "UltrasonicServo.c"

int main()
{
    void loop()
    {

        if((*positionLogic()==5)&& trigger==1)
        {
            servoStop();
        }
        else if ((*positionLogic()==1)&& trigger==1 && (ultrasonic()>=10))
        {
            servo1Right();
        }
        else if ((*positionLogic()==2)&& trigger==1 && (ultrasonic()>=10))
        {
            servo1Left();
        }

        else if((*(positionLogic()+2)==3)&& trigger==1 && (ultrasonic()>=10))
        {
            servo3Up();
        }
        else if((*(positionLogic()+2)==4)&& trigger==1 && (ultrasonic()>=10))
        {
            servo3Down();
        }

        else if((trigger==1) && (fsr()<=5))
        {
           flex();
        }

        else if ((trigger==1) && (fsr()>=5))
        {
            stopGripper();
        }

    }
}



