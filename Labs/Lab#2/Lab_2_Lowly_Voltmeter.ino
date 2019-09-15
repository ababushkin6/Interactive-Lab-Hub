#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int ledPin = 10;          // the PWM pin the LED is attached to
int sensorPin = A0;
int sensorValue = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT); 
}

void loop() {
  sensorValue = analogRead(sensorPin);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(sensorValue);
  
  int val = map(sensorValue, 0, 1023, 0, 255);
  int voltageVal = map(sensorValue, 0, 1023, 0, 5);
  lcd.setCursor(0, 1);
  lcd.print(voltageVal);
  lcd.print(" V");

  analogWrite(ledPin, val);
}
