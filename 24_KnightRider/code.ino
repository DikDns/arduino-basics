
const int timer = 100;
const int leds[6] = {3,5,6,9,10,11};

void setup(){
  for (int i = 0; i < 6; i++){
    pinMode(leds[i], OUTPUT); 
  }
}

void loop(){
  for(int i = 0; i < 6; i++){
    digitalWrite(leds[i], HIGH);
    delay(timer);
    digitalWrite(leds[i], LOW);
  }
  for(int i = 5; i >= 0; i--){
    digitalWrite(leds[i], HIGH);
    delay(timer);
    digitalWrite(leds[i], LOW);
  }
}