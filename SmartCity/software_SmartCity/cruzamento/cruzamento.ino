#define red1 5
#define yellow1 6
#define green1 7

#define red2 8
#define yellow2 9
#define green2 10 

#define temporizacao 1000

void setup() {
  // put your setup code here, to run once:
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);
 }

void loop() {
  // put your main code here, to run repeatedly:
  /*digitalWrite(green1, HIGH);
  digitalWrite(green2, HIGH);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, HIGH);
*/
  

  //1
  digitalWrite(green1, HIGH);
  digitalWrite(red2, HIGH);
  delay(4*temporizacao);
  
  //2
  digitalWrite(green1, LOW);
  digitalWrite(yellow1, HIGH);  
  delay(1*temporizacao);

  //3
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, HIGH);  
  delay(0.5*temporizacao);

  //4
  digitalWrite(red2, LOW);
  digitalWrite(green2, HIGH);  
  delay(4*temporizacao);

  //5
  digitalWrite(green2, LOW);
  digitalWrite(yellow2, HIGH);  
  delay(1*temporizacao);

  //6 
  digitalWrite(yellow2, LOW);
  digitalWrite(red2, HIGH);  
  delay(0.5*temporizacao);

  
  
 
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, HIGH);
  delay(2000); 
  digitalWrite(red1, LOW);

  
}
