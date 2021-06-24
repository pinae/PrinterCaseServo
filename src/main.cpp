#include <Arduino.h>
#include <Servo.h>

Servo doorServo;
int pos = 0;
int targetPos = 0;

void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT);
  pinMode(6, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  doorServo.attach(3);
}

void loop() {
  Serial.println(digitalRead(4));
  if (digitalRead(2)) { // open door and activate fan
    targetPos = 155;
    analogWrite(6, 100);
  } else { // close door and stop fan
    targetPos = 0;
    analogWrite(6, 0);
  }
  if (pos > targetPos) {
    pos--;
    doorServo.write(pos);
  }
  if (pos < targetPos) {
    pos++;
    doorServo.write(pos);
  }
  delay(10);
}