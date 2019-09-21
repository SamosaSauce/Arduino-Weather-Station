#include <LiquidCrystal_I2C.h>            //include libraries
#include <Wire.h>              
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

LiquidCrystal_I2C lcd(0x27,20,4);

DallasTemperature sensors(&oneWire);

 float HighTempValue1 = 100;             //Declare floats
 float HighTempValue2 = 30.01;
 float MidTempValue1 = 30.00;
 float MidTempValue2 = 20.01;
 float LowTempValue1 = 20.00;
 float LowTempValue2 = 0;
 float Celcius=0;
 float Fahrenheit=0;
 int redLED = 3;                       //Declare ints
 int greenLED = 6;
 int blueLED = 10;
 int on = 255;
 int off = 0;
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
  
  sensors.requestTemperatures();                        //Read sensors
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  
 lcd.init();                                 //Print read
  lcd.init();
  lcd.backlight();
  //lcd.setCursor(1,0);
 // lcd.print("OVMS Falcons!!");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(Celcius);
  lcd.print(" C");
  lcd.setCursor(0,2);
  lcd.print("");
   lcd.setCursor(2,3);
  lcd.print("");
  
  if (Celcius>=LowTempValue2 && Celcius<=LowTempValue1){     //Cold
  lcd.setCursor(0,0);
  lcd.print("Cold");
  digitalWrite(blueLED,HIGH);
  delay(1000);
  }

  else {
  digitalWrite(blueLED, LOW);
  }

  if (Celcius>=MidTempValue2 && Celcius<=MidTempValue1){     //Moderate
  lcd.setCursor(0,0);
  lcd.print("Moderate");
  digitalWrite(greenLED,HIGH);
  delay(1000);
  }

 else{
    
    digitalWrite(greenLED,LOW);
    
  }


  if (Celcius>=HighTempValue2 && Celcius<=HighTempValue1){  //Hot
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



 
