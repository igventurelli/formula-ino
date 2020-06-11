#include <PS4BT.h>
#include <usbhub.h>
#include "BackAxle.h"
#include "FrontAxle.h"

#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
BTD Btd(&Usb);

PS4BT PS4(&Btd, PAIR);

bool printAngle, printTouch;
uint8_t oldL2Value, oldR2Value;

void setup() {
  initBackAxle();
  initFrontAxle();

  /*
    The Bluetooth and USB codes are based on the original example from the USB Host Shield Library 2.0
    For more information about this code, please visit the code creator's blog:
    http://blog.tkjelectronics.dk/
  */

  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial);
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1);
  }
  Serial.print(F("\r\nPS4 Bluetooth Library Started"));
}

void loop() {
  Usb.Task();

  if (PS4.connected()) {
    
    move(PS4.getAnalogHat(LeftHatX));

    if (PS4.getAnalogButton(R2)) {
      speedUp(PS4.getAnalogButton(R2));
    }

    if (PS4.getAnalogButton(L2)) {
      reverse(PS4.getAnalogButton(L2));
    }

    if (PS4.getButtonClick(CIRCLE)) {
      handBrake();
    }
    
    if (PS4.getButtonClick(PS)) {
      PS4.disconnect();
    }
  }
}
