const int buzzerPin = 1; // Pin for the piezo buzzer
int frequency = 0;       // Variable to store the frequency value from p5.js

void setup() {
  Serial.begin(9600);    // Initialize serial communication at 9600 baud rate
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available to read
    // Read the incoming byte (0-255) from the serial port
    int inByte = Serial.read(); 

    // Map the byte value to a usable frequency range (e.g., 100 Hz to 2000 Hz)
    // The incoming value (inByte) is 0-255, we map it to our desired range
    frequency = map(inByte, 0, 255, 100, 2000); 

    // Play the tone with the calculated frequency
    tone(buzzerPin, frequency); 
  }
}