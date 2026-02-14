#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define NUM_PIXELS 8

Adafruit_NeoPixel strip(NUM_PIXELS, 2, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.setBrightness(255);

  // Simple rainbow across 8 pixels
  for (int i = 0; i < NUM_PIXELS; i++) {
    uint8_t hue = i * 256 / NUM_PIXELS;
    strip.setPixelColor(i, strip.ColorHSV(hue * 256, 255, 255));
  }
  strip.show();
  Serial.println("Ready.");
}

void loop() {
}
