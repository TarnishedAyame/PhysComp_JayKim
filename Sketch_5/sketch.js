let serial; // variable for instance of the serialport library
let portName = 'COM3'; // fill in your serial port name
let options = { baudRate: 9600}; // change the baud rate to match your Arduino code
let outByte = 0;  // 8-bit data to send to microcontroller


let mouseData; // data to send

function setup() 
{
  createCanvas(800, 800);
  textAlign(CENTER, CENTER);
  rectMode(CENTER);
  textSize(32);
  noStroke();

  //P5 SerialPort Setup
  serial = new p5.SerialPort();             // make a new instance of the serialport library
  serial.on('list', printList);             // set a callback function for the serialport list event
  serial.on('connected', serverConnected);  // set callback for connecting to the server
  serial.on('open', portOpen);              // set callback for the port opening
  serial.on('data', serialEvent);           // set callback for when new data received
  serial.on('error', serialError);          // set callback for errors
  serial.on('close', portClose);            // set callback for closing the port
  serial.list();                            // list the serial ports
  serial.open(portName, options);           // open a serial port
}

function draw() 
{
//____GFX_START____
//Suppose to be able to change color when pressing the key "W"
		if ((keyIsPressed === true) && (key === 'w')) {
  background('#5bb6ebff');
  } else {
    background('#37df83ff');
  }

  //center line
  stroke('#58ed96');
  line(0, height/2, width, height/2);

  //Volume indicators

  //Rect is on the 80 X value
  fill('#6B95E8');
  rect(600, 80, 200, 130);

  //Rect is on the 300 X value
  fill('#3767BF');
  rect(600, 300, 200, 130);

  //Rect is on the 500 X value
  fill('#1E52B3');
  rect(600, 500, 200, 130);

  //Rect is on the 700 X value
  fill('#032C66');
  rect(600, 700, 200, 130);

  //____GFX_END____

  mouseData = map(mouseY, 0, height, 255, 0); 
  //Maps the mouse to a Value between 0 and 255
// when the mouse goes up Values decreases and value decreases and likewise when
//the mouse goes down value increase and value increase.

// Constrain the value to ensure it stays within the byte range (0-255)
  mouseData = constrain(mouseData, 0, 255);
    // Write the byte to the serial port
  serial.write(int(mouseData)); // Convert to integer before sending as a single byte

  // Display the value on the screen for debugging
  textSize(18);
  text("Mouse Y: " + mouseY, 10, 20);
  text("Sent Value: " + int(mouseData), 10, 40);

}

function portOpen() //gets called when the serial port opens
{
  print("SERIAL PORT OPEN");
}

function portClose() //gets called when the serial port closes
{
  print("SERIAL PORT CLOSED");
}

function printList(portList) // gets called when the serial.list() function is called
{
  print("List of Available Serial Ports: ");
  for (var i = 0; i < portList.length; i++) 
  {
    print(i + portList[i]); //print list of available serial ports to console
  }
}

function serialEvent() // gets called when new serial data arrives
{
  //only sending data to microcontroller in this sketch, so not being used
}

function serialError(err) //gets called when there's an error
{
  print('ERROR: ' + err);
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERVER");
}