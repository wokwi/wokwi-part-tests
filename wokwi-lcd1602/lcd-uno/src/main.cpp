#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.print("Hello Wokwi!");
  Serial.println("Display initialized");
}

void loop() {
}
