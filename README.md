# Raspberry Pi Pico W - PIO 4-Digit 7-Segment Counter

Professionalized project layout and documentation for a Raspberry Pi Pico W firmware that drives a 4-digit 7-segment display using PIO.

## Project Overview

This firmware continuously increments a counter and displays it on a 4-digit seven-segment module. The implementation uses:

- **RP2040 PIO** to shift segment/digit data efficiently
- **Arduino-style entry points** (`setup()`/`loop()`)
- **Serial1 @ 115200** for startup log output

> Core behavior and logic are preserved from the provided source.

## Repository Structure

- `src/main.cpp`: Main firmware source (unchanged logic)
- `include/`: Reserved for headers (such as generated PIO headers)
- `docs/wiring.md`: Wiring and GPIO mapping documentation
- `docs/architecture.md`: Firmware architecture and module-level explanation
- `diagram.json`: Wokwi hardware diagram
- `CMakeLists.txt`: Documentation-oriented CMake scaffold for C/C++ repo consistency

## Features

- Displays an incrementing integer on 4 digits (0000 -> 9999 and wraps)
- Uses a lookup table for seven-segment encoding (`digits[]`)
- PIO state machine output for segment multiplexing

## Components List

Derived from `diagram.json`:

1. Raspberry Pi Pico / Pico W compatible target (`wokwi-pi-pico`)
2. 4-digit seven-segment display (`wokwi-7segment`, `digits=4`)
3. Serial monitor connection (virtual in Wokwi)

## GPIO Mapping (Pico W)

| Function | 7-Segment Pin | Pico W GPIO |
|---|---|---|
| UART TX to monitor | RX (monitor) | GP0 |
| UART RX from monitor | TX (monitor) | GP1 |
| Segment A | A | GP2 |
| Segment B | B | GP3 |
| Segment C | C | GP4 |
| Segment D | D | GP5 |
| Segment E | E | GP6 |
| Segment F | F | GP7 |
| Segment G | G | GP8 |
| Decimal Point | DP | GP9 |
| Digit Select 1 | DIG1 | GP10 |
| Digit Select 2 | DIG2 | GP11 |
| Digit Select 3 | DIG3 | GP12 |
| Digit Select 4 | DIG4 | GP13 |

See full connection notes in `docs/wiring.md`.

## Run in Wokwi

1. Create/import project in Wokwi.
2. Place `src/main.cpp` as sketch source.
3. Use provided `diagram.json` as the project diagram.
4. Select **Arduino Community Edition** environment for Pico.
5. Start simulation and open Serial Monitor (115200 baud).

## Run on Real Hardware (Pico W)

1. Wire the 4-digit seven-segment module to **GP2..GP13** exactly as documented.
2. Build/upload with an Arduino-compatible RP2040 core that supports PIO helpers used by `segment.pio.h`.
3. Open serial output at 115200 to verify startup message.

### Notes for real hardware

- Ensure display type (common anode/cathode) matches the segment encoding table.
- Add current-limiting resistors if your specific display module requires them.
- If your toolchain requires explicit PIO header generation, provide `segment.pio` and generate `segment.pio.h` before compile.

## Wi-Fi Credentials

This project does **not** use Wi-Fi APIs. No credentials are required or stored.

## Non-Behavioral Normalization Performed

- Standardized repository layout (`src/`, `docs/`, `include/`)
- Added structured technical documentation
- Preserved firmware logic exactly
