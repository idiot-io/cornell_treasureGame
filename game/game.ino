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
  matrix.setBrightness(40);
  matrix.setTextWrap(false);
  matrix.fillScreen(0); //blank
  matrix.show();

  //button stuff
  pinMode(buttonPin, INPUT_PULLUP);

  index = 0;
  flicker_all(2, 2000);


}

void loop() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState)
    lastDebounceTime = millis();

  if (millis() - lastDebounceTime > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        Serial.println(millis() - buttonPressTimeStamp);
        if (millis() - buttonPressTimeStamp > 1000) {
          index = 12; //reset
          if (DEBUG) Serial.println("restart");
        } else {
          index++;
          flicker_ST12(5, 100); //number of loops, time of delay
          if (DEBUG) Serial.println(index);
        }
        done = 0 ; //run the stage function
        
      } else if (buttonState == LOW) {
        buttonPressTimeStamp = millis();
      }

    }
  }

  lastButtonState = reading;
  stages(index);

}

