#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  Serial.println("ILI9341 Test!");

  tft.begin();
  tft.setRotation(1);  // Landscape mode
  tft.fillScreen(ILI9341_BLACK);
  
  // Draw some text
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.println("ILI9341 Test");
  tft.println("Hello World!");
  
  // Draw a rectangle
  tft.fillRect(50, 100, 140, 40, ILI9341_RED);
  tft.setCursor(60, 110);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.println("Button");
  
  Serial.println("Display initialized");
}

void loop() {
  static int counter = 0;
  
  // Update counter display
  tft.fillRect(50, 150, 140, 40, ILI9341_BLUE);
  tft.setCursor(60, 160);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("Count: ");
  tft.println(counter);
  
  Serial.print("Counter: ");
  Serial.println(counter);
  
  counter++;
  delay(1000);
} 