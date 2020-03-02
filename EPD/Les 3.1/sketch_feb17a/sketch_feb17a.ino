// Tot opdracht 2


int potmeter = A0;
int rememberWaarde = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int waarde = analogRead(potmeter);
  mapfunctie(waarde, 4);

}

void mapfunctie(long waarde, int maxWaarde) {
  waarde = waarde / 100;
  if (waarde != rememberWaarde && rememberWaarde != maxWaarde) {
    Serial.println(waarde);
  }
  if (waarde < maxWaarde) {
    rememberWaarde = waarde;
  } else {
    rememberWaarde = maxWaarde;
  }
}
