// Define a que pino está conectado o LED
#define LED 8

// Variável onde fica armazenado um a temporização 
int temporizacao = 1000;

/*** Função onde é inicializado o programa ***/
void setup()
{
  // Indica que o pino onde está conectado o LED irá sair energia
  pinMode(LED, OUTPUT);
}

/*** Função que irá ser repetida infinitamente ***/
void loop()
{
  // Liga o LED
  digitalWrite(LED, HIGH);
  //Mantém o LED ligado durante a temporização definida
  delay(1000); 

  // Desliga o LED
  digitalWrite(LED, LOW);
  //Mantém o LED desligado durante a temporização definida
  delay(1000);
}
