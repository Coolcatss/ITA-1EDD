#include <EEPROM.h>

const int POT_PIN = 0;
const int INTERVAL = 5000;

int eepromMem = 0;

unsigned long previousMillis;

void setup() {
  serialSetup();
}

//TODO: grotere waardes verdelen over meerdere adressen
void loop() {
  int potVal = analogRead(POT_PIN);
  unsigned long currentMillis = millis();

  Serial.print("Potmeter: ");
  Serial.println(potVal);

  if (Serial.available() > 0) {
    char input = Serial.read();

    if (input == 's') {
      for (int i = 0; i < 255; i++) {
        EEPROM.write(i, potVal / 4);
        Serial.print(i);
        Serial.print(" ");
        Serial.println(potVal / 4);
        eepromMem = i;
      }
    }
  }

  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;
    int eepromVal = EEPROM.read(eepromMem);
    Serial.print("EEPROM: ");
    Serial.println(eepromVal);
  }

}
