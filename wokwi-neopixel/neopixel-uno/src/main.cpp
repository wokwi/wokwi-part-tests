#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixel(1, 2, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  pixel.begin();
  pixel.setBrightness(255);
  pixel.setPixelColor(0, pixel.Color(0, 0, 255));
  pixel.show();
  Serial.println("Ready.");
}

void loop() {
}
