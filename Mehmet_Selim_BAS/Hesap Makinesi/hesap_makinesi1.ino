#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const byte ROW = 4;
const byte COL = 4;

char keys[ROW][COL] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'S', '0', '=', '/'}
};

byte pinRow[ROW] = {7, 6, 5, 4};
byte pinCol[COL] = {3, 2, 9, 8};

Keypad keypad = Keypad(makeKeymap(keys), pinRow, pinCol, ROW, COL);

LiquidCrystal_I2C lcd(0x27, 16, 2);

String num1, num2;
char op;
boolean opVar = false;
boolean sonuc = false;
int numLen;
float result; // Eksik tanımlama

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY && (key != '+' && key != '-' && key != '*' && key != '/' && key != '=' && key != 'S')) { // Mantıksal operatörlerde hata
    if (opVar == false) {
      num1 = num1 + key;
      numLen = num1.length();
      lcd.setCursor(0, 0);
      lcd.print(num1);
    } else {
      num2 = num2 + key;
      lcd.setCursor(numLen + 3, 0);
      lcd.print(num2);
      sonuc = true;
    }
  }
  if (opVar == false && key != NO_KEY && (key == '+' || key == '-' || key == '*' || key == '/')) { // Mantıksal operatörde hata
    opVar = true;
    op = key;
    lcd.setCursor(numLen + 1, 0);
    lcd.print(op);
  }
  if (opVar == true && sonuc == true && key != NO_KEY && key == '=') {
    switch (op) {
      case '+':
        result = num1.toFloat() + num2.toFloat();
        break;
      case '-':
        result = num1.toFloat() - num2.toFloat();
        break;
      case '*':
        result = num1.toFloat() * num2.toFloat();
        break;
      case '/':
        if (num2.toFloat() != 0.0) { // Karşılaştırma operatöründe hata
          result = num1.toFloat() / num2.toFloat();
        } else {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("0'a bolunemez");
          delay(3000);
          num1 = "";
          num2 = "";
          opVar = false;
          sonuc = false;
          lcd.clear();
          return;
        }
        break;
    }
  }
  lcd.setCursor(0,1);
  lcd.print(result);
  if (opVar == true && sonuc == true && key != NO_KEY && key == 'S'){
    lcd.clear();
    lcd.setCursor(0,0);
    num1 = "";
    num2 = "";
    result = 0.0;
    opVar = false;
    sonuc = false;
  }
}
