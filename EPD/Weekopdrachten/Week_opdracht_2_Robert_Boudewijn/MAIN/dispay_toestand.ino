void leegDisplay(char input) {
  if (input == 's' || input == 'S') {
    huidigeToestand = ROLLEN;
  }
}

int countForRollen = 0;
void rollen(char input, unsigned long currentMillis, int interval) {
  if (countForRollen < 16) {
    displayBinair(number(countForRollen));
    if ( currentMillis - previosMilles >= interval) {
      previosMilles = currentMillis;
      countForRollen++;
    }
  } else if (countForRollen = 15) {
    countForRollen = 0;
  }
  if (input == 'h' || input == 'H') {
    huidigeToestand = UITROLLEN;
  }
}

void uitrollen(char input, unsigned long currentMillis, int interval, unsigned long currentMillis2, int interval2) {
  if ( currentMillis - previosMilles2 >= interval2 ) {
    previosMilles2 = currentMillis2;
    huidigeToestand = TOON_WAARDE;
  } else if (countForRollen < 16) {
    displayBinair(number(countForRollen));
    if ( currentMillis - previosMilles >= interval) {
      previosMilles = currentMillis;
      countForRollen++;
    }
  } else if (countForRollen = 15) {
    countForRollen = 0;
  }
}

void toonWaarde(char input) {
  if (input == 's' || input == 'S') {
    huidigeToestand = ROLLEN;
  }

}
