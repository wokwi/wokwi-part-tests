#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(115200);
  Serial.println("BMP180 test!");

  // Initialize I2C with Xiao ESP32-C3 pins (D4=GPIO6=SDA, D5=GPIO7=SCL)
  Wire.begin(6, 7);

  if (!bmp.begin()) {
    Serial.println("BMP180 not found!");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("BMP180 found!");
}

void loop() {
  float temperature = bmp.readTemperature();
  int32_t pressure = bmp.readPressure();

  Serial.printf("Temperature: %.1f C\n", temperature);
  Serial.printf("Pressure: %d Pa\n", pressure);

  delay(1000);
}
