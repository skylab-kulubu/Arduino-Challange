void setup()
{
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(6, LOW);
  delay(5000);
  digitalWrite(13, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(6, LOW);
  delay(3000);
  digitalWrite(13, LOW);
  digitalWrite(9, LOW);
  digitalWrite(6, HIGH);
  delay(40000);
}
