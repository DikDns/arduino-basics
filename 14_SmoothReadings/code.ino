
const int numReadings = 10;
int readings[numReadings];
int readIndex = 0;
int total = 0;
int average = 0;

int output = 0;

int inputPin = A0;

void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < numReadings; i++){
    readings[i] = 0;
  }

  pinMode(11, OUTPUT);
}

void loop()
{

  total = total - readings[readIndex];

  Serial.print("TOTAL:  ");
  Serial.println(total);

  readings[readIndex] = analogRead(inputPin);
  total += readings[readIndex];

  readIndex++;

  if ( readIndex >= numReadings){
    readIndex = 0;
  }

  average = (total / numReadings);
  output = (average / 4);

  Serial.print("AVERAGE:  ");
  Serial.println(average);

  Serial.print("OUTPUT:  ");
  Serial.println(output);

  analogWrite(11, output);
  
  Serial.println(" ");
  
  delay(1);
}