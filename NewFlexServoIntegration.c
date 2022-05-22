
void gripper(int a[])
{

   
    voltage[] = getVoltage();
    int finalVoltage;
    finalVoltage=(voltage[0]+voltage[1])/2;

    if (finalVoltage>=342)
    {
      shrinkGripper;
    }  
    else
    {
      expandGripper;
    }                                                            //30 degree--50k----1.67V
    _delay_ms(500);
}








