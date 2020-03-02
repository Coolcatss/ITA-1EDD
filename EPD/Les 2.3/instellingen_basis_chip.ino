const int DS = 8;     // Hiermee geef je door hoeveel ledjes aan moeten staan
const int SH_CP = 10; // clock
const int ST_CP = 9;  // latch pin/ einde van send.

void setup() {
  pinMode(DS, OUTPUT);
  pinMode(SH_CP, OUTPUT);
  pinMode(ST_CP, OUTPUT);

  digitalWrite(DS, LOW);
  digitalWrite(SH_CP, LOW);
  digitalWrite(ST_CP, LOW);

  // Alles uit.
  digitalWrite(DS, LOW);
  for (int i = 0; i < 8; i++) {
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
  }
  pinMode(ST_CP, HIGH);
  pinMode(ST_CP, LOW);


  // Alles aan.

  digitalWrite(DS, HIGH);

  for (int i = 0; i < 8; i++) {
    digitalWrite(SH_CP, HIGH);
    digitalWrite(SH_CP, LOW);
  }

  digitalWrite(ST_CP, HIGH);
  digitalWrite(ST_CP, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

}
