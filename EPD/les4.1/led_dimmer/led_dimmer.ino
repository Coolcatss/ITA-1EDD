const byte PIN = 3;
const int HZ= 60; //hoeveelheid knippers per seconde
const float DUTY_CYCLE= 0.25; // verteld hoe dim het ledje moet zijn


void setup() {
  pinMode(PIN, OUTPUT);

}

void loop() {
  float cycletime = 100/hz;
  float hightime= cycletime *DUTY_CYCLE;
  float lowtime = cycletime -hightime; // of lowTime = cycletime *(1-dutycycle);

  digitalWrite(PIN, HIGH);
  delay(hightime);
  digitalWrite(PIN, LOW);
  delay(lowtime);

}
