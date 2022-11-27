#define trigPin 6
#define echoPin 7
#define buzzer 8
 int sure,mesafe;
void setup()
{
 
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
	
}

void loop()
{
	digitalWrite(trigPin,HIGH);
  	delayMicroseconds(1000);
  	digitalWrite(trigPin,LOW);
	sure = pulseIn(echoPin,HIGH);
  	mesafe = (sure/2) /29.1;
  	
  	if(mesafe<100){
    	digitalWrite(buzzer,HIGH);
    }else{
    	digitalWrite(buzzer,LOW);
    }
  
  	Serial.println(mesafe);
}

// 29.1=> ses hizinin oda sicakligindaki bir microsaniyede aldigi cm