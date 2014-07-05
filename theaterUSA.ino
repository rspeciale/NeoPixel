/*
  <theaterUSA.ino> - This program creates a three color theaterChase.
  Each third pixel alternates between three colors at the brightness/rate specified.
  Created by Ryan Speciale. July 3, 2014.
*/

#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(40, PIN, NEO_GRB + NEO_KHZ800);
  
static uint8_t rate = 50; // pixel refresh rate
static int brightness = 35; // overall strip brightness

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
  
  theaterChase(red, wht, blu, rate);
  theaterChase(org, wht, blu, rate);
  theaterChase(grn, wht, org, rate);
  theaterChase(ylw, vlt, cyn, rate);
  
}


//---- theaterChase, three-color ----
//---- 3 colors passed, along with delay in ms ----
void theaterChase(uint32_t c1, uint32_t c2, uint32_t c3, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c1);    //turn every third pixel on
      }
      for (int i=1; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c2);    //turn every third pixel on
      }
      for (int i=2; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c3);    //turn every third pixel on
      }
      
      strip.show();
     
      delay(wait);
    }
  }
}
