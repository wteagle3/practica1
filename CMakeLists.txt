cmake_minimum_required(VERSION 3.13)
project(pico_w_7segment_pio C CXX ASM)

# Pico SDK-based structure placeholder for teams that build outside Arduino IDE.
# The provided firmware is Arduino-style (setup/loop) and intended for
# arduino-community workflows (e.g., Wokwi/Arduino IDE).

add_custom_target(${PROJECT_NAME}_docs ALL
  COMMENT "Documentation-only target. Build firmware via Arduino tooling."
)
