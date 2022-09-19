#include <LiquidCrystal.h>

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);
double temp=0;
void setup()
{
  lcd_1.begin(16, 2); 
  lcd_1.print("temperature:");
}

void loop()
{
  temp=analogRead(A0);

  lcd_1.setCursor(0, 1);
 
  lcd_1.print(temp/9.3);
  delay(1000); 
  
}
