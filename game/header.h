
//GRID lib using neopixel_grid
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

//sprites
//via https://github.com/masteruan/NeoPixel-Matrix-Sprite/
#include "Definitions.h"
#include "Shape.h"

//tone melody digital examples
#include "pitches.h"

//pin connected to bus
#define pixpin_grid 5
#define pixpin_BTA 6
#define pixpin_BTB 3
#define pixpin_ST12 4 

//number of pixels in bus
#define pixcount_grid 64
#define pixcount_ST12 12
#define pixcount_BTA 11 //bta1 is 2 leds, rest are groups of 3
int bta1 = 0,  bta3 = 2, bta5 = 5,  bta7 = 8;
#define pixcount_BTB 9 // groups of 3
int btb2 = 0, btb4 = 3, btb6 = 6;

Adafruit_NeoPixel BTA = Adafruit_NeoPixel(pixcount_BTA, pixpin_BTA, NEO_GRB);
Adafruit_NeoPixel BTB = Adafruit_NeoPixel(pixcount_BTB, pixpin_BTB, NEO_GRB);
Adafruit_NeoPixel ST12 = Adafruit_NeoPixel(pixcount_ST12, pixpin_ST12, NEO_GRB);

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, pixpin_grid,
                            NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
                            NEO_GRB            + NEO_KHZ800);

//handles the button
#include <Bounce2.h>
#define BTN_pin 2                // button on pin 2
Bounce debouncer = Bounce();
unsigned long buttonPressTimeStamp;
int index = 0;
boolean done = false;

