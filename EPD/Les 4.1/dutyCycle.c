int rgbLeds[3] = {13, 12, 11};
unsigned long int previousMillis;
const int HZ = 120; //hoeveelheid knippers per seconde
const float DUTY_CYCLE = 0.25; // verteld hoe dim het ledje moet zijn

int kleur = 0;

boolean aan = true;
void setup() {
  pinSetup();
  Serial.begin(9600);
  digitalWrite(rgbLeds[kleur], HIGH);
}

void loop() {

  unsigned long int currentMillis = millis();
  int cycletime = 1000 / HZ;
  int hightime = (cycletime * DUTY_CYCLE);
  int lowtime = cycletime - hightime; // of lowTime = cycletime *(1-dutycycle);
  if (aan && currentMillis >= previousMillis + hightime) {
    previousMillis = currentMillis;
    digitalWrite(rgbLeds[kleur], LOW);
    aan = false;
        kleur++;
        if(kleur == 3){
          kleur = 0;
        }
    Serial.println("Aan");
  } else if (!aan && currentMillis >= previousMillis + lowtime) {
    previousMillis = currentMillis;
    digitalWrite(rgbLeds[kleur], HIGH);
    aan = true;
  }
}
void pinSetup() {
  for (int i = 0; i < 3; i++) {
    pinMode(rgbLeds[i], OUTPUT);
  }
}
