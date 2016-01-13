
//GRID lib using neopixel_grid
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

//handles the button
#include <Bounce2.h>

//pin connected to bus
#define pixpin_grid 5
#define pixpin_BT1357 6
#define pixpin_BT246 3
#define pixpin_ST12 4

//number of pixels in bus
#define pixcount_grid 64
#define pixcount_BT1357 11 //BT1 is 2 leds, rest are groups of 3
#define pixcount_BT246 9 // groups of 3
#define pixcount_ST12 12

Adafruit_NeoPixel BT1357 = Adafruit_NeoPixel(pixcount_BT1357, pixpin_BT1357, NEO_GRB);
Adafruit_NeoPixel BT246 = Adafruit_NeoPixel(pixcount_BT246, pixpin_BT246, NEO_GRB);
Adafruit_NeoPixel ST12 = Adafruit_NeoPixel(pixcount_ST12, pixpin_ST12, NEO_GRB);

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, pixpin_grid,
                            NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
                            NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255)
};

// Instantiate a Bounce object :

#define BTN_pin 2                // button on pin 2
Bounce debouncer = Bounce();
unsigned long buttonPressTimeStamp;

