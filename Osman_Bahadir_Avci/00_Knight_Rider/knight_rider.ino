int leds[10] = {0,1,2,3,4,5,6,7,8,9};
void setup()
{
  for(int i=0;i<10;i++){
  pinMode(leds[i],OUTPUT);
  }
}

void loop()
{
  for(int i= 9; i>0; i--){
  digitalWrite(i,HIGH);
  delay(100);
  digitalWrite(i,LOW);
  }
  
  for(int i= 0; i<10; i++){
  digitalWrite(i,HIGH);
  delay(100);
  digitalWrite(i,LOW);
  }
}