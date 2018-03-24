int infraRed2;
int infraRed3;
int infraRed4;
int infraRed5;
String Sensor2 = "Sensor 2:" ; String Sensor3 = "Sensor 3:" ; String Sensor4 = "Sensor 4:" ; String Sensor5 = "Sensor 5:" ;

void setup() {
  // put your setup code here, to run once:
pinMode(A2, INPUT); //Top left sensor
pinMode(A3, INPUT); //Bottom left sensor
pinMode(A4, INPUT); //Top right sensor
pinMode(A5, INPUT); //Bottom right sensor
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(Sensor2); Serial.println(analogRead(2));
Serial.println(Sensor3); Serial.println(analogRead(3));
Serial.println(Sensor4); Serial.println(analogRead(4));
Serial.println(Sensor5); Serial.println(analogRead(5));
delay(500);

}
