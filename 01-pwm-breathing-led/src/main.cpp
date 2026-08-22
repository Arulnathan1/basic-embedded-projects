#include <Arduino.h>

const int LED_PIN = 9;      // to output to LED 
const int BUTTON_PIN = 2;   // toggle button to turn on/off the circuit
const int POT_PIN = A0;     // to control PWM for brightness 

bool running = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // reads LOW when clicked
  Serial.begin(9600);
}

void loop() {
  // --- Button toggle with debounce ---
  bool buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == LOW && lastButtonState == HIGH) {
    running = !running;
    delay(50); // debounce
  }
  lastButtonState = buttonState;

  // --- LED control ---
  if (running) {
    int potValue = analogRead(POT_PIN);       // 0–1023
    int brightness = map(potValue, 0, 1023, 0, 255); // scale to PWM range
    analogWrite(LED_PIN, brightness);
  } else {
    analogWrite(LED_PIN, 0); // off when paused
  }

  delay(10); // small loop delay for stability
}