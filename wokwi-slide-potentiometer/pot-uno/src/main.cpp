#include <Arduino.h>

const int POT_PIN = A0;  // Slide potentiometer connected to A0

void setup() {
  Serial.begin(115200);
  pinMode(POT_PIN, INPUT);
}

void loop() {
  int potValue = analogRead(POT_PIN);
  Serial.print("Potentiometer value: ");
  Serial.println(potValue);
  delay(100);  // Small delay to prevent flooding the serial output
}
