## 24-09-2026

- Confirmed USB-C cable supports data transfer (blue LED lit on connect)
- Wired ESP32 +/- to breadboard, then breadboard +/- to display (+ from 3v3)
- Installed PlatformIO extension in VS Code
- Created project `handheld-console` in repo folder, board: Espressif ESP32 Dev Module
- It Generated a folder with some files, among them:
  `platformio.ini` (board settings)
   and `src/main.cpp` (code)
- Device Manager showed unrecognized device → installed Silicon Labs CP210x driver
- Researched ESP32 pinout and ILI9341 2.8" SPI display pinout
See [ESP32 pinout PDF](ESP32-instructions.pdf) 
See [Display datasheet](2.8inch_SPI_Module_MSP2807_User_Manual_EN.pdf)
- Wired ESP32 to screen
See [Pin map](pin-map.md)
- Wrote first test code: turns on display backlight

## 29-09-2026

- Added the library TFT_eSPI to platfromio.ini
(Save the file. PlatformIO downloads the library automatically the next build)
- TFT_eSPI doesn't auto-detect the pins — it needs a setup with
    - Which display driver you have (ILI9341)
    - Which GPIOs are wired for CS, DC, RESET, SDI, SCK
- Configured TFT_eSPI for my wiring in platform.io
- Deleted the test code for the backlight
- Added new code for testing some display funktions
- Issues encountered:
    1. Backlight (pin 19) not turning on
    **Cause:** tft.init() also configures TFT_BL (pin 19) internally, since it's defined in build_flags. Calling pinMode digitalWrite for pin 19 BEFORE tft.init() gets overridden — tft.init() resets it after.
    **Fix:** Moved `pinMode(19, OUTPUT); digitalWrite(19, HIGH);` to AFTER the rest of the draw calls, so it runs last and isn't overridden.

    2. Text not showing (screen color worked, text didn't)
    **Cause:** No font loaded — TFT_eSPI needs at least one `LOAD_FONTx` defined, or text silently fails to appear-
    **Fix:** Added `-DLOAD_GLCD=1` to `build_flags` in platformio.ini.

- Wired buttons to my setup (GND to one side - GPIO another side)
- Programing and testing buttons
- Issues encountered:
1. Two buttons where not working on press
    **Cause:**GPIO 34/35 are input-only, no internal pull-up, so they float
    **Fix** Moved from GPIO35 to GPIO13. Moved from GPIO43 to GPIO21