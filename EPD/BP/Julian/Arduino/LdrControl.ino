const int AVOND = 2;
const int DAG = 0;

int ldrPin = A0; 

void ldrControlSetup(){
  pinMode(A0, INPUT);
}

int ldrControlcheckStatusDag(){
  int lichtSterkte = analogRead(ldrPin);
  if(lichtSterkte >= 500){
    return AVOND;
  }else{
    return DAG;
  }
}
