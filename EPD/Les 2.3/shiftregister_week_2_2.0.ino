const int DS = 8;
const int SH_CP = 10;
const int ST_CP = 9; // latch pin

byte patroon = B11110111; // B00000001

const int INTERVAL = 500;
unsigned long previousMillis;

void setup() {

  previousMillis = 0 - INTERVAL;

  pinMode(DS, OUTPUT);
  pinMode(SH_CP, OUTPUT);
  pinMode(ST_CP, OUTPUT);

  digitalWrite(DS, LOW);
  digitalWrite(SH_CP, LOW);
  digitalWrite(ST_CP, LOW);

  // alles uit
  digitalWrite(DS, LOW);

  for (int i = 0; i < 8; i++) {
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
  }

  digitalWrite(ST_CP, HIGH);
  digitalWrite(ST_CP, LOW);

}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;

    // shift register functionaliteit

    for (int i = 0; i < 8; i++) {
      if (isBitEen(patroon, i)) {
        digitalWrite(DS, HIGH);
      }
      else {
        digitalWrite(DS, LOW);
      }
      digitalWrite(SH_CP, HIGH);
      digitalWrite(SH_CP, LOW);
    }

    digitalWrite(ST_CP, HIGH);
    digitalWrite(ST_CP, LOW);

    // om de lampjes allemaal n keer te laten branden
    //    patroon = patroon << 1;
    //    if (patroon == 0){
    //      patroon = 1;
    //    }
    //
  }

  // go do smt else
}

boolean isBitEen (byte pattern, int index) {
  byte check = 1 << index;
  return (pattern & check) == check;
}
