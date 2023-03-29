//   challenge #3 - Mudar cor RGB LED com potenciometro
 
int led_R = 9; // pino LED Vermelho (R)
int led_G = 10; // pino LED Verde (G)
int led_B = 11; // Pino LED Azul (B)
int pot = A0;
 
int valorPot;
 
void setup()
{
  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);
}
 
void loop()
{
  valorPot = analogRead(pot); // lê o valor do potenciômetro (de 0 a 1023)
  if(valorPot > 0 && valorPot <= 341) // entre 256 e 512, acende vermelho
  {
    acendeVermelho();
  }
  if(valorPot > 341 && valorPot <= 682) // entre 512 e 768, acende verde
  {
    acendeVerde();
  }
  if(valorPot > 682 && valorPot <= 1023) // entre 768 e 1023, acende azul
  {
    acendeAzul();
  }       
}
 
void acendeVermelho()
{
  digitalWrite(led_R, LOW);
  digitalWrite(led_G, HIGH);
  digitalWrite(led_B, HIGH);
}
 
void acendeVerde()
{
  digitalWrite(led_R, HIGH);
  digitalWrite(led_G, LOW);
  digitalWrite(led_B, HIGH);
}
 
void acendeAzul()
{
  digitalWrite(led_R, HIGH);
  digitalWrite(led_G, HIGH);
  digitalWrite(led_B, LOW);
}
