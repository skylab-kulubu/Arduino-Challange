int led = 8;


void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  
}

void loop()
{
	int ldrSensor = analogRead(A0);
  	Serial.println(ldrSensor);
  	if(ldrSensor <= 800){
  		digitalWrite(led,HIGH);
    }else{
    	digitalWrite(led,LOW);
    }
}