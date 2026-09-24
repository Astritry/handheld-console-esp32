# Research

This document collects what I learned while planning this project. My research didn't happen in a clean order, it came from an idea, then watching other people's projects, then microcontrollers, then slowly filling in the gaps. This is everything organized by topic instead of by the order I actually learned it.

## The idea

I'm a student at FH Erfurt studying Angewandte Informatik (Ingenieurinformatik). During semester break I wanted a project that combines both sides of my degree: building the hardware myself and writing the software (games) myself. I decided on a small handheld gaming device, starting with simple games like Snake and Pong, with the idea that I can keep adding more games over time. The case/housing is intentionally postponed until the electronics and code work.

## Choosing a microcontroller

I went with the ESP32 WROOM-32

I initially considered whether something simpler, like an Arduino Uno, could work instead.
Reasons why I chose the ESP32:

- RAM: the Uno only has 2KB of RAM. A 320x240 display has 76,800 pixels, and a full off-screen buffer (2 bytes per pixel, needed for smooth, flicker-free drawing) would need about 153KB, roughly 75x more RAM than the Uno has. The ESP32 has 520KB, enough to hold a full buffer with room left over.
- Speed: the Uno runs at 16MHz with no hardware floating-point. The ESP32 runs at 240MHz, dual-core, which matters once I'm handling game logic, collisions, sound, and screen updates at the same time.
- Flash storage: the Uno has only 32KB total for the whole program. The ESP32 gives 4MB+.
- The ESP32 also has built-in WiFi/Bluetooth, which I'm not using yet, but could be useful later (e.g. a two-player link).

So the Uno *can* technically drive a small display if you skip buffering and keep things very simple, but for multiple games with smooth movement, buttons, and sound together, it would have been the wrong tool.

## Choosing a display

I went with a 2.8" SPI TFT LCD, ILI9341 driver, 320x240 resolution, with touch (touch unused).

Things I learned while deciding:
- SPI vs. parallel: SPI displays only need a handful of GPIO pins (clock, data, chip-select, data/command, reset), which matters a lot since I also need pins free for 8 buttons, a buzzer, and a battery-voltage read. A parallel display would use far more pins.
- IPS vs. TN: I originally wanted an IPS panel for better color and viewing angles. The one I bought is actually a TN panel, which is cheaper and easier to find at this size, but has worse off-angle color shifting. I accepted this tradeoff for the first prototype.
- Resolution: I was worried 240x320 might be too small, but it's actually larger than the original Game Boy's 160x144 screen, so it's plenty for simple 2D games.
- Driver chip matters for code: the display uses the ILI9341 driver, which needs to be set correctly in the TFT_eSPI library's User_Setup.h file (I initially assumed ST7789, which is a different, similarly common driver — checking the actual chip name on the listing mattered).

## Buttons

I'm using a mix of 6x6mm and 12x12mm tactile push buttons.

- Buttons are wired between a GPIO pin and GND, using the microcontroller's internal INPUT_PULLUP mode. This means no external resistors are needed for basic button reading.
- 6x6mm caps were hard to find. A bare 6x6mm switch stem is only about 3.5mm wide, uncomfortable to press repeatedly, and cap listings are inconsistently named online (searched under "Tastkappe", "Tastknopf", "Kappe für Kurzhupttaster" in German, or just "6x6 tactile switch cap" in English). I didn't end up finding standalone caps.
- I bought a 12x12mm set that already includes caps, so I plan to use 12x12mm for buttons where a bigger, clickier press matters, and compare it against the bare 6x6mm switches.
- Reserved/avoided GPIO pins: GPIO 0, 2, 12 and 15 are involved in the ESP32's boot process (GPIO0 is tied to the BOOT button, GPIO2 often to the onboard LED, GPIO12 and 15 are read at startup). A button or component holding these pins at the wrong level during power-on can prevent the board from booting or flashing correctly. I avoided all four when planning my pin layout.
- GPIO 34-39 are input-only (no internal pull-up available), so they're not suitable for simple buttons without external pull-up resistors, but they work well for analog reads like the battery voltage divider.

