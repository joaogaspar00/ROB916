#include <Keypad.h>
#include <LiquidCrystal.h>
#define Password_Lenght 4 

LiquidCrystal lcd(A0, A1, 10, 11, 12, 13);

char customKey;

char mestre[Password_Lenght+1] = "#916"; 

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
    lcd.clear();
    char password[Password_Lenght+1] = {};
    int index=0;
    lcd.setCursor(0,0);
    lcd.print("Insira password:");
    
    while(index<Password_Lenght){
      customKey = myKeypad.getKey();
      if(customKey){
        Serial.println(customKey);
        password[index] = customKey;
        index++;
        lcd.setCursor(0,1);
        lcd.print(password);
      }
    }
    delay(500);
    if(!strcmp(password, mestre)){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Cidade Ligada");
      lcd.setCursor(0,1);
      lcd.print(":)");
      analogWrite(A2, 250);
      cidade_ligada();
      }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Password errada!");
      }
    delay(2000);
    Serial.println(strlen(password));
    Serial.println(password);
}




void cidade_ligada(){
  int i = 0;
  while(i != 1){
    customKey = myKeypad.getKey();
    if(customKey == '*'){
      i = 1;
    }
  }
  analogWrite(A2, 0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Cidade Desligada");
  delay(2000);
}
