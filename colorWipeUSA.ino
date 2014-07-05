/*
  <colorWipeUSA.ino> - This program creates an American Flag on the NeoPixel Shield.
  Each row is filled pixel by pixel at the rate and brightness specified.
  Created by Ryan Speciale. July 3, 2014.
*/

#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(40, PIN, NEO_GRB + NEO_KHZ800);
  
static uint8_t rate = 50; // pixel refresh rate
static int brightness = 30; // overall strip brightness

// **** RGB Color Constants ****
   uint32_t off = strip.Color(000, 000, 000);
   uint32_t blu = strip.Color(000, 000, 255);
   uint32_t red = strip.Color(255, 000, 000);
   uint32_t wht = strip.Color(255, 255, 255);
   uint32_t org = strip.Color(255, 140, 000);
   uint32_t grn = strip.Color(000, 255, 000);
   uint32_t ylw = strip.Color(255, 255, 000);
   uint32_t cyn = strip.Color(000, 255, 255);
   uint32_t vlt = strip.Color(255, 000, 255);
   
//******************************

  
void setup() {
  strip.begin();
  strip.setBrightness(brightness); // overall brightness of all LEDs
  strip.show(); // initialize all pixels
}

void loop() {

  // **** USA Flag row by row ****
  colorWipeUSA(red, wht, blu, rate); // 50ms delay
  delay(100);  // 100ms delay between scans
  colorWipe(off, 1);  // clear display
  colorWipeUSA(red, wht, blu, rate/2); // 100ms delay
  
 // *** colorWipe, normal ****
 //colorWipe(blu, 50); // whole strip
 
}

//---- regular colorWipe, whole strip ----
//---- 1 color pased, along with delay in ms ----
    
    void colorWipe(uint32_t c, uint8_t wait) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, c);  //whole strip
          strip.show();
          delay(wait);
      }
}
//---------------------------------------

//---- make an American Flag in wiping fashion ----
//---- 3 colors passed along with delay in ms ----
    void colorWipeUSA(uint32_t c1, uint32_t c2, uint32_t c3, uint8_t wait) {
      for(uint16_t i=0; i<3; i++) { 
          strip.setPixelColor(i, c3);  //blue square - row 1
          strip.show();
          delay(wait);
      }
      for(uint16_t i=3; i<8; i++) {
          strip.setPixelColor(i, c1);  //red stripe - row 1
          strip.show();
          delay(wait);
      }
      for(uint16_t i=8; i<11; i++) {
          strip.setPixelColor(i, c3);  //blue square - row 2
          strip.show();
          delay(wait);
      }
      for(uint16_t i=11; i<16; i++) {
          strip.setPixelColor(i, c2);  //white stripe - row 2
          strip.show();
          delay(wait);
      }
      for(uint16_t i=16; i<19; i++) {
          strip.setPixelColor(i, c3);  //blue square - row 3
          strip.show();
          delay(wait);
      }
      for(uint16_t i=19; i<24; i++) {
          strip.setPixelColor(i, c1);  //red stripe - row 3
          strip.show();
          delay(wait);
      }
      for(uint16_t i=24; i<32; i++) {
          strip.setPixelColor(i, c2);  //white stripe - row 4
          strip.show();
          delay(wait);
      }
      for(uint16_t i=32; i<41; i++) {
          strip.setPixelColor(i, c1);  //red stripe - row 5
          strip.show();
          delay(wait);
      }
    }
//--------------------------------------

