#include <Servo.h>
Servo myservo;

void setup() {
  Serial.begin(9600);
  slagboomConfig();
  statesConfig();
  invoerConfig();
  geluidConfig();
  startShiftRegister1();
  startShiftRegister2();
}

void loop() {
  states_loop();
  geluid();
}
