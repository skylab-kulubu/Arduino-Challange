const int ledPin[] = {1, 2, 3, 4, 5};
const int buttonPin[] = {8, 9, 10, 11, 12};
int ilk;
void akma(int ilk, int son) {
  if (ilk > son) {
    for (int i = ilk; i > son; i--) {
      digitalWrite(ledPin[ilk], LOW);
      digitalWrite(ledPin[i], HIGH);
      delay(500);
      digitalWrite(ledPin[i], LOW);
    }
    digitalWrite(ledPin[son], HIGH);
    
  } else if (ilk < son) {
    for (int i = ilk; i < son; i++) {
      digitalWrite(ledPin[ilk], LOW);
      digitalWrite(ledPin[i], HIGH);
      delay(500);
      digitalWrite(ledPin[i], LOW);
    }
    digitalWrite(ledPin[son], HIGH);
  } else {
    digitalWrite(ledPin[son], HIGH);
  }
}

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPin[i], OUTPUT);
    pinMode(buttonPin[i], INPUT);
  }
}

void loop() {
  if (digitalRead(buttonPin[0]) == HIGH) {
    akma(ilk, 0);
    ilk = 0;
  }
  if (digitalRead(buttonPin[1]) == HIGH) {
    akma(ilk, 1);
    ilk = 1;
  }
  if (digitalRead(buttonPin[2]) == HIGH) {
    akma(ilk, 2);
    ilk = 2;
  }
  if (digitalRead(buttonPin[3]) == HIGH) {
    akma(ilk, 3);
    ilk = 3;
  }
  if (digitalRead(buttonPin[4]) == HIGH) {
    akma(ilk, 4);
    ilk = 4;
  }
  delay(100);
}
