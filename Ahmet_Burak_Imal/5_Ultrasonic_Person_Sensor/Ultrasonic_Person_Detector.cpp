#include <LiquidCrystal.h>


LiquidCrystal lcd (1,2,4,5,6,7);

int pir_sensor = 13;
int pir_reader;
int buzzer = 9;

void setup()
{
 pinMode(13,INPUT); 
 pinMode(buzzer,OUTPUT);
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.print("Human Detector:)");
 lcd.setCursor(0,1);
 lcd.print("Myth.Scapegopat");
  
 delay(2000);
  
 lcd.clear();
  
}

void loop()
{
  pir_reader = digitalRead(pir_sensor);
 if (pir_reader ==1){
   digitalWrite(buzzer,HIGH);
   
  lcd.setCursor(4,0);
  lcd.print("There is");
    lcd.clear();
   lcd.setCursor(4,1);
  lcd.print(" Human");
   
 }
   else{
     digitalWrite(buzzer,LOW);
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("There is");
   lcd.setCursor(4,1);
  lcd.print("No Human");
   delay(500);
   }
 ;
  
}
