#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Serial.println(F("MPU6050 test!"));

  if (!mpu.begin()) {
    Serial.println(F("MPU6050 not found!"));
    while (1) {
      delay(1000);
    }
  }
  Serial.println(F("MPU6050 found!"));

  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  Serial.print(F("Accel X: "));
  Serial.print(a.acceleration.x, 1);
  Serial.print(F(" Y: "));
  Serial.print(a.acceleration.y, 1);
  Serial.print(F(" Z: "));
  Serial.print(a.acceleration.z, 1);
  Serial.println(F(" m/s^2"));

  delay(500);
}
