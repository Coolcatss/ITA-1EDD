
const int SERVO_MAX = 90;
const int SERVO_MIN = 0;
int servoPos;
int servoGoal;

void slagboomConfig() {
  myservo.attach(6);
  servoPos = SERVO_MIN;
  servoGoal = SERVO_MAX;
  myservo.write(SERVO_MIN);
}

void slagboomOmhoog() {
  myservo.write(SERVO_MAX);
}

void slagboomOmlaag(){
  myservo.write(SERVO_MIN);
}
