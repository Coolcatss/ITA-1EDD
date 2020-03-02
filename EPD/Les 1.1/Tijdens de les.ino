int waitTime = 250;
const int LED_ROOD = 13;
const int LED_GEEL = 12;
const int LED_GROEN = 11;

void setup() {
  pinMode(LED_ROOD, OUTPUT);
  pinMode(LED_GEEL, OUTPUT);
  pinMode(LED_GROEN, OUTPUT);
}

void loop() {
  digitalWrite(LED_ROOD, HIGH);
  delay(waitTime);
  digitalWrite(LED_ROOD, LOW);
  digitalWrite(LED_GEEL, HIGH);
  delay(waitTime);
  digitalWrite(LED_GEEL, LOW);
  digitalWrite(LED_GROEN, HIGH);
  delay(waitTime);
  digitalWrite(LED_GROEN, LOW);
}
