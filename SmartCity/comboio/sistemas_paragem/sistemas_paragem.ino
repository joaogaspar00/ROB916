#define IR1 2 
#define IR2 3
#define RELE 4

#define NAO_ESTEVE_PARADO 0
#define ESTEVE_PARADO 1

#define TEMPO_PARAGEM 10            // em segundos
#define TEMPORIZACAO_PARAGEM 5      // em segundos

void setup(){
    pinMode (IR1, INPUT);
    pinMode (IR2, INPUT); 
    pinMode (RELE, OUTPUT);
}

void loop(){
  
    int leituraSensor1 = digitalRead(IR1);
    int leituraSensor2 = digitalRead(IR2);
    
    if (leituraSensor1 == 0 || leituraSensor2 == 0){
      pararComboio();
      andarComboio(ESTEVE_PARADO);
    }  

    andarComboio(NAO_ESTEVE_PARADO);
}

void pararComboio(){
    digitalWrite(RELE, LOW);
    delay(TEMPO_PARAGEM * 1000);                  // Tempo que o comboio está parado
}

void andarComboio(int estado){
  
    digitalWrite(RELE, HIGH);
    
    if(estado == 1){        
        delay(TEMPORIZACAO_PARAGEM * 1000);       // Tempo para o comboio passar pelo sensor
    }
}
