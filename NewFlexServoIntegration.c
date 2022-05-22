

#include "FlexFunctions.c"
void gripper()
{


    int digitalVoltage;
    digitalVoltage=(*getVoltage()+*(getVoltage()+2))/2;

    if (digitalVoltage>=394)
    {
      shrinkGripper;
    }  
    else
    {
      expandGripper;
    }                                                            //30 degree--50k----1.67V
    _delay_ms(500);                                               //45degree--62.5k---1.923V
}                                                                 //so 1.923V -----393.4458=394







