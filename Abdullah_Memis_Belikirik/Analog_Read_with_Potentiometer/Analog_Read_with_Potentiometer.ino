int read = A0;
float value;

void setup(){
  pinMode(read, INPUT);
  Serial.begin(9600);
}

void loop(){
  value = analogRead(read);
  Serial.print("digital value =");
  Serial.println(value);
  delay(250);
}
