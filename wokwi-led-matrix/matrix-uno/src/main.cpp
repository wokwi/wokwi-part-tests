#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define ROWS 8
#define COLS 8
#define NUM_PIXELS (ROWS * COLS)

Adafruit_NeoPixel matrix(NUM_PIXELS, 2, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  matrix.begin();
  matrix.setBrightness(255);

  // Checkerboard pattern: red and blue
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      int i = row * COLS + col;
      if ((row + col) % 2 == 0) {
        matrix.setPixelColor(i, matrix.Color(255, 0, 0));
      } else {
        matrix.setPixelColor(i, matrix.Color(0, 0, 255));
      }
    }
  }
  matrix.show();
  Serial.println("Ready.");
}

void loop() {
}
