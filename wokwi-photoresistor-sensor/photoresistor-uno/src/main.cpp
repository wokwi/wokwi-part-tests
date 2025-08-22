#include <Arduino.h>

const int PHOTORESISTOR_PIN = A0;

// These constants should match the photoresistor's "gamma" and "rl10" attributes
const float GAMMA = 0.7;
const float RL10 = 50;

void setup()
{
  Serial.begin(115200);
  Serial.println("Photoresistor Sensor Test");
}

void loop()
{
  // Read the analog value from the photoresistor
  int lightValue = analogRead(PHOTORESISTOR_PIN);

  // Convert to voltage (ESP32 ADC reference is 3.3V, 12-bit resolution)
  float voltage = (lightValue * 5) / 1024.0;

  // Convert the analog value into lux value:
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

  // Print the values
  Serial.print("Sensor value: ");
  Serial.print(lightValue);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print(", Lux: ");
  Serial.println(lux);

  // Wait before next reading
  delay(1000);
}
