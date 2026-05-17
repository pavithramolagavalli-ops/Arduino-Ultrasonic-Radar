#include <Servo.h>

Servo myServo; 
const int pingPin = 11; // PING))) SIG pin D11 ki undi
long duration;
int distance;

void setup() {
  pinMode(pingPin, OUTPUT);
  Serial.begin(9600);
  myServo.attach(9); // Servo D9 ki undi
}

void loop() {
  for(int i=15; i<=165; i++){
    myServo.write(i);
    delay(50);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.println(".");
  }
  
  for(int i=165; i>=15; i--){
    myServo.write(i);
    delay(50);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.println(".");
  }
}

int calculateDistance(){
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  distance = duration * 0.034 / 2;
  
  if(distance > 400 || distance <= 0) distance = 400;
  return distance;
}
