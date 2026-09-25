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