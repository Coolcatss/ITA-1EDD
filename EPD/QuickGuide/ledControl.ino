byte ledPin1 = 13;
byte ledPin2 = 12;
byte ledPin3 = 11;

void ledControlSetup(){
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void ledControlSetLedOn(byte ledPin){
  digitalWrite(ledPin, HIGH);
}
void ledControlSetLedOff(byte ledPin){
  digitalWrite(ledPin, LOW);
}
