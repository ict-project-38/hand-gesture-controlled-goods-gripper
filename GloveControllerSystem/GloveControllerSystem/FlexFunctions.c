unsigned int a[2];


int* getVoltage()
{
	DDRA=0x00;
	ADCSRA=0b10000001;
	ADMUX=0b01000000;
	ADCSRA |= (1 << ADSC);
	int Ain;
	int AinLow;

	ADCSRA=0b11000001;
	ADMUX=0b01000000;
	while((ADCSRA & (0x10))==0);
	_delay_us(10);
	AinLow = (int)ADCL;
	Ain = (int)ADCH*256;
	Ain = Ain+ AinLow;
	a[0]=((Ain/1023)*128);
	_delay_ms(10);





	ADCSRA=0b11000001;
	ADMUX=0b01000001;
	while ((ADCSRA & (0x10))==0);
	_delay_us(10);
	AinLow = (int)ADCL;
	Ain= (int)ADCH*256;
	AinLow = Ain+ AinLow;
	a[1]=((Ain/1023)*128);
	_delay_ms(10);
	return a;


}
