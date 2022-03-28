#include "pitches.h"

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0);
  
  // map the analog input range (in this case, 400 - 1000 from the photoresistor)
  // to the output pitch range (120 - 1500Hz)
  // change the minimum and maximum input numbers below depending on the range
  
  int thisPitch = map(sensorValue, 400, 1000, 120, 1500);
  
  tone(9, thisPitch, 10);
  
  delay(1)
  
}