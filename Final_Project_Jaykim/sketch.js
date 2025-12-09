let serial; // variable for instance of the serialport library
let portName = 'COM3'; // fill in your serial port name
let options = { baudRate: 9600}; // change the baud rate to match your Arduino code
let outVal = 0; // value to be sent via serial

let sound;

function preload() {
  sound = loadSound("Ki_charge.mp3");
}

function setup() {
  createCanvas(400, 400);

  serial = new p5.SerialPort();             // make a new instance of the serialport library
  serial.on('list', printList);             // set a callback function for the serialport list event
  serial.on('connected', serverConnected);  // set callback for connecting to the server
  serial.on('open', portOpen);              // set callback for the port opening
  serial.on('data', serialEvent);           // set callback for when new data received
  serial.on('error', serialError);          // set callback for errors
  serial.on('close', portClose);            // set callback for closing the port
  serial.list();                            // list the serial ports
  serial.open(portName, options);           // open a serial port

  textAlign(CENTER, CENTER);
}

function draw() {
  background(220);

  text("To Charge up Ki", width/2, height/2);
}

function mousePressed() {
  // Play audio from PC
  if (sound && !sound.isPlaying()) {
    sound.play();
  }

  // Tell Arduino to blink
  if (serial) {
    serial.write("1");
  }
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