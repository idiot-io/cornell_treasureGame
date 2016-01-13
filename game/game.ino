//game (with cornell)

#define DEBUG 1

#include "header.h" //boring stuff in another tab
bool oldState = HIGH;
int index = 0;

void setup() {
  if (DEBUG) Serial.begin(57600);

  //LED instances
  BT246.begin();   BT1357.begin(); ST12.begin();
  BT246.show(); BT246.show(); ST12.show() ;

  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);

  //button stuff
  pinMode(BTN_pin, INPUT_PULLUP);
  debouncer.attach(BTN_pin);
  debouncer.interval(20);

}

int x    = matrix.width();
int pass = 0;

void loop() {
  // Update the Bounce instance :
  debouncer.update();
  if (debouncer.fell()) buttonPressTimeStamp = millis();
  if ( debouncer.rose()  ) {
    Serial.println(millis() - buttonPressTimeStamp);
    if (millis() - buttonPressTimeStamp > 2000) {
      index = 12; //reset
      if (DEBUG) Serial.println("restart");
    } else {
      index++;
      if (DEBUG) Serial.println(index);
    }
  }

  stages(index);
}

