#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int temperature;
int temperaturePin = A0;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop(){
  temperature = ((analogRead(temperaturePin) * 4.91)-500)/10;
  
  lcd.setCursor(0, 0);
  lcd.print("Temperature ");
  lcd.setCursor(0,1);
  lcd.print(temperature);
  
  Serial.print(temperature);
  Serial.println(" C ");
  delay(500);
}
  
