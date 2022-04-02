const int ledPin = 9;
void setup()
{
  Serial.begin(9600);
  while(!Serial){
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(9, OUTPUT);
}

void loop()
{
  byte brightness;
  // Check if the data has been sent
  if(Serial.available()){
    brightness = Serial.read();
    analogWrite(ledPin, brightness);
  }
}


/*
! Processing Code
import processing.serial.*;

Serial port;

void setup(){
  size(256, 150);
  
  println("Available Serial Ports:");
  
  println(Serial.list());
  
  port = new Serial(this, Serial.list()[0], 9600);
  
  
}

void draw(){
 for (int i = 0; i < 256; i++){
   stroke(i);
   line(i, 0, i, 150);
 }
 
 port.write(mouseX);
} 
*/