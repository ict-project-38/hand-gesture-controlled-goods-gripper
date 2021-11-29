const int flexPin = A0;
const int ledPin = 7;

void setup()
{
    Serial.begin(9600);
    pinMode(ledPin,OUTPUT);
}

void loop()
{
    int flexValue;
    flexValue = analogRead(flexPin);
    Serial.print("sensor: ");
    Serial.println(flexValue);

    if(flexValue>890)
        digitalWrite(ledPin,HIGH);
    else
        digitalWrite(ledPin,LOW);

    delay(20);
}








