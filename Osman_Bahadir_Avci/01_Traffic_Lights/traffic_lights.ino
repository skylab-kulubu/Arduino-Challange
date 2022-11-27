
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  
}

void loop()
{
  RedLight(10);
  YellowLight(9);
  GreenLight(8);
}

void RedLight(int led){
	digitalWrite(led, HIGH);
  	delay(5000);
  	digitalWrite(led,LOW);
  
    
}
void YellowLight(int led){
	digitalWrite(led, HIGH);
  	delay(1500);
  	digitalWrite(led,LOW);
}
void GreenLight(int led){
	digitalWrite(led, HIGH);
  	delay(4000);
  	digitalWrite(led,LOW);
}