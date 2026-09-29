#include <Arduino.h>
#include <TFT_eSPI.h> // loads the screen library

// put function declarations here:
int myFunction(int, int);

TFT_eSPI tft = TFT_eSPI(); // creates the screen object
const int BTN_PIN_1 = 14; // the button is wired to GPIO14
const int BTN_PIN_2 = 27;
const int BTN_PIN_3 = 26;
const int BTN_PIN_4 = 25;
const int BTN_PIN_Down = 33;
const int BTN_PIN_Right = 32;
const int BTN_PIN_Up = 13;
const int BTN_PIN_Left = 21;

void setup() {

  // setup for the screen
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(4);
  tft.setCursor(90, 50);
  tft.setTextFont(1);
  tft.println("Salut!");
  
  // screen stays on
  pinMode(19, OUTPUT);
  digitalWrite(19, HIGH); 

  // Buttons
  pinMode(BTN_PIN_1, INPUT_PULLUP); //set the pin as an input, with the internal pull-up on
  pinMode(BTN_PIN_2, INPUT_PULLUP);
  pinMode(BTN_PIN_3, INPUT_PULLUP);
  pinMode(BTN_PIN_4, INPUT_PULLUP);
  pinMode(BTN_PIN_Down, INPUT_PULLUP);
  pinMode(BTN_PIN_Right, INPUT_PULLUP);
  pinMode(BTN_PIN_Up, INPUT_PULLUP);
  pinMode(BTN_PIN_Left, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Button 1
  if (digitalRead(BTN_PIN_1) == LOW) {       // LOW means the button is pressed
    tft.fillCircle(240, 195, 10, TFT_BLUE);   // draws a blue Circle: x, y, radius, color
  }
  else {
    tft.fillCircle(240, 195, 10, TFT_BLACK); // erase the circle when the buttons is released (by turning it the same color as the backround)
  }

    //Button 2
  if (digitalRead(BTN_PIN_2) == LOW) {
    tft.fillCircle(260, 170, 10, TFT_RED);
  }
  else {
    tft.fillCircle(260, 170, 10, TFT_BLACK);
  }

      //Button 3
  if (digitalRead(BTN_PIN_3) == LOW) {
    tft.fillCircle(240, 145, 10, TFT_GREEN);
  }
  else {
    tft.fillCircle(240, 145, 10, TFT_BLACK);
  }

        //Button 4
  if (digitalRead(BTN_PIN_4) == LOW) {
    tft.fillCircle(220, 170, 10, TFT_YELLOW);
  }
  else {
    tft.fillCircle(220, 170, 10, TFT_BLACK);
  }
      //Button Down
  if (digitalRead(BTN_PIN_Down) == LOW) {
  tft.fillTriangle(60, 180, 80, 180, 70, 200, TFT_WHITE);  // draw arrow
} else {
  tft.fillTriangle(60, 180, 80, 180, 70, 200, TFT_BLACK);  // erase it (same shape, background color)
}

      //Button Right
  if (digitalRead(BTN_PIN_Right) == LOW) {
  tft.fillTriangle(85, 175, 85, 155, 105, 165, TFT_WHITE);  // draw arrow
} else {
  tft.fillTriangle(85, 175, 85, 155, 105, 165, TFT_BLACK);  // erase it (same shape, background color)
}

      //Button Up
  if (digitalRead(BTN_PIN_Up) == LOW) {
  tft.fillTriangle(60, 150, 80, 150, 70, 130, TFT_WHITE);  // draw arrow
} else {
  tft.fillTriangle(60, 150, 80, 150, 70, 130, TFT_BLACK);  // erase it (same shape, background color)
}

      //Button Left
  if (digitalRead(BTN_PIN_Left) == LOW) {
  tft.fillTriangle(55, 175, 55, 155, 35, 165, TFT_WHITE);  // draw arrow
} else {
  tft.fillTriangle(55, 175, 55, 155, 35, 165, TFT_BLACK);  // erase it (same shape, background color)
}

  delay(10);   // small pause so the screen isn't redrawn nonstop (reduce flicker)
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}