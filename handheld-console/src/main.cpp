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

// for the buzzer
const int BUZZER_PIN = 22; //defines the buzzer pin
const int BUZZER_CHANNEL = 0; // any free LEDC channel

unsigned long lastButtonCheck = 0; // last checked buttons
const int buttonCheckInterval = 10;// how often to check buttons (ms) - replaces old delay(10) for butons

unsigned long buzzerStartTime = 0; // when the current tone started playing
bool buzzerPlaying = false;        // is a tone currently sounding?
const int buzzerDuration = 200;    // how long a tone should last (ms)

  // ===== FUNCTION: start playing a tone, without blocking =====
void playTone(int frequency) {
  ledcWriteTone(BUZZER_CHANNEL, frequency); // start the tone immediately
  buzzerStartTime = millis();               // remember the exact moment it started
  buzzerPlaying = true;                     // mark that a tone is currently active
  }

void setup() {

  Serial.begin(115200);

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

  // Buzzer
  ledcSetup(BUZZER_CHANNEL, 2000, 8); // channel, initial frequency (Hz), resolution (bits)
  ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL); // attach the buzzer pin to that channel

}

void loop() {
  // put your main code here, to run repeatedly:

  //Button 1
  if (digitalRead(BTN_PIN_1) == LOW) {       // LOW means the button is pressed
    tft.fillCircle(240, 195, 10, TFT_BLUE);   // draws a blue Circle: x, y, radius, color
    if (!buzzerPlaying) {                    // only trigger a new tone if one isn't already playing
      playTone(1000);
    }
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

      //Buzzer
      if (buzzerPlaying && (millis() - buzzerStartTime >= buzzerDuration)) {
    ledcWriteTone(BUZZER_CHANNEL, 0); // stop the sound
    buzzerPlaying = false;            // mark that nothing is playing anymore
  }
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}