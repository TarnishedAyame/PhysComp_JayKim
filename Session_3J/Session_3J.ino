
const int potPin = 1;   
const int ledPin1 = 4;  
const int ledPin2 = 5; 
const int ps2 = 6;
const int Fade = 7;


int potValue = 0;

void setup() {
  //Outputs of the LEDs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(ps2, OUTPUT);
  pinMode(Fade, OUTPUT);


  Serial.begin(115200);
}

void loop() {
  potValue = analogRead(potPin);

  // Print the value to the Serial Monitor for monitoring
  Serial.print("Pot value: ");
  Serial.println(potValue);

 //The plan is that when it reaches a certain thershold it will turn one LED on and the other one Off
  if (potValue < 512) {
    
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
  } else if (potValue > 512) {
     
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
  }


  for (int brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(Fade, brightness); 
    delay(30); // the speed it fades out
  }

 
  for (int brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(Fade, brightness); 
    delay(30); 
  }
  
  delay(10);
}