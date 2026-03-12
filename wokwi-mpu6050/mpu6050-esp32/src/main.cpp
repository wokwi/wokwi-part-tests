#include <Arduino.h>
#include <MPU6050.h>

#define SDA_PIN 21
#define SCL_PIN 22
#define INT_PIN 4

MPU6050 mpu;
volatile uint32_t intCount = 0;
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR dataReadyISR() {
  portENTER_CRITICAL_ISR(&mux);
  intCount++;
  portEXIT_CRITICAL_ISR(&mux);
}

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("MPU6050 Test (ESP32)");

  Wire.begin(SDA_PIN, SCL_PIN);
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 not found!");
    while (1) delay(1000);
  }
  Serial.println("MPU6050 found");

  // Default range: +/- 2g (16384 LSB/g)
  mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_2);

  // Enable DATA_RDY interrupt on INT pin
  mpu.setIntDataReadyEnabled(true);
  pinMode(INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), dataReadyISR, FALLING);
}

uint32_t reading = 0;

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getIntDataReadyStatus();

  float gx = ax / 16384.0;
  float gy = ay / 16384.0;
  float gz = az / 16384.0;

  Serial.print("Accel X: ");
  Serial.print(gx, 1);
  Serial.print(" Y: ");
  Serial.print(gy, 1);
  Serial.print(" Z: ");
  Serial.print(gz, 1);
  Serial.println(" g");

  reading++;
  if (reading == 5) {
    uint32_t count;
    portENTER_CRITICAL(&mux);
    count = intCount;
    portEXIT_CRITICAL(&mux);
    if (count > 0) {
      Serial.println("INT pin: OK");
    }
  }

  delay(500);
}
