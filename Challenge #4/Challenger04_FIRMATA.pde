import processing.serial.*;
import cc.arduino.*;

Arduino arduino;
int ledPin = 9;
int ldrPin = 0;
float circleSize = 10;

void setup() {
  size(400, 400);
  background(0);
  arduino = new Arduino(this, Arduino.list()[2], 57600);
  arduino.pinMode(ledPin, Arduino.OUTPUT);
}

void draw() {
  background(0);
  int ldrValue = arduino.analogRead(ldrPin);
  float circleSize = map(ldrValue, 0, 1023, 0, 5255);
  fill(255);
  ellipse(width/2, height/2, circleSize*5, circleSize*5);
  int ledValue = (int) map(ldrValue, 0, 1023, 0, 255);
  arduino.analogWrite(ledPin, ledValue);
}
