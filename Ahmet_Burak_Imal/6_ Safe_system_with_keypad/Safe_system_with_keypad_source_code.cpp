#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

#define Password_Length 5

Servo maservo;
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

int pos = 0;

char Data[Password_Length];
char Master[Password_Length] = "0000";
byte data_count = 0, master_count = 0;

bool Pass_is_good;
bool door = false;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};

Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup()
{
  maservo.attach(9, 2000, 2400);
  ServoClose();
  lcd.begin(16, 2);
  lcd.setCursor(1,0);
  lcd.print("Protected Lock");
  loading("Loading");
  lcd.clear();
  delay(100);
}


void loop()
{
  if (door == true)
  {
    customKey = customKeypad.getKey();
    if (customKey == '#')
    {
      lcd.clear();
      ServoClose();
      lcd.print("Lock is closed");
      delay(1000);
      door = false;
    }
  }
  else
    Open();

}

void loading (char msg[]) {
  lcd.setCursor(0, 1);
  lcd.print(msg);

  for (int i = 0; i < 9; i++) {
    delay(1000);
    lcd.print(".");
  }
}

void clearData()
{
  while (data_count != 0)
  { 
    Data[data_count--] = 0;
  }
  return;
}

void ServoClose()
{
  for (pos = 90; pos >= 0; pos -= 10) { 
    maservo.write(pos);
  }
}

void ServoOpen()
{
  for (pos = 0; pos <= 90; pos += 10) {
    maservo.write(pos);  
  }
}

void Open()
{
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  delay(1000);  
  
  customKey = customKeypad.getKey();
  if (customKey)
  {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }

  if (data_count == Password_Length - 1)
  {
    if (!strcmp(Data, Master))
    {
      lcd.clear();
      ServoOpen();
      lcd.print("Correct Password");
      door = true;
      delay(2000);
      loading("Waiting");
      lcd.clear();
      lcd.print(" Time is up! ");
      delay(1000);
      ServoClose();
      door = false;      
    }
    else
    {
      lcd.clear();
      lcd.print(" Wrong Password ");
      lcd.print(" Please Try Again! ");
      door = false;
    }
    delay(1000);
    lcd.clear();
    clearData();
  }
}
