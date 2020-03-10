const int TIMEDLAMP_STATE_AAN = 1;
const int TIMEDLAMP_STATE_UIT = 0;

// Current state
int timedlampCurrentState;

//Timer
unsigned long timedlampPreviousMillis;
const int TIMEDLAMP_INTERVAL = 5000;

void timedlampSetup() {
  Serial.begin(9600);

  ledControlSetup();
  // statemachinestart
  timedlampCurrentState = TIMEDLAMP_STATE_UIT;
  timedlampUitEntry();

}

// ----LOOP--------------------------

void timedlampLoop() {
  Serial.println(timedlampCurrentState);
  switch (timedlampCurrentState) {
    case TIMEDLAMP_STATE_AAN: {
        // --- Do ---------------------
        timedlampAanDo();
        // --- events -----------------
        unsigned long currentMillis = millis();
        if (currentMillis >= timedlampPreviousMillis + TIMEDLAMP_INTERVAL) {
          //timer
          timedlampAanExit();
          timedlampCurrentState = TIMEDLAMP_STATE_UIT;
          timedlampUitEntry();
        }
        break;
      }
    case TIMEDLAMP_STATE_UIT: {
        Serial.println("EWA state is uit");
        // --- Do ---------------------
        timedlampUitDo();
        // --- events -----------------
        char input;
        input = Serial.read();

        if (input == 'x') {
          timedlampUitExit();
          timedlampCurrentState = TIMEDLAMP_STATE_AAN;
          timedlampAanEntry();
        }
        break;
      }
  }
}


// --- TIMEDLAMP_STATE_AAN -----------
void timedlampAanEntry() {
  //lamp aan
  ledControlSetLedOn();
  // reset timer
  timedlampPreviousMillis = millis();
}

void timedlampAanDo() {
  // <nothing>
}

void timedlampAanExit() {
  // <nothing>
}


// --- TIMEDLAMP_STATE_UIT -----------
void timedlampUitEntry() {
  // lamp uit
  ledControlSetLedOff();
}

void timedlampUitDo() {
  // <nothing>
}

void timedlampUitExit() {
  // <nothing>
}
