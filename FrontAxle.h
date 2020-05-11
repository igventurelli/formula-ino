
/**
  Servo rotation is limited to 160º
  This is needed because 0º is not actually 0º, but something about 20º
  So to make it "linear", we need to cut the corner
  
  Cheap servo ¯\_(ツ)_/¯
 */

#include "Arduino.h"
#include <Servo.h>

Servo servo;

void frontAxleInit() {
  servo.attach(9);
  delay(15);
  servo.write(0);
  delay(15);
}

void _servoWrite(int value) {
  servo.write(value);
  delay(15);
}

void frontAxleMove(int value) {
  if (value > 160) {
    _servoWrite(160);
    return;
  }

  if (value < 0) {
    _servoWrite(0);
    return;
  }

  _servoWrite(value);
}
