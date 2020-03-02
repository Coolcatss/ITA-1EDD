const int LED_ROOD = 13;
boolean gedaan = true;

void setup() {
  pinMode(LED_ROOD, OUTPUT);
  digitalWrite(LED_ROOD, HIGH);
}

void loop() {
  //  while (millis() < 2000) {
  //    digitalWrite(LED_ROOD, HIGH);
  //    delay (1000);
  //    digitalWrite(LED_ROOD, LOW);
  //    delay (1000);
  //  }
  //  digitalWrite(LED_ROOD, HIGH);
  //  delay (250);
  //  digitalWrite(LED_ROOD, LOW);
  //  delay (250);

  //  for (int e = millis(); ; e < 2000 ) {
  //    digitalWrite(LED_ROOD, HIGH);
  //    delay (1000);
  //    digitalWrite(LED_ROOD, LOW);
  //    delay (1000);
  //  }
  //  for (int e = millis(); ; e > 2000) {
  //    digitalWrite(LED_ROOD, HIGH);
  //    delay (250);
  //    digitalWrite(LED_ROOD, LOW);
  //    delay (250);
  //  }

  if(gedaan == false){
  knipperlicht(2000, 1000);}else{
  knipperlicht(2000, 250);}
}
void knipperlicht(int duur, int hz) {
  int tijd = millis()+(-millis());
  while (tijd < duur) {
    digitalWrite(LED_ROOD, HIGH);
    delay (hz);
    digitalWrite(LED_ROOD, LOW);
    delay (hz);
  }
  gedaan =!gedaan;
}
