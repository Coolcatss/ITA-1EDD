int servoPin = 3;
Servo servo;

void servoControlSetup(){
  servo.attach(servoPin);
}

void servoControlOpenSlagboom(){
  servo.write(90);

}
void servoControlSluitSlagboom(){
  servo.write(180);
  }
