#include <Arduino.h>
#include <Wire.h>

int count = 0;

void receiveEvent();

void setup()
{
     Wire.begin(0x30); // Set up its I2C address to 0x30
     Wire.onReceive(receiveEvent); // Set up received mode from Master board
     Serial.begin(9600);
}
 
void loop(){}
 
void receiveEvent() 
{
  while(Wire.available()) 
  {
    Serial.println(Wire.read());
  }
}
