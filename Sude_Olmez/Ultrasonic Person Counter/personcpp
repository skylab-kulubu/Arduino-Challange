#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int Pirpin=8;
int hareket;

void setup()
{
  pinMode(Pirpin,INPUT);
  lcd.begin(16, 2); 
  
}

void loop()
{
 hareket= digitalRead(Pirpin);
  
  if(hareket==1){
   
  lcd.setCursor(0, 0);  
  lcd.print("HUMAN:");	
  lcd.clear();  
  lcd.setCursor(0, 1);
 
  lcd.print("exists");
    
  }
 
  else if (hareket==0){
  lcd.clear();
  lcd.setCursor(0, 0);    
  lcd.print("HUMAN:");  
  lcd.setCursor(0, 1);
  lcd.print("doesn't exist");
    delay(500);
  }
  
}
