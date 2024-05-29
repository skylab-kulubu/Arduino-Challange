#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9; 
const int echoPin = 10; 

long mesafe; 
int insanDurumu = 0; 

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  mesafe = pulseIn(echoPin, HIGH) * 0.034 / 2;
  
  if(mesafe < 180){
    lcd.setCursor(0,0);
    lcd.print("Insan Var");
  }
  else{
    lcd.setCursor(0,0);
    lcd.print("Insan Yok");
  }
  delay(100);
  
}
