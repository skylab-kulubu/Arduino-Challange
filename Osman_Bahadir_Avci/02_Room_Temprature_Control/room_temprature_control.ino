
void setup()
{
  	Serial.begin(9600);
 	
}

void loop()
{
  	float TMP_Value = analogRead(A0);
  	Serial.println(TMP_Value);
  	float mv = TMP_Value *5000 / 1024;
  	float C = (mv-500) /10;
  	Serial.println(C);
 	delay(1000);
}