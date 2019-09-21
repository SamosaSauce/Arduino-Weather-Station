#include <LiquidCrystal_I2C.h> 
#include <Wire.h>              
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

LiquidCrystal_I2C lcd(0x27,20,4);

DallasTemperature sensors(&oneWire);

 float Celcius=0;
 float Fahrenheit=0;
 float subValue = 263.39;
 int ThermistorPin = 0;
 int Vo;
 float R1 = 10000;
 float logR2, R2, T, Tc, Tf;
 float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
 String topLine = "Oak Valley";
 String bottomLine = "GO FALCONS!!";
 
void setup(void)
{

  Serial.begin(9600);

  sensors.begin();

lcd.init();                      
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

 lcd.init();                      
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(Tc);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(Tf);
  lcd.print(" F");
   lcd.setCursor(0,2);
  lcd.print("");
   lcd.setCursor(2,3);
  lcd.print("");
  
  
}
