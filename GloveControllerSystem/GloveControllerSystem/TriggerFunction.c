int triggerSwitchVal()
{
	DDRB=0x00;
	if (PINB==0x01)
		return 1;
	if (PINB==0x00)
		return 0;

}