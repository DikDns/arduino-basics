// LED PIN
const int BUTTON_PIN = 2;
const int LED_PIN = 13;

int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

void setup()
{
  // To communicate with our PC
  Serial.begin(9600);
  
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState != lastButtonState){
   	// if the state HIGH increment the counter
    if(buttonState == HIGH){
      buttonPushCounter++;
      Serial.println("On");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      Serial.println("Off");
    }
    delay(50);
  }
  
  lastButtonState = buttonState;


  // turns on the LED every four button pushes by 
  // checking the modulo of the
  // division of two numbers:
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  
}