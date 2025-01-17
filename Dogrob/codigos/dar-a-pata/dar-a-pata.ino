#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVO_FREQ 50

#define NUM_MOTORES 12

                     /* MOTOR 0   1   2 */ 
int maximoPWM[NUM_MOTORES] = {515,515,515,  /* PATA 0 */ 
                              515,515,515,  /* PATA 1 */ 
                              515,515,515,  /* PATA 2 */ 
                              515,515,515}; /* PATA 3 */ 
                              
                     /* MOTOR 0  1  2 */           
int minimoPWM[NUM_MOTORES] = {70,70,70,  /* PATA 0 */
                              70,70,70,  /* PATA 1 */
                              70,70,70,  /* PATA 2 */
                              70,70,70}; /* PATA 3 */

                        /* MOTOR 0   1   2 */
int maximoANGULO[NUM_MOTORES] = {205,205,205,  /* PATA 0 */
                                 205,205,205,  /* PATA 1 */
                                 205,205,205,  /* PATA 2 */
                                 205,205,205}; /* PATA 3 */
int minimoANGULO = 0;


                  /* MOTOR 0  1  2 */ 
int angulo[NUM_MOTORES] = {90,125,0,   /* PATA 0 */ 
                           90,10,90,   /* PATA 1 */
                           90,125,0,  /* PATA 2 */
                           70,90,90};  /* PATA 3 */ 
                           
                     /* MOTOR 0 1 2 */
int invertido[NUM_MOTORES] = {0,0,1,  /* PATA 0 */ 
                              1,0,1,  /* PATA 1 */ 
                              1,1,0,  /* PATA 2 */ 
                              0,1,0}; /* PATA 3 */ 

                 /* MOTOR 0 1 2 */
int desvio[NUM_MOTORES] = {0,0,0,  /* PATA 0 */ 
                           0,0,0,  /* PATA 1 */ 
                           0,0,0,  /* PATA 2 */ 
                           0,0,0}; /* PATA 3 */                      

void setup() {
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
}

void loop(){
  for(int motor = 0; motor<12;motor++){
    if(invertido[motor]==0){
      pwm.setPWM(motor, 0, map(angulo[motor] + desvio[motor],
                               0,maximoANGULO[motor],
                               minimoPWM[motor],maximoPWM[motor]));
    }
    else{
      pwm.setPWM(motor, 0, map(180 - angulo[motor] + desvio[motor],
                               0,maximoANGULO[motor],
                               minimoPWM[motor],maximoPWM[motor]));
    }
  }

  angulo[5] = 30;
  delay(750);

  for(int motor = 0; motor<12;motor++){
    if(invertido[motor]==0){
      pwm.setPWM(motor, 0, map(angulo[motor] + desvio[motor],
                               0,maximoANGULO[motor],
                               minimoPWM[motor],maximoPWM[motor]));
    }
    else{
      pwm.setPWM(motor, 0, map(180 - angulo[motor] + desvio[motor],
                               0,maximoANGULO[motor],
                               minimoPWM[motor],maximoPWM[motor]));
    }
  }

  angulo[5] = 150;
  delay(750);
  
}
