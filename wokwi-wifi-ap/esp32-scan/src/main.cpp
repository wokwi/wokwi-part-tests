#include <WiFi.h>
#include <algorithm>
#include <vector>

struct NetworkInfo {
  String ssid;
  int channel;
  bool secured;
};

void setup() {
  Serial.begin(115200);
  delay(100);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.printf("Scanning for WiFi networks...\r\n");
  int numNetworks = WiFi.scanNetworks();

  std::vector<NetworkInfo> networks;
  for (int i = 0; i < numNetworks; i++) {
    networks.push_back({WiFi.SSID(i), WiFi.channel(i), WiFi.encryptionType(i) != WIFI_AUTH_OPEN});
  }
  std::sort(networks.begin(), networks.end(),
    [](const NetworkInfo& a, const NetworkInfo& b) { return a.ssid < b.ssid; });

  Serial.printf("Found %d networks:\r\n", numNetworks);
  for (const auto& net : networks) {
    Serial.printf("  %s (ch %d, %s)\r\n",
      net.ssid.c_str(), net.channel, net.secured ? "secured" : "open");
  }

  Serial.printf("Connecting to TestNet-WPA2...\r\n");
  WiFi.begin("TestNet-WPA2", "test1234");

  int timeout = 200;
  while (WiFi.status() != WL_CONNECTED && timeout > 0) {
    delay(100);
    timeout--;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.printf("Connected!\r\n");
    Serial.printf("IP: %s\r\n", WiFi.localIP().toString().c_str());
  } else {
    Serial.printf("Connection failed (status=%d)\r\n", WiFi.status());
  }
}

void loop() {
  delay(1000);
}
