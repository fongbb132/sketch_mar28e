int enablePin = 7;
int pushPin2 = 4;
int pushPin = 3;
int Dwave = A2;
int Dsensor = A3;
int frontLightSensor = A1;
int backLightSensor = A0;

int switchPin = 2; //switch input

//
int motor1Pin = 12; //Hbridge leg 1
int motor1Pin2 = 11; //Hbridge leg 2
int motor2Pin = 9; //Hbridge for second motor;
int motor2Pin2 = 10 ; //Hbridge for second motor;

int enable1Pin = 8; //Hbridge enable pin OUT12
int enable2Pin = 13; //EN34

int slowSpeed =400;
int fastSpeed = 500;
int currentDirection;
int currentSpeed = slowSpeed;
int duration;
int count;

boolean running=LOW;
//for button
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean isTargetFound = LOW;

boolean isThisOut = false;


void setup(){
  Serial.begin (9600);
  pinMode(pushPin, INPUT);
  pinMode(switchPin, INPUT);
  pinMode(enable1Pin,OUTPUT);
  pinMode(pushPin2, INPUT);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(Dwave,OUTPUT);
  pinMode(Dsensor, INPUT);
}

void loop(){
  motor(0,300);
}

//255 is the max value for motor
//dir - 0 is front, 1 is back, 2 for left, 3 for right, 4 for stop
void motor(int dir, int velocity){
  switch(dir){
  case 0: 
    digitalWrite(motor1Pin, LOW); // set leg 1 of the H-bridge low
    digitalWrite(motor1Pin2, HIGH); // set leg 2 of the H-bridge high
    digitalWrite(motor2Pin, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(enable1Pin, velocity);
    analogWrite(enable2Pin, velocity);
    delay (50);
    break;
  case 1:
    digitalWrite(motor1Pin, HIGH); // set leg 1 of the H-bridge low
    digitalWrite(motor1Pin2, LOW); // set leg 2 of the H-bridge high
    digitalWrite(motor2Pin, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(enable1Pin, velocity);
    analogWrite(enable2Pin, velocity);
    delay (50);
    break;
  case 2:
    digitalWrite(motor1Pin, LOW); // set leg 1 of the H-bridge low
    digitalWrite(motor1Pin2, HIGH); // set leg 2 of the H-bridge high
    digitalWrite(motor2Pin, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(enable1Pin, velocity);
    analogWrite(enable2Pin, velocity);
    delay (50);
    break;
  case 3:
    digitalWrite(motor1Pin, HIGH); // set leg 1 of the H-bridge low
    digitalWrite(motor1Pin2, LOW); // set leg 2 of the H-bridge high
    digitalWrite(motor2Pin, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(enable1Pin, velocity);
    analogWrite(enable2Pin, velocity);
    delay (50);
    break;
  case 4:
    digitalWrite(motor1Pin, LOW); // set leg 1 of the H-bridge low
    digitalWrite(motor1Pin2, LOW); // set leg 2 of the H-bridge high
    digitalWrite(motor2Pin, LOW);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(enable1Pin, velocity);
    analogWrite(enable2Pin, velocity);
    break;
  default:
    digitalWrite(motor1Pin, LOW); // set leg 1 of the H-bridge low
    digitalWrite(motor1Pin2, HIGH); // set leg 2 of the H-bridge high
    digitalWrite(motor2Pin, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite (enable1Pin, velocity);
    delay (50);
    break;
  }

}
