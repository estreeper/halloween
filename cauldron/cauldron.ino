#include <FastLED.h>

#define ASTRAND_DATA_PIN 10
#define BSTRAND_DATA_PIN 8

/* We had to use "null pixels" to get the data signal to propogate from the 
  Arduino to the beginning of the strands, see:
  https://www.holidaycoro.com/kb_results.asp?ID=156
  There are 5 on strand A and 4 on strand B
*/
#define ASTRAND_START_LED 5
#define ASTRAND_END_LED 255
#define BSTRAND_START_LED 4
#define BSTRAND_END_LED 254

#define SPIRAL_LENGTH 250

CRGB astrand[ASTRAND_END_LED - ASTRAND_START_LED];
CRGB bstrand[BSTRAND_END_LED - BSTRAND_START_LED];

// put your setup code here, to run once:
void setup() {
  // TODO(eric): need to skip over the null pixels
  FastLED.addLeds<WS2811, ASTRAND_DATA_PIN>(astrand, SPIRAL_LENGTH);
  FastLED.addLeds<WS2811, BSTRAND_DATA_PIN>(bstrand, SPIRAL_LENGTH);
}

// put your main code here, to run repeatedly:
void loop() {
  cycle(CRGB(130, 0, 255), 3);
}

void cycle(CRGB color, int delayMS) {
  for (int i = SPIRAL_LENGTH; i > 0; i--) {
    astrand[i] = color;
    bstrand[i] = color;
    FastLED.show();
    delay(delayMS);
  }
  FastLED.clear();
}
