#include <Arduino.h>
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println(F("HX711 test!"));

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  // Set scale factor (calibration value)
  // For the 5kg load cell simulation, raw values range from 0-2100
  scale.set_scale(420.0); // This gives us readings in a 0-5 range for 0-2100 raw

  // Tare the scale to zero
  scale.tare();

  Serial.println(F("HX711 initialized and tared"));
}

void loop() {
  delay(500);

  if (scale.is_ready()) {
    long rawValue = scale.get_value();
    float weight = scale.get_units();

    Serial.print(F("Raw: "));
    Serial.print(rawValue);
    Serial.print(F(" Weight: "));
    Serial.print(weight, 2);
    Serial.println(F(" units"));
  } else {
    Serial.println(F("HX711 not ready"));
  }
}
