#define potenciometro A0      // Porta analogica 0         
#define ledPin 8              // Porta digital 8

void setup() {
  pinMode(ledPin, OUTPUT);    // Definicao do pino 8 como output
}

void loop() {
  
  int intervalo = analogRead(potenciometro);  // Leitura do valor 
    
  digitalWrite(ledPin, HIGH);  // Ligar led
  delay(intervalo);            // Manter o led ligado durante o tempo dado pelo potenciometro      
  
  digitalWrite(ledPin, LOW);   // Desligar led
  delay(intervalo);            // Manter o led desligado durante o tempo dado pelo potenciometro         
}
