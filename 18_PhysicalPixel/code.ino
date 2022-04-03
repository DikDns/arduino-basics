
const int ledPin = 13;
int incomingByte;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  if(Serial.available() > 0){
    incomingByte = Serial.read();
    //! If there is a 'H' , turn on LED
    if (incomingByte == 'H'){
      digitalWrite(ledPin, HIGH);
    }
    //! If there is a 'L' , turn off LED
    if (incomingByte == 'L'){
      digitalWrite(ledPin, LOW);
    }
  }
}


/*
! Processing Code

  import processing.serial.*;

  float boxX;

  float boxY;

  int boxSize = 20;

  boolean mouseOverBox = false;

  Serial port;

  void setup() {

    size(200, 200);

    boxX = width / 2.0;

    boxY = height / 2.0;

    rectMode(RADIUS);

    // List all the available serial ports in the output pane.

    // You will need to choose the port that the Arduino board is connected to

    // from this list. The first port in the list is port #0 and the third port

    // in the list is port #2.

    // if using Processing 2.1 or later, use Serial.printArray()

    println(Serial.list());

    // Open the port that the Arduino board is connected to (in this case #0)

    // Make sure to open the port at the same speed Arduino is using (9600bps)

    port = new Serial(this, Serial.list()[0], 9600);

  }

  void draw() {

    background(0);

    // Test if the cursor is over the box

    if (mouseX > boxX - boxSize && mouseX < boxX + boxSize &&

        mouseY > boxY - boxSize && mouseY < boxY + boxSize) {

      mouseOverBox = true;

      // draw a line around the box and change its color:

      stroke(255);

      fill(153);

      // send an 'H' to indicate mouse is over square:

      port.write('H');

    }

    else {

      // return the box to its inactive state:

      stroke(153);

      fill(153);

      // send an 'L' to turn the LED off:

      port.write('L');

      mouseOverBox = false;

    }

    // Draw the box

    rect(boxX, boxY, boxSize, boxSize);

  }
*/