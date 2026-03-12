#include <SPI.h>
#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

MFRC522DriverPinSimple ss_pin(5);
MFRC522DriverSPI driver{ss_pin};
MFRC522 mfrc522{driver};

void setup() {
  Serial.begin(115200);
  mfrc522.PCD_Init();

  Serial.print("MFRC522 Version: 0x");
  Serial.println(mfrc522.PCD_GetVersion(), HEX);
  Serial.println("MFRC522v2 Ready");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("Card UID:");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? ":0" : ":");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  Serial.print("PICC type: ");
  Serial.println(MFRC522Debug::PICC_GetTypeName(piccType));

  mfrc522.PICC_HaltA();
  delay(1000);
}
