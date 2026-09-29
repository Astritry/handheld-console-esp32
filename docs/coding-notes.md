# Coding in VS Code

## Backlight Display Test

Program to turn the screen's backlight on right after wiring, to check the screen works.

**platformio.ini** (added `monitor_speed = 115200`, rest was default):
```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
```

**main.cpp**, inside `void setup()`:
```cpp
Serial.begin(115200); //starts communication between the ESP32 and your laptop over USB, at a speed of 115200 baud.
pinMode(19, OUTPUT); // tells the ESP32 that GPIO19 will be used to send voltage out (as opposed to INPUT, reading voltage)
digitalWrite(19, HIGH);   // sets GPIO19 to 3.3V. Since backlight wire is on pin 19, this turns the backlight on. LOW would set it to 0V (off).
Serial.println("Backlight on, pin 19 is HIGH") //prints that text to the Serial Monitor, purely so you can confirm on your laptop screen that this line of code actually ran. It has no effect on the hardware.
```

## Library TFT_eSPI

Added the library to **platformio.ini**
```ini
lib_deps = bodmer/TFT_eSPI@^2.5.43
```
Configured TFT_eSPI for my wiring in **platform.io**
```ini
; setup pins for the display
build_flags =
    -DUSER_SETUP_LOADED=1 ; this is on (1=true) so that my following setup will be used
    -DILI9341_DRIVER=1 ; this loads the correct driver for my chip
    -DTFT_MISO=-1 ; Define (D) constant called TFT_Master In, Slave Out (-1 for not used since i do not use touch function)
    -DTFT_MOSI=23 ; Master Out, Slave In
    -DTFT_SCLK=18 ; Serial Clock
    -DTFT_CS=16 ; Chip Select
    -DTFT_DC=17 ; Data Command
    -DTFT_RST=4 ; Reset
    -DTFT_BL=19 ; Back Light
    -DSPI_FREQUENCY=40000000 ;40 MHz (for the SPI clock) (safe starting value)
    -DTFT_WIDTH=240 ; width resolution (shorter side)
    -DTFT_HEIGHT=320 ; height resolution (longer side)
    -DLOAD_GLCD=1 ; need fonts for display text to work
```
## Display Test
Code for testing some of the display functions

**main.cpp**, to includes:
```cpp
#include <TFT_eSPI.h> // from the library for the display
```

**main.cpp**, declaration after includes:
```cpp
TFT_eSPI tft = TFT_eSPI();
```
- This creates an object named tft from the TFT_eSPI class (a class is like a blueprint; an object is one actual instance made from it). Everything done to the screen (clearing it, drawing text) goes through this tft object, using the pins defined in build_flags (TFT_CS, TFT_DC, etc.). This line runs once, before setup(), at the point your program starts up.

**main.cpp**, inside `void setup()`:
```cpp
  tft.init(); // Initializes the display (othing will work before this runs).
  tft.setRotation(0); // Sets the screen orientation. Values are 0–3, each rotating the display 90° further.
  tft.fillScreen(TFT_BLACK); // Fills the entire screen with a solid color
  tft.setTextColor(TFT_WHITE); // Sets what color any text drawn after this line will be.
  tft.setTextSize(4); //Sets a text size multiplier (1 is the smallest).
  tft.setCursor(50, 100); // Sets where the next text will appear, as (x, y) pixel coordinates from the top-left corner of the screen. (10, 10) means 10 pixels right, 10 pixels down.
  tft.setTextFont(1); //not needed if there is one font loaded in .ini (the numnber indicates the order of the loaded fonts).
  tft.println("Salut!"); //displays the text

  pinMode(19, OUTPUT); //sets the 19 as an output (to only SEND voltage).
  digitalWrite(19, HIGH); // Backlight on(set voltage to 3.3V).
```