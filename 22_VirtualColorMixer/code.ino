const int redPin = A0;      // sensor to control red color

const int greenPin = A1;    // sensor to control green color

const int bluePin = A2;     // sensor to control blue color

void setup() {

  Serial.begin(9600);
}

void loop() {

  Serial.print(analogRead(redPin));

  Serial.print(",");

  Serial.print(analogRead(greenPin));

  Serial.print(",");

  Serial.println(analogRead(bluePin));
}