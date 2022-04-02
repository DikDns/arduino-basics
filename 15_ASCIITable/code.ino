
void setup()
{
  Serial.begin(9600);
  while(!Serial){
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("ASCII Table ~ Character Map");
}

// First Visible ASCII Character is 33
int thisByte = 33;

void loop()
{
  while(thisByte <= 126){
    
    Serial.write(thisByte);

    Serial.print(", dec: ");
    // Decimal is the default format for Serial.print() and Serial.println(),
    // so no modifier is needed:
    // Serial.print(thisByte, DEC);
    Serial.print(thisByte);

    Serial.print(", hex:");
    Serial.print(thisByte, HEX);

    Serial.print(", oct:");
    Serial.print(thisByte, OCT);

    Serial.print(", bin:");
    Serial.println(thisByte, BIN);

    thisByte++;
    delay(1);
  }
}