int Led = 13;
int lightSensor = A0;
int analogValue = 0;
void setup() {
  pinMode (Led, OUTPUT);
}


void loop() {
  analogValue = analogRead(lightSensorPin);
if (analogValue < 50 || analogValue > 100){
  digitalWrite (Led, LOW);
}
else if(analogValue >= 50 && analogValue <= 100)
{digitalWrite (Led, HIGH);}
}

