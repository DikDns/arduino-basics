const int SENSOR_PIN = A0;
const int LED_COUNT = 10;

int ledPins[LED_COUNT] = {
  2,3,4,5,6,7,8,9,10,11
};

void setup() {
  for(int i = 0; i < LED_COUNT; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int sensorVal = analogRead(SENSOR_PIN);

  int ledLevel = map(sensorVal, 0, 1023, 0, LED_COUNT);

  for (int i = 0; i < LED_COUNT; i++){
    if(i < ledLevel){
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    } 
  }

}