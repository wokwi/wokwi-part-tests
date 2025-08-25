#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIXEL_COUNT 24

Adafruit_NeoPixel ring = Adafruit_NeoPixel(24, 2);

int32_t Wheel(byte WheelPos);

void setup() {
  Serial.begin(115200);
  ring.begin();
  ring.setBrightness(255);

  for (uint16_t j = 0; j < 256 * 5; j++) {
    for (uint16_t i = 0; i < ring.numPixels(); i++) {
      ring.setPixelColor(i, Wheel(((i * 256 / ring.numPixels()) + j) & 255));
    }
  }

  ring.show();
  Serial.println("LEDs ready.");
}

void loop() {
}

int32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return ring.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return ring.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return ring.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
