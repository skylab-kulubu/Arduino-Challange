#define Buton 8
#define Led 10

void setup() {
  pinMode(Buton,INPUT);
  pinMode(Led,OUTPUT);
}

void loop() {
  int button_state = digitalRead(Buton);

  if(buton_state == 1){
    digitalWrite(Led,HIGH);
  }
  else{
    digitalWrite(Led,LOW);
  }
}
