// LED PIN
int myPin = 2;

void setup()
{
  // To communicate with our PC
  Serial.begin(9600);
  
  pinMode(myPin, INPUT);
}

void loop()
{
  int sensorValue = digitalRead(myPin);
  Serial.println(sensorValue);
}