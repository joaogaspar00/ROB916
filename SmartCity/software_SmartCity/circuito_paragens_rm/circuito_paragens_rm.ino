#define outpin1 3
#define outpin2 2
#define ledpin 4                                                                  


void setup() {
  pinMode(outpin2, INPUT);
  pinMode(outpin1, INPUT);
  pinMode(ledpin, OUTPUT);

}

void loop() {
  
  int leitura1 = digitalRead(outpin1);
  int leitura2 = digitalRead(outpin2);
  
  if (leitura1 == 0|| leitura2 == 0){
    digitalWrite(ledpin, LOW);
    }
  else {
    digitalWrite(ledpin, HIGH);
  }
}
