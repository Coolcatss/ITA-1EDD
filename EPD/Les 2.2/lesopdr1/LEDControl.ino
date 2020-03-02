// LED Lampen
// Kachung Li
// 06-02-2020

int ledPins[] = {13, 12, 11, 10, 9, 8, 7, 6, 5};
int amountLedPins = 8;


void ledControlSetup() {
  for (int i = 0; i < getAmountLedPins(); i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

// Geef de aantal pins terug. nodig voor andere methodes die niet direct bij de variabele bij komen.
int getAmountLedPins() {
  return amountLedPins;
}

// Geef de aantal pins terug, maar deel het door 2. Nodig voor de patroon samenvoegen.
int getHalfLedPins() {
  return getAmountLedPins() / 2;
}

int getLedState() {
  return ledState;
}

// Zet een lamp aan
void ledControlSetLedOn(int ledLamp) {
  digitalWrite(ledLamp, HIGH);
}

// Zet een lamp uit.
void ledControlSetLedOff(int ledLamp) {
  digitalWrite(ledLamp, LOW);
}

// Zet de led lamp aan en uit.
void ledControlToggleLed(int ledLamp) {
  digitalWrite(ledLamp, ledState);
}

void ledControlToggleLedState() {
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
}

void ledControlFlickerLed() {
  ledControlToggleLedState();
  for (int i = 0; i < getAmountLedPins(); i++) {
    ledControlToggleLed(ledPins[i]);
  }
}
