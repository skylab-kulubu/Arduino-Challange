const int button1 = 2; 
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;
const int button5 = 6;
const int button6 = 7;
const int LED[] = {14,15,16,17,18,19};
const int redLed = 8;
const int greenLed = 9;
void chechEnt1(int button);

int code [] = {6,5,4,3,2,1};
int ent[7];
void setup(){
  Serial.begin(9600); //begin Serial

  pinMode(button1, INPUT_PULLUP); //1-6 arasi butun butonlari input olarak atadik 
  pinMode(button2, INPUT_PULLUP); 
  pinMode(button3, INPUT_PULLUP); 
  pinMode(button4, INPUT_PULLUP); 
  pinMode(button5, INPUT_PULLUP); 
  pinMode(button6, INPUT_PULLUP); 

  pinMode(redLed, OUTPUT);  //yesil ve kirmizi ledleri output olarak tanimladik
  pinMode(greenLed, OUTPUT); 
  digitalWrite(redLed, LOW); 
  for (int i = 0; i < 6;i++){
    Serial.println(code[i]);
    Serial.println(ent[i]); 
    pinMode(LED[i],OUTPUT);
  }
}

  
void loop(){ 
  if (digitalRead(button1) == LOW){ //eger button1'e basilirsa, chechEnt1'e gidilir ve 1 atlanir.
    chechEnt1(1);
    delay(250);
  }
  else if (digitalRead(button2) == LOW){ //eger button2'ye basilirsa, chechEnt1'e gidilir ve 2 atlanir.
    chechEnt1(2);
    delay(250);
  }
  else if (digitalRead(button3) == LOW){ //eger button3'e basilirsa, chechEnt1'e gidilir ve 3 atlanir.
    chechEnt1(3);
    delay(250);
  }
  else if (digitalRead(button4) == LOW){ //eger button4'e basilirsa, chechEnt1'e gidilir ve 4 atlanir.
    chechEnt1(4);
    delay(250);
  }
  else if (digitalRead(button5) == LOW){ //eger button5'5e basilirsa, chechEnt1'e gidilir ve 5 atlanir.
    chechEnt1(5);
    delay(250);
  }
  else if (digitalRead(button6) == LOW){ //eger button6'ya basilirsa, chechEnt1'e gidilir ve 6 atlanir.
    chechEnt1(6);
    delay(250);
  }
}

void chechEnt1(int button){ //girilen array'in ilk elemani kontrol edilir
  digitalWrite(LED[button-1],HIGH);
  if (ent[0] != 0){ //sifir degilse (yani array girildiyse)
    chechEnt2(button); //botonu gecip checkEnt2'ye gecilir.
  }
  
  else if(ent[0] == 0){ //eger sifirsa (henuz bir button ile tanimlanmadiysa)
    ent[0] = button; //ilk ogeyi basilan button olarak ayarla
    Serial.print("1: ");Serial.println(ent[0]);
  }
  
}

void chechEnt2(int button){ //girilen array'in ikinci elemani kontrol edilir
  digitalWrite(LED[button-1],HIGH);
  if (ent[1] != 0){ //sifir degilse (yani array girildiyse)
    chechEnt3(button); //botonu gecip checkEnt3'e gecilir.
  }
  
  else if(ent[1] == 0){ //eger sifirsa (henuz bir button ile tanimlanmadiysa)
    ent[1] = button; //ikinci ogeyi basilan button olarak ayarla
    Serial.print("2: ");Serial.println(ent[1]); 
  }
//diger tum voidlerde ayni islemler tekrarlanir.
}

void chechEnt3(int button){ 
  digitalWrite(LED[button-1],HIGH);
  if (ent[2] != 0){ 
    chechEnt4(button); 
  }
  
  else if (ent[2] == 0){ 
    ent[2] = button; 
    Serial.print("3: ");Serial.println(ent[2]); 
  }
  
}

void chechEnt4(int button){  
  digitalWrite(LED[button-1],HIGH);
  if (ent[3] != 0){ 
    chechEnt5(button); 
  }
  
  else if (ent[3] == 0){
    ent[3] = button;
    Serial.print("4: ");Serial.println(ent[3]); 
  }
  
}


void chechEnt5(int button){  
  digitalWrite(LED[button-1],HIGH);
  if (ent[4] != 0){
    chechEnt6(button);
  }
  else if (ent[4] == 0){
    ent[4] = button;
    Serial.print("5: ");Serial.println(ent[4]); 
  }
  
}

void chechEnt6(int button){
  digitalWrite(LED[button-1],HIGH);
  if (ent[5] == 0){
    ent[5] = button; 
    Serial.print("6: ");Serial.println(ent[5]);
    delay(100);
    compareCode();
  }
}

void compareCode(){ //code[] array ile ent[] array karsilastirilir ve dogru olup olmadigi kontrol edilir.
  for (int i = 0; i<6;i++){
    Serial.println(ent[i]);
  }
  if ((ent[0]==code[0]) && (ent[1]==code[1]) && (ent[2]==code[2]) && (ent[3]==code[3]) && (ent[4]==code[4])&& (ent[5]==code[5])){ //eger array'lerin butun elemanlari esir ise
    digitalWrite(redLed, LOW); //redLed sonsun 
    digitalWrite(greenLed, HIGH); //greenLED yansin
    delay(1000);
    digitalWrite(greenLed, LOW); //bekleme sonrasinda greenLed tekrar sonsun
    
    for (int i = 0; i < 7; i++){ 
      ent[i] = 0;
      
    }
 
    loop(); //return to loop() (not really necessary)
  }
  
  else { //eger tanimli sifre yanlis girilirse, redLed yanar ve bekleme sonrasi soner
    
    digitalWrite(redLed,HIGH);
    delay(1000);
    digitalWrite(redLed,LOW);
    Serial.println("Red OFF");
    for (int i = 0; i < 7; i++){
      ent[i] = 0;
     
    }
    
  }
  close_all();
}

void close_all(){
digitalWrite(LED[0],LOW);
digitalWrite(LED[1],LOW);
digitalWrite(LED[2],LOW);
digitalWrite(LED[3],LOW);
digitalWrite(LED[4],LOW);
digitalWrite(LED[5],LOW);
}
