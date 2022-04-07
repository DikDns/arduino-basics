const int leds[6] = {3,5,6,9,10,11};
int inByte = 0;

void setup(){
  Serial.begin(9600);
  for (int i = 0; i < 6; i++){
    pinMode(leds[i], OUTPUT); 
  }
}

void loop(){
  
  if(Serial.available() > 0){
    inByte = Serial.read();
  
    switch (inByte){
      case 'a':
        digitalWrite(leds[0], HIGH);
        break;
      case 'b':
        digitalWrite(leds[1], HIGH);
        break;
      case 'c':
        digitalWrite(leds[2], HIGH);
        break;
      case 'd':
        digitalWrite(leds[3], HIGH);
        break;
      case 'e':
        digitalWrite(leds[4], HIGH);
        break;
      case 'f':
        digitalWrite(leds[5], HIGH);
        break;
      default:
        for(int i = 0; i < 6; i++){
          digitalWrite(leds[i], LOW);
        }
    }
  
  }

}