#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);  
  Wire.begin(6, 7); // SDA, SCL pins for Seeed Xiao ESP32-C3
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("Hello Wokwi :-)");
  lcd.setCursor(2, 1);
  lcd.print("ESP32-C3 w/I2C");

  Serial.println("Display initialized");
}

void loop() {
  delay(100);
}
