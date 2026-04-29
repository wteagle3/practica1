# Firmware Architecture

## Overview

The firmware is a compact Arduino-style application for RP2040/Pico W that delegates display timing/output to a PIO program.

## File/Module Breakdown

- `src/main.cpp`
  - Contains lookup table (`digits[]`) for numeral encoding.
  - Defines base pin constants:
    - `first_segment_pin = 2`
    - `first_digit_pin = 10`
  - Initializes serial and PIO program in `setup()`.
  - Packs 4 digits into a 32-bit word in `displayNumber(uint value)`.
  - Runs a monotonic counter in `loop()` with 200 ms delay.

- `segment.pio.h` (referenced)
  - Expected to expose:
    - `segment_program`
    - `segment_program_init(...)`
  - Normally generated from a `.pio` source by `pioasm` or supplied by framework examples.

## Runtime Flow

1. Boot enters `setup()`.
2. UART starts at 115200 and prints a banner.
3. PIO program is loaded (`pio_add_program`).
4. State machine initialized (`segment_program_init`).
5. `loop()` repeatedly:
   - writes packed segment data for current count
   - increments count
   - waits 200 ms

## Data Path

`int i` -> `displayNumber(i)` -> digit extraction (`/1000`, `/100`, `/10`, `%10`) -> `digits[]` lookup -> pack to 32-bit -> `pio_sm_put()`.

## Behavior Preservation

No algorithmic or logic changes were introduced. Repository updates are documentation and structure-focused.
