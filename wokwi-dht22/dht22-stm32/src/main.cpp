#include <Arduino.h>
#include <DHT.h>

#define DHTPIN D2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT22 test (STM32)");
  dht.begin();
}

void loop() {
  delay(500);
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  Serial.print("Humidity: ");
  Serial.print(humidity, 2);
  Serial.print("%  Temperature: ");
  Serial.print(temperature, 2);
  Serial.println("°C");
}
