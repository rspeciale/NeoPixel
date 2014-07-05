/*
  <marqueeText.ino> - This program creates a matrix display of text marquee style.
  The text is displayed in a scrolling marquee in a specified color.
  Created by Ryan Speciale. July 3, 2014.
*/ 

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6

// MATRIX DECLARATION:
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(5, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);// done in AdaFruit_Colors.h

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

const uint16_t colors[] = {red, wht, blu};	// array of colors to use

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);  //text scrolls completely off screen
  matrix.setBrightness(brightness);  //overall brightness of LEDs
  matrix.setTextColor(colors[0]);  //use colors in array for text
}

int x = matrix.width();
int pass = 0;

void loop() {

    // **** display text marquee ****  
    marquee(rate);  // delay constant in ms
    
}

//---- text display, via marquee ----
//---- text string is defined BELOW ----
//---- 1 color array pased, along with delay in ms ----
    
    void marquee(uint8_t wait){
         matrix.fillScreen(0); // clear display
         matrix.setCursor(x, 0); // matrix start point
         
         // --- THIS IS WHERE YOU DEFINE TEXT ----
         matrix.print(F("USA")); // TEXT STRING TO PRINT
        
             if(--x < -36) { 
                 x = matrix.width();
                 if(++pass >= 3) pass = 0;
                     matrix.setTextColor(colors[pass]);
              }
        
         matrix.show();
         delay(rate);
    }
//-------------------------------------