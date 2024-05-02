void setup()
{
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop()
{
  //Yesili ac Sariyi kapa
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
  delay(5000);
  
  //Yesili kapa Sariyi ac
  digitalWrite(2,HIGH);
  digitalWrite(1,LOW);
  delay(2500);
  
  //Sariyi kapa Kirmiziyi ac
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
  delay(5000);
  
  //Kirmiziyi kapa Sariyi ac
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
  delay(2500);
}