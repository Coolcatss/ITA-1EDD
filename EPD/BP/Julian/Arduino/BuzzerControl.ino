int buzzerPin = 4;

int buzzerTone = 1000;

int buzzerLengte = 1000;
void buzzerControlSetup(){
  pinMode(buzzerPin, OUTPUT);
}

void buzzerControlTik(){
  tone(buzzerPin, buzzerTone);
}
void buzzerControlStop(){
  noTone(buzzerPin);
}
void buzzerControlTik1Sec(){
  tone(buzzerPin, buzzerTone, buzzerLengte);
}
