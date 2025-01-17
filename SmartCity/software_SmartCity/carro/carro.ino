#define A 0
#define B 1
#define P 0
#define N 1

#define in1 5
#define in2 6
#define in3 9
#define in4 10

#define enA 3
#define enB 11


int matriz_motores[2][2] = {{in1, in2}, {in3, in4}};

void ligar_motor(int matriz_motores[2][2], int motor, int direcao){
  if (direcao == P){
    digitalWrite(matriz_motores[motor][P], HIGH);
    digitalWrite(matriz_motores[motor][N], LOW);
  }
  else{
    digitalWrite(matriz_motores[motor][P], LOW);
    digitalWrite(matriz_motores[motor][N], HIGH);
  }
}

void define_velocidade(int motor, int velocidade){
  if(motor == A){
    analogWrite(enA, velocidade);
  }
  else{
    analogWrite(enB, velocidade);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(13, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  ligar_motor(matriz_motores, A, P);
  ligar_motor(matriz_motores, B, P);
  define_velocidade(A, 100);
  define_velocidade(B, 100);
  delay(8200);
  ligar_motor(matriz_motores, A, P);
  ligar_motor(matriz_motores, B, P);
  define_velocidade(A, 100);
  define_velocidade(B, 150);
  delay(1330);
}
