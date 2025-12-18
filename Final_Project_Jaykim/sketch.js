let serial; // variable for instance of the serialport library
let portName = 'COM3'; // fill in your serial port name
let options = { baudRate: 9600}; // change the baud rate to match your Arduino code
let outVal = 0; // value to be sent via serial

let port;
let connectButton;
let sound;
let img;


let circleA = { x: 120, y: 120, r: 50 };
let circleB = { x: 280, y: 120, r: 50 };
/* 
The Final Project and what this code does is that when you click the mouse you turn on
the LEDS which blink and a sound plays as well.
*/
function preload() {
  sound1 = loadSound("Ki_charge.mp3");
  sound2 = loadSound("ActiveSSJGoku.mp3");
  sound3 = loadSound("GokuActiveSkillEN.mp3");
   img = loadImage("Namek.jpg");
}

function setup() {
  createCanvas(1200, 950);

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
  background("#FFFF00");
  image(img, 0, 0);


 // Button A
  fill("#fc8403");
  ellipse(200, 200, 100);

  // Button B
  fill("#fcba03");
  ellipse(400, 200, 100);

  fill(255);
  textAlign(CENTER);
  text("A", 200, 205);
  text("B", 400, 205);
}

 function mousePressed() {
  // Button A
  if (dist(mouseX, mouseY, 200, 200) < 50) {
    if (sound3.isLoaded()) sound3.play();
    {if (sound1.isLoaded()) sound1.play();
    serial.write('A');
  }
}

  // Button B
  if (dist(mouseX, mouseY, 400, 200) < 50) {
    if (sound2.isLoaded()) sound2.play();
    serial.write('B');
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
function sendToArduino(char) {
  const data = new TextEncoder().encode(char);
  writer.write(data);
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