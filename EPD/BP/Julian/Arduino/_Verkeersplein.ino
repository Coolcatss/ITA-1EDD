#include <Servo.h>

int onthouden;
int input;

void setup() {
  Serial.begin(9600);
  buttonControlSetup();
  ledControlSetup();
  segmentDisplaySetup();
  VerkeerspleinMainSetup();
  servoControlSetup();
}
int klik;
void loop() {
  VerkeerspleinMainLoop();
  buttonControlLoop();
  
  input = button_Clicked();
  
  if (onthouden != input) {
    input = onthouden;
    Serial.println(onthouden);
//    buzzerControlTik1Sec();
    if(klik == 5){
      klik = 0;
    }else {
      klik++;
    }
  }
  Serial.println(getButton());
    ledControlSetShiftRegister(ledControlPatronen(klik));
    segmentDisplaySetShiftRegister(segmentDisplayPatronen(klik));
}


//Save
//  buzzerControlStop();

//  servoControlOpenSlagboom();
//  ldrControlcheckStatusDag();
