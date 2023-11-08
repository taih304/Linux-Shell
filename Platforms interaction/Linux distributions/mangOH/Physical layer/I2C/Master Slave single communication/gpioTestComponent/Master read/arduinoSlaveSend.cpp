#include <Arduino.h>
#include <Wire.h>

int count = 0;

void sendNumber();

void setup()
{
     Wire.begin(0x30); // Set up its I2C address to 3
     Wire.onRequest(sendNumber); // Set up received mode from Master board
}
 
void loop(){}
 
void sendNumber()
{
     Wire.write(count);
     count++;
}