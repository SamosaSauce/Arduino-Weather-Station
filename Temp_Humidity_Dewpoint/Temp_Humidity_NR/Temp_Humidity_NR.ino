#include <LiquidCrystal_I2C.h> //Include library for LCD display
#include <Wire.h>              //Include library for LCD display
#include <dht.h>               //Include library for Humiture sensor

LiquidCrystal_I2C lcd(0x27,20,4);   // set the LCD address to 0x27 for a 16 chars and 2 line display

#define DHT11PIN 8                       //Set pin for Humiture sensor
dht1wire DHT(DHT11PIN, dht::DHT11);      //Set pin for Humiture sensor

int nrTempValue = 23;
int nrHumidityValue = 40;
int i = DHT.getTemperature();
int w = DHT.getHumidity();
int yellowLED = 2;
int redLED = 4;
String topLine = "Oak Valley";
String bottomLine = "GO FALCONS!!";
 
void setup()
{
  Serial.begin(9600); //Open Serial port

  pinMode (redLED,OUTPUT);
  pinMode (yellowLED,OUTPUT);

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

void loop()
{

  unsigned long b = micros();
  dht::ReadStatus chk = DHT.read();
  unsigned long e = micros();

  Serial.println(F("OVMS RULES!!"));

  Serial.print(F("Humidity (%): "));
  Serial.println(DHT.getTemperature()/10);

  Serial.print(F("Temperature (°C): "));
  Serial.println(i);

  Serial.print(F("Dew Point (°C): "));
  Serial.println(DHT.dewPoint());

  Serial.println(" ");

  delay(500);

  lcd.init();                      
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(DHT.getTemperature()/10);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.getHumidity()/10);
  lcd.print(" %");
   lcd.setCursor(0,2);
  lcd.print("");
   lcd.setCursor(2,3);
  lcd.print("");

  if (DHT.getTemperature()/10==nrTempValue){
  digitalWrite(redLED,HIGH);
  }

  else {
  digitalWrite(redLED,LOW);
  }

  if (DHT.getHumidity()/10==nrHumidityValue){
  digitalWrite(yellowLED,HIGH);
  }

  else {
  digitalWrite(yellowLED,LOW);
  }

}

