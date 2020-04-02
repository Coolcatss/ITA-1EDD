int buzzer = 5;
int tikInterval;
const int TIKTIJD = 20;
bool buzzerAan;
unsigned long geluidsTimer;

void geluidConfig() {
  pinMode(buzzer, OUTPUT);
  geluidsTimer = timerReset();
  buzzerAan = false;
  snelheid = 1;
}

void geluid() {
  if (snelheid == 0) {
    tikInterval = 0;
  } else if (snelheid == 1) {
    tikInterval = 1000;
  } else if (snelheid == 2){
    tikInterval = 200;
  }

  if (timerIsPassed(geluidsTimer, tikInterval) && !buzzerAan) {
    Serial.println("AAN");
    tone(buzzer, 1000);
    buzzerAan = true;
    geluidsTimer = timerReset();
  }
  if (timerIsPassed(geluidsTimer, TIKTIJD) && buzzerAan){
    Serial.println("UIT");
    noTone(buzzer);
    buzzerAan = false;
    geluidsTimer = timerReset(); 
  }
}
