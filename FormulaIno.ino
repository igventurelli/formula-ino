#include "BackAxle.h"
#include "FrontAxle.h"

void setup() {
  initBackAxle();
  initFrontAxle();
}

void loop() {
  move(0);
  delay(1000);
  
  move(160);
  delay(1000);
  
  speedUp(100);
  delay(1000);
  
  reverse(100);
  delay(1000);

  handBrake();
  delay(1000);

  neutral();
  delay(1000);
}
