const int leds[5] = {4, 5, 6, 7, 15};


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    // Turn all LEDs ON
    if (command == 'A') {
      for (int i = 0; i < 5; i++) {
        digitalWrite(leds[i], HIGH);
      }
    }

    // Random blinking pattern
    if (command == 'B') {
      for (int i = 0; i < 10; i++) {
        int led = random(0, 5);
        digitalWrite(leds[led], HIGH);
        delay(150);
        digitalWrite(leds[led], LOW);
      }

    }
  }
}