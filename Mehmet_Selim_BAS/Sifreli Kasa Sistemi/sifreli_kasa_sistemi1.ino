#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Wire.h>
#include <Servo.h>

#define SERVO_PIN 2
#define SERVO_LOCK_POS 0
#define SERVO_UNLOCK_POS 90
Servo kilitServo;

const byte rows = 4;
const byte cols = 4;

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte rowpin[rows] = {13,12,11,10};
byte colpin[cols] = {9,8,7,6};
char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowpin, colpin, rows, cols);

boolean sifreVar = false;
String result = "";
String deneme = "";


void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  kilitServo.attach(2);
}

void loop()
{
  
  if(sifreVar == false){
    kilitServo.write(90);
    lcd.setCursor(0,0);
    lcd.print("Kilitli Degil");
    lcd.setCursor(0,1);
    lcd.print("Sifre gir :");
    lcd.setCursor(12,1);
    lcd.print("____");
    while(result.length() < 4){
      char key = keypad.getKey();
      if(key != NO_KEY && key != '*'){
        result = result + key;
        lcd.setCursor(11 + result.length(), 1);
        lcd.print("*");
      }
    }
    sifreVar = true;
  }
  if(sifreVar == true){
    kilitServo.write(0);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Kilitli");
    lcd.setCursor(0,1);
    lcd.print("Sifre gir :");
    lcd.setCursor(12,1);
    lcd.print("****");
    delay(2000);
    lcd.setCursor(12,1);
    lcd.print("____");
    while(deneme.length() < 4){
      char key = keypad.getKey();
      if(key != NO_KEY && key != '*'){
        deneme = deneme + key;
        lcd.setCursor(11 + deneme.length(), 1);
        lcd.print("*");
      }  
    }
    lcd.setCursor(12,1);
    lcd.print("****");
     if(result == deneme){
    	sifreVar = false;
        result = "";
        deneme = "";
       	lcd.setCursor(12,1);
    	lcd.print("____");
  	}
    else{
     	
      	lcd.clear();
      	lcd.setCursor(0,0);
      	lcd.print("Yanlis Sifre");
      	deneme = "";
      	delay(3000);
       	sifreVar = true;
    }
    
  }
 
  
}