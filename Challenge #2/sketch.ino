int ledPins[] = {2, 3, 4, 5, 6, 7};
int buttonPin = 8;
int currentNumber = 0;

void setup() {
  // initialize LED pins as outputs
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // initialize button pin as input with pullup resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // wait for button press
  while (digitalRead(buttonPin) == HIGH);

  // generate random numbers and display on LEDs
  for (int i = 0; i < 20; i++) {
    int randomNumber = random(1, 7);
    displayNumber(randomNumber);
    delay(150);
  }

  // update current number with the last generated number
  currentNumber = random(1, 7);

  // wait for button release
  while (digitalRead(buttonPin) == LOW);

  // display the last generated number on LEDs
  displayNumber(currentNumber);

  // print the last generated number to serial monitor
  Serial.println(currentNumber);
}

void displayNumber(int number) {
  // turn off all LEDs
  for (int i = 0; i < 6; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // turn on LEDs corresponding to the number
  for (int i = 0; i < number; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}
