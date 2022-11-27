int leds[5] = {13,12,11,10,9};
int buttons[5] = {6,5,4,3,2};
int first, last;

void go(int first, int last){

  		if(last == 0 || first == 0){}
  		else{
  		
          digitalWrite(last,HIGH);
          delay(1000);
          
  		if(last > first){
          for(int i= last+1;i>first;i--){
            digitalWrite(i-1,HIGH);
        	delay(250);
            digitalWrite(i-1,LOW);
          	delay(250);
          }
        }else if(first > last){
          for(int i= last+1;i<first;i++){
          	digitalWrite(i-1,HIGH);
        	delay(250);
      	 	digitalWrite(i-1,LOW);
          	delay(250);
          }
        }
      	
        
        }
    	digitalWrite(first,HIGH);
  		delay(1000);
    

}

void setup()
{
  Serial.begin(9600);
  
  for(int i = 0; i<5;i++){
  pinMode(leds[i], OUTPUT);
  }
  for(int i = 0; i<5;i++){
  pinMode(buttons[i], INPUT);
  }
  
}

void loop()
{ 
  	int state1 = digitalRead(buttons[0]);
  	int state2 = digitalRead(buttons[1]);
  	int state3 = digitalRead(buttons[2]);
  	int state4 = digitalRead(buttons[3]);
  	int state5 = digitalRead(buttons[4]);
  
  	if(state1 == 1){
  		go(13,last);
      	last = 13;
	}else if(state2 == 1){
  		go(12,last);
      	last = 12;
	}else if(state3 == 1){
  		go(11,last);
      	last = 11;
	}else if(state4 == 1){
  		go(10,last);
      	last = 10;
	}else if(state5 == 1){
  		go(9,last);
      	last = 9;
	}

  
  	
  delay(100);
}