#include "FrontAxle.h"

void setup() {
  frontAxleInit();
}

void loop() {
  frontAxleMove(-100);
  delay(1000);
  frontAxleMove(180);
  delay(1000);
}
