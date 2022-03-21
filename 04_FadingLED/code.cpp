#include <SPI.h>

int led = 13;
int brightness = 0;
int fadeAmount = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  analogWrite(led, brightness);
  brightness += fadeAmount;
  
  if(brightness <= 0 || brightness >= 255){
  	fadeAmount = -fadeAmount;
  }
  Serial.println(brightness);
  
  delay(100);
}