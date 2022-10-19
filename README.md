# Halloween
Spooky software for Halloween.

## Cauldron
Code to drive the lights in the clouds coming out of the cauldron in the dining
room.

### Getting Started
You will need the Arduino IDE: https://www.arduino.cc/en/software

You will also need to install the FastLED package by clicking on Tools -> Manage
Libraries, then searching for FastLED and installing it. Also make sure to set
the correct board in Tools (we're using Arduino Mega).

Open `cauldron.ino` in the Arduino IDE, then make any changes and click "Upload"
to run the code on the board.

There are two strands, each laid out in a spiral shape, and each with 250 WS2811
LEDs, plus some additional null pixels to allow the signal to make it from the
board to the starts of the strands without interference causing it to glitch
out. Long cables act as antennas and cause issues if null pixels aren't used.

Only signal cables are hooked to the Arduino, the lights themselves are powered
by a separate DC power supply.

Note that the lights coming out of the cauldron are at the ends of the strands
(index 249), with the first light in the strand being the outer edge of the
spiral (index 0).
