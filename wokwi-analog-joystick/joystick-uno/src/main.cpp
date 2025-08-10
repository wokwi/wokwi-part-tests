#include <Arduino.h>

#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN 2

void setup()
{
  Serial.begin(115200);
  Serial.println(F("Analog Joystick test"));
  pinMode(SEL_PIN, INPUT_PULLUP);
}

int lastVert = 0;
int lastHorz = 0;
bool lastSelPressed = false;

void loop()
{
  int vert = analogRead(VERT_PIN);
  int horz = analogRead(HORZ_PIN);
  bool selPressed = digitalRead(SEL_PIN) == LOW;
  if (vert != lastVert)
  {
    Serial.print(F("Vertical: "));
    Serial.println(vert);
    lastVert = vert;
  }
  if (horz != lastHorz)
  {
    Serial.print(F("Horizontal: "));
    Serial.println(horz);
    lastHorz = horz;
  }
  if (selPressed != lastSelPressed)
  {
    if (selPressed)
    {
      Serial.println(F("Select pressed"));
    }
    else
    {
      Serial.println(F("Select released"));
    }
    lastSelPressed = selPressed;
  }
  delay(100);
}