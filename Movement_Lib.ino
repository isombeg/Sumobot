const int leftForward = 9;
const int leftBackward = 10;
const int rightForward = 5;
const int rightBackward = 6;

int motorPinList = {leftForward, leftBackward, rightForward, rightBackward};

const float motAngVel = 20.94; // rad/s
const float roboDim = 0.10; // m
const float wheelDiam = 0.042; // m


void setup() {
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
}

void forwardDrive(){
  digitalWrite(leftForward, HIGH); digitalWrite(leftBackward, LOW); 
  digitalWrite(rightForward, HIGH); digitalWrite(rightBackward, LOW);
}

void backwardDrive(){
  digitalWrite(leftForward, LOW); digitalWrite(leftBackward, HIGH); 
  digitalWrite(rightForward, LOW); digitalWrite(rightBackward, HIGH);
}

void stopMoving(){
  digitalWrite(leftForward, LOW); digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW); digitalWrite(rightBackward, LOW);
}

void leftPivot(){
  digitalWrite(leftForward, HIGH); digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW); digitalWrite(rightBackward, HIGH); // Runs the left motor forward and right motor backward for stationnary pivot
}

void rightPivot(){
  digitalWrite(leftForward, LOW); digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, HIGH); digitalWrite(rightBackward, LOW); // Runs the right motor forward and left motor backward for stationnary pivot
}


void forwardOpp(int oppPosition){ // oppPosition is bool determining whether opp is in front or not
  while(qrdRead == false && oppPosition == true){ //as long as robot is not on white line and opponent is still in front
    forwardDrive();
  }
  stopMoving();
}

void pivotOpp(){ //pivot when side sensors pick up readings
  while (visibleLeft == true){
    rightPivot();
  }
  while (visibleRight == false){
    leftPivot();
  }
}
