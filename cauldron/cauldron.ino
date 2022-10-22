#include <FastLED.h>

#define ASTRAND_DATA_PIN 10
#define BSTRAND_DATA_PIN 8

/* We had to use "null pixels" to get the data signal to propogate from the 
  Arduino to the beginning of the strands, see:
  https://www.holidaycoro.com/kb_results.asp?ID=156
  There are 5 on strand A and 4 on strand B
*/
#define ASTRAND_START_LED 4
#define ASTRAND_END_LED 254
#define BSTRAND_START_LED 3
#define BSTRAND_END_LED 253
#define ASTRAND_TOTAL_LEN ASTRAND_END_LED + 1
#define BSTRAND_TOTAL_LEN BSTRAND_END_LED + 1
#define ASTRAND_SPIRAL_LENGTH ASTRAND_END_LED-ASTRAND_START_LED
#define BSTRAND_SPIRAL_LENGTH BSTRAND_END_LED-BSTRAND_START_LED
#define SPIRAL_LENGTH 250

CRGB a_physical_strand[ASTRAND_END_LED + 1];
CRGB b_physical_strand[BSTRAND_END_LED + 1];

CRGB* astrand[ASTRAND_SPIRAL_LENGTH];
CRGB* bstrand[BSTRAND_SPIRAL_LENGTH];

// put your setup code here, to run once:
void setup() {
  FastLED.addLeds<WS2811, ASTRAND_DATA_PIN>(a_physical_strand, ASTRAND_TOTAL_LEN + 1);
  FastLED.addLeds<WS2811, BSTRAND_DATA_PIN>(b_physical_strand, BSTRAND_TOTAL_LEN + 1);

  populate_astrand();
  populate_bstrand();
}

void populate_astrand() {
  for(int i = ASTRAND_SPIRAL_LENGTH; i > 0; i--) {
    astrand[ASTRAND_SPIRAL_LENGTH-i] = &a_physical_strand[i + ASTRAND_START_LED];
  }
}

void populate_bstrand() {
  for(int i = BSTRAND_SPIRAL_LENGTH; i > 0; i--) {
    bstrand[BSTRAND_SPIRAL_LENGTH-i] = &b_physical_strand[i + BSTRAND_START_LED];
  }
}

// put your main code here, to run repeatedly:
void loop() {
  cycle(CRGB(130, 0, 255), 3);
}

void cycle(CRGB color, int delayMS) {
  for (int i = 0; i < ASTRAND_SPIRAL_LENGTH; i++) {
    a_physical_strand[i] = color;
    b_physical_strand[i] = color;
    FastLED.show();
    delay(delayMS);
  }
  FastLED.clear();
}
