const int ledPin = 4;
const int John = 5;
const int ps2 = 6;
const int psp = 7;
const int ledOn =15;
const int fading = 8;

int ms = 250;
int speed = 250;           
bool ledState = 0;      


void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(John, OUTPUT);

  pinMode(ps2, OUTPUT);
  pinMode(psp, OUTPUT);
  digitalWrite(ps2, LOW);
  digitalWrite(psp, LOW);

  pinMode(ledOn, OUTPUT);

  pinMode(fading, OUTPUT);

  Serial.begin(115200);

}

void loop() {
  digitalWrite(ledPin, HIGH); 
  delay(ms); 
  digitalWrite(ledPin, LOW); 
  delay(ms); 

  digitalWrite(John, LOW); 
  delay(speed); 
  digitalWrite(John, HIGH); 
  delay(speed); 

  digitalWrite(ps2, HIGH);
  digitalWrite(ps2, HIGH);
  delay(650);
  digitalWrite(ps2, LOW);
  digitalWrite(ps2, LOW);
  delay(350);

  if (digitalRead(ps2) == HIGH) {
    digitalWrite(psp, HIGH); //Turns the led on
  } else {
    digitalWrite(psp, LOW); 
  }
  
digitalWrite(psp, HIGH);
  delay(650); 
  digitalWrite(psp, LOW);
  delay(350);

  digitalWrite(ledPin, HIGH);

  digitalWrite(ledOn, HIGH);

  for (int brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(fading, brightness); 
    delay(30); // the speed it fades out
  }

 
  for (int brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(fading, brightness); 
    delay(30); 
  }



}
