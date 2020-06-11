#include "Arduino.h"

const int IN3 = 6;
const int IN4 = 7;


void initFrontAxle() {
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void _toRight() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void _toLeft() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void _toCenter() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void move(int value) {

  if (value >= 137) {
    _toRight();
    return;
  }

  if (value <= 117) {
    _toLeft();
    return;
  }

  _toCenter();
}
