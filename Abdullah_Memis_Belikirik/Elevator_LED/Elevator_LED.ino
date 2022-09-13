#define button1 8
#define button2 9
#define button3 10
#define button4 11
#define button5 12
#define button6 13

int leds[] = {2,3,4,5,6,7};
int last = 0;

void elevator(int cur, int last){
  if(cur>last){
    for(int i=last+1; i<cur+1; i++){
      digitalWrite(leds[i-1],HIGH);
      delay(500);
    }
  }
  else if(cur<last){
    for(int i=last; i>cur; i--){
      digitalWrite(leds[i-1],LOW);
      delay(400);
    }
  }
}

void setup()
{
  Serial.begin(9600);
  for(int i=2; i<8; i++){
  	pinMode(i,OUTPUT);
  }
  for(int i=8; i<14; i++){
  	pinMode(i,INPUT);
  }
}

void loop()
{
  int state1 = digitalRead(button1);
  int state2 = digitalRead(button2);
  int state3 = digitalRead(button3);
  int state4 = digitalRead(button4);
  int state5 = digitalRead(button5);
  int state6 = digitalRead(button6);
  
  if(state1==1){
  	elevator(1,last);
    last = 1;
  }
  else if(state2==1){
  	elevator(2,last);
    last = 2;
  }
  else if(state3==1){
  	elevator(3,last);
    last = 3;
  }
  else if(state4==1){
  	elevator(4,last);
    last = 4;
  }
  else if(state5==1){
  	elevator(5,last);
    last = 5;
  }
  else if(state6==1){
  	elevator(6,last);
    last = 6;
  }
  delay(100);
}
