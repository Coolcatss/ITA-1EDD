const int DS = 8;     // Hiermee geef je door hoeveel ledjes aan moeten staan
const int SH_CP = 10; // clock
const int ST_CP = 9;  // latch pin/ einde van send.

unsigned long previosMilles;
unsigned long previosMilles2;
const int INTERVAL = 40;
const int INTERVAL2 = 3000;

const int LEEG_DISPLAY = 1;
const int ROLLEN = 2;
const int UITROLLEN = 3;
const int TOON_WAARDE = 4;

int huidigeToestand = LEEG_DISPLAY;

void setup() {
  previosMilles = 0 - INTERVAL;
  previosMilles2 = 0 - INTERVAL2;
  startShiftRegsister();
  Serial.begin(9600);
}

void loop() {
  char input;
  input = Serial.read();
  unsigned long currentMillis = millis();
    unsigned long currentMillis2 = millis();

  switch (huidigeToestand) {
    case LEEG_DISPLAY:
      leegDisplay(input);
      break;
    case ROLLEN:
      rollen(input, currentMillis, INTERVAL);
      break;
    case UITROLLEN:
      uitrollen(input, currentMillis, 80, currentMillis2, INTERVAL2);
      break;
    case TOON_WAARDE:
      toonWaarde(input);
      break;
  }
}
