
//Instantiate a new advanced serial object with 500 transmit slots


#define trigPin 2 // Front Left
#define echoPin 3 
#define trigPin2 7 //Front Right
#define echoPin2 8
#define trigPinL 11 //Left
#define echoPinL 12
#define trigPinR 0 //Right
#define echoPinR 1


long distance, distance2, distanceR, distanceL;

void setup() {
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);
  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);
  
}


long pingUltra(int tPin, int ePin){
  long duration, distance;
  digitalWrite(tPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(tPin, HIGH);
  delayMicroseconds(2); 
  digitalWrite(tPin, LOW);
  duration = pulseIn(ePin, HIGH);  
  distance = (duration*.0343)/2;
  return distance;
}
void printDist(){
  Serial.print(" Distance Front Left ");
  Serial.print(distance);
  Serial.print("  Distance Front Right  ");
  Serial.print(distance2);
  Serial.print(" Distance Left ");
  Serial.print(distanceL);
  Serial.print("  Distance Right  ");
  Serial.println(distanceR);
}
void printView(){
  Serial.print("Peripheral Vision Left: ");
  Serial.println(peripheralView(0));
//  Serial.print("Peripheral Vision Right: ") //Dont work as of now.
//  Serial.print(peripheralView(1)) 
}
boolean peripheralView(int side){
  //Left = 0, Right = 1
  if(side){ //right
    return (distanceR>=7 && distanceR<=80);
  }else{
    return (distanceLd>=7 && distanceL<=80);
  }
}

void loop() {
//  boolean test = 3<5;
//  Serial.println(test);
  distance = pingUltra(trigPin, echoPin);
  distance2 = pingUltra(trigPin2, echoPin2);
  distanceL = pingUltra(trigPinL, echoPinL);
  distanceR = pingUltra(trigPinR, echoPinR);
  printDist();
  printView();
  
}

