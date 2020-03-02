void setup() {
  ledControlSetup();
  Serial.begin(9600);
}

void loop() {
  char input;

  input = Serial.read();;
  if (input == 'h' && input == 'H') {
    keyH(250);      //Van rechts naar links, aan en direct uit.
  } else if (input == 's' && input == 'S') {
    keyS(250);       //Van buiten naar binnen.
  } else if (input == 'r' && input == 'R') {
    R(250);          //Van rechts naar links. Alle lampjes blijven aan na inschakelen.
  } else if (input == 'l' && input == 'L') {
    L(250);          //Van links naar rechts. Alle lampjes blijven aan na inschakelen.
  } else if (input == 'e' && input == 'E') {
    E();             //Alles gaat uit.
  }
}
