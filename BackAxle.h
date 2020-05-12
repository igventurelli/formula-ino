#include "Arduino.h"

const int IN1 = 2;
const int IN2 = 4;
const int RIGHT_SPEED_CONTROL = 3;

const int IN3 = 6;
const int IN4 = 7;
const int LEFT_SPEED_CONTROL = 5;

void initBackAxle() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(RIGHT_SPEED_CONTROL, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(LEFT_SPEED_CONTROL, OUTPUT);
}

void _changeSpeed(int value) {
  analogWrite(LEFT_SPEED_CONTROL, value);
  analogWrite(RIGHT_SPEED_CONTROL, value);
}

void speedUp(int value) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  _changeSpeed(value);
}

void brake(int value) {
  _changeSpeed(value);
}

void handBrake() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void reverse(int value) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  _changeSpeed(value);
}

void neutral() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
