


// void setup()
// {
//   // start serial port at 9600 bps:
//   Serial.begin(9600);
//   while (!Serial) {
//     ; // wait for serial port to connect. Needed for native USB port only
//   }
// }

// void loop(){

//  Serial.println(analogRead(A0));

// }




int sensor_1 = 0;
int sensor_2 = 0;
int sensor_3 = 0;
int inByte = 0;

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  pinMode(2, INPUT);

  establishContact();  
}

void loop()
{
  if(Serial.available() > 0){
    inByte = Serial.read();

    sensor_1 = (analogRead(A0) / 4);

    delay(10);  // delay to let ADC recover

    sensor_2 = (analogRead(A1) / 4);

    sensor_3 = map(digitalRead(2), 0, 1, 0, 255);

    // Send Sensor Values
    Serial.write(sensor_1);
    Serial.write(sensor_2);
    Serial.write(sensor_3);

  }
}

// send a byte to establish contact until receiver responds
void establishContact() {
  while (Serial.available() <= 0) {
    Serial.write('A');   // send a capital A
    delay(300);
  }
}