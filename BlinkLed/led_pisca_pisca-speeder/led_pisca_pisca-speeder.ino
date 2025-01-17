#define pinLed 8
#define pinBotao 2

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinBotao, INPUT);
}
void loop() {
  while (digitalRead(pinBotao) == HIGH) {
    digitalWrite(pinLed, HIGH);
    delay(100);
    digitalWrite(pinLed, LOW);
    delay(100);
  }  
}
