const int redPin = 3;
const int greenPin = 5;
const int yellowPin = 6;
const int purplePin = 9;

int red, green, yellow, purple;

void setup()
{
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(purplePin, OUTPUT);
}

void loop()
{
  while(Serial.available() > 0){
    red = Serial.parseInt();
    green = Serial.parseInt();
    yellow = Serial.parseInt();
    purple = Serial.parseInt();

    if(Serial.read() == '\n'){
      // constrain the values to 0 - 255 and invert
      red = 255 - constrain(red, 0, 255);
      green = 255 - constrain(green, 0, 255);
      yellow = 255 - constrain(yellow, 0, 255);
      purple = 255 - constrain(purple, 0, 255);

      // fade the red, green, and yellow legs of the LED:
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(yellowPin, yellow);
      analogWrite(purplePin, purple);

      Serial.print(red, HEX);
      Serial.print(green, HEX);
      Serial.print(yellow, HEX);
      Serial.println(purple, HEX);
    }
  }
}
