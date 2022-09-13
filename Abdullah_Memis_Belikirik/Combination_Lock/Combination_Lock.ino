#define button1 2
#define button2 3
#define button3 4
#define button4 5
#define button5 6
#define button6 7
#define redLed 8
#define greenLed 9

int code[] = {1,2,3,4,5,6};
const int LED[] = {14,15,16,17,18,19};

int entered[6]; 

void setup(){
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);
  pinMode(redLed, OUTPUT); 
  pinMode(greenLed, OUTPUT); 
  for (int i = 0; i < 6;i++){
    pinMode(LED[i],OUTPUT);
  }
}

void loop(){ 
  if (digitalRead(button1) == LOW){
    checkEntered1(1);
    delay(250);
  }
  else if (digitalRead(button2) == LOW){ 
    checkEntered1(2);
    delay(250); 
  }
  else if (digitalRead(button3) == LOW){ 
    checkEntered1(3);  
    delay(250); 
  }
  else if (digitalRead(button4) == LOW){ 
    checkEntered1(4); 
    delay(250);
  }
    else if (digitalRead(button5) == LOW){ 
    checkEntered1(5);
    delay(250);
  }
    else if (digitalRead(button6) == LOW){ 
    checkEntered1(6);
    delay(250);
  }
}

void checkEntered1(int button){ 
  digitalWrite(LED[button-1],HIGH);
  if (entered[0] != 0){ 
    checkEntered2(button); 
  }  
  else if(entered[0] == 0){
    entered[0] = button; 
  }  
}

void checkEntered2(int button){ 
  digitalWrite(LED[button-1],HIGH);
  if (entered[1] != 0){ 
    checkEntered3(button); 
  }  
  else if(entered[1] == 0){ 
    entered[1] = button; 
  }  
}

void checkEntered3(int button){  
  digitalWrite(LED[button-1],HIGH);
  if (entered[2] != 0){ 
    checkEntered4(button); 
  } 
  else if (entered[2] == 0){ 
    entered[2] = button; 
  }  
}

void checkEntered4(int button){ 
  digitalWrite(LED[button-1],HIGH);
  if (entered[3] != 0){ 
    checkEntered5(button); 
  }  
  else if (entered[3] == 0){ 
    entered[3] = button; 
  }  
}


void checkEntered5(int button){ 
  digitalWrite(LED[button-1],HIGH);
  if (entered[4] != 0){ 
    checkEntered6(button); 
  }
  else if (entered[4] == 0){
    entered[4] = button; 
  } 
}

void checkEntered6(int button){
  digitalWrite(LED[button-1],HIGH);
  if (entered[5] == 0){ 
    entered[5] = button; 
    compareCode(); 
  }
}

void compareCode(){ 
  bool flag =true;
    for(int i1=0;i1<6;i1++)
    {
      if(entered[i1]!=code[i1]) flag=false;
    }
   if(flag==true) digitalWrite(greenLed, HIGH); 
    else digitalWrite(redLed, HIGH);      
    for (int i = 0; i < 6; i++){
      entered[i] = 0; 
    }
      delay(2000);
  close_all();
}

void close_all(){
  digitalWrite(LED[0],LOW);
  digitalWrite(LED[1],LOW);
  digitalWrite(LED[2],LOW);
  digitalWrite(LED[3],LOW);
  digitalWrite(LED[4],LOW);
  digitalWrite(LED[5],LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW); 
}
