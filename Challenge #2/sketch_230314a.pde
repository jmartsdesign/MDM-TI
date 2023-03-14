import processing.serial.*;

Serial serialPort;

void setup() {
  size(200, 200);
  // get and print the list of avariable ports
  printArray(Serial.list());
  serialPort = new Serial(this, Serial.list()[2], 9600);
}

void draw() {
  // read last generated number from serial monitor
  if (serialPort.available() > 0) {
    int number = Integer.parseInt(serialPort.readStringUntil('\n').trim());

    // display the number as text
    background(255);
    fill(0);
    textSize(50);
    textAlign(CENTER, CENTER);
    text(number, width/2, height/2);
  }
}
