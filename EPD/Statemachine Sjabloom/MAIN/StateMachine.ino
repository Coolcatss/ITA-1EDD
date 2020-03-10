////////////////////////
// Basic state machine//
// By: R. Boudewijn   //
// Date: 10/03/2020   //
// #MN# = Machine name//
////////////////////////

// ----Alle states gedefineerd-------
const int #MN#_STATE_UIT = 0;
const int #MN#_STATE_AAN = 1;

// ----Houdt bij welke state je zit--
int #MN#CurrentState;

void #MN#Setup() {  // statemachinestart (Runt 1 keer)
  #MN#CurrentState = #MN#_STATE_UIT; // Zet de eerste state aan.
  #MN#UitEntry(); // Start de entry van de eerste state.

}

// ----LOOP--------------------------

void #MN#Loop() {
  switch (#MN#CurrentState) {
    case #MN#_STATE_AAN: {
        // --- Do ---------------------
        #MN#AanDo();

        // --- Exit Statement ---------
        #MN#timedlampAanExit();
        #MN#CurrentState = #MN#_STATE_UIT;
        #MN#UitEntry();
        break;
      }

    case #MN#_STATE_UIT: {
        // --- Do ---------------------
        #MN#UitDo();

        // --- events -----------------
        #MN#UitExit();
        #MN#CurrentState = #MN#_STATE_AAN;
        #MN#AanEntry();
      }
      break;
  }
}


// --- #MN#_STATE_AAN -----------
void #MN#AanEntry() {
  //<nothing>
}

void #MN#AanDo() {
  // <nothing>
}

void #MN#AanExit() {
  // <nothing>
}


// --- TIMEDLAMP_STATE_UIT -----------
void #MN#UitEntry() {
  // <nothing>
}

void #MN#UitDo() {
  // <nothing>
}

void #MN#UitExit() {
  // <nothing>
}
