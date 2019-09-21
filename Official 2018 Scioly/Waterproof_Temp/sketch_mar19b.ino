#include <LiquidCrystal_I2C.h>            //include libraries
#include <Wire.h>              
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

LiquidCrystal_I2C lcd(0x27,20,4);

DallasTemperature sensors(&oneWire);

 float subValue = 267.39;
 float HighTempValue1 = 100;             //Declare floats
 float HighTempValue2 = 30.01;
 float MidTempValue1 = 30.00;
 float MidTempValue2 = 20.01;
 float LowTempValue1 = 20.00;
 float LowTempValue2 = 0;
 float Celcius=0;
 float Fahrenheit=0;
 int ThermistorPin = 0;
 int Vo;
 int redLED = 3;                       //Declare ints
 int greenLED = 6;
 int blueLED = 10;
 int on = 255;
 int off = 0;
 float R1 = 10000;
 float logR2, R2, T, Tc, Tf;
 float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
 String topLine = "Oak Valley";       //Declare strings
 String bottomLine = "GO FALCONS!!";
 
void setup(void)
{

  Serial.begin(9600);

  pinMode (redLED,OUTPUT);        //Set pins
  pinMode (greenLED,OUTPUT);
  pinMode (blueLED,OUTPUT);

  sensors.begin();               //Set sensors

  

lcd.init();                      //print topLine and bottomLine
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(topLine);
  lcd.setCursor(0,1);
  lcd.print(bottomLine);
   lcd.setCursor(0,2);
  lcd.print("");
   lcd.setCursor(2,3);
  lcd.print("");

  delay(2000);
}

void loop(void)
{ 
  
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - subValue; // - 273.15
  Tf = (Tc * 9.0)/ 5.0 + 32.0; 
  
 lcd.init();                                 //Print read
  lcd.init();
  lcd.backlight();
  //lcd.setCursor(1,0);
 // lcd.print("OVMS Falcons!!");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(Tc);
  lcd.print(" C");
  lcd.setCursor(0,2);
  lcd.print("");
   lcd.setCursor(2,3);
  lcd.print("");
  
  if (Tc>=LowTempValue2 && Tc<=LowTempValue1){     //Cold
  lcd.setCursor(0,0);
  lcd.print("Cold");
  digitalWrite(blueLED,HIGH);
  delay(1000);
  }

  else {
  digitalWrite(blueLED, LOW);
  }

  if (Tc>=MidTempValue2 && Tc<=MidTempValue1){     //Moderate
  lcd.setCursor(0,0);
  lcd.print("Moderate");
  digitalWrite(greenLED,HIGH);
  delay(1000);
  }

 else{
    
    digitalWrite(greenLED,LOW);
    
  }


  if (Tc>=HighTempValue2 && Tc<=HighTempValue1){  //Hot
  lcd.setCursor(0,0);
  lcd.print("Hot");
  digitalWrite(redLED,HIGH);
  delay(1000);
  }

  else{
    
    digitalWrite(redLED,LOW);
  }

}

//else {
  //analogWrite(blueLED,off);
  //}
 //else {
 // analogWrite(greenLED,off);
 // }
//else {
  //analogWrite(redLED,off);
  //}

 // else{
   // digitalWrite(blueLED,LOW);
   // digitalWrite(greenLED,LOW);
   // digitalWrite(redLED,LOW);
 // }



 
