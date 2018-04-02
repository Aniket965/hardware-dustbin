#include <Servo.h>

#define MAX_DISTANCE_RANGE 50

int triger_pin = 2;
int echo_pin = 4;

long prev_duration = 0;
long current_duration = 0;
long distance_cm = 0;
float level_cm = 25;
int angle = 0;
Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
  servo.write(0);
}



void loop() {
  
  current_duration = get_level();
  distance_cm = get_distance() / 29 / 2;
  level_cm = current_duration / 29 / 2;
  if (distance_cm < 25 || level_cm < 5 ) {
    if(level_cm < 5) {
      Serial.println(level_cm);
      }else {
    servo.write(90);
    delay(15000);
    servo.write(0);
      }
  }else {
  if (level_cm > 25) {
    Serial.println(25);
  } else {
    Serial.println(level_cm);
  }
  delay(1000);
  }
}


/**
   it returns the duration after hitting the object
*/
long get_level() {
  long duration;
  pinMode(triger_pin, OUTPUT);
  digitalWrite(triger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(triger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triger_pin, LOW);
  pinMode(echo_pin, INPUT);
  duration = pulseIn(echo_pin, HIGH);
  delay(15);
  return duration;

}
long get_distance() {
  long duration;
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  delayMicroseconds(2);
  digitalWrite(5, HIGH);
  delayMicroseconds(10);
  digitalWrite(5, LOW);
  pinMode(6, INPUT);
  duration = pulseIn(6, HIGH);
  delay(15);
  return duration;

}
