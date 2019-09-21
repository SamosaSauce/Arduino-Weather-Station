void setup() {
  pinMode (12, INPUT);
  pinMode (13, OUTPUT);

}

void loop() 
  int sensor = digitalRead (12);
if (sensor == 1)
{
  digitalWrite (13, HIGH);
}
else
{
  digitalWrite (13, LOW);
}

