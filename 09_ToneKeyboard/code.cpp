#include "pitches.h"

const int threshold = 10;

int notes[] = {
  NOTE_A4, NOTE_B4, NOTE_C3
}

void setup()
{
}

void loop()
{
  for(int i = 0; i < 3; i++{
    int sensorValue = analogRead(i);
    
    if(sensorValue > threshold){
      tone(8, notes[i], 20);
    }
    
  }
}