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