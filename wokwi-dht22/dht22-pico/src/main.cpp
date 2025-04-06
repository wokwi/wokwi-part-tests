#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2        // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial1.begin(115200);
  Serial1.println("DHT22 test (Pi Pico)");
  dht.begin();
}

void loop() {
  delay(500);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again)
  if (isnan(h) || isnan(t)) {
    Serial1.println("Failed to read from DHT sensor!");
    return;
  }

  Serial1.print("Humidity: ");
  Serial1.print(h);
  Serial1.print("%  Temperature: ");
  Serial1.print(t);
  Serial1.println("°C");
}
