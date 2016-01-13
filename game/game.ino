//game (with cornell)

#define DEBUG 1

#include "header.h" //boring stuff in another tab

void setup() {
  if (DEBUG) Serial.begin(57600);

  //LED instances
  BTA.setBrightness(100); BTB.setBrightness(100); ST12.setBrightness(100);
  BTB.begin();   BTA.begin(); ST12.begin();
  BTB.show(); BTA.show(); ST12.show() ;

  matrix.begin();
  matrix.setBrightness(20);
  matrix.fillScreen(0); //blank

  //button stuff
  pinMode(BTN_pin, INPUT_PULLUP);
  debouncer.attach(BTN_pin);
  debouncer.interval(20);

  index = 0;
  //flicker_all(2, 2000);

  matrix_circle();
}

void loop() {
  /*
  // Update the Bounce instance
  debouncer.update();
  if (debouncer.fell()) buttonPressTimeStamp = millis();
  if ( debouncer.rose()  ) {
    if (DEBUG) Serial.println(millis() - buttonPressTimeStamp);
    if (millis() - buttonPressTimeStamp > 2000) {
      index = 12; //reset
      if (DEBUG) Serial.println("restart");
    } else {
      index++;
      flicker_ST12(5, 100); //number of loops, time of delay
      done = 0 ; //run the stage function
      if (DEBUG) Serial.println(index);
    }
  }

  stages(index);
  */
}

