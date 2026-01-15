#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Wire.setSDA(PB7);  // D4
  Wire.setSCL(PB6);  // D5
  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("Hello Wokwi :-)");
  lcd.setCursor(2, 1);
  lcd.print("STM32L031 I2C");

  Serial.println("Display initialized");
}

void loop() {
  delay(100);
}
