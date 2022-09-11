void setup()
{
  pinMode(A1, INPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  int value = analogRead(A1);
  
  if (value<800){
    digitalWrite(5, HIGH);       
  }
  else {
    digitalWrite(5, LOW);
  }
}
