const int lowestPin = 3;
const int highestPin = 11;

void setup()
{
  Serial.begin(9600);
  for(int thisPin = lowestPin; thisPin <= highestPin; thisPin++){
    if(thisPin == 4 || thisPin == 7 || thisPin == 8){
      continue;
    }
    pinMode(thisPin, OUTPUT);
  }
}

void loop()
{
  for(int thisPin = lowestPin; thisPin <= highestPin; thisPin++){
    if(thisPin == 4 || thisPin == 7 || thisPin == 8){
      continue;
    }
    
    for(int brightness = 0; brightness < 255; brightness++){
      if(thisPin == 3){
      	analogWrite(thisPin + 6, brightness);
      } else if(thisPin == 9){
      	analogWrite(thisPin - 6, brightness);
      } else if(thisPin == 10 || thisPin == 11){
      	analogWrite(thisPin - 5, brightness);
      } else {
      	analogWrite(thisPin + 5, brightness);
      }
      analogWrite(thisPin, brightness);
      delay(2);
    }
    
    for(int brightness = 255; brightness >= 0; brightness--){
      if(thisPin == 3){
      	analogWrite(thisPin + 6, brightness);
      } else if(thisPin == 9){
      	analogWrite(thisPin - 6, brightness);
      } else if(thisPin == 10 || thisPin == 11){
      	analogWrite(thisPin - 5, brightness);
      } else {
      	analogWrite(thisPin + 5, brightness);
      }
      analogWrite(thisPin, brightness);
      delay(2);
    }
    
    delay(100);
  }
  
  
}