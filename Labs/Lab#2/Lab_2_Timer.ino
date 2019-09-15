///// For Display /////
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

///// For Encoder /////
#define ENC_A 6 
#define ENC_B 7

///// For Speaker /////

#include "pitches.h"
// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 4, 4
};

///// For LEDs /////
int ledPin1 = 9;
int ledPin2 = 10;

///// Button /////
int buttonPin = 13;

///// Other Variables /////
int timeToCount = 0;


void setup() {
  // LCD
  lcd.begin(16, 2);

  // Encoder
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
 
  Serial.begin (9600);
  Serial.println("Start");
  
  // LEDs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // Button
  pinMode(buttonPin, INPUT);
  
}

void loop() { 
  ///// Encoder
  static unsigned int counter4x = 0;      //the SparkFun encoders jump by 4 states from detent to detent
  static unsigned int counter = 0;
  static unsigned int prevCounter = 0;
  int tmpdata;
  tmpdata = read_encoder();
  if( tmpdata) {
    counter4x += tmpdata;
    counter = counter4x/4;
    if (prevCounter != counter){
      Serial.print("Counter value: ");
      Serial.println(counter);
      lcd.print("Counter Value: ");
      lcd.setCursor(0, 1);
      lcd.print(counter);
      
    }
    prevCounter = counter;
  }
  lcd.setCursor(0, 0);
  
  if (digitalRead(buttonPin) == HIGH)
  {
    timeToCount = counter;
    lcd.print("Countdown Timer: ");
    lcd.setCursor(0, 1);
    lcd.print(timeToCount);
    
    delay(30);
    
    while (timeToCount >= 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Time Remaining");
      lcd.setCursor(0, 1);
      lcd.print(timeToCount);
      timeToCount = timeToCount - 1;
      delay(1000);
    }

    if (timeToCount == -1)
    {
      int i = 0;
      while ( i < 3)
      {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        play_alert();
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        delay(50);
        i = i + 1;
        
      }
    }
    
  }
  
}



 
///// Encoder Reading Function /////
int read_encoder()
{
  static int enc_states[] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};
  static byte ABab = 0;
  ABab *= 4;                   //shift the old values over 2 bits
  ABab = ABab%16;      //keeps only bits 0-3
  ABab += 2*digitalRead(ENC_A)+digitalRead(ENC_B); //adds enc_a and enc_b values to bits 1 and 0
  return ( enc_states[ABab]);
   
}

///// Counter Alert /////
void play_alert() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
