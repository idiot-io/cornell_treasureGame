#include "FastLED.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
//
// RGB Calibration code
//
// Use this sketch to determine what the RGB ordering for your chipset should be.  Steps for setting up to use:

// * Uncomment the line in setup that corresponds to the LED chipset that you are using.  (Note that they
//   all explicitly specify the RGB order as RGB)
// * Define DATA_PIN to the pin that data is connected to.
// * (Optional) if using software SPI for chipsets that are SPI based, define CLOCK_PIN to the clock pin
// * Compile/upload/run the sketch 

// You should see six leds on.  If the RGB ordering is correct, you should see 1 red led, 2 green 
// leds, and 3 blue leds.  If you see different colors, the count of each color tells you what the 
// position for that color in the rgb orering should be.  So, for example, if you see 1 Blue, and 2
// Red, and 3 Green leds then the rgb ordering should be BRG (Blue, Red, Green).  

// You can then test this ordering by setting the RGB ordering in the addLeds line below to the new ordering
// and it should come out correctly, 1 red, 2 green, and 3 blue.
//
//////////////////////////////////////////////////



#define buttonPin1 2                // button on pin 2

CRGB medal1[6];
CRGB medal2[3];
CRGB pocket[64];


//btn1
int buttonState1;                    // variable to store button state
int lastButtonState1;                // variable to store last button state
int count;
long previousMillis1 = 0;            // variable to store last time LED was updated
long startTime1 ;                    // start time for stop watch
long elapsedTime1 ;                  // elapsed time for stop watch


void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
   	delay(1000);
   FastLED.addLeds<NEOPIXEL, 5>(pocket, 64);
  FastLED.addLeds<NEOPIXEL, 6>(medal1, 6);
  FastLED.addLeds<NEOPIXEL, 7>(medal2, 3);
      Serial.begin(9600);
  
   pinMode(buttonPin1, INPUT_PULLUP);       // not really necessary, pins default to INPUT anyway
   //digitalWrite(buttonPin1, LOW);   // turn on pullup resistors. Wire button so that press shorts pin to ground.
  
   count=0;
}

void loop() {

BTN1 ();
  
 
}




void BTN1 (){
  
   // check for button1 press
   buttonState1 = digitalRead(buttonPin1);                   // read the button state and store

   if (buttonState1 == LOW && lastButtonState1 == HIGH){     // check for a high to low transition
      // if true then found a new button press while clock is not running - start the clock

      startTime1 = millis();                                   // store the start time
      delay(20);                                               // short delay to debounce switch
      lastButtonState1 = buttonState1;                          // store buttonState in lastButtonState, to compare next time

   }

   else if (buttonState1 == HIGH && lastButtonState1 == LOW){     // check for a high to low transition
      // if true then found a new button press while clock is running - stop the clock and report

        elapsedTime1 =   millis() - startTime1;              // store elapsed time
        lastButtonState1 = buttonState1;                     // store buttonState in lastButtonState, to compare next time
      int presstime1 = elapsedTime1 / 600L;
       // routine to report elapsed time 
      // Serial.print("btn1 Press time:"); Serial.print( presstime1); Serial.print("sec");        // divide by 1000 to convert to seconds - then cast to an int to print
      // Serial.println();
       
     
       if(presstime1==1){//less then a sec
        
//       Serial.print('A');
//       Serial.println();
       count++;
       Serial.print(count);
        Serial.println();
        switch(count){
    case 0: 
    // nothing happens all leds off
            break;
    case 1: 
    //beep
          tone(3, 440, 200);
          delay(200);
            break;
    case 2: 
    //beep
           tone(3, 440, 200);
          delay(200);
            break;
    case 3:
    //first medal on!
          blinky1();
            break;
    case 4:
    //beep
    tone(3, 440, 200);
          delay(200);
            break;
    case 5:
    //beep
    tone(3, 440, 200);
          delay(200);
            break;
    case 6: 
    //second medal on!
      blinky2();
            break;
    case 7: 
            break;
    case 8: 
            break;
    case 9: 
            break;
  }
        
        
         
   }
    if(presstime1>1){//long
       
       Serial.print('X');
       Serial.println();
      
      count=0;
   }
   
   lastButtonState1 = buttonState1;                         // store buttonState in lastButtonState, to compare next time
    
   }
   
}

void blinky1(){

 for(int i = 0; i < 6; i++) {
    medal1[i] = CRGB(55,255,10);
FastLED.show();
 delay(200);
//    // clear our current dot before we move on
//  medal1[i] = CRGB::Black;
  }
  

}
void blinky2(){

 for(int i = 0; i < 3; i++) {
    medal2[i] = CRGB(255,255,10);
FastLED.show();
 delay(200);
//    // clear our current dot before we move on
//  medal2[i] = CRGB::Black;
  }
 

}
