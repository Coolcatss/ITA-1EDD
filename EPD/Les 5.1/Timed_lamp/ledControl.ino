const int LED_PIN = 11;

void ledControlSetup(){
  pinMode(LED_PIN, OUTPUT);
}

void ledControlSetLedOn(){
  digitalWrite(LED_PIN, HIGH);
}

void ledControlSetLedOff(){
  digitalWrite(LED_PIN, LOW);
}
