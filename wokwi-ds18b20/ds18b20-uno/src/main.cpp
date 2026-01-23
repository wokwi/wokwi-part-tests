#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DS18B20 test!"));
  sensors.begin();
  Serial.print(F("Found "));
  Serial.print(sensors.getDeviceCount());
  Serial.println(F(" device(s)"));
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  if (tempC == DEVICE_DISCONNECTED_C) {
    Serial.println(F("Error: Could not read temperature"));
    return;
  }

  Serial.print(F("Temperature: "));
  Serial.print(tempC, 2);
  Serial.println(F(" C"));
  delay(1000);
}
