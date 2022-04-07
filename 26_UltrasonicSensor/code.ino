const unsigned int TRIG_PIN = 13;
const unsigned int ECHO_PIN = 12;

void setup(){
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
  // Microseconds to Centimeters
  int distance= (duration / 29 / 2);

  if (duration == 0){
    Serial.println("Warning: no pulse from sensor");
  } else {
    Serial.print("distance to nearest object:");
    Serial.println(distance);
    Serial.println(" cm");
  }

  delay(100);
}