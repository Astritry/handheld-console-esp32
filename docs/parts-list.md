# Parts list

Here is a list of every part that I bought specifically for this project.

Many of these parts were bought in bulk, leaving me with plenty of spares for future projects.
Buying in bulk was often cheaper per unit than buying single pieces.

I already had some of the tools required for this project from my apprenticeship, but I also bought additional tools which are not listed here.

All of the parts listed here were bought from Amazon on 23/09/2026 (prices may change over time).

## Battery

*Price and Listing Name*
 - 13.99€
 - XINLANTECH 3.7 V 2600 mAh rechargeable Li-ion battery with XH2.54 mm/2P connector for Croove voice amplifier, 9.62 Wh, B0143KH9KG.

 *Description and Reasoning*
 - I chose a pre-built cell to keep this project beginner-friendly. This 2600 mAh battery comes with a protection circuit against overcharging and short circuits, which is necessary since it feeds directly into the charging module and should provide around 3–5 hours of playtime.
 - The battery (3.0–4.2 V) goes to the IP5306 module (which boosts to 5 V) and then to the ESP32's 5 V/VIN pin.

## Resistor Kit

*Price and Listing Name*
 - 10.99€
 - BOJACK Resistors Assortment Kit 1 Ohm - 1M Ohm 1/4W Carbon Film Resistor Kit (25 Values 1000 Pieces)

 *Description and Reasoning*
 - For this build, I only need two 100 kΩ resistors wired as a voltage divider, so that the ESP32 can safely read the battery's voltage on an analogue-to-digital converter (ADC) pin.
 - The pin can only handle up to 3.3 V, while the battery reaches 4.2 V; therefore, the divider halves the voltage.

## Power Supply Module

*Price and Listing Name*
 - 5.96€
 - 5V 2A Type-C USB Boost Step-Up Power Supply Module High Precision Lithium Battery Charging Protection Converter Boost Integrated Discharge Module (Pack of 3)

 *Description and Reasoning*
 - It combines a lithium battery charger and a boost converter on one small board. It draws 5V from a USB-C cable to charge the 3.7V battery and boosts the battery's 3.0–4.2 V output to a steady 5 V for the ESP32 separately.
 - I chose the all-in-one module over building the charger and booster as two separate parts (TP4056 + MT3608) because it supports 'power path' (charging and running the device simultaneously) and has a built-in power button (K pin), eliminating the need for a separate physical switch.

## Display

*Price and Listing Name*
 - 13.99€
 - 2.8 Inch LCD TFT Touch Display Binghe 2.8 Inch SPI LCD Display Touch Module with Touch Pen 320 x 240 Resolution Driver ILI9341 4-Wire SPI Compatible with Arduino

 *Description and Reasoning*
 - Shows the game graphics. Uses the SPI interface, which needs only a handful of pins on the ESP32, an important factor since I have limited GPIOs available for buttons too.
 -  I originally wanted an IPS panel for better colour and viewing angles, but this ILI9341 model is a TN panel instead, cheaper and easier to find at this size, though colours shift more when viewed off-angle. I accepted this tradeoff for the first prototype and may revisit it for a later revision.
 - The touch function is unused in this project, since I'm controlling the console with physical buttons, but it didn't add cost over a non-touch version.

## 6x6 mm Push Buttons

*Price and Listing Name*
 - 5.98€
 - VooGenzek 100 Pieces 10 Values 6 x 6 mm Micro Momentary Tactile Push Button Switch, Button Micro Tactile Switch Kit, Black

 *Description and Reasoning*
 - Small tactile switches used for the D-pad, Start and Select. I wanted to try both 6x6mm and 12x12mm sizes to compare feel and ease of soldering, since this was my first time working with either.
 - If I go with 12x12mm, useful as a spare set for a reset button or other small inputs later.

## 12x12 mm Push Buttons

*Price and Listing Name*
 - 7.99€
 - YIXISI 120 Pieces (12 x 12 x 7.3 mm) Pieces Tactile Push Button Switch, Micro Momentary Push Button Switch, 4 Pin Micro Switch, with Cap for Arduino

 *Description and Reasoning*
 - Larger tactile switches, planned for buttons where a bigger, clickier press feels better.
 - Also chosen to compare against the 6x6mm size directly on the same board, since this is my first time choosing buttons for a project.

## Piezo Buzzer

*Price and Listing Name*
 - 4.99€
 - Gerui 4 x KY-006 Passive Piezo Buzzer Alarm Module Compatible With Arduino and Raspberry Pi

 *Description and Reasoning*
 - A passive buzzer for basic sound feedback, since it adds another output type to work with beyond the screen.
 - Planned uses include a startup jingle, a game-over or "death" sound, and a low-battery warning beep.

## Breadboard Kit

*Price and Listing Name*
 - 12.99€
 - Breadboard Kit, 3 x 830 Points, Dupont Cable Jumper Wire for Arduino 3 x 830 point pegboards, solderless, 185 pieces. Separable Colour Coded PVC Insulated Cable for Arduino & ESP32

 *Description and Reasoning*
- For prototyping and testing circuits before soldering anything permanently.

## Cable Set

*Price and Listing Name*
 - 10.99€
 - 26AWG 0.13 mm² Silicone Cable Set, 6 Colours, 6 m Each Colour Flexible tinned copper wire for electronics, PCB, DIY circuits, LED and signal lines

 *Description and Reasoning*
 - For the permanent wiring.
 - Chosen over solid-core wire for its flexibility.

## ESP32 Module

*Price and Listing Name*
 - 19.98€
 - 3 x 38-pin USB C ESP32 NodeMCU WiFi Bluetooth Module ESP32 WROOM 32 Development Board with CP2102 Compatible with Arduino Type C Interface

 *Description and Reasoning*
 - The microcontroller that runs the game code and drives the display. 
 - Wide community support/documentation.
 - I chose it over an Arduino Uno for its far higher clock speed and RAM, both needed to redraw a 320x240 screen smoothly.

## PCB Board Kit

*Price and Listing Name*
 - 10.98€
 - VooGenzek Pack of 46 PCB Board Kits, 12 Pieces Double-Sided PCB Prototype Cards + 12 Pieces Male/Female Header Connector + 10 Pieces 2/3 Pin Screw Clamp + 12 Pieces Nylon Column.

 *Description and Reasoning*
 - Double-sided prototype boards used to solder all the components together permanently.

Total: 118.83€

Console-only estimate: ~43.14€*

*This parts list is written by me and checked with DeepL for language.*