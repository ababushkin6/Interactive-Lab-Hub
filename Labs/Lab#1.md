# IDD-Fall 2019-Lab1: Blink!

**Alan Babushkin (azb6)**
**Due: September 10, 2019**

## Part A. Set Up a Breadboard

![Initial Breadboard Setup](https://github.com/ababushkin6/Interactive-Lab-Hub/blob/master/Labs/Lab%201%20Breadboard%20Setup%202.jpg)


## Part B. Manually Blink a LED

**a. What color stripes are on a 100 Ohm resistor?**

The color stripes on a 100 Ohm resistor are [Brown, Black, Brown, Tolerance Color] on a 4 band resistor and [Brown, Black, Black, Black, Tolerance Color] on a 5 band resistor.
 
**b. What do you have to do to light your LED?**

In order to light the LED you need to press the button and hold it in order for the LED to keep glowing.

## Part C. Blink a LED using Arduino

### 1. Blink the on-board LED

**a. What line(s) of code do you need to change to make the LED blink (like, at all)?**

In order for the onboard LED to blink none of the code needs to be changed. It controls the correct LED to blink all by itself.

**b. What line(s) of code do you need to change to change the rate of blinking?**

The lines of code that you need to change to change the rate of blinking are the two "delay(1000);" lines in the loop part of the code. Increasing the delay makes the LED blink slower while decreasing the delay increases the blinking rate.

**c. What circuit element would you want to add to protect the board and external LED?**

The circuit element you can add to protect the board and an external LED is a resistor. It will limit the voltage across the LED and at the same time regulate the current so it doesn't burn out.

**d. At what delay can you no longer *perceive* the LED blinking? How can you prove to yourself that it is, in fact, still blinking?**

The delay at which I can no longer percieve the LED blinking is when the two delays are set to 15 (i.e. 15ms delay). I know that it is still blinking from prior experience and that once I raise it slighly it it still blinking rapidly but still blends together.

**e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.**

[Personal Blink Code](https://github.com/ababushkin6/Interactive-Lab-Hub/blob/master/Labs/Lab_1_Blink.ino)

### 2. Blink your LED

**Make a video of your LED blinking, and add it to your lab submission.**

[Blink the LED](https://www.youtube.com/watch?v=-Rkczo5w9hE&feature=youtu.be)

## Part D. Manually fade an LED

**a. Are you able to get the LED to glow the whole turning range of the potentiometer? Why or why not?**

The LED does glow the whole turning range, since no matter the resistance the potentiometer is tuned to, there is still the other resistor which means there is current flowing and the LED stays lit. At the same time the resistance of the pot isn't high enough to stop the current flow.

## Part E. Fade an LED using Arduino

**a. What do you have to modify to make the code control the circuit you've built on your breadboard?**

The part of the Fade example code you have to modify is in following line: "int led = 9;" you need to change the **9** to an **11** since that is the pin to which we connected the circuit we built. 

**b. What is analogWrite()? How is that different than digitalWrite()?**

AnalogWrite() is used to write a specific output to a pin in the range of [0,255] where 0 corresponds to 0V and 255 corresponds to 5V. The difference to digitalWrite() is that digitalWrite() can only choose LOW (0V) or HIGH (5V) while analogWrite() can also choose anything in between.

## Part F. FRANKENLIGHT!!!

### 1. Take apart your electronic device, and draw a schematic of what is inside. 

**a. Is there computation in your device? Where is it? What do you think is happening inside the "computer?"**

There is no computation inside my device.

**b. Are there sensors on your device? How do they work? How is the sensed information conveyed to other portions of the device?**

There are no sensors inside my device.

**c. How is the device powered? Is there any transformation or regulation of the power? How is that done? What voltages are used throughout the system?**

The device is powered using two AAA batteries (DC Voltage). The voltage the device runs at is 2.4V. The voltage to the LED light is regulated using a puch button.

**d. Is information stored in your device? Where? How?**

### 2. Using your schematic, figure out where a good point would be to hijack your device and implant an LED.

Since I had no objects that I could destroy, I decided to take apart some lights I had in such a way that they can be reassembled. Due to this, instead of adding an LED I instead will control them to blink using an Arduino/Processing program.
The process involved dismantling two clip-on LED lights and a LED lit pen. The lights were then connected to the breadboard and the microcontroller at three different pins. 
The idea was to have them flash according to a song that is being played. Since I do not possess the sensor listening to sound I had to input the song internally, through Processing. 
The song was then split into beats of LOW, MED, and HIGH, and each corresponding beat lights up the corresponding LED. 

### 3. Build your light!

**Make a video showing off your Frankenlight.**





