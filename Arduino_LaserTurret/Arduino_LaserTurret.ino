#include <Servo.h>

Servo servoX;
Servo servoY;

const int servoXPin = 10;
const int servoYPin = 9;

int angleX = 90;
int angleY = 90;

void receiveCommand() {
  char command;
  while(Serial.available() > 0){
    command = Serial.read();
    if (command == 'w' && angleY < 180)
      angleY = angleY - 5;
    if (command == 's' && angleY > 0)
      angleY = angleY + 5;
    if (command == 'a' && angleX < 180)
      angleX = angleX + 5;
    if (command == 'd' && angleX > 0)
      angleX = angleX - 5;
    }
}
void updateTurret () {
  servoX.write(angleX);
  servoY.write(angleY);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoX.attach(servoXPin);
  servoY.attach(servoYPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  receiveCommand();
  updateTurret();
}
