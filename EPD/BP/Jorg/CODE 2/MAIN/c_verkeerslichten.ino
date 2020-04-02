// Deze functie krijgt de kant van het stoplicht en de kleur mee waarop de stoplichten moeten staan
void verkeerslicht(char kant, int kleur) {
  if (kant == 'l') { //LINKS
    if (kleur == 1) {
      verkeersLichtWeergeven(B01000010); // GROEN
    } else if (kleur == 2) {
      verkeersLichtWeergeven(B00100010); // GEEL
    } else if (kleur == 3) {
      verkeersLichtWeergeven(B00010010); // ROOD
    }
  } else if (kant == 'r') { // RECHTS
    if (kleur == 1) {
      verkeersLichtWeergeven(B00011000); // GROEN
    } else if (kleur == 2) {
      verkeersLichtWeergeven(B00010100); // GEEL
    } else if (kleur == 3) {
      verkeersLichtWeergeven(B00010010); // ROOD
    }
  }
  if (kleur == 0) {
    verkeersLichtWeergeven(B00000000);
  }
  if (kleur == 4) {
    verkeersLichtWeergeven(B00100100);
  }
}

////-------------Verkeerslichten--------------
const int DS_1 = 10;     // Hiermee geef je door hoeveel ledjes aan moeten staan
const int ST_CP_1 = 9;  // latch pin/ einde van send.
const int SH_CP_1 = 8; // clock

void startShiftRegister1() {
  pinMode(DS_1, OUTPUT);
  pinMode(SH_CP_1, OUTPUT);
  pinMode(ST_CP_1, OUTPUT);

  digitalWrite(DS_1, LOW);
  digitalWrite(SH_CP_1, LOW);
  digitalWrite(ST_CP_1, LOW);

  //   alles uit
  digitalWrite(DS_1, LOW);
  for ( int i = 0; i < 8; i++) {
    digitalWrite(SH_CP_1, HIGH);
    digitalWrite(SH_CP_1, LOW);
  }
  digitalWrite(ST_CP_1, HIGH);
  digitalWrite(ST_CP_1, LOW);
}


boolean isBitSet(byte pattern, int index) {
  byte check = B00000001 << index;
  return ((pattern & check)  == check);
}

void verkeersLichtWeergeven(byte patroon) {
  for (int i = 0; i < 8; i++) {
    if (isBitSet(patroon, i) == true) {
      digitalWrite(DS_1, HIGH);
    } else {
      digitalWrite(DS_1, LOW);
    }
    digitalWrite(SH_CP_1, HIGH);
    digitalWrite(SH_CP_1, LOW);
  }
  digitalWrite(ST_CP_1, HIGH);
  digitalWrite(ST_CP_1, LOW);
}
