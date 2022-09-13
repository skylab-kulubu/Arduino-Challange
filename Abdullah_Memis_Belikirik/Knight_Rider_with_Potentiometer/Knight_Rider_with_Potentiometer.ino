#define pot A0
int leds[] = {0,1,2,3,4,5,6,7};

void setup() {
  for(int i=0; i<8; i++){
   pinMode(leds[i],OUTPUT); 
  }
}

void loop() {
  int value = analogRead(pot)/10;
  for(int i=1; i<8; i++){
    digitalWrite(leds[i],HIGH);
    delay(value);
    digitalWrite(leds[i],LOW);
  }
  for(int j=7; j>-1; j--){
    digitalWrite(leds[j],HIGH);
    delay(value);
    digitalWrite(leds[j],LOW);
  }
}
