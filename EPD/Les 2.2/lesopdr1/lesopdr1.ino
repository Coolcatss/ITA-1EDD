unsigned long previousMillis;
int INTERVAL = 100;
int ledState = LOW; 


void setup() {
  previousMillis = 0 - INTERVAL;
  pinMode(7, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= INTERVAL) {
  
    ledControlFlickerLed();
    
    previousMillis = currentMillis;
  }
}
