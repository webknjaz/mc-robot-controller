#include "settings.h"
#include "robot.h"
#include "peripheral.h"

robot::Robot::Robot(protocol::Protocol *p, peripheral::Peripheral *hw) {
  this->proto = p;
  this->hw = hw;
  DEBUG();
  DEBUG("[debug] Robot initialized.");
}

void robot::Robot::init() {
  this->hw->init();
  this->proto->init();
}

byte robot::Robot::getAngle(byte motor) {
  return this->hw->getMotorAngle(motor);
}

void robot::Robot::setAngle(byte motor, byte angle) {
  this->hw->setMotorAngle(motor, angle);
}
