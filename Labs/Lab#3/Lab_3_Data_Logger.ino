///////////////

#include <EEPROM.h>

/** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
int addr = 0;
int buttonPin = 13;
int numPresses = 0;
int address = 0;
byte value;

///////////////

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

///////////////

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);

}

void loop() {
  if (digitalRead(buttonPin) == HIGH)
  {
    numPresses = numPresses + 1;
    if (numPresses > 2)
    {
      numPresses = 0;
    }
    Serial.println(numPresses);
  }
//  Serial.println(numPresses);
  if (numPresses == 1)
  {
    delay(500);
    int val = analogRead(0) / 4;

    /***
    Write the value to the appropriate byte of the EEPROM.
    these values will remain there when the board is
    turned off.
    ***/

    EEPROM.write(addr, val);

    /***

    Rather than hard-coding the length, you should use the pre-provided length function.
    This will make your code portable to all AVR processors.
    ***/
    
    addr = addr + 1;
    if (addr == EEPROM.length()) 
    {
      addr = 0;
    }

    /***
    As the EEPROM sizes are powers of two, wrapping (preventing overflow) of an
    EEPROM address is also doable by a bitwise and of the length - 1.

    ++addr &= EEPROM.length() - 1;
    ***/


    delay(100);
  }
  else if (numPresses == 2)
  {
    value = EEPROM.read(address);

    Serial.print(address);
    testdrawstyles(address);
    Serial.print("\t");
    Serial.print(value, DEC);
    testdrawstyles2(value);
    Serial.println();

    /***
    Advance to the next address, when at the end restart at the beginning.

    Larger AVR processors have larger EEPROM sizes, E.g:
    - Arduno Duemilanove: 512b EEPROM storage.
    - Arduino Uno:        1kb EEPROM storage.
    - Arduino Mega:       4kb EEPROM storage.

    Rather than hard-coding the length, you should use the pre-provided length function.
    This will make your code portable to all AVR processors.
    ***/
    address = address + 1;
    if (address == EEPROM.length()) 
    {
      address = 0;
    }

    /***
    As the EEPROM sizes are powers of two, wrapping (preventing overflow) of an
    EEPROM address is also doable by a bitwise and of the length - 1.

    ++address &= EEPROM.length() - 1;
    ***/

    delay(500);
  }
  else if (numPresses == 0)
  {
    Serial.println("Data Logger Resting");
  }

}

void testdrawstyles(int inputVal) {
  display.clearDisplay();

  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.print(F("Loc: "));
  display.println(inputVal);

  display.display();
  delay(1000);
}

void testdrawstyles2(int inputVal2) {
  display.clearDisplay();

  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(5,0);             // Start at top-left corner
  display.print(F("Val: "));
  display.println(inputVal2);

  display.display();
  delay(1000);
}
