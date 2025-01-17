#include <Wire.h> 

int ADXL345 = 0x53;

float X, Y, Z;  

void setup() {
  Serial.begin(9600); 
  Wire.begin();
  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D);
  Wire.write(8);
  Wire.endTransmission();
  delay(10);
}

void loop() {
  
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); 
  
  X = ( Wire.read()| Wire.read() << 8);
  X = X/256;
  Y = ( Wire.read()| Wire.read() << 8);
  Y = Y/256;
  Z = ( Wire.read()| Wire.read() << 8);
  Z = Z/256;

  Serial.print("X= ");
  Serial.print(X);
  Serial.print("   Y= ");
  Serial.print(Y);
  Serial.print("   Z= ");
  Serial.println(Z);
}
