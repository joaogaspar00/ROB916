#include "ctimer.h"
 
#define LED0  8
 
cTimer  g_Timer0(true); 
// Defina aqui os tempos em ms para cada LED piscar:
#define   TEMPO_0   500
bool    gLed0 = false;
 
 
void setup() {
  pinMode(LED0, OUTPUT);
  digitalWrite(LED0, 0);
 
  g_Timer0.SetTimeOut(TEMPO_0);
   
}
 
 
void loop() {
  
    if(g_Timer0.IsTimeOut(true))
    {
      digitalWrite(LED0, gLed0);
      gLed0 = !gLed0;  
    }
   
    if(g_Timer1.IsTimeOut(true))
    {
      digitalWrite(LED1, gLed1);
      gLed1 = !gLed1;  
    }

    aumentar = digitalRead(maiorFreq);
    diminuir = digitalRead(menorFreq);

    if (aumentar == HIGH && intervalo < 2100) {
      intervalo += 100;
    } 
    else if(diminuir == HIGH && intervalo > 0){
      intervalo -= 100;
    }

    Serial.println(intervalo);
}
