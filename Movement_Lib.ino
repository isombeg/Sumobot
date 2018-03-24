const int leftForward = 9;
const int leftBackward = 10;
const int rightForward = 11;
const int rightBackward = 12;

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
  digitalWrite(leftForward, HIGH); digitalWrite(rightForward, HIGH);
}

void backwardDrive(){
  digitalWrite(leftBackward, HIGH); digitalWrite(rightBackward, HIGH);
}

void stopMoving(){
  for (int pin = 9; pin < 13; pin ++){
    digitalWrite(pin, LOW);
  }
}

void leftPivot(){
  digitalWrite(leftForward, HIGH); digitalWrite(rightBackward, HIGH); // Runs the left motor forward and right motor backward for stationnary pivot
}

void rightPivot(){
  digitalWrite(rightForward, HIGH); digitalWrite(leftBackward, HIGH); // Runs the right motor forward and left motor backward for stationnary pivot
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
  while (visibleRight == right){
    leftPivot();
  }
}

void loop(){
  
  
}
