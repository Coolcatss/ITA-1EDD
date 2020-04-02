int stopTimer() {
  return 0;
}

unsigned long timerSetup(unsigned long interval) {
  return 0 - interval;
}

bool timerIsPassed(unsigned long timer, unsigned long interval) {
  return millis() - timer >= interval;
}

unsigned long timerReset() {
  return millis();
}
