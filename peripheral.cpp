#include "settings.h"
#include "peripheral.h"

peripheral::Peripheral::Peripheral() {
  DEBUG();
  DEBUG("[debug] Peripheral constructed.");
}

void peripheral::Peripheral::init() {
  DEBUG();
  DEBUG("[debug] Peripheral initialized.");
}

byte peripheral::Peripheral::getMotorAngle(byte motor) {
  return 46;
}

void peripheral::Peripheral::setMotorAngle(byte motor, byte angle) {
  return;
}
