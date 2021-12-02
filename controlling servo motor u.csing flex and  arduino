#include <Servo.h>

Servo myServo;

const int flexPin = A0;

void setup()
{
    myServo.attach(11);
}

void loop()
{
    int flexValue;
    int servoPosition;

    flexValue = analogRead(flexPin);

    servoPosition = map(flexValue, 800, 900, 0, 180);
    servoPosition = constrain(servoPosition, 0, 180);

    myServo.write(servoPosition);

    delay(20);
}
