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
 int yellowLED = 2;
 int redLED = 4;
 String topLine = "Oak Valley";
 String bottomLine = "GO FALCONS!!";
 
void setup(void)
{

  Serial.begin(9600);

  pinMode (redLED,OUTPUT);
  pinMode (yellowLED,OUTPUT);

  sensors.begin();

  digitalWrite(redLED,HIGH);
  digitalWrite(yellowLED,HIGH);

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

 digitalWrite(redLED,HIGH);
  delay(100);
  digitalWrite(redLED,LOW);
  delay(100);

  digitalWrite(redLED,HIGH);
  delay(100);
  digitalWrite(redLED,LOW);
  delay(100);

  digitalWrite(yellowLED,HIGH);
  delay(100);
  digitalWrite(yellowLED,LOW);
  delay(100);

  digitalWrite(yellowLED,HIGH);
  delay(100);
  digitalWrite(yellowLED,LOW);
  delay(100);
  
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.println(Fahrenheit);

 lcd.init();                      
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(Celcius);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(Fahrenheit);
  lcd.print(" F");
   lcd.setCursor(0,2);
  lcd.print("");
   lcd.setCursor(2,3);
  lcd.print("");
  
  digitalWrite(redLED,HIGH);
  delay(100);
  digitalWrite(redLED,LOW);
  delay(100);

  digitalWrite(redLED,HIGH);
  delay(100);
  digitalWrite(redLED,LOW);
  delay(100);

  digitalWrite(yellowLED,HIGH);
  delay(100);
  digitalWrite(yellowLED,LOW);
  delay(100);

  digitalWrite(yellowLED,HIGH);
  delay(100);
  digitalWrite(yellowLED,LOW);
  delay(100);
  
}
