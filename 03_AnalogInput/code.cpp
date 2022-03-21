int myLed = 13;
void setup()
{
  pinMode(myLed, OUTPUT);
  
}

void loop()
{
  int sensorValue = analogRead(A0);
  digitalWrite(myLed, HIGH);
  delay(sensorValue);
  digitalWrite(myLed, LOW);
  delay(sensorValue);
}