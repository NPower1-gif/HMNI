
int sensorPin = A0;
int sensorValue;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(sensorPin, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue = analogRead(sensorPin);
Serial.println(sensorValue);
delay(1000/60);
//since p5 works with 60 frames/sec and arduino senses data in miliseconds to get 60 data per second we need to divide 1000 miliseconds with 60

}
