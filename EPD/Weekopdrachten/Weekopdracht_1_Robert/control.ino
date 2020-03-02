int numberOfLeds(){
  return 8;
}
int pinArray(int pin){
  const int PIN_ARRAY[] = {13, 12, 11, 10, 9, 8, 7, 6};

 return PIN_ARRAY[pin];
}

void ledControlSetup() {
 for (int ledNumber = 0; ledNumber < numberOfLeds(); ledNumber++) {
 pinMode(pinArray(ledNumber), OUTPUT);
 }
}
