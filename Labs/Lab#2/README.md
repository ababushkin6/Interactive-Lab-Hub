# IDD-Fall 2019-Lab2: Digital Timer

## Part A. Solder your LCD panel

**Soldered LCD Front**
![Soldered LCD Front](https://github.com/ababushkin6/Interactive-Lab-Hub/blob/master/Labs/Lab%232/Soldered%20LCD%20Front.jpg)

**Soldered LCD Back**
![Soldered LCD Back](https://github.com/ababushkin6/Interactive-Lab-Hub/blob/master/Labs/Lab%232/Soldered%20LCD%20Back.jpg)

## Part B. Writing to the LCD

**a. What voltage level do you need to power your display?**

You need a voltage level of 5V to power your display. 

**b. What voltage level do you need to power the display backlight?**

The voltage level required for the backlight is also 5V.

**c. What was one mistake you made when wiring up the display? How did you fix it?**

No mistakes were made in the wiring of the display.

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**

The line of code you need to change is the following line:

    lcd.print("Hello World"); to lcd.print("Alan Babushkin");

**e. Include a copy of your Lowly Multimeter code in your lab write-up.**

[Low Voltage Multimeter Code](https://github.com/ababushkin6/Interactive-Lab-Hub/blob/master/Labs/Lab%232/Lab_2_Lowly_Voltmeter.ino)

## Part C. Using a time-based digital sensor

[Working Rotary Encoder](https://github.com/ababushkin6/Interactive-Lab-Hub/blob/master/Labs/Lab%232/Rotary%20Encoder%20Testing.MOV)

## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**

To make the song play twice as fast, you could either change the *1000* to *500* in the following line of code:

    int noteDuration = 1000 / noteDurations[thisNote];
or you can multiply the numbers by two in this part of the code:

    int noteDurations[] = {
      10,10,10,2,2,10,10,10,2,4, \
      10,10,10,2,4,10,10,10,2,4};

**b. What song is playing?**

The song playing is the theme to Star Wars.

## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

My timer is made using a LCD, a rotary encoder, a button, a speaker and two LEDs. The rotary encoder is turned to set the timer in seconds while being desplayed on the LCD screen. Then the button is pressed to start the timer which shows the countdown on the LCD. Finally when the timer ends (reaches 0), the speaker plays an alert at the same time that the LEDs flash.

The code for this utilizes the earlier parts of this lab  and the built-in libraries. The code followed by the video is below:

[Lab 2 Timer Code](https://github.com/ababushkin6/Interactive-Lab-Hub/blob/master/Labs/Lab%232/Lab_2_Timer.ino)

[Pitches.h](https://github.com/ababushkin6/Interactive-Lab-Hub/blob/master/Labs/Lab%232/pitches.h)

[Timer Working](https://github.com/ababushkin6/Interactive-Lab-Hub/blob/master/Labs/Lab%232/Lab%202%20Timer%20Video.mp4)
