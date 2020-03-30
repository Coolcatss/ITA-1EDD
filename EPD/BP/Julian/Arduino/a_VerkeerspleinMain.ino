int currentState;

//Dag situatie.
const int KRUISPUNT_GESLOTEN = 0;
const int OPEN_SLAGBOOM = 1;
const int OVERSTEEK_VOETGANGER = 2;
const int SLUIT_SLAGBOOM = 3;
const int STOPLICHT_LINKS_GROEN = 4;
const int STOPLICHT_LINKS_ORANJE = 5;
const int STOPLICHT_LINKS_ROOD = 6;
const int STOPLICHT_RECHTS_GROEN = 7;
const int STOPLICHT_RECHTS_ORANJE = 8;
const int STOPLICHT_RECHTS_ROOD = 9;
//Nacht situatie.
const int START_NACHT = 10;
const int NACHT = 11;
const int EIND_NACHT = 12;

//Timer
unsigned long int previousMillis;
int interval = 1000;
boolean timer = true;

boolean buzzerTik;

void VerkeerspleinMainSetup() {
  currentState = KRUISPUNT_GESLOTEN;

}

void VerkeerspleinMainLoop() {
  unsigned long int currentMillis = millis();
  switch (currentState) {
    case KRUISPUNT_GESLOTEN: {
        KRUISPUNT_GESLOTEN_ENTRY();
        KRUISPUNT_GESLOTEN_DO(currentMillis);
        KRUISPUNT_GESLOTEN_EXIT();
      }
      break;
    case OPEN_SLAGBOOM: {
        Serial.println("WERKT");
      }
      break;
    case OVERSTEEK_VOETGANGER: {

      }
      break;
    case SLUIT_SLAGBOOM: {

      }
      break;
    case STOPLICHT_LINKS_GROEN: {

      }
      break;
    case STOPLICHT_LINKS_ORANJE: {

      }
      break;
    case STOPLICHT_LINKS_ROOD: {

      }
      break;
    case STOPLICHT_RECHTS_GROEN: {

      }
      break;
    case STOPLICHT_RECHTS_ORANJE: {

      }
      break;
    case STOPLICHT_RECHTS_ROOD: {

      }
      break;
    case START_NACHT: {

      }
      break;
    case NACHT: {

      }
      break;
    case EIND_NACHT: {

      }
      break;
  }
}
//----Functies
int setRichting() {
  return getButton();
}


//-----------Kruispunt_gesloten.
void KRUISPUNT_GESLOTEN_ENTRY() {
  //<nothing>
}
void KRUISPUNT_GESLOTEN_DO(int currentMillis) {
  int richting = setRichting();

  if(richting == 13){
    currentState = OPEN_SLAGBOOM;
  }
  if (currentMillis >= previousMillis + interval) {
    if (buzzerTik) {
      buzzerControlTik();
    } else if (!buzzerTik) {
      buzzerControlStop();
    }
    previousMillis = currentMillis;
  }
}
void KRUISPUNT_GESLOTEN_EXIT() {

}
//-----------OPEN_SLAGBOOM
void OPEN_SLAGBOOM_ENTRY() {

}
void OPEN_SLAGBOOM_DO() {

}
void OPEN_SLAGBOOM_EXIT() {

}
//-----------OVERSTEEK_VOETGANGER
void OVERSTEEK_VOETGANGER_ENTRY() {

}
void OVERSTEEK_VOETGANGER_DO() {

}
void OVERSTEEK_VOETGANGER_EXIT() {

}
//-----------SLUIT_SLAGBOOM
void SLUIT_SLAGBOOM_ENTRY() {

}
void SLUIT_SLAGBOOM_DO() {

}
void SLUIT_SLAGBOOM_EXIT() {

}
//-----------STOPLICHT_LINKS_GROEN
void STOPLICHT_LINKS_GROEN_ENTRY() {

}
void STOPLICHT_LINKS_GROEN_DO() {

}
void STOPLICHT_LINKS_GROEN_EXIT() {

}
//-----------STOPLICHT_LINKS_ORANJE
void STOPLICHT_LINKS_ORANJE_ENTRY() {

}
void STOPLICHT_LINKS_ORANJE_DO() {

}
void STOPLICHT_LINKS_ORANJE_EXIT() {

}
//-----------STOPLICHT_LINKS_ROOD
void STOPLICHT_LINKS_ROOD_ENTRY() {

}
void STOPLICHT_LINKS_ROOD_DO() {

}
void STOPLICHT_LINKS_ROOD_EXIT() {

}
//-----------STOPLICHT_RECHTS_GROEN
void STOPLICHT_RECHTS_GROEN_ENTRY() {

}
void STOPLICHT_RECHTS_GROEN_DO() {

}
void STOPLICHT_RECHTS_GROEN_EXIT() {

}
//-----------STOPLICHT_RECHTS_ORANJE
void STOPLICHT_RECHTS_ORANJE_ENTRY() {

}
void STOPLICHT_RECHTS_ORANJE_DO() {

}
void STOPLICHT_RECHTS_ORANJE_EXIT() {

}
//-----------STOPLICHT_RECHTS_ROOD
void STOPLICHT_RECHTS_ROOD_ENTRY() {

}
void STOPLICHT_RECHTS_ROOD_DO() {

}
void STOPLICHT_RECHTS_ROOD_EXIT() {

}

//-----------START_NACHT
void START_NACHT_ENTRY() {

}
void START_NACHT_DO() {

}
void START_NACHT_EXIT() {

}
//-----------NACHT
void NACHT_ENTRY() {

}
void NACHT_DO() {

}
void NACHT_EXIT() {

}
//-----------EIND_NACHT
void EIND_NACHT_ENTRY() {

}
void EIND_NACHT_DO() {

}
void EIND_NACHT_EXIT() {

}
