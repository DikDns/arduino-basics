
const int sensorPin = A0;
const int ledPin = 9;
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value
int sensorValue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
  while(millis() < 1000){
  	sensorValue = analogRead(sensorPin);
    
    if(sensorValue > sensorMax){
      sensorMax = sensorValue;
    }
    
    if(sensorValue < sensorMin){
      sensorMin = sensorValue;
    }
  }
  
  digitalWrite(13, LOW);
}

void loop()
{
  // read the sensor:
  sensorValue = analogRead(sensorPin);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, sensorMin, sensorMax);
  
  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  
  // fade the LED using the calibrated value:
  analogWrite(ledPin, sensorValue);
  
  delay(2);
}