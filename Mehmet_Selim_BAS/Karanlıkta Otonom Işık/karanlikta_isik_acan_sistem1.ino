//Pinleri belirtiyorum
#define isikOlcer A0
int led = 5;
void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop()
{
  //Fotorezistorden deger aliyorum
  int isikDeger = analogRead(isikOlcer);
  //Kontrol amacli terminale yazdiriyorum
  Serial.println(isikDeger);
  
  if(isikDeger > 500){
  	digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  delay(1000);
}