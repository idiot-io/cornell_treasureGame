//LED lib
#include <Adafruit_NeoPixel.h>

//GRID lib using neopixel_grid
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define BTN_pin1 2                // button on pin 2


#define pixpin_grid 5
#define pixpin_medal1 6
#define pixpin_medal2 3

#define pixcount_grid 64
#define pixcount_medal1 6
#define pixcount_medal2 3

Adafruit_NeoPixel medal1 = Adafruit_NeoPixel(pixcount_medal1, pixpin_medal1, NEO_GRB);
Adafruit_NeoPixel medal2 = Adafruit_NeoPixel(pixcount_medal2, pixpin_medal2, NEO_GRB);

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, pixpin_grid,
                            NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
                            NEO_GRB            + NEO_KHZ800);
const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };
