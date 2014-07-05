/*
  <matrixLibrary.ino> - This program is a collection of matrix commands.
  The commands from the NeoMatrix library are described below.
  Created by Ryan Speciale. July 3, 2014.
*/ 

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_Colors.h>

#define PIN 6

static uint8_t rate = 50; //pixel refresh rate
static int brightness = 35; //overall strip brightness

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(5, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);
  
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


const uint16_t colors[] = {red, wht, blu}; // colors to be used in display

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(brightness);
  matrix.setTextColor(colors[0]);
}

int x    = matrix.width(); // assign matrix width to variable x
int pass = 0;  

void loop() {
  matrix.fillScreen(0);
  
  //**** simple line ****
  //matrix.drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);
  //matrix.drawLine(0, 0, 7, 4, red);
  
  //**** vertical/horizontal line ****
  //matrix.drawFastVLine(uint16_t x0, uint16_t y0, uint16_t length, uint16_t color);
  //matrix.drawFastHLine(uint16_t x0, uint16_t y0, uint16_t length, uint16_t color);
  
  //**** rectangle fill ****
  //matrix.fillRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t color);
  //**** rectangle outline ****
  //matrix.drawRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t color);
  
  //**** circle fill ****
  //matrix.fillCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color);
  //**** circle outline ****
  //matrix.drawCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color);
  
  //**** rounded rectangle fill ****
  //matrix.fillRoundRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t radius, uint16_t color);
  //**** rounded rectangle outline ****
  //matrix.drawRoundRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t radius, uint16_t color);

  //**** triangle fill ****
  //matrix.fillTriangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
  //**** triangle outline ****
  //matrix.drawTriangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
 
  //**** single character ****
  //matrix.drawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg, uint8_t size);
  
  //**** text ****
  //matrix.setCursor(uint16_t x0, uint16_t y0);
  //matrix.setTextColor(uint16_t color);
  //matrix.setTextColor(uint16_t color, uint16_t backgroundcolor);
  //matrix.setTextSize(uint8_t size);
  //matrix.setTextWrap(boolean w);
  
  //**** fill screen ****
  //matrix.fillScreen(uint16_t color);
  
  matrix.show(); // print the matrix and wait
  delay(rate);
}
