int sensorValue = 0;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  // lê valor sensor
  sensorValue = analogRead(A0);
  // imprime leitura do sensor para saber alcance
  Serial.println(sensorValue);
    // mapeia leitura do sensor para intervalo do LED
  analogWrite(9, map(sensorValue, 0, 1023, 0, 255));
  delay(100); 
}