const int SENSOR_PIN = A0;
const int LED_COUNT = 10;
int ledLevel = 0;
int ledPins[LED_COUNT] = {
  2,3,4,5,6,7,8,9,10,11
};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < LED_COUNT; i++){
    pinMode(ledPins[i], OUTPUT);
  }

}

void loop() {
  ledLevel = Serial.read();

  Serial.println(ledLevel);

  for (int i = 0; i < LED_COUNT; i++){
    if(i < ledLevel){
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    } 
  }
}