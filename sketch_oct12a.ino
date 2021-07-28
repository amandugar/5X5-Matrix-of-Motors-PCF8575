#include "Arduino.h"
#include "PCF8575.h"
#include "Wire.h"

bool keyPressed = false;


void keyPressedOnPCF8575() {
  // Interrupt called (No Serial no read no wire in this function, and DEBUG disabled on PCF library)
  keyPressed = true;

}
// Set i2c address
PCF8575 pcf85751(0x20, 2, keyPressedOnPCF8575);
PCF8575 pcf85752(0x21, 2, keyPressedOnPCF8575);

void setup()
{
  Serial.begin(115200);

  for (int i = 0 ; i <= 15; i++) {
    pcf85751.pinMode(i, OUTPUT);
  }
  for (int i = 0 ; i <= 8; i++) {
    pcf85752.pinMode(i, OUTPUT);
  }
    for (int i = 0 ; i <= 8; i++) {
    pcf85753.pinMode(i, OUTPUT);
  }
  pcf85751.begin();
  pcf85752.begin();
  pcf85753.begin();
  Wire.begin();
}

void loop()
{
  for (int i = 0 ; i <= 15; i++) {
    pcf85751.digitalWrite(i, HIGH);
    delay(100);
    pcf85751.digitalWrite(i, LOW);
    delay(100);
  }  for (int i = 0 ; i <= 8;i++) {
    pcf85752.digitalWrite(i, HIGH);
    delay(100);
    pcf85752.digitalWrite(i, LOW);
    delay(100);
  }
   for (int i = 0 ; i <= 8; i++) {
    pcf85753.digitalWrite(i, HIGH);
    delay(100);
    pcf85753.digitalWrite(i, LOW);
    delay(100);
  }
}
