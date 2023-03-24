int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.print("Digite R, G ou B");
}

void loop() {
  // Serial.println("Olá Teste");
  if (Serial.available() > 0) {
    char color = Serial.read();
    if (color == 'R') {
      digitalWrite(redPin, HIGH);
      delay(500);
    } else if (color == 'r') {
      digitalWrite(redPin, LOW);
      delay(500);
    } else if (color == 'G') {
      digitalWrite(greenPin, HIGH);
      delay(500);
    } else if (color == 'g') {
      digitalWrite(greenPin, LOW);
      delay(500);
    } else if (color == 'B') {
      digitalWrite(bluePin, HIGH);
      delay(500);
    } else if (color == 'b') {
      digitalWrite(bluePin, LOW);
      delay(500);
    }
    Serial.print("Digite R, G ou B para ligar ou desligar");
  }
}
