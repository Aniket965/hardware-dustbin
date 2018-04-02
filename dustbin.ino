#include <Servo.h>
#include <Arduino.h>

#define MAX_DISTANCE_RANGE 50

int triger_pin = 2;
int echo_pin = 4;
int dusbin_trigger_pin  = 3;
int dustbin_echo_pin = 5;
long durations;
int isDustbinFull = 0;
long maxDistance = 25;`
long current_distance;
long dustbin_level = 0;

Servo servo1,servo2,servo3;


void setup() {
  Serial.begin(9600);
  servo1.attach(9);
}

void loop() {
  current_distance = get_distance(echo_pin,triger_pin);
  Serial.println(get_distance(dustbin_echo_pin,dusbin_trigger_pin));
  if(isDustbinFull && current_distance < maxDistance) {
  // Dustbin will not
  // near by Dustbin  will open automatically
  //TODO: Open servo dustbin 2
  } else if (current_distance < maxDistance)) {
    open_dustbin();
  }

}

int open_dustbin() {
    Serial.println("Opening Dustbin");
    servo3.write(90);
    delay(60000);
}


long get_distance(echo,trigger) {
  long duration;
  pinMode(trigger,OUTPUT);
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  pinMode(echo,INPUT);
  duration = pulseIn(echo,HIGH);
  delay(15);
  return duration/29/2;
}