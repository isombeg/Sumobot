
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
  
  Serial.begin(9600);
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
  Serial.print("Peripheral Vision Right: "); //Dont work as of now.
  Serial.print(peripheralView(1)); 
}
boolean peripheralView(int side){//Returns true or false for the visiblity of an object on the sides in the range [7,80]cm
  //Left = 0, Right = 1
  if(side){ //right
    return (distanceR>=7 && distanceR<=80);
  }else{
    return (distanceL>=7 && distanceL<=80);
  }
}
int isInFront(){
  if(distance<=80||distance2<=80){
    if(abs(distance-distance2)<=4){//perfect alignment
      return 0;
    }else if(distance>distance2){//enemy on the right, bank right
      return 1;
    }else if(distance<distance2){//enemy on the left, bank left
      return -1;
    }
  }
}

void loop() {
//This block updates all the distance readings of the ultrasonic sensors which may or may not be used by other methods
  distance = pingUltra(trigPin, echoPin);
  distance2 = pingUltra(trigPin2, echoPin2);
  distanceL = pingUltra(trigPinL, echoPinL);
  distanceR = pingUltra(trigPinR, echoPinR);

  //Call peripheralView(0) or 1 as well as isInFront() after updating the distances
  printDist();
  printView();
  
}

