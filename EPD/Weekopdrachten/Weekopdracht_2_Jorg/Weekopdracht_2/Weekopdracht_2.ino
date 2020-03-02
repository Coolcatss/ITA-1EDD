const int LEEG_DISPLAY = 1;
const int ROLLEN = 2;
const int UITROLLEN = 3;
const int TOON_WAARDE = 4;
int huidigeToestand = LEEG_DISPLAY;

void setup() {

  pinMode(DS, OUTPUT);
  pinMode(SH_CP, OUTPUT);
  pinMode(ST_CP, OUTPUT);

}


void loop() {
  switch (huidigeToestand) {
    case LEEG_DISPLAY:
      // Schrijf hier de code die moet worden uitgevoerd
      // in toestand LEEG_DISPLAY
      digitalWrite(DS, LOW);
      break;
    case ROLLEN:
      // Schrijf hier de code die moet worden uitgevoerd
      // in toestand ROLLEN
Weekopdracht 2: Hexadecimale dobbelsteen 4
      break;
    case UITROLLEN:
      // Schrijf hier de code die moet worden uitgevoerd
      // in toestand UITROLLEN
      break;
    case TOON_WAARDE:
      // Schrijf hier de code die moet worden uitgevoerd
      // in toestand TOON_WAARDE
      break;
  }
}
