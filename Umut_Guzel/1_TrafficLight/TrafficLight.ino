// C++ code

//pins
int red=3;
int yellow=5;
int green=6;
  

void setup(){
  pinMode(red, OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop(){
  red_light();
  delay(10000);
  yellow_light();
  delay(3000);
  green_light();
  delay(10000);
  second_yellow();
  delay(1500);
}


void red_light(){
  digitalWrite(red,HIGH);
  digitalWrite(yellow,LOW);
  digitalWrite(green,LOW);
}

void yellow_light(){
  digitalWrite(red,HIGH);
  digitalWrite(yellow,HIGH);
  digitalWrite(green,LOW);
}

void green_light(){
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,HIGH);
}

void second_yellow(){
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
  digitalWrite(green,LOW);
}