#include <SPI.h>
#include <SD.h>

const int chipSelect = 5;
File myFile;

void setup() {
  Serial.begin(115200);

  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("SD card initialized successfully");

  // Create a test file
  myFile = SD.open("/test.txt", FILE_WRITE);
  if (myFile) {
    Serial.println("File created successfully");

    // Write some data
    myFile.println("Hello, Wokwi!");
    myFile.close();
    Serial.println("Data written successfully");
  } else {
    Serial.println("Error creating file");
    return;
  }

  // Read the file
  myFile = SD.open("/test.txt");
  if (myFile) {
    Serial.println("Data read successfully");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("Error opening file");
    return;
  }

  Serial.println("Test completed");
}

void loop() {
  // Nothing to do here
}
