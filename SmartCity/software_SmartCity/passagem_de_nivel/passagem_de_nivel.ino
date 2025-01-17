#include <Servo.h> 
int posicao = 40;
Servo s;

void setup() {
  pinMode (12,OUTPUT); /*12 e o vermelho*/
  pinMode (13,OUTPUT); /*13 e o verde*/
  s.attach (7);
  Serial.begin (9600);
  s.write (posicao);  
}

void loop() {
    digitalWrite (13, LOW);
    digitalWrite (12, HIGH);
    for(;posicao<=140;posicao++){
      s.write (posicao);
      delay(20);
    }
 
    delay(1000);

    digitalWrite (13, HIGH);
    digitalWrite (12, LOW);
    for(;posicao>=40;posicao--){
      s.write (posicao);
      delay(20);
    }

    delay(1000);
}
