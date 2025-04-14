#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // SDA, SCL pins for ESP32

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("SSD1306 Test");
  display.println("Hello World!");
  display.display();
  Serial.println("Display initialized");
}

void loop() {
  // Add some animation
  static int counter = 0;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Counter: ");
  display.println(counter);
  display.display();
  Serial.print("Counter: ");
  Serial.println(counter);
  counter++;
  delay(1000);
}
