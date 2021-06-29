
#include <Arduino.h>
#include <Wire.h>

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  ////////////////////////////////////////////// 
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 8);
  int AccelXH = Wire.read();
  
  Wire.beginTransmission(0x68);
  Wire.write(0x3C);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 8);
  int AccelXL =Wire.read();
/////////////////////////////////////////////////
  Wire.beginTransmission(0x68);
  Wire.write(0x3D);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 8);
  int AccelYH = Wire.read();
  
  Wire.beginTransmission(0x68);
  Wire.write(0x3E);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 8);
  int AccelYL =Wire.read();
/////////////////////////////////////////////////
  Wire.beginTransmission(0x68);
  Wire.write(0x41);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 8);
  int AccelZH = Wire.read();
  
  Wire.beginTransmission(0x68);
  Wire.write(0x42);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 8);
  int AccelZL =Wire.read();
/////////////////////////////////////////////////

  int Accel_valx = (AccelXH << 8) | AccelXL ;
  int Accel_valy = (AccelYH << 8) | AccelYL ;
  int Accel_valz = (AccelZH << 8) | AccelZL ;

  Serial.println(Accel_valx);
  Serial.println(Accel_valy);
  Serial.println(Accel_valz);
  delay(1000);
}
