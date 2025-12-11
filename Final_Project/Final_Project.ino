const int ledPin = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;
const int ledPin4 = 7;
const int ledPin5 = 15;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char command = Serial.read();
//do it as a timer not as a delay cause it will pause the commands
    if (command == '1') {
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);

      digitalWrite(ledPin2, HIGH); 
      delay(25);
      digitalWrite(ledPin2, LOW);

      digitalWrite(ledPin3, HIGH); 
      delay(50);
      digitalWrite(ledPin3, LOW);

      digitalWrite(ledPin4, HIGH); 
      delay(150);
      digitalWrite(ledPin4, LOW);

      digitalWrite(ledPin5, HIGH);
      delay(235);
      digitalWrite(ledPin5,LOW);
    }
  }

}
