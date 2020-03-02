void startShiftRegsister(){
  pinMode(DS, OUTPUT);
  pinMode(SH_CP, OUTPUT);
  pinMode(ST_CP, OUTPUT);

  digitalWrite(DS, LOW);
  digitalWrite(SH_CP, LOW);
  digitalWrite(ST_CP, LOW);

  // alles uit
  digitalWrite(DS, LOW);
  for ( int i = 0; i < 8; i++) {
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
  }
  digitalWrite(ST_CP, HIGH);
  digitalWrite(ST_CP, LOW);

}
