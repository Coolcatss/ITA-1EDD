const int LED = 13;
const int BUTTON = 9;
boolean ledState = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

}
void loop() {
  if (digitalRead(9) == 1) {
    ledState= !ledState;
    Serial.println(ledState);
    delay(150);
  }
  if (ledState == true) {
    digitalWrite(LED, HIGH);
    Serial.println("LED STAAT AAN");
  } else if(ledState == false) {
    digitalWrite(LED, LOW);
        Serial.println("LED STAAT UIT");
  }
}
