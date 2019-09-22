# IDD-Fall 2019-Lab3: Data Logger

## Part A. Writing to the Serial Monitor

**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**

Based on the readings from te serial monitor, the range of the analog values is from 0 to 1023.

**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

The arduino's analog to digital converter (ADC) has 10 bits of resolution.

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**

Using the RGB LED along with some of the resistors the RGB is made to light up in 6 different colors. 

## Part C. Voltage Varying Sensors

### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**

The values being read from the force sensor are from 0 to 1023 which can be translated to a voltage of 0-5V; which is the voltage connected to the force resistive sensor

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

The voltage has a linear relationship to the force applied to the FSR. It maps linearily from 0-1023 to 0-5.

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

In order to get the full range of ouput voltages from the LED when controlling it usinf the FSR the line of code you need is to map the values that the FSR reads to the values that you output to the LED as follows:
     
    outputLED = map(inputFSR, 0, 1023, 0, 255);

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

The resistance that you need to get in series to get a reasonable value of voltages is any resistance in the 10k Ohm to 27k Ohm range. This lets the max of the sensors' resistance take up almost the whole voltage while when the sensor's resistance is at a minimum it is large enough that most of the voltage is across the resistor.

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

The resistance decreases linearly as the force applied increases. For example,for the FSR as a force of 0-20lbs is applied the resistance goes from 100k Ohm to 200 Ohm.

### 2. Accelerometer

**a. Include your accelerometer read-out code in your write-up.**

[Accellerometer Code]()

### Optional. Graphic Display 

**Take a picture of your screen working insert it here!**

Below is the code used to read the AO pin and then display the value on the OLED. A video of the screen working through this is also attached.

[Reading A0 OLED Code](https://github.com/ababushkin6/Interactive-Lab-Hub/blob/master/Labs/Lab%233/Lab_3_OLED_Display_of_Input.ino)

[OLED Working Video](https://youtu.be/5EgvecDvAIk)

## Part D. Logging values to the EEPROM and reading them back

### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

No it does not matter which actions are on which state as there is no difference between the order of the states and you can turn the potentiometer to start at any of the positions which negates the order of the states as well.

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

The code here is all in the setup function and not in the loop because you want to do the action once after calling it and not keep going which would require an external trigger to stop, preventing you from doing any other actions. 

**c. How many byte-sized data samples can you store on the Atmega328?**

You can store 1024 byte-sized data samples on the Atmega328.

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

You would drop two of the 10-bit data so that you can store it as a byte. For the analog data from the I2C devices you would do the same. 

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the EEPROMPut example)**

You would store the data a bit at a time and what doesn't fit into the byte-sized location would be removed; repeating till everything is saved. 

Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.

### 2. Design your logger

**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!

**a. Record and upload a short demo video of your logger in action.**
