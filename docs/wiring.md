# Wiring and GPIO Usage (Raspberry Pi Pico W)

## Summary

The design connects a 4-digit seven-segment display directly to GPIO pins using one pin per segment line and one pin per digit-select line.

- Segment lines start at **GP2** (`first_segment_pin = 2`)
- Digit select lines start at **GP10** (`first_digit_pin = 10`)

## Pin Mapping Table

| Pico W GPIO | Display Signal | Role |
|---|---|---|
| GP2 | A | Segment A |
| GP3 | B | Segment B |
| GP4 | C | Segment C |
| GP5 | D | Segment D |
| GP6 | E | Segment E |
| GP7 | F | Segment F |
| GP8 | G | Segment G |
| GP9 | DP | Decimal Point |
| GP10 | DIG1 | Digit enable (left/right per module orientation) |
| GP11 | DIG2 | Digit enable |
| GP12 | DIG3 | Digit enable |
| GP13 | DIG4 | Digit enable |

## UART / Debug

| Pico W GPIO | Endpoint | Purpose |
|---|---|---|
| GP0 | Serial Monitor RX | UART TX from Pico |
| GP1 | Serial Monitor TX | UART RX to Pico |

## Assumptions and Notes

1. The wiring is derived from the provided Wokwi `diagram.json`.
2. Exact physical pin numbers on the 40-pin header depend on board orientation; always map by **GPIO name** (GPx).
3. Segment polarity depends on display type and the `digits[]` encoding table in firmware.
