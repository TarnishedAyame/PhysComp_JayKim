const int potPin = 1;   
const int ledPin1 = 4;  
const int ledPin2 = 5;
const int ledPin3 = 6;
const int ledPin4 = 7;
const int ledPin5 = 15;

const int buttonPin = 40;
const int piezopin = 42;

int buttonState = 0;
int potValue = 0;
void setup() {
  // Setting up
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(piezopin, OUTPUT);

  
  Serial.begin(115200);
}

void loop() {

  potValue = analogRead(potPin);
  buttonState = digitalRead(buttonPin);

  // Print the value to the Serial Monitor for monitoring
  Serial.print("Pot value: ");
  Serial.println(potValue);

 //The plan is that when it reaches a certain thershold it will turn one LED on and the other one Off
 // And when Pot reaches maximum the piezo will make a tune. was debating on brightness or something else like if u push a button a LED will turn on
 // a LED and will increase brightness overtime.
  if (potValue < 100) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);

  } if (buttonState==true && potValue > 900) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    tone(piezopin, 500);
    
  } if (buttonState==true && potValue > 2000) {
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    tone(piezopin, 1000);

  } if (buttonState==true && potValue > 3000) {
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin3, LOW);
    tone(piezopin, 1500);

  } if (buttonState==true && potValue > 4090) {
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin4, LOW);
    tone(piezopin, 2000);
  }
  else {
    noTone(piezopin);
  }
}
