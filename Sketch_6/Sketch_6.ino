const int adcPin = 1; 
int adcRead = 0;  
int ledPins[] = {4, 5, 6, 7, 8};
int numLeds = 5;
int incomingValue;
String incomingString = "";

//software timer variables
int lastTime = 0;
int currentTime = 0;
int timerInterval = 2;


void setup() 
{
  Serial.begin(9600); 
  analogReadResolution(8);  //adjust adc read range to 0-255, 1-byte, 8-bit
    
    for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
}

void loop() 
{
  currentTime = millis(); //read current elapsed time
  if (currentTime - lastTime >= timerInterval)  
  {
    lastTime = currentTime; //store current time as last time so we know when timer last occured
    adcRead = analogRead(adcPin); 

    Serial.write(adcRead);  //to send binary data to UART

    //code in here will only run every 2ms
  }

}