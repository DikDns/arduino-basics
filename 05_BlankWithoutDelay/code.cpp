#include <SPI.h>

int led = LED_BUILTIN;
int ledState = LOW;
unsigned long previousMillis = 0;
// interval (milliseconds)
const int interval = 1000;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval){
  	// Save the last time blinked
    previousMillis = currentMillis;
    
    ledState = (ledState == HIGH) ? LOW : HIGH;
    
    digitalWrite(led, ledState);
  }
  
  Serial.println(currentMillis);
}