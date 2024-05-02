#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int butonPin1 = 8;
int butonPin2 = 9;
int butonPin3 = 10;
int butonPin4 = 11;

LiquidCrystal_I2C lcd(0x27, 16, 2);

boolean sifreVar = false;
String sifre;
String deneme;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  pinMode(butonPin1, INPUT);
  pinMode(butonPin2, INPUT);
  pinMode(butonPin3, INPUT);
  pinMode(butonPin4, INPUT);
}

void loop() {
  lcd.setCursor(0, 0);
  if (sifreVar == false) {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Yeni Sifre Girin");
    lcd.setCursor(0, 0);
    while (sifre.length() < 4) {
      char key1 = butonOku(butonPin1, '1');
      if (key1 != '\0') {
        sifre += key1;
        lcd.print("*");
        delay(200);
      }

      char key2 = butonOku(butonPin2, '2');
      if (key2 != '\0') {
        sifre += key2;
        lcd.print("*");
        delay(200);
      }

      char key3 = butonOku(butonPin3, '3');
      if (key3 != '\0') {
        sifre += key3;
        lcd.print("*");
        delay(200);
      }

      char key4 = butonOku(butonPin4, '4');
      if (key4 != '\0') {
        sifre += key4;
        lcd.print("*");
        delay(200);
      }
    }
    sifreVar = true;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Kilitli");
    lcd.setCursor(0, 1);
    lcd.print("Sifreyi Girin");
    delay(2000);
  } else {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Sifreyi Girin");
    lcd.setCursor(0, 0);
    while (deneme.length() < 4) {
      char key1 = butonOku(butonPin1, '1');
      if (key1 != '\0') {
        deneme += key1;
        lcd.print("*");
        delay(200);
      }

      char key2 = butonOku(butonPin2, '2');
      if (key2 != '\0') {
        deneme += key2;
        lcd.print("*");
        delay(200);
      }

      char key3 = butonOku(butonPin3, '3');
      if (key3 != '\0') {
        deneme += key3;
        lcd.print("*");
        delay(200);
      }

      char key4 = butonOku(butonPin4, '4');
      if (key4 != '\0') {
        deneme += key4;
        lcd.print("*");
        delay(200);
      }
    }
  }

  if (deneme == sifre) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sifre Dogru!");
    lcd.setCursor(0, 1);
    lcd.print("Kilit Acildi");
    delay(2000);
    sifre = "";
    deneme = "";
    sifreVar = false;
  }else if(deneme != sifre && deneme.length() == 4){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sifre Yanlis!");
    lcd.setCursor(0, 1);
    lcd.print("Yeniden Dene");
    delay(2000);
    deneme = "";
    sifreVar = true;
  }
}

char butonOku(int pin, char key) {
  delay(10);
  if (digitalRead(pin) == HIGH) {
    return key;
  }
  return '\0';
}

