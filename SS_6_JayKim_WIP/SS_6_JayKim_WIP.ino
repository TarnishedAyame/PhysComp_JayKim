// The idea is that when you press the button it will go to A and B this is a test for it and the LED will turn on
// Potpin and buzzer is just there for test purposes of what I wanted to try but if it doesnt work it will just exist and wont do anything.
const int adcPin = 1;
const int buzzerPin = 1;
int frequency = 0;

const int buttonPin_1 = 41;                        

const int ledPin = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;
const int ledPin4 = 7;
const int ledPin5 = 8;

bool buttonState_1 = 0;

int inByte = 0;
int adcRead = 0;
//software timer variables
int lastTime = 0;
int currentTime = 0;
int timerInterval = 2;

void setup() 
{
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);

  digitalWrite(ledPin, 0);
  digitalWrite(ledPin2, 0);
  digitalWrite(ledPin3, 0);
  digitalWrite(ledPin4, 0);
  digitalWrite(ledPin5, 0);
  
  analogReadResolution(10); //set ADC from 0 to 1023 range
  Serial.begin(9600); //open serial port at 9600bps
}

void loop()
{
  if(Serial.available()) //if serial buffer is greater than zero...
  {
    inByte = Serial.read(); //store incoming byte
    if(inByte == 'A') //if incoming byte is 'A'...
    {
      digitalWrite(ledPin, 1);  //turn LED ON
      buttonState_1 = !digitalRead(buttonPin_1);  //read button 1
      Serial.print(buttonState_1);  
      Serial.print(',');            //send comma ASCII char to separate values
      Serial.print(adcRead);     
      Serial.print('\n');           //send newline ASCII char to frame end of message
    }
    else if (inByte == 'B') //if incoming byte is 'B'...
    {
      digitalWrite(ledPin, 0);  //turn LED OFF
      digitalWrite(ledPin2, 1);
      digitalWrite(ledPin3, 0);
      digitalWrite(ledPin4, 0);
      digitalWrite(ledPin5, 0);
      Serial.println("Sensor Update Paused...");  //send paused status message
      //using Serial.println adds a newline after each print, so no need for Serial.print('/n')
    }
    else //if incoming byte is neither 'A' nor 'B'
    {
      digitalWrite(ledPin, 0);  //turn LED OFF
      digitalWrite(ledPin2, 0);
      digitalWrite(ledPin3, 0);
      digitalWrite(ledPin4, 1);
      digitalWrite(ledPin5, 1);
      Serial.println("Rx Byte is neither 'A' nor 'B'"); //send status message
    }
  }
}