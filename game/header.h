
//GRID lib using neopixel_grid
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

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
//to get the color you need google "hex colors"
//you can also use plain (rrr,ggg,bbb) instead of this
const int num_colors = 5;
const static uint32_t BTcolors[num_colors] = {
  0x000000,     //black
  0xff0000,    // red
  0x00ff00,    // green
  0x0000ff,    // blue
  0xffffff,    // white
};


Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, pixpin_grid,
                            NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
                            NEO_GRB            + NEO_KHZ800);

int x    = matrix.width();
int pass = 0;
const uint16_t colors[] = { //the colors we use
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255)
};




//handles the button
#include <Bounce2.h>
#define BTN_pin 2                // button on pin 2
Bounce debouncer = Bounce();
unsigned long buttonPressTimeStamp;
int index = 0;
boolean done = false;

