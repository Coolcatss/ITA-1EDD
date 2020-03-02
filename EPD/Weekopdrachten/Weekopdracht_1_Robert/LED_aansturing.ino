void keyH(int speed) {
  for (int thisPin = 13; thisPin > 5; thisPin-- ) {
    digitalWrite(thisPin, HIGH);
    delay(speed);
    digitalWrite(thisPin, LOW);
  }
}

void keyS(int speed) {
  byte LEDSeq [5][8] = {
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  };
  int LEDSeqLength = 4;
  for (int sequence = 0; sequence < LEDSeqLength; sequence++) {
    for (int pin = 0; pin < numberOfLeds(); pin++ ) {
      digitalWrite(pinArray(pin), LEDSeq [sequence][pin]);
    }
    delay(speed);
  }
}

void R(int speed) {
  for (int thisPin = 6; thisPin < 18; thisPin++ ) {
    digitalWrite(thisPin, HIGH);
    delay(speed);
  }
}

void L(int speed) {
  for (int thisPin = 13; thisPin > 5; thisPin-- ) {
    digitalWrite(thisPin, HIGH);
    delay(speed);
  }
}

void E() {
  for (int thisPin = 13; thisPin > 5; thisPin-- ) {
    digitalWrite(thisPin, LOW);
  }
}
