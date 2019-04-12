// boundary led 
int hled ;
int lled;
// pin switch 
int swit;

int onled = lled;
//value returned when put the switch
int switon ;
//delay time
int delaytime;
//--------------------------------------------------------------
void changemode(int x);
//--------------------------------------------------------------
void setup() {
  for(int i=lled;i<=hled;i++) pinMode(i,OUTPUT);
  pinMode(swit,INPUT);
}
void loop() {
  changemode(digitalRead(swit));
  for(int i=lled;i<=hled;i++){
    if(i == onled ) digitalWrite(i,1);
    else digitalWrite(i,0);
  }
}

void changemode(int x){
  if(x==switon) ++onled;
  if(onled>hled) onled = lled;
  delay(delaytime);
}

