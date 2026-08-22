# PWM Breathing LED with Potentiometer & Button Control

A PWM-based LED project that fades smoothly ("breathes") in and out, 
with a potentiometer controlling brightness and a push button toggling 
the effect on/off. Built with PlatformIO on an Arduino Uno.

## Demo

![Circuit photo](media/photo.jpg)

## Hardware
- Arduino Uno
- 1x LED
- 1x 220Ω resistor
- 1x push button (4-pin tactile)
- 1x 10kΩ potentiometer
- Breadboard + jumper wires

## Wiring
- LED anode → 220Ω resistor → Pin 9 (PWM)
- LED cathode → GND
- Button: one leg → Pin 2, opposite-side leg → GND (uses internal pull-up)
- Potentiometer: outer legs → 5V and GND, wiper (middle leg) → A0

## Controls
- **Button** — toggles the breathing effect on/off
- **Potentiometer** — adjusts brightness while active

## How it works
`analogRead()` on the potentiometer pin returns a value from 0–1023, 
which is remapped to PWM's 0–255 range and written to the LED pin with 
`analogWrite()`. The button flips a `running` flag using edge detection 
with basic debounce, so a single press toggles state rather than requiring 
the button to be held.

## Build & Upload
\`\`\`bash
pio run --target upload
\`\`\`

## What I learned
- PWM signal generation and duty cycle control
- Reading analog input from a potentiometer
- Debouncing a mechanical button in software
- Debugging with isolation tests (bare-bones code to separate hardware vs logic issues)