## Power and battery (the hardest part for me to understand)

This was the most confusing part of the whole project, and took the most research to get right, since the USB-C port only powers/programs the board, it does not charge or manage a battery.

- The battery (3.7V LiPo/Li-ion cell) stores energy, ranges from about 4.2V (full) to 3.0V (empty), and can't charge itself.
- A charging module takes 5V over USB-C and charges the cell safely, stopping at 4.2V so it doesn't overcharge (lithium cells can be a fire risk if overcharged).
- A boost converter, since the battery's 3.0-4.2V is lower than the 5V the ESP32 needs on its `5V`/`VIN` pin, the boost converter steps the voltage up.

Why a boost converter specifically, and not a buck converter: the direction of conversion depends on whether your source voltage is above or below your target.
- Source lower than target (my case: 3.7V battery → 5V needed) → **boost** (step-up) converter.
- Source higher than target (e.g. two cells in series, 7.4V → 5V needed) → **buck** (step-down) converter.
- If the source voltage range straddles the target the whole time, you'd need a buck-boost converter that can do both, but that's not my situation.

*Two ways to build this power chain, which I researched and compared:*
1. Separate parts: a TP4056 charging module (with protection chip) + a separate MT3608 boost converter, wired together with a manual slide switch.
2. All-in-one module (IP5306-based): combines charging and boosting on one board, has a fixed 5V output (no trimmer, no risk of wrong voltage), supports "power path" (can run the device and charge the battery at the same time), and has a built-in power button pin (`K`). I chose this option for the final build, since it's simpler and safer, even though it teaches less about each individual stage.

*Why the battery needs its own protection circuit, even though the charging module also has protection:* 
- The charging module's protection watches the *charging process* (stops at 4.2V, cuts output on over-discharge during use).
- The battery's own built-in protection circuit watches the *cell itself* directly (overcurrent, short circuits, overheating), independently of whatever is plugged into it.
- This is apparently intentional redundancy, similar to a car having both a fuse and a circuit breaker, standard practice for anything lithium-based, since a bare unprotected cell is a real fire/safety risk if shorted or damaged.

*Battery capacity*
- Add up the current draw of all components: ESP32 active (~150-200mA), display + backlight (~50-100mA), buzzer (negligible).
- Estimated total draw: roughly 250-350mA.
- Runtime = capacity ÷ draw. So a 2600mAh battery ÷ ~300mA ≈ 8-9 hours in theory, though real-world runtime is usually lower (batteries rarely deliver their full rated capacity, and the boost converter itself wastes some power as heat).
- I estimated around 3-5 hours.

*A power habit to avoid:*
- running the device while it's charging isn't dangerous with a proper charger, but with a simple TP4056-style charger (no power path), it confuses the "battery full" detection, since the chip decides "full" based on charge current dropping to ~100mA, and a running device keeps drawing current past that point.
- This can mean the battery never actually reaches "done" charging, and the chip runs warmer for longer. The IP5306-style module avoids this problem entirely via power path.

## Tools

Already familiar with these from my apprenticeship, research needed here.
- Soldering iron
- Board holder
- Multimeter

## Tools and platform for coding

- VS Code + PlatformIO (a VS Code extension that adds microcontroller support: compiling, uploading, board management).
- TFT_eSPI library for driving the display, configured for the ILI9341 driver and my specific pin layout in `User_Setup.h`.
- Considered JetBrains CLion (free via GitHub Student Pack) but skipped it, since PlatformIO in VS Code is simpler and more commonly used for this kind of project.

## Case planning

Decided to postpone the case entirely until the electronics and code are working and I've physically measured every part (with a caliper). Planned approach:
1. Measure all real parts once they arrive.
2. Sketch the layout (Game Boy-style: screen center, D-pad left, A/B right, Start/Select below).
3. Model it in CAD (considering Tinkercad, FreeCAD, or Fusion 360).
4. Produce it via 3D printing.

*This research file is written by me and checked with DeepL for language.*
