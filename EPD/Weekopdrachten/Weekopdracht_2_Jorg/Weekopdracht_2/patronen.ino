const byte patronen = {
  B00000000, //0
  B01100000, //1
  B11011100, //2
  B11110010, //3
  B01100110, //4
  B10110110, //5
  B10111110, //6
  B11100000, //7
  B11111110, //8
  B11110110, //9
  B11101110, //A
  B00111110, //B
  B10011100, //C
  B01111010, //D
  B10011110, //E
  B10001110  //F
}

boolean isBitEen (byte pattern, int index) {
  byte check = 1 << index;
  return (pattern & check) == check;
}
