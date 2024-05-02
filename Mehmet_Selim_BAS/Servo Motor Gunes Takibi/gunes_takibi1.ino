#include <Servo.h>


#define SERVO_PIN 2
Servo solarServo;
  
void setup(){
    Serial.begin(9600);
   	solarServo.attach(2);
    
}

void loop() {
    int value1 = analogRead(A0);
  	int value2 = analogRead(A1);
  	
 	if(value1 > value2){
    	solarServo.write(140);	
  	}
  	else if(value1 == value2){
    	solarServo.write(90);
  	}
  	else{
     	solarServo.write(40);
  	}
}
