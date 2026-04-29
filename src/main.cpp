/**
 * Pi Pico PIO driving a 4-digit seven segment display example.
 *
 * Copyright (C) 2021, Uri Shaked
 */

#include "segment.pio.h"

uint8_t digits[] = {
  0b11000000, // 0
  0b11111001, // 1
  0b10100100, // 2 
  0b10110000, // 3
  0b10011001, // 4
  0b10010010, // 5
  0b10000010, // 6
  0b11111000, // 7
  0b10000000, // 8
  0b10011000, // 9
};

const uint8_t first_segment_pin = 2;
const uint8_t first_digit_pin = 10;

void setup() {
  Serial1.begin(115200);
  Serial1.println("Raspberry Pi Pico PIO 7-Segment Example");

  // Load the PIO program and initialize the machine
  auto offset = pio_add_program(pio0, &segment_program);
  segment_program_init(pio0, 0, offset, first_segment_pin, first_digit_pin);
}

void displayNumber(uint value) {
  pio_sm_put(pio0, 0, 
    digits[value / 1000 % 10] << 24 |
    digits[value / 100 % 10] << 16 |
    digits[value / 10 % 10] << 8 |
    digits[value % 10]
  );
}

int i = 0;
void loop() {
  displayNumber(i++);
  delay(200);
}
