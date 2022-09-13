#define LDR A0
#define hot 4
#define cold 2

void setup()
{
  pinMode(hot,OUTPUT);
  pinMode(cold,OUTPUT);
}

void loop()
{
  int temp = analogRead(A0);
  if(temp > 155){
  	digitalWrite(4,HIGH);
    delay(100);
    digitalWrite(4,LOW);
  }
  if(temp < 121){
  	digitalWrite(2,HIGH);
    delay(100);
    digitalWrite(2,LOW);
  }
  delay(50);
}
