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