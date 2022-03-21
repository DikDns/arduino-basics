// LED PIN
const int BUTTON_PIN = 2;
const int LED_PIN = 13;

int ledState = 1;
int buttonState;
int lastButtonState = 0;

// the last time the output pin was toggled
unsigned long lastDebounceTime = 0;
 // the debounce time; increase if the output flickers
unsigned long debounceDelay = 50;

void setup()
{
  // To communicate with our PC
  Serial.begin(9600);
  
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  // init LED State
  digitalWrite(LED_PIN, ledState);
}

void loop()
{
  int reading = digitalRead(BUTTON_PIN);
  
  if(reading != lastButtonState){
   	lastDebounceTime = millis(); 
  }
  
  if((millis() - lastDebounceTime) > debounceDelay){
   	 
    if(reading != buttonState){
     	buttonState = reading;	
      
      ledState = (buttonState == 1) ? !ledState : ledState;
      
    }
      
  }
  
  digitalWrite(LED_PIN, ledState);
  
  lastButtonState = reading;
}