//LCD nin Kutuphanesi
#include <LiquidCrystal_I2C.h>
//Sensorun pini
#define sensor A3
//Ekranin adresi ve boyutlari
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup()
{
  Serial.begin(9600);
  //Ekrani aciyorum
  lcd.init();
  lcd.backlight();
}

void loop()
{
  //Sensorun okudugu degeri once gerilim
  //Sonra da dereceye ceviriyorum (celcius)
  int okuma = analogRead(sensor);
  float voltaj = okuma * (5.0/1024);
  float derece = (voltaj - 0.4972) * 100;
  
  //Lcd takmadan önce terminalden kontrol ediyorum
  Serial.print(derece);
  Serial.println("Derece");
  delay(1000);
  
  //Lcd ekrana degerleri yazdiriyorum
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(derece);
  lcd.setCursor(0,1);
  lcd.print("Derece");
  delay(2500);
}