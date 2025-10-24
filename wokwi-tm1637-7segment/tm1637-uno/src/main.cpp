#include <Arduino.h>
#include "TM1637.h"

// TM1637 pins
const int CLK_PIN = 4;
const int DIO_PIN = 5;

TM1637 display;

void setup() {
  Serial.begin(9600);
  Serial.println(F("TM1637 test!"));

  display.begin(CLK_PIN, DIO_PIN, 4);
  display.setBrightness(5);  // Set brightness (0-7)

  Serial.println(F("Display initialized"));
}

void loop() {
  // Display "0000"
  display.displayInt(0);
  Serial.println(F("Displaying: 0000"));
  delay(1000);

  // Display "1234"
  display.displayInt(1234);
  Serial.println(F("Displaying: 1234"));
  delay(1000);

  // Display "4567"
  display.displayInt(4567);
  Serial.println(F("Displaying: 4567"));
  delay(1000);

  // Display "8888" (all segments on)
  display.displayInt(8888);
  Serial.println(F("Displaying: 8888"));
  delay(1000);

  // Display "13:37" (colon)
  display.displayTime(13, 37, true);
  Serial.println(F("Displaying: 13:37"));
  delay(1000);

  // Display with leading zeros cleared "-42"
  display.displayClear();
  display.displayInt(-42, true);
  Serial.println(F("Displaying: -42"));
  delay(1000);
}
