int knopLinks = 2;
int knopRechts = 3;
int knopVoetgangers = 4;
int LDR = A5;

int valLinks = 0;
int valVoetgangers = 0;
int valRechts = 0;

void invoerConfig() {
  pinMode(knopLinks, INPUT);
  pinMode(knopVoetgangers, INPUT);
  pinMode(knopRechts, INPUT);
  pinMode(LDR, INPUT);
}

boolean buttonPressed() {
  if (CURRENT_STATE == STATE_ALLES_ROOD) {
    valLinks = digitalRead(knopLinks);
    valRechts = digitalRead(knopRechts);
    valVoetgangers = digitalRead(knopVoetgangers);

    if (valLinks == HIGH || valRechts == HIGH || valVoetgangers == HIGH) {
      wieMag();
      return true;
    } else return false;
  }
}

void nachtstandActief(){
  int valLDR = analogRead(LDR);
  if (valLDR < 550){
    nachtstand = true;
  } else nachtstand = false;
}

char wieMag() {
  valLinks = digitalRead(knopLinks);
  valRechts = digitalRead(knopRechts);
  valVoetgangers = digitalRead(knopVoetgangers);

  if (valLinks == HIGH) {
    welkeKant = 'l';
  } else if (valRechts == HIGH) {
    welkeKant = 'r';
  } else if (valVoetgangers == HIGH){
    welkeKant = 'v';
  }
}
