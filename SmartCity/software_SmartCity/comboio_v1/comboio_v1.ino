#include <Servo.h> 

#define SEGUNDO 1000

#define temporizacaoSensores 2.5

#define sensorPassagem 4
#define semaforoVermelho 5
#define semaforoVerde 6

#define sensorParagem1 8
#define sensorParagem2 9
#define energiaCarril 10

#define portaServo 7

int pos = 90;
Servo s;

void setup() {
  
    Serial.begin(9600);

    pinMode(sensorPassagem, INPUT);
    pinMode(semaforoVermelho, OUTPUT);
    pinMode(semaforoVerde, OUTPUT);
  
    pinMode(sensorParagem1, INPUT);
    pinMode(sensorParagem2, INPUT);
    pinMode(energiaCarril, OUTPUT);

    s.attach(portaServo);
    s.write(pos);
  
    digitalWrite(semaforoVerde, HIGH);
    digitalWrite(semaforoVermelho, LOW);
  
    digitalWrite(energiaCarril, HIGH);
}

void loop() {
 
    if(digitalRead(sensorPassagem) == LOW){
      abreCancela();
    }
    else if(digitalRead(sensorParagem1) == LOW || digitalRead(sensorParagem2) == LOW){
      pararComboios();
    }
    
}

void pararComboios(){
  
    Serial.println(">> Parar o comboio");
    digitalWrite(energiaCarril, LOW);
  
    delay(4 * SEGUNDO);
  
    Serial.println(">> Andar o comboio");
    digitalWrite(energiaCarril, HIGH);
  
  delay(temporizacaoSensores*SEGUNDO);  
}

void abreCancela(){
  
    digitalWrite(semaforoVerde, LOW);
    digitalWrite(semaforoVermelho, HIGH);
  
    delay(SEGUNDO/0.5);
  
    Serial.println(">> Fechar cancela");
    for(; pos >= 0; pos--){
        s.write(pos);
        delay(SEGUNDO/50);
    }
  
  
    delay(SEGUNDO);
  
    Serial.println(">> Abrir cancela");
    for(; pos < 90; pos++){
      s.write(pos);
      delay(SEGUNDO/50);
    }
  
    delay(SEGUNDO/0.5);
  
    digitalWrite(semaforoVerde, HIGH);
    digitalWrite(semaforoVermelho, LOW);
  
    delay(temporizacaoSensores*SEGUNDO);

}
