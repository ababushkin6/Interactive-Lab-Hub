#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


int pos = 0;    // variable to store the servo position


int buttonPin = 10;
int theCount = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(buttonPin, INPUT);
  myservo.write(0);
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH)
  {
    Serial.println("Jack GO!");
    theCount = random(15);
    delay(1000*theCount);
    pos = 140;
    myservo.write(pos);
  }

  
}

void move_fast()
{
  for (pos = 0; pos <= 180; pos += 5) { 
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 180; pos >= 0; pos -= 5) {
    myservo.write(pos);              
    delay(15);                       
  }
}

void move_slow()
{
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              
    delay(20);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);              
    delay(20);                       
  }
}
