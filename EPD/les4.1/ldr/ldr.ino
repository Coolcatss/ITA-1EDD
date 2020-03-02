void setup() {
  pinMode(A2, INPUT);
  Serial.begin(9600);

}

void loop() {
  int value = analogRead(A2);
  Serial.println(value);

  delay(100);

}
