#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>

#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
Adafruit_FT6206 ts = Adafruit_FT6206();

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  if (!ts.begin(40)) {
    Serial.println("FT6206 not found");
    while (1);
  }
  Serial.println("Touch ready");
}

void loop() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    Serial.printf("Touch: %d %d\r\n", p.x, p.y);
    // Flip to display coordinates for drawing
    int dx = map(p.x, 0, 240, 240, 0);
    int dy = map(p.y, 0, 320, 320, 0);
    tft.fillCircle(dx, dy, 3, ILI9341_PURPLE);
    delay(100);
  }
  delay(10);
}
