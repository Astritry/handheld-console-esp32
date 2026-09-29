# Pin Map

## Power

| ESP32 | Connects to | Notes |
|-----|-------------|-------|
| GND | Breadboard GND rail | shared ground |
| 3V3 | Breadboard + rail | strip for 3.3V |

## Display (ILI9341, SPI)

| ESP32 Pin | Display Pin | Function |
|-----------|-------------|----------|
| 3V3 (through Breadboard) | VCC | Power |
| GND (through Breadboard) | GND | Ground |
| GPIO16 | CS | Chip select |
| GPIO4  | RESET | Reset |
| GPIO17 | DC | Data/command |
| GPIO23 | SDI (MOSI) | SPI data |
| GPIO18 | SCK | SPI clock |
| GPIO19 | LED | Backlight |

## Butons

| 1st Side | 2nd Side | Function |
|-------|--------------------------|-------------|
|GPIO14 | GND (through Breadboard) | Button 1 |
|GPIO27 | GND (through Breadboard) | Button 2 |
|GPIO26 | GND (through Breadboard) | Button 3 |
|GPIO25 | GND (through Breadboard) | Button 4 |
|GPIO33 | GND (through Breadboard) | Button Down |
|GPIO32 | GND (through Breadboard) | Button Right |
|GPIO13 | GND (through Breadboard) | Button Up |
|GPIO21 | GND (through Breadboard) | Button Left |

## Buzzer KY-006

| Connects to  | Label | Function |
|-------|--------------------------|-------------|
| GPIO22 | S | Signal - drive with a square wave (tone())|
|   | middle | Not connected |
| GND | - | Ground|