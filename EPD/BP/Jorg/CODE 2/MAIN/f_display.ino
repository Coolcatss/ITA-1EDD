byte getallen[] = {
  B11111100, //0
  B01100000, //1
  B11011010, //2
  B11110010, //3
  B01100110, //4
  B10110110, //5
  B10111110, //6
  B00011100, //LOPEN (7)
  B10110110  //STOP  (8)
};

void displayDit(int input){
  displayWeergeven(getallen[input]);
}

////-------------DISPLAY--------------
const int DS_2 = 13;     // Hiermee geef je door hoeveel ledjes aan moeten staan
const int ST_CP_2 = 12;  // latch pin/ einde van send.
const int SH_CP_2 = 11; // clock



void startShiftRegister2() {
  pinMode(DS_2, OUTPUT);
  pinMode(SH_CP_2, OUTPUT);
  pinMode(ST_CP_2, OUTPUT);

  digitalWrite(DS_2, LOW);
  digitalWrite(SH_CP_2, LOW);
  digitalWrite(ST_CP_2, LOW);

  //   alles uit
  digitalWrite(DS_2, LOW);
  for ( int i = 0; i < 8; i++) {
    digitalWrite(SH_CP_2, HIGH);
    digitalWrite(SH_CP_2, LOW);
  }
  digitalWrite(ST_CP_2, HIGH);
  digitalWrite(ST_CP_2, LOW);
}

void displayWeergeven(byte patroon) {
  for (int i = 0; i < 8; i++) {
    if (isBitSet(patroon, i) == true) {
      digitalWrite(DS_2, HIGH);
    } else {
      digitalWrite(DS_2, LOW);
    }
    digitalWrite(SH_CP_2, HIGH);
    digitalWrite(SH_CP_2, LOW);
  }
  digitalWrite(ST_CP_2, HIGH);
  digitalWrite(ST_CP_2, LOW);
}
