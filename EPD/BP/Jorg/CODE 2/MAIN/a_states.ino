// ------------STATES-------------
const int STATE_ALLES_ROOD = 1;
const int STATE_AUTO = 2;
const int STATE_VOETGANGERS = 16;
const int STATE_NACHSTAND_SLAGBOOM = 17;
const int STATE_NACHTSTAND = 18;
const int STATE_SLAGBOOM_OMHOOG = 19;
const int STATE_SLAGBOOM_OMLAAG = 20;

int CURRENT_STATE;
int VERKEERSLICHT_STATE;

int verkeerslichtKleur;
char welkeKant;

//------TIMER INSTELLINGEN--------
int groenInterval = 3000;
int geelInterval = 500;
int dodeTijd = 2000;
int countdown;
bool nachtstand;
bool dodeTijdActief;
unsigned long timer;
int snelheid;



void statesConfig() {
  timer = timerSetup(groenInterval);
  welkeKant = 'l';
  verkeerslichtKleur = 3;
  dodeTijdActief = false;
  nachtstand = false;
  invoerConfig();
  CURRENT_STATE = STATE_ALLES_ROOD;
}

void states_loop() {
  switch (CURRENT_STATE) {
    case STATE_ALLES_ROOD:
      allesRood_Do();
      if (buttonPressed() && (welkeKant == 'l' || welkeKant == 'r')) {
        allesRood_Exit();
        CURRENT_STATE = STATE_AUTO;
        auto_Entry();
      }
      if (buttonPressed() && welkeKant == 'v' || nachtstand == true) {
        allesRood_Exit();
        slagboomOmhoog_Entry();
        CURRENT_STATE = STATE_SLAGBOOM_OMHOOG;
      }
      break;

    case STATE_AUTO:
      if (timerIsPassed(timer, groenInterval) && verkeerslichtKleur == 3) {
        auto_Do();
      }
      if (timerIsPassed(timer, geelInterval) && verkeerslichtKleur == 2) {
        auto_Exit();
        allesRood_Entry();
        CURRENT_STATE = STATE_ALLES_ROOD;
      }
      break;

    case STATE_SLAGBOOM_OMHOOG:
      slagboomOmhoog_Do();
      if (nachtstand == false) {
        voetgangers_Entry();
        CURRENT_STATE = STATE_VOETGANGERS;
      } else {
        nachtstand_Entry();
        CURRENT_STATE = STATE_NACHTSTAND;
      }
      break;


    case STATE_VOETGANGERS:
      if (timerIsPassed(timer, 3000)) {
        voetgangers_Do();
      }
      break;

    case STATE_SLAGBOOM_OMLAAG:
      slagboomOmlaag_Do();
      slagboomOmlaag_Exit();
      allesRood_Entry();
      CURRENT_STATE = STATE_ALLES_ROOD;
      break;

    case STATE_NACHTSTAND:
      nachtstand_Do();
      if (nachtstand == false) {
        slagboomOmlaag_Entry();
        CURRENT_STATE = STATE_SLAGBOOM_OMLAAG;
      }
      break;

  }
}
//-------STATE FUNCTIONS--------
void allesRood_Entry() {
  snelheid = 1;
  welkeKant = 'l';
  verkeerslichtKleur = 3;
  verkeerslicht(welkeKant, verkeerslichtKleur);
}

void allesRood_Do() {
  verkeerslicht(welkeKant, verkeerslichtKleur);
  displayDit(8);
  nachtstandActief();
}

void allesRood_Exit() {
}

//--------AUTO STATE--------------------
void auto_Entry() {
  verkeerslicht(welkeKant, 1);
  timer = timerReset();
}

void auto_Do() {
  verkeerslicht(welkeKant, 2);
  verkeerslichtKleur = 2;
  timer = timerReset();
}

void auto_Exit() {
  dodeTijdActief = true;
}

//--------SLAGBOOM STATE-----------------
void slagboomOmhoog_Entry() {
  slagboomOmhoog();
}

void slagboomOmhoog_Do() {
}

void slagboomOmhoog_Exit() {
}


//--------VOETGANGERS STATE-----------------
void voetgangers_Entry() {
  snelheid = 2;
  displayDit(7);
  timer = timerReset();
  countdown = 6;
}

void voetgangers_Do() {
  while (countdown > 0) {
    if (timerIsPassed(timer, 1000)) {
      displayDit(countdown);
      timer = timerReset();
      countdown--;
    }
    if (countdown == 0) {
      slagboomOmlaag_Entry();
      CURRENT_STATE = STATE_SLAGBOOM_OMLAAG;
    }
  }
}

void voetgangers_Exit() {
  displayDit(8);
}

//----------SLAGBOOM OMLAAG STATE---------
void slagboomOmlaag_Entry() {
  snelheid = 1;
  slagboomOmlaag();
}

void slagboomOmlaag_Do() {
}

void slagboomOmlaag_Exit() {
}

//----------NACHTSTAND STATE----------
void nachtstand_Entry() {
  displayDit(8);
  timer = timerReset();
  verkeerslichtKleur = 4;
  verkeerslicht(welkeKant, verkeerslichtKleur);
}

void nachtstand_Do() {
  if (timerIsPassed(timer, 1000) && verkeerslichtKleur == 4) {
    Serial.println("uit");
    verkeerslichtKleur = 0;
    verkeerslicht(welkeKant, verkeerslichtKleur);
    timer = timerReset();
  }
  if (timerIsPassed(timer, 1000) && verkeerslichtKleur == 0) {
    Serial.println("AAN");
    verkeerslichtKleur = 4;
    verkeerslicht(welkeKant, verkeerslichtKleur);
    timer = timerReset();
  }
  nachtstandActief();
}

void nachtstand_Exit() {
}
