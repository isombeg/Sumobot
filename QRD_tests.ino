const int infraRed1 = A0;
const int infraRed2 = A1;
const int infraRed3 = A2;
const int infraRed4 = A3;


void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT); //Back left sensor
pinMode(A1, INPUT); //Top left sensor
pinMode(A2, INPUT); //Top right sensor
pinMode(A3, INPUT); //Back right sensor
Serial.begin(9600);
}

float proximityVDC(float proxADC){
  float proxV = proxADC*5.0/1023.0;
  return pro-xV;
}
void loop() {
//   put your main code here, to run repeatedly:
  float proxim1 = (float)analogRead(infraRed1);
  Serial.print(" Sensor 1:  ");
  Serial.print(proximityVDC(proxim1));
  float proxim2 = (float)analogRead(infraRed2);
  Serial.print(" Sensor 2:  ");
  Serial.print(proximityVDC(proxim2));
  float proxim3 = (float)analogRead(infraRed3);
  Serial.print(" Sensor 3:  ");
  Serial.print(proximityVDC(proxim3));
  float proxim4 = (float)analogRead(infraRed4);
  Serial.print(" Sensor 4:  ");
  Serial.println(proximityVDC(proxim4));
  delay(50);

}