#include <Arduino.h>
#include <TFT_eSPI.h> // from the library for the display

// put function declarations here:
int myFunction(int, int);

TFT_eSPI tft = TFT_eSPI();

void setup() {

  pinMode(19, OUTPUT);

  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(4);
  tft.setCursor(50, 100);
  tft.setTextFont(1);
  tft.println("Salut!");
  
  pinMode(19, OUTPUT);
  digitalWrite(19, HIGH); // Backlight on
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}