# Coding in VS Code

## Display test

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
```