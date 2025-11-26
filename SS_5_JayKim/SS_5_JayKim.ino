const int buzzerPin = 1; 
int frequency = 0;  

void setup() {
  Serial.begin(9600); 
  pinMode(buzzerPin, OUTPUT); 
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming byte (0-255) from the serial port
    int inByte = Serial.read(); 

    // Map the byte value to a usable frequency range (e.g., 100 Hz to 2000 Hz)
    // The incoming value (inByte) is 0-255, we map it to our desired range
    frequency = map(inByte, 0, 255, 100, 2000); 

    // Play the tone with the calculated frequency
    tone(buzzerPin, frequency); 
  }
}