#define Potpin A0
#define Led 3

void setup() {
  
}

void loop() {
  int value = analogRead(Potpin);
  value = map(value,0,1023,0,255);
  analogWrite(Led,value);
}
