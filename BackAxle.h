#include "Arduino.h"

const int IN1 = 2;
const int IN2 = 4;
const int SPEED_CONTROL = 3;

void initBackAxle() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(SPEED_CONTROL, OUTPUT);
}

void _changeSpeed(int value) {
  analogWrite(SPEED_CONTROL, value);
}

void speedUp(int value) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  _changeSpeed(value);
}

void handBrake() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
}

void reverse(int value) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  _changeSpeed(value);
}

void neutral() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
