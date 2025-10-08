const int buttonPin = 9;
const int ledPin = 4;
const int led2 = 5;
const int led3 = 6;
const int led4 = 7;

int ms = 250;
int speed = 300;
bool ledState = 0;
bool buttonState = 0;
bool lastButtonState = 0;
bool toggle = 0;
bool fallToggle = 0;


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  Serial.begin(115200);

}

void loop() {
  for (int brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(led4, brightness); 
    delay(30); // the speed it fades out
  }

 
  for (int brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(led4, brightness); 
    delay(30); 
  }

  buttonState = !digitalRead(buttonPin);
// if the button is pressed it detects it and goes from LOW to HIGH 
  if (buttonState && !lastButtonState)
  {
    toggle = !toggle;
  }
// When the button is released it goes from HIGH to LOW
  if (!buttonState && lastButtonState)
  {
    fallToggle = !fallToggle;
  }
  
  lastButtonState = buttonState; 

  digitalWrite(led3, toggle); // Turns the LED on and off with the toggle

Serial.printf("Button = %i _ Toggle = %i _ Falling = %i \n", buttonState, toggle, fallToggle);

//this is a test of when the button is pressed one LED is on while when the led is pressed another LED is turned off.
if (digitalRead(buttonPin) == HIGH) {
  digitalWrite(ledPin, HIGH);
}
else {
  digitalWrite(ledPin, LOW);
}
  if(digitalRead(buttonPin) == LOW) {
    digitalWrite(led2, LOW);
  }else{
      digitalWrite(led2, HIGH);
    }
}
